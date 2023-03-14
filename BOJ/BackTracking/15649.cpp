/*
* 1.아이디어
* 백트래킹 알고리즘을 사용한다
* 중복숫자를 허용하지 않으므로 각 수가 나왔는지 체크해주는 check배열 생성
* 수를 저장했다가 출력해줄 arr배열 생성
*
* dfs처럼 탐색을 하면 된다.
*
* arr의 0번째부터 3번째까지 백트래킹을 사용해 저장하고, 3번째를 다 채웠다면 출력하게 한다.
* 2.시간복잡도
* M번 호출되고 N번 반복하므로 O(N^M) N,M<=8 따라서 가능
*/
#include <iostream>

using namespace std;

bool Check[9];
int arr[9];

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
		if (Check[i])
			continue;
		arr[cnt] = i;
		Check[i] = true;
		dfs(cnt + 1);
		Check[i] = false;
	}
}

int main(void) {

	cin >> N >> M;

	dfs(0);

	return 0;
}