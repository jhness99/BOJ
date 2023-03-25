/*
* 1.아이디어
* i에서 j 도시로 갈 수 있고, (map[i][j] != 0) 아직 가지 않은 도시라면(!check[j]) 이동할 수 있다.
* 이동한 경로를 저장했다가 이동한 도시의 수가 4개가 되면 모든 비용을 더해 최대값이랑 비교해준다.
*  
* 처음에 위처럼 접근하려했지만 다시 되돌아올 수 있는지 확인해야하므로, 해당 확인하는 로직을 넣어주고
* 방문한 곳으로 돌아가야 하기때문에 arr에 저장하지 않고 합으로 더하다가 마지막에 시작위치로 더해줬다.
*
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>

using namespace std;

int N, answer = 1000000000;
int map[10][10];
int arr[10];
bool check[10];

void DFS(int start, int cnt, int index, int sum) {
	if (cnt == N) {
		if (map[index][start] == 0) return;
		answer = min(answer, sum + map[index][start]);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] || map[index][i] == 0) continue;
		check[index] = true;
		DFS(start, cnt + 1, i, sum+ map[index][i]);
		check[index] = false;
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		check[i] = true;
		DFS(i, 1, i, 0);
		check[i] = false;
	}

	cout << answer;

	return 0;
}