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
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M, answer = 0;
//	cin >> N >> M;
//	
//	int left = -1;
//	int right = 0;
//
//	vector<int> input(N);
//	for (auto& i : input){
//		cin >> i;
//		left = max(left, i);
//		right += i;
//	}
//		
//	while(left <= right) {
//		int mid = (left + right) / 2;
//		int cnt = 1;
//		int temp = mid;
//		bool flag = false;
//		for (int i = 0; i < N; i++) {
//
//			if (temp - input[i] < 0) {
//				cnt++;
//				temp = mid;
//			}
//			temp -= input[i];
//		}
//
//		if (cnt > M) {
//			left = mid + 1;
//		}
//		else {
//			answer = mid;
//			right = mid - 1;
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-28 복습
/*
* 1.아이디어
* 가장 짧게 인출하는 경우는 1번에 쓸 돈을 모두구하는 경우이고 최소로 출금했을때 모든 날에 사용할 수 있어야 하므로
* left는 최대값, right는 모든 값에 합으로 한다.
*
* 이분탐색을 통해 mid를 구하고 mid를 기준으로 모든 값을 확인해서 mid에 해당값을 뺀 값이 0보다 작다면, cnt를 올려주고
* mid를 초기화한다.아닐경우 그냥 mid에서 빼준다.
*
* 나온 cnt를 가지고 M과 비교해서 cnt가 더 클경우, start = mid + 1;
* 작거나 같을경우, end = mid - 1, answer = mid을 해준다.
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
	for (auto& i : input) {
		cin >> i;
		left = max(left, i);
		right += i;
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int temp = mid;
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