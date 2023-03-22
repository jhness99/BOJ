/*
* 1.아이디어
* N과 M과 비슷한 백트래킹 문제이다.
* 입력받은 수를 오름차순으로 정렬한다. 왜냐하면 증가하는 순서로 출력해야 하기 때문이다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int input[8];
int answer[8];

int N, M;

void DFS(int cnt, int index) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i < N; i++) {
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