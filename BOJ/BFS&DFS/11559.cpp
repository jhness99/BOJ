/*
* 1.아이디어
* 우선 현재 존재하는 모든 블럭을 확인한다.
* 확인해서 BFS연산으로 해당 블록과 같은 주변의 블록의 개수를 확인하고 4이상이라면 제거할 큐에 넣는다.
* 연산이 끝나면 제거할 큐에 들어간 블록으로 한번 더 bfs연산을 해주고 연산을 하면서 블록을 부순다.
* 만약 블럭을 부순적이 있다면 연쇄를 1 올려준다.
* 
* 탐색과 파괴가 끝나면 모든 블록을 중력이 적용되도록 내려준다.
* 
* 더 이상 부셔지는 블록이 없을 때 까지 반복해준다.
* 
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

char MAP[12][6];
bool visited[12][6];

int answer;

bool SearchBreakBlock(int x, int y) {
	int cnt = 1;
	char color = MAP[y][x];
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];

			if (0 > nx || nx >= 6 || 0 > ny || ny >= 12) continue;
			if (visited[ny][nx] || MAP[ny][nx] != color) continue;
			cnt++;
			q.push({ nx, ny });
			visited[ny][nx] = true;
		}
	}
	if (cnt >= 4)
		return true;
	else
		return false;
}

void BreakBlock(queue<pair<int, int>> q) {
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		char color = MAP[y][x];
		MAP[y][x] = '.';
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= 6 || 0 > ny || ny >= 12) continue;
			if (visited[ny][nx] || MAP[ny][nx] != color) continue;
			visited[ny][nx] = true;
			q.push({ nx, ny });
		}
	}
}

bool Puyo() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (MAP[i][j] == '.' || visited[i][j]) continue;
			if (SearchBreakBlock(j, i)) q.push({ j, i });
		}
	}
	BreakBlock(q);
	if (q.size() != 0) {
		answer++;
		return true;
	}
	return false;
}

void FallBlock() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			int tempY = i;
			while (tempY < 11) {
				if (MAP[tempY + 1][j] == '.')
					tempY++;
				else break;
			}
			if (tempY != i) {
				MAP[tempY][j] = MAP[i][j];
				MAP[i][j] = '.';
			}
		}
	}
}

int main(void) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) 
			cin >> MAP[i][j];
	}
	
	while (true) {
		if (!Puyo()) break;
		FallBlock();
	}

	cout << answer;

	return 0;
}