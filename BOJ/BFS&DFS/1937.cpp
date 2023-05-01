/*
* 1.아이디어
* BFS를 사용해 모든 곳을 확인해주면 되는 문제이다.
* 다음 위치로 갈 때 탐색하기 전 위치보다 값이 크면 이동할 수 있도록 해서
* 가장 많이 이동한 값으로 갱신해주면 된다.
* 
* (틀린부분)
* BFS로 해결하려고 했지만 경로를 확인해야 하므로 DFS로 푸는것이 맞는것같다.
* BFS로도 가능할 것 같지만 DFS가 출제의도인것같아서 DFS로 풀었다.
* 
* DP까지 사용해서 DFS로 탐색을 마치고 돌아올 때 하나씩 갱신해주면서 해당 위치에서 얼마나 이동할 수 있는지 체크한다.
* 체크한 값을 max를 통해 DP를 갱신해준다.
*/
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int N;
int map[500][500];
int DP[500][500];

int DFS(int x, int y) {
	if (DP[y][x] != 0) return DP[y][x];
	DP[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
		if (map[ny][nx] > map[y][x])
			DP[y][x] = max(DP[y][x], DFS(nx, ny) + 1);
	}
	return DP[y][x];
}

int main(void) {

	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			answer = max(answer, DFS(j, i));
	}

	cout << answer;

	return 0;
}