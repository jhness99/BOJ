/*
* 1.아이디어
* (틀린아이디어)
* 깊이우선탐색과 dp를 사용하면 풀 수 있는 문제이다
* 먼저 상하좌우를 dfs로 탐색하는데 탐색하고 있는 위치의 높이가 탐색 할 위치의 높이보다 커야지 탐색한다.
* dfs의 방문체크같은 경우는 dp를 이용해서 dp가 0이라면 방문하지 않음, 0이 아니거나 도착위치라면 그대로 반환을 한다
* 그렇게 반환한 값을 dp[y][x] = dp[y][x] + dfs(ny, nx);에 넣는다.
* 최종적으로 시작 위치의 dp가 경로의 갯수가 된다.
* 
* (맞은아이디어)
* 거의다 맞은 아이디어지만 1가지 부족한 것이 있다면 방문체크다 위에선 방문체크를 dp로 한다고 했는데, 방문체크를 하려면 
* dp의 수가 바뀌어야 한다. 따라서 -1로 초기화를 하고 방문 했을경우 0으로 바꿔준다.
* 그리고 -1이 아니라면, 즉 방문을 했다면 해당 dp[y][x]를 반환해아한다. 나머지는 위와 같다.
* 그리고 마지막에 상하좌우 4개의 체크가 완료됬다면, dp[y][x]를 반환해 현재 노드에서 얼마나 많은 경로가 있는지도 알려줘야한다.
* 2.시간복잡도
* 3.변수형
* int : 
*/
#include <iostream>

using namespace std;

int M, N;
int dp[500][500];
int map[500][500];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1)
		return 1;
	if (dp[y][x] != -1)		//방문 이미 했을경우
		return dp[y][x];

	dp[y][x] = 0;			//방문체크
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
		if (map[ny][nx] < map[y][x]) {
			dp[y][x] = dp[y][x] + dfs(nx, ny);
		}
	}
	return dp[y][x];
}

int main(void) {

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;		//방문초기화
		}
	}

	dfs(0, 0);
	cout << dp[0][0];

	return 0;
}