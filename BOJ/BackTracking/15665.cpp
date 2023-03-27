/*
* 1.아이디어
* N과 M (12)문제에서는 더 작은수가 나오면 안됬지만 이것은 더 작은수까지 허용해주면 된다.
* DFS에서 index를 주어서 다음수는 같거나 큰 수 부터 탐색하는 것을 없에면 된다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int input[7];
int answer[7];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	int temp = -1;
	for (int i = 0; i < N; i++) {
		if (temp == input[i]) continue;
		answer[cnt] = input[i];
		temp = input[i];
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