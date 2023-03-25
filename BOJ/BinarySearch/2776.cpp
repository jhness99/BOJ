/*
* 1.아이디어
* 수첩1,2 모두 최대 100만개의 정수를 가질 수 있으므로 완전탐색을 하면 시간복잡도가 높게 나온다
* 따라서 이분탐색으로 접근한다.
* lower_bound를 사용하면 쉽게 풀 수 있다
* 수첩1을 오름차순으로 정렬한 후 수첩2의 숫자들을 lower_bound로 찾아내서 있을경우1, 없을경우 0을 출력하게 하면 된다.
* 2.시간복잡도
* M회만큼 N크기의 수를 확인하므로, O(MlogN), M, N <=1000000 따라서 가능
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int N, M;
//		cin >> N;
//
//		vector<int> v1(N);
//		for (auto& i : v1)
//			cin >> i;
//
//		sort(v1.begin(), v1.end());
//		
//		cin >> M;
//		for (int i = 0; i < M; i++) {
//			int Num;
//			cin >> Num;
//			auto upper = upper_bound(v1.begin(), v1.end(), Num);
//			auto lower = lower_bound(v1.begin(), v1.end(), Num);
//
//			if (upper - lower > 0) cout << 1 << '\n';
//			else cout << 0 << '\n';
//		}
//	}
//
//	return 0;
//}
//2023-03-24 복습
/*
* 1.아이디어
* upper_bound와 lower_bound를 사용해 두 index가 같지 않을경우 해당수가 존재하므로 1, 아닐경우 0을 출력
*
* 2.시간복잡도
* 정렬를 사용했으므로 O(NlogN), 이분탐색을 M번 반복했으므로, O(MlogN) N,M<=1000000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;

		vector<int> A(N);
		for (auto& i : A)
			cin >> i;

		sort(A.begin(), A.end());

		cin >> M;
		vector<int> B(M);
		for (auto& i : B)
			cin >> i;

		for (int i = 0; i < M; i++) {
			auto low = lower_bound(A.begin(), A.end(), B[i]);
			auto upper = upper_bound(A.begin(), A.end(), B[i]);

			if (upper != low)
				cout << 1;
			else
				cout << 0;

			cout << "\n";
		}
	}

	return 0;
}