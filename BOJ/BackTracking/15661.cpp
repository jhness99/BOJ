/*
* 1.아이디어
* 14889번 문제와 비슷한 문제이지만 N/2개의 팀원수 제한이 없다.
* 따라서 모든 경우를 확인해줘야한다. 
*/
#include <iostream>

using namespace std;

int input[20][20];
bool check[20];

int N;
int answer = 1000000000;

void DFS(int cnt, int index) {
	if (cnt >= 1) {
		int star = 0;
		int link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i] && check[j]) star += input[i][j];
				if (!check[i] && !check[j]) link += input[i][j];
			}
		}
		int temp = abs(star - link);
		answer = min(answer, temp);
	}
	for (int i = index; i < N; i++) {
		check[i] = true;
		DFS(cnt + 1, i + 1);
		check[i] = false;
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	DFS(0, 0);

	cout << answer;

	return 0;
}