/*
* 1.아이디어
* 입력받은 값을 끝나는 시간 기준으로 정렬
* 확인하고 있는 스케쥴의 시작 시간보다 이전에 수행한 스케쥴의 끝나는 시간이 같거나 더 작을경우
* cnt++, 이전에 수행한 스케줄의 끝나는 시간을 갱신
* 
* 2.시간복잡도
* O(N) N<=100000, 따라서 가능
* 
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
///*
//* 단순하게 p1.second < p2.second만 해줬더니 두개가 같을경우를 고려하지 않아서 틀렸었다.
//*/
//bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
//	if (p1.second == p2.second) {
//		return p1.first < p2.first;
//	}
//	else {
//		return p1.second < p2.second;
//	}
//}
//
//int main(void) {
//
//	int N, cnt = 0;
//	cin >> N;
//
//	vector<pair<int, int>> schedule(N);
//	for (auto& p : schedule)
//		cin >> p.first >> p.second;
//
//	sort(schedule.begin(), schedule.end(), compare);
//
//	int prevStart = -1;
//	for (int i = 0; i < N; i++) {
//		if (prevStart <= schedule[i].first) {
//			prevStart = schedule[i].second;
//			cnt++;
//		}
//	}
//
//	cout << cnt;
//
//	return 0;
//}
//2023-03-21
/*
* 1.아이디어
* 입력한 수를 끝나는 시간 기준으로 정렬한다.
* 첫번째 수를 기준으로, 끝나는 시간보다 시작하는 시간이 더 큰 회의를 찾는다.
* 해당 회의를 기준으로 끝나는 시간을 갱신해주고 answer++한다.
* 이를 반복해준다.
* 2.시간복잡도
* 정렬하므로 O(NlogN) N<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//second말고 first도 정렬 해야 됨 왜냐하면 그리디하게 해야하기 때문에 최선의 선택을 해야함

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, answer = 1;
	cin >> N;

	vector <pair<int, int>> schedule(N);
	for (auto& p : schedule)
		cin >> p.first >> p.second;

	sort(schedule.begin(), schedule.end(), compare);

	int endTime = schedule[0].second;
	for (int i = 1; i < N; i++) {
		if (schedule[i].first >= endTime) {
			answer++;
			endTime = schedule[i].second;
		}
	}

	cout << answer;

	return 0;
}