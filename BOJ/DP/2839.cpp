#include <iostream>

using namespace std;

int dp[5001];

int main(void) {

	int N;
	cin >> N;

	//DP방식
	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (dp[i - 3]) dp[i] = dp[i - 3] + 1;
		if (dp[i - 5]) dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
	}

	if (dp[N] == 0)
		cout << -1;
	else cout << dp[N];

	/*
	* 그리디 방식
	int N;
	int cnt = 0;
	cin >> N;

	while (N >= 0) {
		if (N % 5 == 0) {
			cnt += N / 5;
			cout << cnt;
			return 0;
		}
		N -= 3;
		cnt++;
	}
	cout << -1;*/

	return 0;
}