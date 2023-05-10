/*
* 1.아이디어
* 모든 L을 BFS탐색으로 탐색해준다. 이때 해당 시작 위치를 기준으로 가장 멀리 떨어져있는 위치의 L을 answer에 계속 갱신해준다.
* 
* BFS와 브루트포스를 이용해 문제를 풀 수 있다.
* 
* queue에 저장하는 x, y 말고도 그 위치의 길이또한 저장해준다. 
* 이 방법이 아니더라도 배열을 하나 만들어서 저장하는 방법이나, while안에 있는 for문이 끝날때마다 cnt를 올려줘서 기록하는 방법도 있다.
* 여튼 이러한 방법으로 탐색을 시작한 위치에서 갈 수 있는 가능한 모든 위치와 시작위치의 거리를 확인해서 가장 큰 값으로 계속 갱신을 해주는 것이다.
* 
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int R, C;
char MAP[50][50];
bool visited[50][50];

int answer;

void BFS(int x, int y) {
	int len = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y } , 0});
	visited[y][x] = true;
	while (!q.empty()) {
		auto index = q.front();
		len = max(len, index.second);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = index.first.first + dx[i];
			int ny = index.first.second + dy[i];

			if (0 > nx || nx >= C || 0 > ny || ny >= R) continue;
			if (visited[ny][nx] || MAP[ny][nx] == 'W') continue;

			visited[ny][nx] = true;
			q.push({ { nx, ny } , index.second+1 });
		}
	}
	answer = max(len, answer);
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> MAP[i][j];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				BFS(j, i);
			}
		}
	}
	
	cout << answer;
	return 0;
}