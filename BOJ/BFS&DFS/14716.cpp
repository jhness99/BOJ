/*
* 1.아이디어
*/
#include <iostream>

using namespace std;

int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int M, N, answer;
int MAP[250][250];
bool visited[250][250];

void DFS(int x, int y) {
	visited[y][x] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
		if (visited[ny][nx] || MAP[ny][nx] == 0) continue;
		DFS(nx, ny);
	}
}

int main(void) {

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && MAP[i][j] == 1) {
				answer++;
				DFS(j, i);
			}
		}	
	}

	cout << answer;

	return 0;
}