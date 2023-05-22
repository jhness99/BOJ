/*
* 1.아이디어
* DFS나 BFS를 사용해서 시작부분의 색을 기준으로 연결되어있는 모든 병사의 수를 계산해서
* 계산한 수를 제곱해서 해당 병사의 값에 넣어주면된다.
* 
* 세로 가로가 아니라 가로 세로로 입력받아야 한다.
* 
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1, };

int White;
int Blue;

int N, M;

vector<string> map;
bool visited[100][100];

void BFS(int x, int y) {
	char Color = map[y][x];
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
			if (visited[ny][nx] || map[ny][nx] != Color) continue;
			cnt++;
			q.push({ nx, ny });
			visited[ny][nx] = true;
		}
	}
	cnt *= cnt;
	if (Color == 'B') Blue += cnt;
	else if (Color == 'W') White += cnt;
}

int main(void) {

	cin >> N >> M;

	map = vector<string>(M);
	
	for (int i = 0; i < M; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j])
				BFS(j, i);
		}
	}

	cout << White << " " << Blue;
	
	return 0;
}