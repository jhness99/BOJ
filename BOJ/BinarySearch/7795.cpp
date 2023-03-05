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
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int N, M, answer = 0;
		cin >> N >> M;

		vector<int> A(N);
		vector<int> B(M);

		for (auto& i : A)
			cin >> i;
		
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