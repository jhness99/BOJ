/*
* 1.아이디어
* 이항 계수 문제이다. 이항계수는 간단하게 dp[i][j] = dp[i-1][j-1] + dp[i-1][j]로 풀 수 있다.
* 2.시간복잡도
* O(N^2), N<=1000, 따라서 가능
* 3.변수형
* int : 10007로 나머지 연산을 하므로 int
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[1001][1001];
//
//int main(void) {
//
//	int N, K;
//	cin >> N >> K;
//
//	dp[0][0] = 1;
//	dp[1][0] = 1;
//	dp[1][1] = 1;
//
//	for (int i = 2; i <= N; i++) {
//		for (int j = 0; j <= i; j++) {
//			if (j == 0) {
//				dp[i][0] = 1;
//				continue;
//			}
//			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
//		}
//	}
//	cout << dp[N][K];
// 
//	return 0;
//}
//2023-02-28
/*
* 1.아이디어
* 파스칼의 삼각형을 풀 듯이 하면 된다. 주어진 값이 5 2 일경우
* 1
* 1 1
* 1 2 1
* 1 3 3 1
* 1 4 6 4 1
* 1 5 10 5 1
* 이런식의 파스칼삼각형을 dp로 구할 수 있다.
* dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
* 초기값 3개만 1로 주어주고 나머지는 점화식으로 가능하다.
* 2.시간복잡도
* O(NK) N,K <= 1000 따라서 가능
* 3.변수형
*
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

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[N][K];

	return 0;
}