/*
* 1.아이디어
* 입력된 값을 받아서 저장한다.
* 입력된 등호에 따라 숫자를 모두 확인하며 저장한다.
* 저장한 숫자가 K+1개가 됬다면, 해당수를 최대 최소값으로 저장해둔 수와 비교한다.
* 비교해서 더 크거나 작으면 갱신해준다.
* 
* 이때 들어갈 수 있는 최대수는 9876543210이기 때문에 문자열을 변환할 때 stoi가 아닌 stoll로 해서
* long long으로 변환하게 해야한다.
* 
* 2.시간복잡도
* 10번 반복을 K번 반복하므로 10^k, O(10^K) K<=9 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <string>

using namespace std;

char input[9];
bool check[10];
char answer[10];

int K;
string Max = "-1";
string Min = "100000000000";

void DFS(int cnt) {
	if (cnt == K + 1) {
		string temp;
		for (int i = 0; i <= K; i++) {
			temp += answer[i];
		}
		if (stoll(Max) < stoll(temp))
			Max = temp;
		if (stoll(Min) > stoll(temp))
			Min = temp;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (check[i]) continue;
		if (input[cnt - 1] == '<') {
			if (answer[cnt - 1] < i + '0') {
				check[i] = true;
				answer[cnt] = '0' + i;
				DFS(cnt + 1);
				check[i] = false;
			}
		}
		else {
			if (answer[cnt - 1] > i + '0') {
				check[i] = true;
				answer[cnt] = '0' + i;
				DFS(cnt + 1);
				check[i] = false;
			}
		}
	}
}

int main(void) {

	cin >> K;

	for (int i = 0; i < K; i++)
		cin >> input[i];

	for (int i = 0; i < 10; i++) {
		check[i] = true;
		answer[0] = '0' + i;
		DFS(1);
		check[i] = false;
	}

	cout << Max << "\n" << Min;

	return 0;
}