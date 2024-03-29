/*
* 1.아이디어
* 입력받은 수들을 점수를 기준으로 내림차순 정렬을 한다.
* 정렬한 과제의 기한을 기준으로 해당 기한~1 까지 비어있는지, 즉 그 날 다른 과제를 했는지 체크
* 과제를 하지 않았다면 해당 날에 과제를 했다는 의미로 점수를 넣어주고 총 합 점수에 더해주고 했을경우 1이 될때까지 진행
* 2.시간복잡도
* 정렬 O(NlogN) + 기한의 최대가 1000이고 N번 반복할 수 있으므로 1000*1000, 따라서 가능
* 3.변수형
* int : 100*1000이므로 100000
*/
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//bool Check[1001] = { false, };
//
//bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
//	return p1.second > p2.second;
//}
//
//int main(void) {
//
//	int N, answer = 0;
//	cin >> N;
//
//	vector<pair<int, int>> v(N);
//	for (auto& p : v)
//		cin >> p.first >> p.second;
//
//	//점수를 기준으로 정렬
//	sort(v.begin(), v.end(), compare);
//
//	for (int i = 0; i < N; i++) {
//		//해당 과제의 종료기한까지 과제할 수 있는 날이 남아있으면, 과제를 하고 점수를 얻는다.
//		for (int j = v[i].first; j > 0; j--) {
//			if (!Check[j]) {
//				Check[j] = true;
//				answer += v[i].second;
//				break;
//			}
//		}
//	}
//	cout << answer;
//
//	return 0;
//}
//2023-03-01 복습
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool compareTo(const pair<int, int>& p1, const pair<int, int>& p2) {
//	return p1.second > p2.second;
//}
//
//int main(void) {
//
//	int N, answer = 0;
//	cin >> N;
//	vector<pair<int, int>> v(N);
//	vector<bool> schedule(N, false);
//
//	for (auto& p : v)
//		cin >> p.first >> p.second;
//
//	sort(v.begin(), v.end(), compareTo);
//
//	for (int i = 0; i < N; i++) {
//		for (int j = v[i].first; j > 0; j--) {
//			if (!schedule[j]) {
//				schedule[j] = true;
//				answer += v[i].second;
//				break;
//			}
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-19 복습
/*
* 1.아이디어
* 푸는법을 까먹어서 예전에 풀었던 아이디어를 보자 바로 생각났다.
* 마치 항공문제에서 푼 유니온파운드 같이 푼 문제였다.
* 성적순으로 정렬하고 우선순위큐를 만들어 top으로 하나씩 뺀다.
* 뺀 성적의 기한을 보고 check배열에 기한보다 작은 곳에 과제를 안 한 날짜를 찾아서 그날 풀었다고 체크해준다.
* 만약 4일경우 4에 체크가 되있다면, 미리 과제를 해도 되므로 이전의 기한에 빈 날이 있는지 체크하고 넣는다.
* 2.시간복잡도
* O(N) N<=1000 따라서 가능
* 3. 변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareTo(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second > p2.second;
}

int main(void) {

	int N, answer = 0;
	cin >> N;

	vector<pair<int, int>> v(N);
	vector<bool> Check(N, false);

	for (auto& p : v)
		cin >> p.first >> p.second;

	sort(v.begin(), v.end(), compareTo);

	for (int i = 0; i < N; i++) {
		for (int j = v[i].first; j > 0; j--) {
			if (!Check[j]) {
				Check[j] = true;
				answer += v[i].second;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}