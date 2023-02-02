/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cnt_array[20] = { 0, };
int main(void) {

	int T, N;
	cin >> T;
	

	for (int TestCase = 0; TestCase < T; TestCase++) {
		int cnt = 1;
		cin >> N;
		
		vector<pair<int, int>> v(N);
		for (int i = 0; i < N; i++) {
			int n1,n2;
			cin >> n1 >> n2;
			v[i] = make_pair( n1, n2 );
		}
		
		sort(v.begin(), v.end());

		int Ranking = v[0].second;
		for (int i = 0; i < N; i++) {
			if (Ranking > v[i].second) {
				cnt++;
				Ranking = v[i].second;
			}
		}
		cnt_array[TestCase] = cnt;
	}
	for (int i = 0; i < T; i++) {
		cout << cnt_array[i] << " ";
	}
	return 0;
}
*/
/*
* 2023-02-02 복습
*/
/*
* 1.아이디어
* 입력값을 pair로 받아옴
* 면접이나 서류 둘 중 하나를 기준으로 정렬
* 정렬된 기준으로, 더 등수가 아래인 지원자의 정렬되지 않은 등수가 위의 지원자보다 낮을 경우 탈락
* 2.시간복잡도
* 탐색에 O(N), 정렬에 O(NlogN), N <= 100000 이므로 가능
* 3.변수형
* vector<pair<int, int>> : 서류와 면접의 정보를 동시에 저장하므로 pair
* int : 최대 합격인원수가 10000의 이하이므로 int
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int T;
	cin >> T;
	while (T--) {
		int N, cnt = 1;
		cin >> N;
		vector<pair<int, int>> v(N);
		for (auto& p : v)
			cin >> p.first >> p.second;

		sort(v.begin(), v.end());

		int prevScore = v[0].second;
		for (int i = 0; i < N; i++) {
			if (v[i].second < prevScore) {
				cnt++;
				prevScore = v[i].second;
			}

		}
		cout << cnt << "\n";
	}


	return 0;
}