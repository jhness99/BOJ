/*
* 1.아이디어
* 
* 가장 큰 값과 가장 작은 값으로 left right로 초기화 해준다.
* 초기화한 left right로 mid를 만들어서 mid을 인출금액이라고 했을때의 몇번 인출해야하는지 계산한다.
* 해당 값이 M보다 작다면, start를 mid + 1로 해서 값을 키우고 
* M보다 크다면 end = mid -1을 해서 값을 줄여준다.
* 만약 M과 같다면 answer = mid를 해주면 된다.
* 
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, M, answer = 0;
	cin >> N >> M;
	
	int left = -1;
	int right = 0;

	vector<int> input(N);
	for (auto& i : input){
		cin >> i;
		left = max(left, i);
		right += i;
	}
		
	while(left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int temp = mid;
		bool flag = false;
		for (int i = 0; i < N; i++) {

			if (temp - input[i] < 0) {
				cnt++;
				temp = mid;
			}
			temp -= input[i];
		}

		if (cnt > M) {
			left = mid + 1;
		}
		else {
			answer = mid;
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}