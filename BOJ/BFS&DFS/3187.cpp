/*
* 1.아이디어
* 
*/
#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int R, C;

char MAP[250][250];
bool visited[250][250];
pair<int, int> answer;
int wolfCnt, sheepCnt;

void DFS(int x, int y) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= C || 0 > ny || ny >= R) continue;
		if (visited[ny][nx] || MAP[ny][nx] == '#') continue;
		if (MAP[ny][nx] == 'v') wolfCnt++;
		else if (MAP[ny][nx] == 'k') sheepCnt++;
		DFS(nx, ny);
	}
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j]) continue;
			wolfCnt = 0;
			sheepCnt = 0;

			DFS(j, i);
			if (wolfCnt >= sheepCnt)
				answer.second += wolfCnt;
			else if (sheepCnt > wolfCnt)
				answer.first += sheepCnt;
		}
	}

	cout << answer.first << " " << answer.second;

	return 0;
}