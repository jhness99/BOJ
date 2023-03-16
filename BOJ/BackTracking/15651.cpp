/*
* 1.아이디어
* 15649 N과 M (1)문제에서 중복만 허용해주면된다. 따라서 해당 코드에서 Check로 중복을 확인해주는 부분을 빼면 된다.
* 2.시간복잡도
* N번 호출되고 M번 반복하는 반복문이 있으므로 O(N^M) N,M<=7, 따라서 가능
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int arr[8];

int N, M;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}

int main(void) {

	cin >> N >> M;

	dfs(0);

	return 0;
}