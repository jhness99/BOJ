/*
* 1.아이디어
* 이 문제는 투포인터로 풀면 될것같다.
* 
* 입력값을 받고 정렬한다.
* left right값을 0으로 초기화하고 answer는 가장 20억으로 설정한다.(가능한 가장 큰 수)
* abs(arr[right] - arr[left])가 M보다 같거나 크다면, 
* result = arr[right] - arr[left];
* answer = min(answer, result), start++;
* 나온 result가 M보다 작다면,
* end++
* 2.시간복잡도
* 정렬로인해 O(NlogN) N<=100,000 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	int left = 0, right = 0;
	int answer = 2000000000;
	while (left < N && right < N) {
		int result = input[right] - input[left];
		if (result >= M) {
			left++;
			answer = min(answer, result);
			if (answer == M)
				break;
		}
		else right++;
	}
	cout << answer;

	return 0;
}