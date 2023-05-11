/*
* 1.아이디어
* 단순하게 완전탐색으로 풀면된다. DFS로 depth가 5가 될때까지 탐색한다.
*/
#include <iostream>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int map[5][5];
bool Check[1000000];
int answer;

void DFS(int x, int y, int sum, int cnt) {
	if (cnt == 5) {
		if (!Check[sum]) {
			Check[sum] = true;
			answer++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;
		DFS(nx, ny, sum * 10 + map[ny][nx], cnt + 1);
	}
}

int main(void) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(j, i, map[i][j], 0);
		}
	}

	cout << answer;

	return 0;
}