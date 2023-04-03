/*
* 1.아이디어
* 상당히 까다로운 구현문제이다.
* 우선 물고기를 방향과 값을 넣어줘야 하므로 pair<int, int>로 만들어준다.
* 1. 기존 map의 정보를 copyMap에 갱신해서 넣어준다. 
* 2. 물고기를 이동시키고 상어를 이동시킨다. 
* 3. 이때 상어의 방향에서 갈 수 있는 모든 칸을 확인해서 체크해준다.
* 4. 체크가 끝나면 copyMap에 저장해준 변하기 전 Map을 다시 Map에 갱신시켜준다.
* 
* 기본적인 로직은 이렇고 구현이 문제다.
* 
* *추가 
* 처음엔 pair로 하려했는데 작은 순서대로 움직여야 하므로 따로 구조체를 만들어야 할 필요성을 느낌
* 
*/
#include <iostream>

using namespace std;

struct FISH {
	int x, y, dir;
	bool Live;
};

int Map[4][4];
FISH fish[17];
int answer;

int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void SetMap(int A[][4], int B[][4], FISH C[], FISH D[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) 
			A[i][j] = B[i][j];
	}
	for (int i = 1; i <= 16; i++) C[i] = D[i];
}

void SwapFish(int index, int index2) {
	FISH Temp = fish[index];
	fish[index].x = fish[index2].x;
	fish[index].y = fish[index2].y;
	fish[index2].x = Temp.x;
	fish[index2].y = Temp.y;
}

void MoveFish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].Live == false) continue;
		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && Map[ny][nx] != -1) {
			if (Map[ny][nx] == 0) {
				fish[i].x = nx;
				fish[i].y = ny;
				Map[ny][nx] = i;
				Map[y][x] = 0;
			}
			else if (Map[ny][nx] != -1) {
				SwapFish(i, Map[ny][nx]);
				swap(Map[y][x], Map[ny][nx]);
			}
		}
		else {
			int nDir = dir + 1;
			if (nDir == 9) nDir = 1;
			int nx = x + dx[nDir];
			int ny = y + dy[nDir];
			while (nDir != dir)
			{
				if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
				{
					if (Map[ny][nx] == 0) {
						fish[i].x = nx;
						fish[i].y = ny;
						Map[ny][nx] = i;
						Map[y][x] = 0;
						fish[i].dir = nDir;
						break;
					}
					else if (Map[ny][nx] != -1) {
						SwapFish(i, Map[ny][nx]);
						swap(Map[y][x], Map[ny][nx]);
						fish[i].dir = nDir;
						break;
					}
				}
				nDir++;
				if (nDir == 9) nDir = 1;
				nx = x + dx[nDir];
				ny = y + dy[nDir];
			}
		}
	}
}

void DFS(int x, int y, int dir, int sum) {
	answer = max(answer, sum);

	int copyMap[4][4];
	FISH copyFish[17];
	SetMap(copyMap, Map, copyFish, fish);
	MoveFish();
	
	for (int i = 1; i <= 3; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (Map[ny][nx] == 0) continue;
			int Num = Map[ny][nx];
			int nDir = fish[Num].dir;
			Map[y][x] = 0;
			Map[ny][nx] = -1;
			fish[Num].Live = false;
			DFS(nx, ny, nDir, sum + Num);
			Map[y][x] = -1;
			Map[ny][nx] = Num;
			fish[Num].Live = true;
		}
	}
	SetMap(Map, copyMap, fish, copyFish);
}

int main(void) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			Map[i][j] = a;
			fish[a] = {j,i,b,true};
		}
	}
	int Num = Map[0][0];
	int dir = fish[Num].dir;
	fish[Num].Live = false;
	Map[0][0] = -1;
	DFS(0, 0, dir, Num);

	cout << answer;

	return 0;
}