/*
* 1.아이디어
* 회전의 스케쥴을 저장할 배열을 따로 만든다.
* 해당 스케쥴에 DFS로 모든 스케쥴을 만들어 계획을 만든다.
* 해당 계획대로 진행하고 최솟값을 갱신한다.
* 
* 구현이 어려웠던 문제
* 아이디어 자체는 아주 처음 생각한 대로 했더니 됬다.
* 배열을 돌리는 것이 좀 햇갈렸다.
* 
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

struct Schedule {
	int r, c, s;
};

int copyMap[51][51];
int map[51][51];
int arr[6];
bool check[6];
int N, M, K;
int Min = 10000;
vector<Schedule> schedules;

void TurnArray() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
	for (int d = 0; d < K; d++) {
		int r = schedules[arr[d]].r;
		int c = schedules[arr[d]].c;
		int s = schedules[arr[d]].s;
		for (int j = 1; j <= s; j++) {
			int temp = copyMap[r - j][c - j];
			for (int i = r - j + 1; i <= r + j; i++) {
				copyMap[i - 1][c - j] = copyMap[i][c - j];
			}
			for (int i = c - j + 1; i <= c + j; i++) {
				copyMap[r + j][i - 1] = copyMap[r + j][i];
			}
			for (int i = r + j-1; i >= r - j; i--) {
				copyMap[i + 1][c + j] = copyMap[i][c + j];
			}
			for (int i = c + j - 1; i > c - j; i--) {
				copyMap[r - j][i + 1] = copyMap[r - j][i];
			}
			copyMap[r - j][c - j + 1] = temp;
		}
	}
	int total = 0;
	for (int k = 1; k <= N; k++) {
		for (int j = 1; j <= M; j++) {
			total += copyMap[k][j];
		}
		Min = min(Min, total);
		total = 0;
	}
}

void DFS(int cnt) {
	if (cnt == K) {
		TurnArray();
		return;
	}
	for (int i = 0; i < K; i++) {
		if (check[i]) continue;
		check[i] = true;
		arr[cnt] = i;
		DFS(cnt + 1);
		check[i] = false;
	}
}

int main(void) {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		schedules.push_back({ r,c,s });
	}

	DFS(0);

	cout << Min;

	return 0;
}