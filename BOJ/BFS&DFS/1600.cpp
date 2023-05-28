/*
* 1.아이디어
* BFS처럼 진행하지만 우리는 말의 이동또한 고려해야 한다.
* 따라서 queue에 말의 이동능력을 사용한 횟수와 이동 횟수를 저장해주어야 한다.
* 
* 이때 해당 칸을 말의 이동을 몇번 사용해서 도착할 수 있었는지 저장하기 위해
* visited를 3차원 배열로 저장해 마지막에는 해당 index가 몇번 말의 이동을 했는지를 확인할 수 있도록 한다.
* 
*/
#include <iostream>
#include <queue>

using namespace std;

struct Q {
	int x;
	int y;
	int hCnt;
	int mCnt;
};

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int hdx[] = { 1,2,2,1,-1,-2,-2,-1 };
int hdy[] = { -2,-1,1,2,2,1,-1,-2 };

int K, W, H;
bool visited[200][200][31];
int map[200][200];

void BFS() {
	queue<Q> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int HorseCnt = q.front().hCnt;
		int MoveCnt = q.front().mCnt;
		q.pop();

		if (x == W - 1 && y == H - 1) {
			cout << MoveCnt;
			return;
		}


		if (HorseCnt < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hdx[i];
				int ny = y + hdy[i];

				if (0 > nx || nx >= W || 0 > ny || ny >= H) continue;
				if (visited[ny][nx][HorseCnt + 1] || map[ny][nx]) continue;

				visited[ny][nx][HorseCnt + 1] = true;
				q.push({ nx, ny, HorseCnt + 1, MoveCnt + 1 });
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= W || 0 > ny || ny >= H) continue;
			if (visited[ny][nx][HorseCnt] || map[ny][nx]) continue;

			visited[ny][nx][HorseCnt] = true;
			q.push({ nx, ny, HorseCnt, MoveCnt + 1 });
		}
	}
	cout << -1;
}

int main(void) {

	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	BFS();

	return 0;
}