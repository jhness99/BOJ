/*
* 1.아이디어
* 우선 2개의 동전이 동시에 떨어지면 안되고 1개씩 떨어져야 한다.
* 여기서 떨어진다는 것은 범위를 벗어난 것이고 평범한 DFS BFS와 다르게 범위를 넘어가면 
* 그 순간 1개만 떨어진지, 2개 전부 떨어진지 확인해서 1개만 떨어졌을 경우 이동횟수를 최솟값과 비교해서 갱신해주면 된다.
* 
* 동전의 위치를 따로 저장해준다.
* DFS에서 버튼을 누른 횟수가 10을 넘거나 기존최대횟수를 넘어가면 종료한다.
* 
*/
#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> coins;

int N, M;
int answer = 11;
char map[20][20];

bool CheckLimit(int x, int y) {
	if (0 <= x && x < M && 0 <= y && y < N)
		return true;
	else return false;
}

void DFS(int x, int y, int xx, int yy, int cnt, int dir) {
	if (answer < cnt) return;
	if (cnt > 10) return;

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int nxx = xx + dx[dir];
	int nyy = yy + dy[dir];

	if (!CheckLimit(nx, ny) && !CheckLimit(nxx, nyy)) return;
	else if (!CheckLimit(nx, ny) && CheckLimit(nxx, nyy)) {
		answer = min(answer, cnt);
		return;
	}
	else if (CheckLimit(nx, ny) && !CheckLimit(nxx, nyy)) {
		answer = min(answer, cnt);
		return;
	}
	if (map[ny][nx] == '#') {    
		nx = x;
		ny = y;
	}
	if (map[nyy][nxx] == '#')
	{
		nxx = xx;
		nyy = yy;
	}
	for (int i = 0; i < 4; i++)
	{
		DFS(nx, ny, nxx, nyy, cnt + 1, i);
	}
}


int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') coins.push_back({ j, i });
		}
	}

	for (int i = 0; i < 4; i++) {
		int x = coins[0].first;
		int y = coins[0].second;
		int xx = coins[1].first;
		int yy = coins[1].second;

		DFS(x, y, xx, yy, 1, i);
	}

	if (answer > 10)
		cout << -1;
	else
		cout << answer;

	return 0;
}