/*
* 1.아이디어
* 모든 조합을 고려해 순서대로 연산해줘야 한다.
* 따라서 N과 M문제처럼 백트래킹, DFS를 사용해 똑같이 모든경우를 계산한다.
* 
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>

using namespace std;

int input[8];
int answer[8];
bool check[8];

int N;
int Max = -1;

void DFS(int cnt) {
	if (cnt == N) {
		int temp = 0;
		for (int i = 0; i < N - 1; i++) {
			temp += abs(answer[i] - answer[i + 1]);
		}
		Max = max(Max, temp);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		answer[cnt] = input[i];
		DFS(cnt + 1);
		check[i] = false;
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> input[i];

	DFS(0);

	cout << Max;

	return 0;
}