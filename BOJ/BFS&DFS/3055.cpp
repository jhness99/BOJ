/*
* 1.아이디어
* 물을 먼저 퍼지게 하고 남은 공간에서 고슴도치가 이동하게 한다. 이때 벽과 물이 있으면 이동할 수 없다.
* BFS을 사용해서 모든 위치를 확인해준다. 그러다가 비버의 굴을 발견하면 이동시간을 저장해준다.
* check를 사용해 방문체크와 시간을 모두 체크해준다.
* 
* 
*/
#include <iostream>
#include <queue>

using namespace std;

int R, C;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int startX;
int startY;
int targetX;
int targetY;
int check[50][50];
char map[50][50];

bool CheckRange(int x, int y) {
	if (0 <= x && x < C && 0 <= y && y < R) return true;
	return false;
}

void flood() {
	char temp[50][50];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '*') continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = j + dx[dir];
				int ny = i + dy[dir];

				if (!CheckRange(nx, ny)) continue;
				if (map[ny][nx] != '.') continue;
				temp[ny][nx] = '*';
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = temp[i][j];
		}
	}
}

void TestPrint() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	int timer = 0;

	while (!q.empty()) {
		
		auto index = q.front();
		q.pop();
		if (timer == check[index.second][index.first]) {
			flood();
			//TestPrint();
			timer++;
		}
		

		for (int i = 0; i < 4; i++) {
			int nx = index.first + dx[i];
			int ny = index.second + dy[i];

			if (!CheckRange(nx, ny)) continue;
			if (map[ny][nx] == '.' || map[ny][nx] == 'D') {
				if (check[ny][nx] == 0) {
					check[ny][nx] = check[index.second][index.first] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}



int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				startX = j;
				startY = i;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'D') {
				targetX = j;
				targetY = i;
			}
		}
	}

	BFS(startX, startY);
	
	if (!check[targetY][targetX])
		cout << "KAKTUS";
	else
		cout << check[targetY][targetX];

	return 0;
}