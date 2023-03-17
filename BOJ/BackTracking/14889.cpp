/*
* 1.아이디어
* 조합이 나오는 종류를 생각해봐야한다. 먼저 N/2가 3이라면, 3명이 팀이되고 1 2 3 이라고 가정했을 때 조합은 
* 1 2, 1 3, 2 1, 2 3, 3 1, 3 2 이렇게 나온다. 이렇게보면 해당하는 자기자신을 제외한 나머지와의 조합이라고 할 수 있다.
* 
* 따라서 dfs로 모든 수를 확인하면서 check를 사용해 숫자를 체크해주고, 팀원수와 팀번호를 1씩 올려서 탐색한다.
* 만약 팀 수가 N/2가 된다면, check에 true와 false인 사람들끼리의 조합을 만들어 더한다음에 둘 사이의 차이를 
* 구해서 최솟값으로 계속 갱신해주면 된다.
* 2.시간복잡도
* O(2^N)번 DFS를 호출한다. DFS가 종료조건이 되어야만 N^2연산을 하므로 제외하면 O(2^N), N<= 20 따라서 가능
*/
#include <iostream>

using namespace std;

int N;
int check[21];
int arr[21][21];
int answer = 100000000;

void DFS(int cnt, int num) {
	if (cnt == N / 2) {
		int star = 0;
		int link = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i] && check[j]) star += arr[i][j];
				if (!check[i] && !check[j]) link += arr[i][j];
			}
		}
		int temp = abs(star - link);
		answer = min(answer, temp);
	}
	for (int i = num; i <= N; i++) {
		check[i] = true;
		DFS(cnt + 1, i + 1);
		check[i] = false;
	}
}

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	DFS(0, 1);
	cout << answer;

	return 0;
}