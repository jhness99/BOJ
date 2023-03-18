/*
* 1.아이디어
* 모든 집과 치킨집의 위치를 저장한다. 모든 치킨집의 경우로 탐색한다.
* M개만큼의 치킨집을 골랐다면 모든 집에서 고른 치킨집끼리의 치킨거리를 계산한다. 
* 작은값으로 갱신해주면서 계산하고 최종적인 치킨거리를 기존값과 비교해서 더 작은값으로 갱신해준다
* 
* 2.시간복잡도
* 
* 3.변수형
* vector<pair<int, int>> house :
* vector<pair<int, int>> chicken :
* vector<pair<int, int>> target :
*/
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer = 10000000;

bool selected[13];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> target;

int Distance(const pair<int, int>& p1, const pair<int, int>& p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void DFS(int index, int cnt) {
	if (cnt == M) {
		int result = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 1000;
			for (int j = 0; j < target.size(); j++) {
				min_dist = min(min_dist, Distance(house[i], target[j]));
			}
			result += min_dist;
		}
		answer = min(result, answer);
	}
	for (int i = index; i < chicken.size(); i++) {
		if (selected[i])
			continue;

		selected[i] = true;
		target.push_back(chicken[i]);
		DFS(i, cnt + 1);
		target.pop_back();
		selected[i] = false;
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;

			if (num == 1)
				house.push_back({ i, j });
			else if (num == 2)
				chicken.push_back({ i, j });
		}
	}

	DFS(0, 0);

	cout << answer;

	return 0;
}