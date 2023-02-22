/*
* 1.아이디어
* 렌선의 길이가 너무 길어서 long long 을 써야하고 일반적인 탐색은 불가능하다
* 따라서 이분탐색을 사용한다.
* 
* left를 0, 입력을 받은 후 가장 큰 길이를 right에저장한다.
* 아래의 로직을 left > right 일 때까지 반복한다.
* -1left와 right의 절반을 mid에 저장하고 각 렌선길이를 mid로 나눈 몫을 total에 저장한다.
* -2total이 N과 비교해서 N보다 작을경우 right = mid - 1
* -3total이 N과 비교해서 같거나 클경우, result = mid, left = mid + 1
* 
* 2.시간복잡도
* O(log(LAN의 최대값)) * K, K<=10,000, LAN의 최대값 = 2,147,483,647, 따라서 가능
* 3.변수형
* long long total : 만약 mid가 엄청 작은수가 나오고 최대값을 나눈 몫이 커지게 되면 int를 넘게 되므로 long long
* 나머지는 int:
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	long long left = 1;
	long long right = -1;
	int answer = 0;

	vector<long long> LAN(K);
	for (auto& i : LAN) {
		cin >> i;
		right = max(i, right);
	}

	while (left <= right) {
		long long total = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < K; i++) 
			total += (LAN[i] / mid);

		if (total < N)
			right = mid - 1;
		else {
			left = mid + 1;
			answer = max(answer, mid);
		}
	}
	
	cout << answer;

	return 0;
}