/*
* 1.아이디어
*/
#include <iostream>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int M, N;
char MAP[1000][1000];
bool visited[1000][1000];

void DFS(int x, int y) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
		if (visited[ny][nx] || MAP[ny][nx] == '1') continue;
		DFS(nx, ny);
	}
}

int main(void) {

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
	}

	for (int i = 0; i < N; i++) {
		DFS(i, 0);
	}

	for (int i = 0; i < N; i++) {
		if (visited[M - 1][i]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}