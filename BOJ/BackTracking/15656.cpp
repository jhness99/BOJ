/*
* 1.아이디어
* N과 M 푸는방식으로 하면 된다.
* 
* 2.시간복잡도
* 
* 3.변수형
* 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int answer[8];
int input[8];

int N, M;

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		answer[cnt] = input[i];
		DFS(cnt + 1);
	}
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input, input + N);

	DFS(0);

	return 0;
}