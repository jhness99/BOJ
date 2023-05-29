/*
* 1.아이디어
* 첫번째로 연산자체를 구현해야한다.
* L이 주어졌을 때 2^L*2^L 크기의 구역을 돌려주면 되는 문제이다.
* 그 후 모든 얼음의 합과 연결된 가장 큰 덩어리의 크기를 출력해줘야한다.
* 
* 구역을 돌리는 문제는 L이 주어졌을 때 L은 가로세로이다.
* 구역은 사각형으로 돌아가게 된다. 따라서 가로세로의 절반, L의 절반만큼의 사각형이 생길 수 있다.
* 이를 이용해서 구역 안에있는 모든 사각형을 돌릴 수 있다.
* 예를 들어 L이 2라면, 4*4크기의 구역이 생긴다.
* 그렇다면 겉부분과 안에 부분의 사각형 2개가 생기게 된다.
* 1 1 1 1 이러한 모습으로 1과 0이 다른 사각형이라고 가정하고 회전이 되게 된다.
* 1 0 0 1 
* 1 0 0 1
* 1 1 1 1
* 
* 이때 회전하는 방법은 한 변을 따로 저장해뒀다가 그 변을 채워주고 마지막에 빈 곳에 저장한 변을 채워주면
* 돌릴 수 있게 된다.
* 
* 0 1 1 1
* 0     1
* 0     1
* 1 1 1 1
* 
* 이런식으로 왼쪽을 따로 빼서 저장한 후 아랫쪽 변을 빈 공간에 복사해주면서 회전을 할 수 있는 것이다.
* 
* 회전 후 얼음이 녹는 것은 단순한 구현으로 풀면된다.
* 주변(상하좌우)에 얼음이 아닌곳이 2개 이상이면 해당 위치의 얼음을 녹인다.
* 
* 모든 예약된 연산이 끝난다면 현재 상태의 얼음덩어리의 개수를 확인해줘야한다.
* 이것은 BFS나 DFS로 연결된 모든 얼음의 크기를 비교해줘서 가장 큰 덩어리의 크기로 갱신해주면 된다.
* 
* 
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, Q, Sum, Answer;
int MAP[70][70];
bool visited[70][70];
int schedule[1000];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void TurnArea(int x, int y, int L) {
	int num = L / 2;
	for (int i = 0; i < num; i++) {
		int startX = x + i;
		int startY = y + i;
		int endX = x + L - 1 - i;
		int endY = y + L - 1 - i;
		
		int x_Idx = endX;
		int y_Idx = endY;
		int Idx = 0;

		vector<int> temp;
		for (int j = startX; j < endX; j++)  temp.push_back(MAP[startY][j]);
		for (int j = startX; j < endX; j++) MAP[startY][j] = MAP[y_Idx--][startX];
		for (int j = endY; j > startY; j--) MAP[j][startX] = MAP[endY][x_Idx--];
		for (int j = endX; j > startX; j--) MAP[endY][j] = MAP[y_Idx++][endX];
		for (int j = startY; j < endY; j++) MAP[j][endX] = temp[Idx++];
	}
}

void TurnMap(int L) {
	for (int i = 0; i < N; i += L) {
		for (int j = 0; j < N; j += L) {
			TurnArea(j, i, L);
		}
	}
}

void MeltIce() {
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
				if (!MAP[ny][nx]) continue;
				cnt++;
			}
			if (cnt < 3) v.push_back({ j, i });
		}
	}
	for (auto& p : v) {
		int x = p.first;
		int y = p.second;
		MAP[y][x]--;
		Sum--;
	}
}

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			if (visited[ny][nx] || !MAP[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({ nx, ny });
			cnt++;
		}
	}
	return cnt;
}

void CountIceSize() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] == 0) continue;
			if (visited[i][j] == true) continue;

			int Result = BFS(j, i);
			Answer = max(Answer, Result);
		}
	}
}

int main(void) {

	cin >> N >> Q;
	N = (1 << N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			Sum += MAP[i][j];
		}
	}

	for (int i = 0; i < Q; i++)
		cin >> schedule[i];


	for (int i = 0; i < Q; i++) {
		int L = (1 << schedule[i]);
		TurnMap(L);
		MeltIce();
	}
	CountIceSize();

	cout << Sum << "\n" << Answer;

	return 0;
}