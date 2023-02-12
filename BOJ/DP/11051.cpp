/*
* 1.아이디어
* 이항 계수 문제이다. 이항계수는 간단하게 dp[i][j] = dp[i-1][j-1] + dp[i-1][j]로 풀 수 있다.
* 2.시간복잡도
* O(N^2), N<=1000, 따라서 가능
* 3.변수형
* int : 10007로 나머지 연산을 하므로 int
*/
#include <iostream>

using namespace std;

int dp[1001][1001];

int main(void) {

	int N, K;
	cin >> N >> K;

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][0] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
		}
	}
	cout << dp[N][K];
 
	return 0;
}