/*
* 1.아이디어
* BFS구현문제이다.
* 맵 밖으로 이동하게 되면 탈출했다고 할 수 있다.
* 만약 다음 이동할 곳이 불이거나 벽이면 이동하지 않는다.
* 
* 탈출할때까지의 카운트를 증가시키면서 이동하면 된다.
* 
* 맵밖에 나갔다면 증가된 카운트를 출력, 만약 맵밖에 못나갔다면 불가능을 출력해준다.
* 
* 백터 fires를 초기화 하지 않아서 오류가 생겼었다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace  std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int W, H, answer, startX, startY;
char MAP[1000][1000];
bool visited[1000][1000];

vector<pair<int, int>> fires;

void printMAP() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void BFS() {
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	visited[startY][startX] = true;
	queue<pair<int, int>> fire;
	for (int i = 0; i < fires.size(); i++) 
		fire.push({ fires[i].first, fires[i].second });
	
	while (!q.empty()) {
		printMAP();
		int fireSize = fire.size();
		for (int i = 0; i < fireSize; i++) {
			int fireX = fire.front().first;
			int fireY = fire.front().second;

			fire.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = fireX + dx[dir];
				int ny = fireY + dy[dir];

				if (0 > nx || nx >= W || 0 > ny || ny >= H) continue;
				if (MAP[ny][nx] == '#' || MAP[ny][nx] == '*') continue;
				MAP[ny][nx] = '*';
				fire.push({ nx, ny });
			}
		}
		int qSize = q.size();
		answer++;
		for (int i = 0; i < qSize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (0 > nx || nx >= W || 0 > ny || ny >= H) {
					cout << answer <<"\n";
					return;
				}
				if (MAP[ny][nx] != '.' || visited[ny][nx]) continue;
				visited[ny][nx] = true;
				q.push({ nx, ny });
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		answer = 0;
		fires.clear();
		cin >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> MAP[i][j];
				if (MAP[i][j] == '@') {
					startX = j;
					startY = i;
					MAP[i][j] = '.';
				}else if (MAP[i][j] == '*') {
					fires.push_back({ j, i });
				}
			}
		}
		
		BFS();
		memset(visited, false, sizeof(visited));
	}

	return 0;
}