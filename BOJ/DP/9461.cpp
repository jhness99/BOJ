/*
* 1.아이디어
* 1 1 1 2 2 3 4 5 7 9 의 수열을 잘 보면 i번째수를 구하려하면 i-2번째수 + i-3번째수가 해당 수임을 알 수 있다. 
* 따라서 dp[i] = dp[i-2] + dp[i-3]
* 2.시간복잡도
* O(N), N<=100이므로, 가능
* 3.변수형
* long long : dp[100]이 8000억을 넘으므로 long long
*/
#include <iostream>

using namespace std;

long long dp[101];

int main(void) {

	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	
	for (int i = 4; i <= 100; i++)
		dp[i] = dp[i - 2] + dp[i - 3];

	while (T--) {
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}

	return 0;
}
//2023-03-15 복습
/*
* 1.아이디어
* 규칙성을 보고 풀면된다 1 1 2 2 3 4 5 7 9 의 규칙은 dp[i] = dp[i - 2] + dp[i - 3] 이다
* 2.시간복잡도
* O(N) N<=100 따라서 가능
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int dp[101];

int main(void) {

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}