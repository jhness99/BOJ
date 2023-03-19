/*
* 1.아이디어
* 백트래킹을 사용해 모든 수를 탐색하면된다. K개의 수에서 6개를 사용하는 조합을 만들면 된다.
* 매개변수 cnt로 확인한 수의 개수를 점차 늘려가면서 answer에 넣어주다가 6개가 된다면 출력해주고 그 다음에서 다시 시작하게 하는
* DFS형식으로 구현하면 된다.
* 
* 2.시간복잡도
* 
* 3.변수형
*/
#include <iostream>

using namespace std;

int answer[6];
int input[12];

int N;

void DFS(int cnt, int index) {
	
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = index; i < N; i++) {
		answer[cnt] = input[i];
		DFS(cnt + 1, i + 1);
	}
}

int main(void) {

	while (true) {
		cin >> N;
		
		if (N == 0)
			return 0;

		for (int i = 0; i < N; i++)
			cin >> input[i];

		DFS(0, 0);
		cout << "\n";
	}

	return 0;
}