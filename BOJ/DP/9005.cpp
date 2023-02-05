/*
* 1.아이디어
* dp[1] = 1, dp[2] = 2, dp[3] = 4 으로 설정한다.
* dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
* 2.시간복잡도
* O(N)에 N<= 10이므로 가능
* 3.변수형
* int
*/
#include <iostream>

using namespace std;

int dp[11];

int main(void) {
	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}