/*
* 1.아이디어
* 0 0 부터 빈 공간을 확인하고 빈공간이 있을경우 상하좌우를 확인한다.
* 그 후 치즈가 있으면 0으로 만들어주고 0일경우 queue에 넣어서 다음 탐색을 해준다.
* 탐색이 끝나고 치즈가 없을경우 종료해주고 치즈가 있다면 한번 더 탐색을 해준다.
* 
* 탐색이 끝나면 timer와 result를 출력해준다.
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int R, C;
int map[100][100];
bool visited[100][100];

int timer;
int result;

bool BFS() {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	timer++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= C || 0 > ny || ny >= R) continue;
			if (visited[ny][nx]) continue;
			
			if (map[ny][nx] == 0) {
				q.push({ nx, ny });
			}
			else if (map[ny][nx] == 1) {
				map[ny][nx] = 0;
				cnt++;
			}
			visited[ny][nx] = true;
		}
	}
	if (cnt == 0) {
		cout << --timer << "\n" << result;
		return true;
	}
	else {
		result = cnt;
		return false;
	}
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	}

	while (true) {
		if (BFS())
			break;
		memset(visited, false, sizeof(visited));
	}

	return 0;
}