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