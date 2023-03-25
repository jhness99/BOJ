/*
* 1.아이디어
* N과 M문제이다. 백트래킹으로 풀면된다.
* 조건은 같은수가 여러번 나와도 되지만 중복되면 안된다.
* 따라서 이전값만 확인해서 중복된 수열만 안나오도록 하면 된다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int input[8];
int answer[8];

void DFS(int cnt, int index) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	int temp = -1;
	for (int i = index; i < N; i++) {
		if (temp == input[i]) continue;
		answer[cnt] = input[i];
		temp = input[i];
		DFS(cnt + 1, i);
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);

	DFS(0,0);

	return 0;
}