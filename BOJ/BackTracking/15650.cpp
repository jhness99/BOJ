/*
* 1.아이디어
* 15649문제와 비슷한 백트래킹 문제이다
* 15649에서 탐색하는 수를 하나씩 올려줘야 한다.
* 그렇게 되면 확인하는 수가 다음 수로 갈 때마다 커지게 되고 그러면 최대범위를 도달하기전에 i가 너무 커져서
* 결국에는 탐색을 못하게 된다. 그러면 당연하게도 자리수(cnt)가 4가 될 수 없어지게되므로
* 중복되는 수들은 아에 출력이 불가능하게 된다. 
*/
#include <iostream>

using namespace std;

bool Check[9];
int arr[9];

int N, M;

void dfs(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= N; i++) {
		if (Check[i])
			continue;
		arr[cnt] = i;
		Check[i] = true;
		dfs(i+1, cnt + 1);
		Check[i] = false;
		
	}
}

int main(void) {
	
	cin >> N >> M;

	dfs(1, 0);
	
	return 0;
}