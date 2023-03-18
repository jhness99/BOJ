/*
* 1.아이디어
* 15652 문제와 비슷하다. 입력받은 문자를 저장하고 오름차순으로 정렬한다.
* DFS 백트래킹으로 모든 수를 확인하는데 이때 이전 문자보다 더 큰 문자만 확인해서 찾는것이다.
* 여기서 하나 까먹은 요소가 있다면 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되있다는 것이다.
* 따라서 출력부분해서 해당 조건을 만족하는 값만 출력해준다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

char arr[15];
char answer[15];
char check[] = { 'a', 'e', 'i', 'o', 'u' };

int L, C;

void DFS(int cnt, int num) {
	if (L == cnt) {
		int num1 = 0;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < 5; j++) {
				if (answer[i] == check[j]) {
					num1++;
					break;
				}
			}
		}
		if(num1 >= 1&& L-num1>= 2)
			cout << answer << "\n";

		return;
	}
	for (int i = num; i < C; i++) {

		answer[cnt] = arr[i];
		DFS(cnt + 1, i + 1);
	}
}

int main(void) {

	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> arr[i];

	sort(arr, arr + C);

	DFS(0, 0);



	return 0;
}