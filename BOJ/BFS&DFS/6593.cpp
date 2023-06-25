/*
* 1.아이디어
* 3차원배열을 BFS로 탐색하면 되는 문제이다.
* 
* 진짜 어이없는 이유로 틀렸다.
* memset의 사용법의 문제였다.
* memset(visited, sizeof(visited), false) 이렇게 써서 틀렸다.
* 
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct State {
	int x, y, z, cnt;
};

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int L, R, C; // z, y ,x
State Start, End;
char MAP[30][30][30];
bool visited[30][30][30];

int BFS() {
	queue<State> q;
	q.push(Start);
	visited[Start.z][Start.y][Start.x] = true;

	while (!q.empty()) {
		State node = q.front();
		q.pop();

		if (MAP[node.z][node.y][node.x] == 'E')
			return node.cnt;

		for (int i = 0; i < 6; i++) {
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			int nz = node.z + dz[i];

			if (0 > nx || nx >= C || 0 > ny || ny >= R || 0 > nz || nz >= L) continue;
			if (visited[nz][ny][nx] || MAP[nz][ny][nx] == '#') continue;
			visited[nz][ny][nx] = true;
			q.push(State{ nx, ny, nz, node.cnt + 1 });
		}
	}
	return -1;
}

int main(void) {
	
	while (true) {
		cin >> L >> R >> C;
		if (!L && !R && !C) return 0;
		
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string temp;
				cin >> temp;
				for (int k = 0; k < C; k++) {
					MAP[i][j][k] = temp[k];
					if (temp[k] == 'S')
						Start = { k, j, i, 0 };
				}
			}
		}
		int answer = BFS();
		if (answer >= 0) {
			cout << "Escaped in " << answer << " minute(s).\n";
		}
		else
			cout << "Trapped!\n";
	}

	return 0;
}