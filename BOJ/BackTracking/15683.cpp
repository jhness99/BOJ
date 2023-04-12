/*
* 1.아이디어
* 맵을 복사해서 로직을 실행한 후 해당 맵에 0의 개수를 세서 최소값을 갱신해주면 된다.
* 
* DFS로 모든 경우의 수를 체크해준다. CCTV의 타입을 기준으로 탐색할 방향을 고려해준다.
* 예를들면 1의 경우 1방향만 확인하면 되고 2의 경우 1과 3 , 0과 2 방향을 확인해주면 된다.
* 
* 입력을 받을 때 CCTV의 위치를 미리 저장해둔다. 해당 CCTV들을 DFS(int index)로 접근해준다.
* 끝날 때 마다 index를 키워줘서 모든 CCTV의 모든 방향을 확인할 수 있도록 하고 index가 CCTV의 총 개수와 같아진다면
* 카피한 맵에 있는 0개 개수를 체크해준다.
*/
#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


vector<pair<int, int>> CCTVLoc;
int map[8][8];
int N, M;
int answer = 64;

void SetCopyMap(int A[][8], int B[][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = B[i][j];
		}
	}
}

void Check(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		x = nx;
		y = ny;

		if (0 > nx || nx >= M || 0 > ny || ny >= N) return;
		if (map[ny][nx] == 6) return;
		if (map[ny][nx] != 0) continue;
		map[ny][nx] = '#';
	}
}

void DFS(int index) {
	if (index == CCTVLoc.size()) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)temp++;
			}
		}
		answer = min(answer, temp);
		return;
	}
	int x = CCTVLoc[index].first;
	int y = CCTVLoc[index].second;
	int backup[8][8];
	SetCopyMap(backup, map);

	for (int dir = 0; dir < 4; dir++) {
		SetCopyMap(backup, map);
		switch (map[y][x])
		{
		case 1:
			Check(x, y, dir);
			break;
		case 2:
			Check(x, y, dir); Check(x, y, dir + 2);
			break;
		case 3:
			Check(x, y, dir); Check(x, y, dir + 1);
			break;
		case 4:
			Check(x, y, dir); Check(x, y, dir + 1); Check(x, y, dir + 2);
			break;
		case 5:
			Check(x, y, dir); Check(x, y, dir + 1); Check(x, y, dir + 2); Check(x, y, dir + 3);
			break;
		}
		DFS(index + 1);
		SetCopyMap(map, backup);
	}
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				CCTVLoc.push_back({ j, i });
		}
	}

	DFS(0);

	cout << answer;

	return 0;
}