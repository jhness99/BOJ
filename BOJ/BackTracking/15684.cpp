/*
* 1.아이디어
* 배열 map[11][30] : 해당 위치에 사다리가 있는지
* 
* 입력값을 모두 갱신했다면, 가능한 모든 위치에 넣어서 확인해준다.
* 
* 백트래킹을 사용해 모든 위치를 탐색해주고, map[i][j], map[i][j-1], map[i][j+1]가 true일경우, 해당위치는 불가능하다.
* 이 조건을 맞춰서 map을 갱신해주고 갱신한 map이 자기자신의 세로줄로 돌아온다면 true 아닐경우 false를 출력한다.
* 만약 모든 세로줄이 자기자신으로 돌아올 수 있다면, 해당 횟수를 답으로 갱신한다.
* 2.시간복잡도
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int N, M, H;
int answer = 4;
bool Visited[31][11];

bool CheckLadder() {
	for (int i = 1; i <= N; i++) {
		int index = i;
		for (int j = 1; j <= H; j++) {
			if (Visited[j][index]) index++;
			else if (Visited[j][index-1]) index--;
		}
		if (index != i) return false;
	}
	return true;
}

void DFS(int cnt, int index) {
	if (cnt >= 4) return;
	
	if (CheckLadder()) {
		answer = min(answer, cnt);
		return;
	}

	for (int i = index; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (Visited[i][j]) continue;
			if (Visited[i][j-1]) continue;
			if (Visited[i][j+1]) continue;

			Visited[i][j] = true;
			DFS(cnt + 1, i);
			Visited[i][j] = false;
		}
	}
}

int main(void) {

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Visited[a][b] = true;
	}

	DFS(0, 1);
	
	cout << (answer == 4 ? -1 : answer);

	return 0;
}