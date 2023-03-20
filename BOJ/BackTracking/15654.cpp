/*
* 1.아이디어
* N과 M 문제를 풀 듯이 풀면 된다.
* 여기서 오름차순으로 해야하므로 정렬사용
* 나머지는 비슷하게 구현하면 된다.
* 
* 2.시간복잡도
* N번 호출되고 M번 반복하므로 O(N^M) N,M<=8 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int input[8];
int answer[8];
bool check[8];

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
		if (check[i]) continue;
		check[i] = true;
		answer[cnt] = input[i];
		DFS(cnt + 1);
		check[i] = false;
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