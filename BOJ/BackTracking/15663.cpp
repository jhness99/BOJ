/*
* 1.아이디어
* N과 M문제이다. 
* 이번엔 중복을 없애야 하는데, 바꿀 위치에 자신이 지금 넣으려고 하는 숫자가 없을 때만 갱신해주면 된다.
* 
* 
* (틀린부분)
* 이전것과 비교하기위해 answer[cnt]와 비교했지만 이렇게 되면 이전에 사용한 숫자가 아닌
* 이전 결과에 있던, 예를들면 1 1 2 의 경우 1 1 2 , 1 2 1 를 출력하고 
* 1 2 1의 데이터를 가져와서 2 1 1을 출력하려고 하는데 3번째의 수가 겹치므로 출력이 안된다.
* 아직 2 1 1 기준 3번째 수는 하지 않았는데 이전에 했던 1 2 1과 겹치게 되므로 따로 변수 tmp를 만들어 이전에 했던 위치를 
* 저장해야 한다.
* 2.시간복잡도
* O(N!) N<=8 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int answer[8];
int input[8];
bool check[8];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	int tmp = -1;
	for (int i = 0; i < N; i++) {
		if (check[i] || tmp == input[i]) continue;
		tmp = input[i];
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