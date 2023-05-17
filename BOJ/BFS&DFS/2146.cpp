/*
* 1.아이디어
* 각 섬에 번호를 붙여서 다른섬끼리 이어지는 다리를 BFS로 탐색해 가장 작은값과 비교해서 갱신해준다.
* 
* 기존엔 하나하나 모든 경로를 확인하는 방법도 있고 해당 영역의 모든 구역을 큐에 저장해서
* 한번에 탐색시키는 방법도 있다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N;

int map[100][100];
bool visited[100][100];

vector<pair<int, int>> v;

void AreaNumbering(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	map[y][x] = num;
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			if (visited[ny][nx] || !map[ny][nx]) continue;

			q.push({ nx, ny });
			visited[ny][nx] = true;
			map[ny][nx] = num;
		}
	}
}

int BFS(int num) {
	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == num)
			{
				visited[i][j] = true;
				q.push({ j, i });
			}
		}
	}

	while (!q.empty()) {
		int s = q.size();
		for (int j = 0; j < s; j++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
				if (map[ny][nx] != 0 && map[ny][nx] != num) return cnt;
				else if (!visited[ny][nx] && !map[ny][nx]) {
					q.push({ nx, ny });
					visited[ny][nx] = true;
				}
			}
		}
		cnt++;
	}
}

int main(void) {

	int answer = 100000000;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				v.push_back({ j,i });
			}
		}
	}
	
	int number = 1;
	for (auto& p : v) {
		if (visited[p.second][p.first]) continue;
		AreaNumbering(p.first, p.second, number);
		number++;
	}

	for (int i = 1; i < number; i++)
	{
		answer = min(answer, BFS(i));
		memset(visited, false, sizeof(visited));
	}

	cout << answer;

	return 0;
}