/*
* 1.아이디어
* 주어진 값을 사용해 맵을 갱신해준다.
* 갱신된 맵을 사용해 BFS나 DFS로 가장 큰 크기로 갱신해준다.
* 
* 
*/
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int R, C, answer;
int map[101][101];
bool visited[101][101];

int BFS(int x, int y){
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;
	int cnt = 1;

	while (!q.empty()) {
		auto index = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = index.first + dx[i];
			int ny = index.second + dy[i];

			if (1 > nx || nx > C || 1 > ny || ny > R) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 1) {
				q.push({ nx, ny });
				visited[ny][nx] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	int N;
	cin >> R >> C >> N;

	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;

		map[r][c] = 1;
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j]) {
				answer = max(answer, BFS(j, i));
			}
		}
	}

	cout << answer;

	return 0;
}