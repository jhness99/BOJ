/*
* 1.아이디어
* N과 M문제처럼 백트래킹을 사용해 풀면된다.
* 2.시간복잡도
* O(N!), N<=8 따라서 가능
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int answer[8];
bool check[9];

int N;

void DFS(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i]) continue;
		check[i] = true;
		answer[cnt] = i;
		DFS(cnt + 1);
		check[i] = false;
	}
}

int main(void) {

	cin >> N;

	DFS(0);

	return 0;
}