/*
* 1.아이디어
* 이 문제는 시뮬레이션 + BFS,DFS문제이다.
* 먼저 가장 큰 블록 그룹을 찾는다. 이때 BFS를 사용해서 찾아준다.
* BFS를 사용해서 무지개포함 해당 숫자의 그룹을 계산해주고 그룹중 가장 큰 그룹의 시작위치를 저장해준다.
* 시작위치는 해당 그룹에서 행과 열이 최소가 되는 위치이다.
* main에서 가장 작은 행, 가장 작은 열부터 확인하는 2중 for문을 사용했기해 해당 조건은 만족한다.
* 이 위치는 무지개가 될 수 없으므로 main에서 BFS를 호출할때 무지개블록일경우는 탐색을 하지 않는다.
* 이때 해당 블럭의 visited는 한번 시뮬레이션 할때까지 초기화 하지 않지만 우리는 무지개블럭의 중복또한 계산해야 한다.
* 따라서 BFS에서 무지개였을 경우와 탐색하는 블록이였을 경우를 각각 고려해서
* visited와 rainbow로 방문을 따로 나눠 방문해준다.
* 이렇게 하면 처음 무지개블록을 그룹으로 넣은 숫자와 다른 숫자가 해당 무지개블록을 그룹으로 넣을 수 있기 때문이다.
* 
* 탐색한 후 DFS를 사용해 해당 블록의 모든 그룹을 제거해준다.
* 제거한 후 중력과 회전을 주어진대로 진행해주면 시뮬레이션의 한 사이클의 종료가 된다.
* 그룹이 단 한개도 남아있지 않을경우 시뮬레이션을 종료해주고 answer를 출력해주면 된다.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int MAP[20][20];
bool visited[20][20];
bool rainbow[20][20];

int N, M, BlockCnt, targetX, targetY, answer, RainbowCnt;
bool flag = true;;

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	int color = MAP[y][x];
	int cnt = 1;
	int cnt2 = 0;
	q.push({ x, y });
	visited[y][x] = true;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			
			if (MAP[ny][nx] == 0) {
				if (!rainbow[ny][nx]) {
					rainbow[ny][nx] = true;
					q.push({ nx, ny });
					cnt2++;
					cnt++;
				}
			}
			else if (MAP[ny][nx] == color){
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ nx, ny });
					cnt++;
				}
			}
		}
	}
	if (cnt > BlockCnt) {	
		targetX = x;
		targetY = y;
		BlockCnt = cnt;
		RainbowCnt = cnt2;
		flag = true;
	}
	else if (cnt == BlockCnt) {
		if (RainbowCnt <= cnt2) {
			targetX = x;
			targetY = y;
			BlockCnt = cnt;
			RainbowCnt = cnt2;
			flag = true;
		}
	}
}

void DFS(int x, int y, int color) {
	MAP[y][x] = -2;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
		if (MAP[ny][nx] == color || MAP[ny][nx] == 0) {
			DFS(nx, ny, color);
		}
	}
}

void Gravity() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == -2) continue;
			if (MAP[i][j] == -1) continue;

			int Color = MAP[i][j];
			int ny = i + 1;
			while (1) {
				if (MAP[ny][j] != -2) break;
				if (ny == N) break;
				ny++;
			}
			ny--;
			MAP[i][j] = -2;
			MAP[ny][j] = Color;
		}
	}
}
void Rotate() {
	for (int i = 0; i < N / 2; i++)
	{
		int Sx = i;
		int Sy = i;
		int Ex = N - i - 1;
		int Ey = N - i - 1;

		int x_Idx = Sx;
		int y_Idx = Sy;
		int Idx = 0;
		vector<int> Temp;
		for (int x = Sx; x < Ex; x++) Temp.push_back(MAP[Sy][x]);
		for (int y = Sy; y < Ey; y++) MAP[Sy][x_Idx++] = MAP[y][Ex];
		for (int x = Ex; x > Sx; x--) MAP[y_Idx++][Ex] = MAP[Ey][x];
		for (int y = Ey; y > Sy; y--) MAP[Ey][x_Idx--] = MAP[y][Sx];
		for (int y = Ey; y > Sy; y--) MAP[y][Sx] = Temp[Idx++];
	}
}

void printMAP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] >= -1)
				cout << MAP[i][j];
			else cout << " ";
			cout << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	while (true) {
		RainbowCnt = 0;
		BlockCnt = 2;
		flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && MAP[i][j] > 0) {
					BFS(j, i);
					memset(rainbow, false, sizeof(rainbow));
				}
			}
		}
		if (!flag) break;
		DFS(targetX, targetY, MAP[targetY][targetX]);
		answer += pow(BlockCnt, 2);
		/*cout << "블럭 제거 후\n";
		printMAP();*/
		Gravity();
		/*cout << "중력 후\n";
		printMAP();*/
		Rotate();
		/*cout << "회전 후\n";
		printMAP();*/
		Gravity();
		/*cout << "중력 후\n";
		printMAP();*/
	}

	cout << answer;

	return 0;
}