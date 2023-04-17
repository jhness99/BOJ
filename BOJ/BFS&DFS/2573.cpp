/*
* 1.아이디어
* 2가지로 연산을 하면된다.
* 우선 주변의 물의 개수에 따라 빙산의 높이를 줄여주는 연산
* 두번째로 빙산이 2덩어리 이상이 됬는지 확인하는 연산
* 이때 덩어리는 상하좌우로 연결되어있다. 따라서 방문처리를 해주면서 DFS나 BFS연산을 해주면 된다.
* 
* (틀린부분)
* 나는 그냥 배열에 갱신을 해주려고 했지만 녹기 전 상태에서 녹았을 때로 갱신해줄 때
* 해당 시간에서 녹아버린 빙산또한 다른 빙산에 영향을 줄 수 있었다.
* 따라서 temp를 만들어서 거기에 임시로 저장해서 녹아버린 빙산은 그 시간때에 적용하지 않도록 해야
* 오류가 나오지 않는것이다.
* 
* 2.시간복잡도
* 
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
 
int map[300][300];
int temp[300][300];
bool visited[300][300];
int N, M;

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;
	while (!q.empty()) {
		auto index = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = index.first + dx[i];
			int ny = index.second + dy[i];

			if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
			if (map[ny][nx] != 0 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void meltUpdate() {
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = j + dx[dir];
				int ny = i + dy[dir];

				if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
				if (map[ny][nx] == 0 && map[i][j] > 0) {
					cnt++;
				}
 			}
			int val = map[i][j] - cnt;
			if (val > 0) temp[i][j] = val;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) 
			map[i][j] = temp[i][j];
	}
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	int answer = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0 && !visited[i][j]) {
					BFS(j, i);
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			cout << 0;
			break;
		}
		else if (cnt >= 2) {
			cout << answer;
			break;
		}
		answer++;
		meltUpdate();
		memset(visited, false, sizeof(visited));
	}

	return 0;
}