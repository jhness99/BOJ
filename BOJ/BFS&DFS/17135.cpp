/*
* 1.아이디어
* 궁수는 총 3명이다. 이때 궁수는 임의로 성에 배치될 수 있다.
* 배치된 궁수는 사거리에 따라 다가오는 적을 죽일 수 있다.
* 
* 가로의 최대크기는 15이므로 배치된 궁수의 위치를 저장하는 select배열에 저장해주고
* 이것을 선택하는 것은 DFS를 사용해 모든 경우를 확인해준다.
* 
* 선택됬다면 해당 과정을 진행하면 되는데 해당 위치에서 가장 가까운 궁수를 탐색하면 된다.
* 궁수와 적의 거리차이는 |궁수의 x - 적의 x| + |궁수의 y - 적의 y|이다. 
* 이 값은 대각선을 제외한 상하좌우로 이동했을 때의 이동한 칸의 개수라고 해도 무방하다.
* 따라서 BFS를 사용해 가장 왼쪽에 있는 가까운 적을 쏴주면 된다.
* 가장 가까운 왼쪽의 적을 죽이기 위해 dx와 dy를 왼쪽으로 우선적으로 탐색하게 한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = { -1,0,1 };
int dy[] = { 0,-1,0 };

int N, M, D, answer, killCnt;

int MAP[15][15];
int CopyMap[15][15];
bool visited[15][15];
bool Check[15][15];
bool Select[15];
int archer[3];

vector<pair<int, int>> Enemy;

void CopyMAP() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			CopyMap[i][j] = MAP[i][j];

}

void Shot() {
	CopyMAP();
	memset(Check, false, sizeof(Check));
	int pos = N;
	while (pos > 0) {
		for (int i = 0; i < 3; i++) {
			memset(visited, false, sizeof(visited));
			queue<pair<int, int>> q;
			int x = archer[i];
			int y = pos - 1;
			q.push({ x, y });

			int moveCnt = 0;
			while (!q.empty()) {
				x = q.front().first;
				y = q.front().second;
				q.pop();

				visited[y][x] = true;

				if (CopyMap[y][x]) {
					Check[y][x] = true;
					break;
				}
				for (int dir = 0; dir < 3; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
					if (abs(archer[i] - nx) + abs(pos - ny) > D) continue;
					if (visited[ny][nx]) continue;
					q.push({ nx, ny });
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Check[i][j]) {
					CopyMap[i][j] = 0;
				}
			}
		}
		pos--;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Check[i][j]) killCnt++;

}

void DFS(int idx, int cnt) {
	if (cnt == 3) {
		killCnt = 0;
		Select[0];
		CopyMap[0][0];
		Check[0][0];
		Shot();
		Select[0];
		
		answer = max(answer, killCnt);
		return;
	}
	for (int i = idx; i < M; i++) {
		if (Select[i]) continue;
		Select[i] = true;
		archer[cnt] = i;
		DFS(i + 1, cnt + 1);
		Select[i] = false;
	}
}

int main(void) {

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	DFS(0, 0);
	cout << answer;

	return 0;
}