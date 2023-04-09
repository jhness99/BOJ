/*
* 1.아이디어
* 모든 경로를 탐색해서 경로를 확인해줘야 한다.
* 따라서 DFS로 접근해서 생각해볼 수 있다.
* 모든 경로를 모두 고려하는 DFS에 각 경로의 확률을 계산해줘야한다.
* 이때 각 확률은 해당 방향으로 가는 확률을 곱해주면 된다.
* 예를 들어 2번 움직이고 각각 25의 확률을 가진 예제를 생각해보자
* 
* 이때 1번째 동쪽으로 갈 확률은 25퍼센트, 1/4 이다. 그 후 다시 이동하는 경우는 각 방향별로 1/4이다. 따라서 2번째로 이동하는 경우는 1/4 * 1/4 이므로
* 1/16이 된다. 동쪽에서 다시 4방향 갈 확률은 전부합처 4/16 이지만 왔던곳으로 되돌아가는 서쪽으로 가는 경우는 제외해야 하므로 3/16이다.
* 각 방향이 3/16으로 확률이 나오고 따라서 12/16이 된다. 이는 3/4가 되고 따라서 단순한 경로는 0.75가 되는 것이다.
* 
* 만약 수가 늘어나서 한바퀴 빙 돌아서 이미 한번 지나간 곳으로 돌아오는 경우도 존재할 수 있다. 이는 어떻게 계산할 수 있냐면,
* 평소 DFS처럼 map을 만들고 visited로 방문처리를 해주면서 방문되지않았을 경우에만 확률을 곱해주고 방문했다면 0을 반환해줘서 해당 경로를
* 고려하지 않도록 예외처리를 하는 것이다.
*/
#include <iostream>

using namespace std;

int N;
double percent[4];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool visited[29][29];

double DFS(int x, int y, int cnt) {
	if (cnt == N)
		return 1.0f;
	
	visited[y][x] = true;
	double Result = 0.0f;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (visited[ny][nx]) continue;
		Result += (percent[i] * DFS(nx, ny, cnt + 1));
	}
	visited[y][x] = false;
	return Result;
}

int main(void) {

	cin >> N;

	for (int i = 0; i < 4; i++) {
		double temp;
		cin >> temp;
		percent[i] = temp / 100.0;
	}

	cout.precision(10);
	cout << fixed << DFS(14, 14, 0);

	return 0;
}