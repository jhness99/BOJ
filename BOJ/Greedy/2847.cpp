//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	
//	int N;
//	int cnt = 0;
//	cin >> N;
//	vector<int> v(N);
//
//	for (auto& i : v)
//		cin >> i;
//
//	for (int i = N-1; i >= 1; i--) {
//		if (v[i] <= v[i - 1]) {
//			cnt += v[i - 1] - v[i] + 1;
//			v[i - 1] = v[i] - 1;
//		}
//	}
//
//	cout << cnt;
//	return 0;
//}
//2023-02-19 복습
/*
* 1.아이디어
* 입력을 받아서 reverse를 사용해 역으로 돌린다
* 처음부터 확인하면서 다음숫자가 현재숫자보다 더 클 경우 answer += v[i+1]-v[i]+1
* 2.시간복잡도
* O(N) N<=100 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, answer = 0;
	cin >> N;

	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	reverse(v.begin(), v.end());

	for (int i = 0; i < N - 1; i++) {
		if (v[i] <= v[i + 1]) {
			answer += v[i + 1] - v[i] + 1;
			v[i + 1] = v[i] - 1;
		}

	}

	cout << answer;
	return 0;
}