/*
* 1.아이디어
* -와 |와 연결되도록 가로로만 이동하는경우 세로로만 이동하는 경우를 처음 시작할 때의 
* 방향으로 고정해서 해당 방향의 끝까지 이동하면서 방문처리를 해준다.
* 
*/
#include <iostream>

using namespace std;

int N, M, cnt;

char MAP[50][50];
bool visited[50][50];

void DFS(int x, int y, char ch){
	if (MAP[y][x] != ch) return;
	visited[y][x] = true;
	
	if (MAP[y][x] == '-') {
		if (x + 1 >= M) return;
		if (visited[y][x + 1]) return;
		DFS(x + 1, y, ch);
	}
	else if (MAP[y][x] == '|') {
		if (y + 1 >= N) return;
		if (visited[y + 1][x]) return;
		DFS(x, y + 1, ch);
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++){
			if (visited[i][j]) continue;
			cnt++;
			DFS(j, i, MAP[i][j]);
		}
	}

	cout << cnt;

	return 0;
}