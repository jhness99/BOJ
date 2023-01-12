#include <iostream>
#include <vector>
#include <queue>

#define MAX 1500

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
bool FIND = false; 
int row, col;
char map[MAX][MAX];
queue<pair<int, int>> swan_Q, swan_NQ, Q, NQ;
pair<int, int> swan_pos;
bool visited[MAX][MAX];

void Swan_bfs() {
	while (!swan_Q.empty() && !FIND) {
		int x = swan_Q.front().first;
		int y = swan_Q.front().second;
		swan_Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < row && 0 <= ny && ny < col) {
				if (!visited[nx][ny]) {
					if (map[nx][ny] == '.') {
						visited[nx][ny] = true;
						swan_Q.push(make_pair(nx, ny));
					}
					else if (map[nx][ny] == 'X') {
						visited[nx][ny] = true;
						swan_NQ.push(make_pair(nx, ny));
					}
					else if (map[nx][ny] == 'L') {
						FIND = true;
						visited[nx][ny] = true;
						break;
					}
				}
			}
		}
	}
}

void Water_bfs() {
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < row && 0 <= ny && ny < col) {
				if (map[nx][ny] == 'X')
				{
					map[nx][ny] = '.';
					NQ.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void) {
	int day = 0;
	cin >> row >> col;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] != 'X') Q.push(make_pair(i, j));
			if (map[i][j] == 'L') {
				swan_pos.first = i;
				swan_pos.second = j;
			}
		}
	}
	
	swan_Q.push(make_pair(swan_pos.first, swan_pos.second));
	visited[swan_pos.first][swan_pos.second] = true;
	while (!FIND) {
		Swan_bfs();
		if (!FIND) {
			Water_bfs();
			Q = NQ;
			swan_Q = swan_NQ;
			while (!NQ.empty()) NQ.pop();
			while (!swan_NQ.empty()) swan_NQ.pop();
			day++;
		}
	}
	cout << day;

	return 0;
}