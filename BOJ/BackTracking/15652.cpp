/*
* 1.아이디어
* N과 M의 비슷한 문제이다
* 이번엔 내림차순이 안되도록 막아야 하므로 다음에 들어가는수가 이전수보다 같거나 커야한다.
* 따라서 다음에 넣는 수를 이전의 값으로 정해줘서 내림차순이 안나오도록 막는다.
* 이때 0의 경우 이전이 없기때문에 해당사항을 예외로 처리해준다.
* 
* 다른풀이
* 다른풀이에서는 반복의 시작 숫자를 따로 index로 넣어 주었고, 이것을 사용해 점점 커지도록 해서
* 다음수가 이전수보다 작아지지 않도록 했다. 이렇게 해도 상관은 없다.
* 
* 2.시간복잡도
* N번 호출해서 M번 반복문을 돌리므로 O(NM) N, M<=8 따라서 가능
* 3. 변수형
*/
#include <iostream>

using namespace std;

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
	for (int i = (cnt == 0 ? 1 : arr[cnt-1]); i <= N; i++) {
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}

int main(void) {

	cin >> N >> M;

	dfs(0);

	return 0;
}