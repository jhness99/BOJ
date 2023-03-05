/*
* 1.아이디어
* dp[K][N]은 K개의 정수로 N을 만들수있는 경우의 수이다.
* dp[K][N]은 K-1일 때 0~N을 만들 수 있는 경우의 수의 합과 같다.
* 그 이유는 예를들어 dp[3][2]의 경우, 뒤가 0이 오는경우는 200 020 110 이고 이는 dp[2][2]에서 뒤에 0을 추가한 것이다.
* 즉, K-1개의 N을 만드는 경우는 K개로 N을만드는 경우중 0을 제일 마지막에 넣었을 때의 경우와 같다.
* 이때, 마지막에 넣을 수 있는 수는 0~N까지고 이것은 즉 dp[k][0]~dp[k][N]까지의 합이라고 할 수있다.
* 여기서 문제에 순서가 뒤바뀐경우도 가능하다고 했으므로 앞에도 고려해서 2배를 해야하지 않냐고 생각할 수 있지만,
* 이전 값에서 중복이 일어나기 때문에 뒤에 붙이는것만을도 충분하다고 할 수 있다.
* 따라서 점화식은, dp[k][n] = dp[k-1][0]+...+dp[k-1][N]이다. 하지만 이 식은 너무길어서 단축해보려한다
* 우리가 생각할 수 있는것은 dp[k][n-1] = dp[k-1][0]+...+dp[k-1][n-1]이다. 
* 따라서 점화식을 dp[k][n] = dp[k][n-1] + dp[k-1][n-1]이다.
* 2.시간복잡도
* O(NK), N,K<=200 따라서가능
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int dp[201][201];

int main(void) {

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= K; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])% 1000000000;
		}
	}

	cout << dp[K][N];

	return 0;
}