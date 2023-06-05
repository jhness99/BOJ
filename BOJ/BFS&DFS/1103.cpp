/*
* 1.아이디어
* (처음 아이디어)
* DFS를 사용해 모든 곳을 확인하는데 이때 cnt를 1씩 올려줘서 더 이상 갈 곳이 없거나
* 구멍에 떨어진다면 떨어지도록 하려고 했지만 DFS이기 때문에 도중에 그만둬버리면
* 다른 길은 갈 수 없으므로 BFS로 했을 때 의미있는 방법이였다.
* 하지만 BFS로는 사이클을 확인할 수 없으므로 불가능
* 따라서 DFS로 해야한다. 그러므로 DFS에 dp를 같이 사용한다.
* 
* (맞은풀이)
* 3가지의 예외를 모두 잡아주어야 한다. 
* 1)만약 다음 이동할 곳이 맵 밖인경우
* 2)만약 다음 이동할 곳이 구멍일경우 
* 3)이미 방문한경우(사이클인경우)
* 크게 3가지고 1,2는 같다고 볼 수 있다.
* 
* dp를 사용해서 모든 값을 -1로 초기화 한 후에 해당위치를 탐색할 때 0으로 바꿔준다.
* 그리고 DFS에서 재귀를 되돌아갈 때 -1이 아닌경우, 즉 이전에 확인했던 것일 경우 자기자신을 반환해서
* 그 이전 함수를 재귀처리할 때 자신의 값을 알려주는 것이다.
* 
* 따라서 dp를 사용해야 하고 재귀가 다시 돌아가는 경우는 1,2의 경우이므로 해당상황에서는 0을 넣어주어서
* 해당 DFS를 호출한 함수에서 1을 얻을 수 있도록 한다.(DFS(nx,ny) + 1)
* 
* 이렇게 하면 시작지점으로 올 경우 가장 경로가 긴 값이 갱신될 것이다.
*/
#include <iostream>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

char MAP[50][50];
bool visited[50][50];
int dp[50][50];
int N, M, answer;

int DFS(int x, int y) {
	//예외처리
	//1,2번경우
	if (0 > x || x >= M || 0 > y || y >= N  || MAP[y][x] == 'H') return 0; 
	//3번경우
	if (visited[y][x]) return -1;
	//만약 해당 칸을 이미 갔다왔다면, 그 경로값 반환
	if (dp[y][x] != -1) return dp[y][x];

	int dist = MAP[y][x] - '0';
	visited[y][x] = true;
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * dist;
		int ny = y + dy[i] * dist;
		
		int temp = DFS(nx, ny);
		//3번경우일경우 모든 재귀함수 -1을 반환시키면서 종료시킴
		if (temp == -1) return -1;
		dp[y][x] = max(dp[y][x], temp+1);
	}
	visited[y][x] = false;
	return dp[y][x];
}


int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}

	memset(dp, -1, sizeof(dp));

	answer = DFS(0, 0);

	cout << answer;

	return 0;
}