/*
* 1.아이디어
* N과M문제에서 중복수열을 빼고 비내림차순으로 정렬하는 문제이다.
* 백트래킹과 이전값을 확인하는 중복찾는 로직을 추가하면 된다.
* 
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
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	int temp = -1;
	for (int i = index; i < N; i++) {
		if (temp == input[i]) continue;
		temp = input[i];
		answer[cnt] = input[i];
		DFS(cnt + 1, i + 1);
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input, input + N);

	DFS(0, 0);

	return 0;
}