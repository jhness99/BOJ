/*
* 1.아이디어
* 피보나치 수열 dp[i] = dp[i-1]+dp[i-2]
* 2.시간복잡도
* O(N), N<=90 이므로 가능
* 3.변수형
* long long
*/
#include <iostream>

using namespace std;

long long dp[91];

int main(void) {

	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];

	return 0;
}