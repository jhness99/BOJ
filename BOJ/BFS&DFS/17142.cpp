/*
* 1.아이디어
* BFS로 선택된 바이러스를 기준으로 탐색을 해서 가장 큰 값을 출력해주면 된다.
* 
* 이때 활성화 된 바이러스와 활성화 되지 않은 바이러스가 나눠지는데 
* 비활성화 된 바이러스가 활성화 하는데 걸리는 시간은 무조건 0초이다.
* 따라서 만약 
* 2 2
* 2 2 의 경우에서 (0,0)위치의 바이러스만 활성화 됬을 경우 걸리는 시간은 0초인것이다.
* 
* 그리고 총 바이러스가 활성화 하는 바이러스보다 많을 수 있는데
* 이것은 DFS로 모두 확인해주면 된다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M, answer = 10000000, emptyCnt;

int MAP[50][50];
int Time[50][50];
bool Select[10];

vector<pair<int, int>> virus;

void BFS(queue<pair<int, int>> q) {
	int TimeCnt = 0;
	int InfectCnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			if (MAP[ny][nx] == 1 || Time[ny][nx] != -1) continue;
			Time[ny][nx] = Time[y][x] + 1;
			if (MAP[ny][nx] == 0) {
				InfectCnt++;
				TimeCnt = Time[ny][nx];
			}
			q.push({nx, ny});
		}
	}
	if (InfectCnt == emptyCnt) {
		answer = min(answer, TimeCnt);
	}
}

void DFS(int idx, int cnt) {
	if (cnt == M) {
		queue<pair<int, int>> q;
		memset(Time, -1, sizeof(Time));
		for (int i = 0; i < virus.size(); i++) {
			if (Select[i] == true) {
				q.push(virus[i]);
				Time[virus[i].second][virus[i].first] = 0;
			}
		}
		BFS(q);
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (Select[i]) continue;
		Select[i] = true;
		DFS(i + 1, cnt + 1);
		Select[i] = false;
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) emptyCnt++;
			else if (MAP[i][j] == 2) virus.push_back({ j, i });
		}
	}

	DFS(0, 0);

	if (answer == 10000000)
		cout << -1;
	else
		cout << answer;

	return 0;
}