/*
* 1.아이디어
* DFS를 사용해보자
* 먼저 파이프의 끝부분을 기준으로 →↘↓ 이지만 가로 세로일 경우에는 직각으로 이동하지 못한다.
* 해당 파이프가 대각선상태인지 세로 가로 상태인지 확인해야한다.
* 대각선의 경우 이동하는 위치 기준 map[i-1][j], map[i][j-1]에 벽이 없어야한다.
* 완전탐색을 하면서 마지막에 목적지에 도착하면 종료해주고 cnt++를 해주면 된다.
* 2.시간복잡도
* DFS인데 3가지 방향으로 갈 수 있으므로 O(3(N^2)) N<=16이므로 가능
* 3.변수형
* 
*/
//#include <iostream>
//
//using namespace std;
//
////가로 세로 대각선
//int dx[] = {1,0,1};
//int dy[] = {0,1,1};
//
//int cnt = 0;
//int N;
//int map[17][17];
//
////state 가로 : 0 세로 : 1 대각선 : 2
//void DFS(int x, int y, int state) {
//	if (x == N && y == N) {
//		cnt++;
//		return;
//	}
//
//	for (int i = 0; i < 3; i++) {
//		if (state == 0 && i == 1) continue;
//		if (state == 1 && i == 0) continue;
//
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (1 > nx || nx > N || 1 > ny || ny > N || map[ny][nx]) continue;
//		if (i == 2 && (map[ny - 1][nx] || map[ny][nx - 1])) continue;
//
//		DFS(nx, ny, i);
//	}
//}
//
//int main(void) {
//
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) 
//			cin >> map[i][j];
//	}
//
//	DFS(2, 1, 0);
//	cout << cnt;
//
//	return 0;
//}
//2023-03-10 복습
/*
* 1.아이디어
* 입력을 받아 map을 초기화
* dfs를 사용해 탐색을 한다. 오른쪽, 아래, 대각선 순서로 이동한다.
* 이때 dfs에서 현재 파이프의 상태를 알려줘서 이동에 제한을 둔다.
* 도착하면 answer ++를 하고 나온다.
*/
#include <iostream>

using namespace std;

//오른쪽 : 0 아래 : 1 대각선 : 2, 
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

int map[17][17];
int N, answer = 0;

//state상태 오른쪽 : 0 아래 : 1 대각선 : 2
void DFS(int x, int y, int state) {
	if (x == N && y == N) {
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (state == 0 && i == 1) continue;
		if (state == 1 && i == 0) continue;

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (1 > nx || nx > N || 1 > ny || ny > N || map[ny][nx]) continue;
		if (i == 2 && (map[ny - 1][nx] || map[ny][nx - 1])) continue;

		DFS(nx, ny, i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(2, 1, 0);
	cout << answer;

	return 0;
}