/*
* 1.아이디어
* 
*/
#include <iostream>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;
char MAP[50][50];
bool visited[50][50];

int startX, startY;

bool flag = false;

bool DFS(int x, int y, int num) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
		if (nx == startX && ny == startY && num >= 4) {
			cout << "Yes";
			flag = true;
			return true;
		}
		if (visited[ny][nx] || MAP[y][x] != MAP[ny][nx]) continue;
		if (DFS(nx, ny, num + 1)) return true;
	}
	visited[y][x] = false;
	return false;
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!flag) {
				startX = j;
				startY = i;
				DFS(j, i, 1);
			}
		}
	}

	if (!flag) cout << "No";

	return 0;
}