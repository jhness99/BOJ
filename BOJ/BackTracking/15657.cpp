/*
* 1.아이디어
* N과 M 문제들과 비슷한 문제이다. 이번 조건은 같은수를 여러개 골라도 되고 고른 수열이 비 내림차순이여야 한다.
* DFS의 호출에서 자기자신을 포함한 호출을 하면 된다. 입력값도 정렬해야한다.
* 
* 2.시간복잡도
* O(N^M) M <= N <=8, 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int answer[8];
int input[8];

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
		DFS(cnt + 1, i);
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