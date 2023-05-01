/*
* 1.아이디어
* 치즈 문제와 비슷하게 풀면 되지만 
* 이 문제는 공기에 닫는 면이 2개여야 한다.
* 따라서 해당 조건을 추가해서 풀어주면 된다.
* 
* Check배열에 해당 시간에 얼마나 많은 공기에 노출되었는지 확인해주고 
* 2개이상의 칸에 노출되었다면 치즈를 없에준다.
* 모든 치즈가 사라져있었을경우, 지난 시간을 출력해준다.
* 
* 매 시간마다 반복할 때 memset으로 visited와 Check를 초기화 해주어야 한다.
*/
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int map[100][100];
bool visited[100][100];
int Check[100][100];

int R, C;
int timer = 0;

bool BFS() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	timer++;
	int cnt = 0;
	while (!q.empty()) {
		auto index = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = index.first + dx[i];
			int ny = index.second + dy[i];

			if (0 > nx || nx >= C || 0 > ny || ny >= R) continue;
			if (map[ny][nx] == 1) {
				cnt++;
				Check[ny][nx]++;
				if (Check[ny][nx] >= 2) {
					map[ny][nx] = 0;
					visited[ny][nx] = true;
				}
			}
			else if (!visited[ny][nx]) {
				q.push({ nx, ny });
				visited[ny][nx] = true;
			}
		}
	}
	if (cnt == 0) {
		cout << --timer;
		return true;
	}
	else
		return false;
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	while (!BFS()) {
		memset(visited, false, sizeof(visited));
		memset(Check, 0, sizeof(Check));
	}

	return 0;
}