/*
* 1.아이디어
* 입력받은 B를 정렬하고 lower_bound를 사용해 가장먼저나온 A[i]와 같거나 큰 수의 index를 가져오고
* 해당 index가 먹을 수 있는 것의 갯수이다. 
* A의 모든 수를 위 알고리즘에 대입해서 나오는 개수를 answer에 저장한다.
* 
* 2.시간복잡도
* 3.변수형
* 
*/
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int N, M, answer = 0;
//		cin >> N >> M;
//
//		vector<int> A(N);
//		vector<int> B(M);
//
//		for (auto& i : A)
//			cin >> i;
//		
//		for (auto& i : B)
//			cin >> i;
//
//		sort(B.begin(), B.end());
//		for (int i = 0; i < N; i++) {
//			int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
//			answer += idx;
//		}
//		cout << answer << "\n";
//	}
//
//	return 0;
//}
//2023-03-27 복습
/*
* 1.아이디어
* B를 정렬하고 lower_bound를 하면 A[i]를 기준으로 해당 index아래가 해당 수보다 더 작은수들이기 때문에
* A[i]보다 작은 수를 알 수 있다.
*
*
* 2.시간복잡도
* N번 이분탐색을 하므로 O(NlogN) N<=20000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int N, M, answer = 0;
		cin >> N >> M;

		vector<int> A(N);
		for (auto& i : A)
			cin >> i;

		vector<int> B(M);
		for (auto& i : B)
			cin >> i;

		sort(B.begin(), B.end());
		for (int i = 0; i < N; i++) {
			int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
			answer += idx;
		}
		cout << answer << "\n";
	}

	return 0;
}