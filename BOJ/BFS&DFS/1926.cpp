/*
* 1.아이디어
* BFS와 DFS 모두 가능하다. 
* BFS와 DFS모두 main함수에서 모든 위치의 수를 확인해주면 된다. 이때 해당 칸이 1일경우만 BFS를 진행해주고
* 방문을 확인해서 방문된 곳일 경우 확인을 하지 않으면 된다.
* 
* BFS의 경우, BFS가 끝난다면 cnt를 1올려주고 가장 큰 값인지 갱신해주면 된다.
* DFS의 경우는 return 을 해서 크기를 반환해서 max로 가장 큰 값인지 갱신해주면 된다.
* 
*/
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int R, C, answer, cnt;

int map[500][500];
bool visited[500][500];

void BFS(int x, int y) {
	int Count = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty()) {
		auto index = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = index.first + dx[i];
			int ny = index.second + dy[i];

			if (0 > nx || nx >= C || 0 > ny || ny >= R) continue;
			if (!map[ny][nx] || visited[ny][nx]) continue;
			q.push({ nx, ny });
			visited[ny][nx] = true;
			Count++;
		}
	}
	answer = max(answer, Count);
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] && !visited[i][j]) {
				BFS(j, i);
				cnt++;
			}
		}
	}

	cout << cnt << "\n" << answer;

	return 0;
}