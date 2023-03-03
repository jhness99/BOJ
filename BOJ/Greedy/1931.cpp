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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 단순하게 p1.second < p2.second만 해줬더니 두개가 같을경우를 고려하지 않아서 틀렸었다.
*/
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

int main(void) {

	int N, cnt = 0;
	cin >> N;

	vector<pair<int, int>> schedule(N);
	for (auto& p : schedule)
		cin >> p.first >> p.second;

	sort(schedule.begin(), schedule.end(), compare);

	int prevStart = -1;
	for (int i = 0; i < N; i++) {
		if (prevStart <= schedule[i].first) {
			prevStart = schedule[i].second;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}