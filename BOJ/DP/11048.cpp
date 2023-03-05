/*
* 1.아이디어
* dp[i][j]는 해당위치에서 가장 많이 사탕을 가져오는 수이다.
* 
* dp[i][j]는 dp[i-1][j] dp[i][j-1] dp[i-1][j-1] 3개중 가장 큰 값을 기존 dp[i][j]에 더한 값이라고 할 수 있다.
* 따라서 점화식은 
* dp[i][j] =  max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]))
* 이때 i j가 0이하로 내려가는것을 막기위한 코드를 사용해도 되지만 귀찮으면 dp[1001][1001]로 선언해 dp[0][0]부분을
* 두면 어차피 0이므로 영향을 주지 못해서 범위제한을 할 필요가 없다.
* 
* 2.시간복잡도
* O(NM) N, M<=1000 따라서 가능
* 3.변수형
*/
#include <iostream>

using namespace std;

int dp[1001][1001];

int main(void) {

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> dp[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			dp[i][j] += max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
	}

	cout << dp[N][M];

	return 0;
}