/*
* 1.아이디어
* 서쪽 게이트가 2개고 동쪽 게이트가 4개라고 하면 먼저 가장 위의 게이트가 연결됬을 때 경우의 수를 생각해보자 (dp[2][4])
* 그렇다면 서쪽의 2번째 게이트와 동쪽의 2,3,4 게이트가 연결 될 수 있는데, 이는 서쪽 게이트가 1개고 동쪽 게이트가 3개일 경우의 경우의 수와 같다.(dp[1][3])
* 그 다음 서쪽 1번째 게이트와 동쪽의 2번째 게이트와 연결되면, 서쪽의 2번째 게이트와 동쪽의 3,4 게이트가 연결될 수 있고, 이는 서쪽 게이트가 1개고 동쪽 게이트가 2개인 경우와 같다(dp[1][2])
* 마지막으로 서쪽 1번째 게이트와 동쪽 3번째 게이트가 연결되면, 서쪽의 2번째 게이트와 동쪽의 4 게이트가 연결될 수 있고 이는 서쪽게이트가 1개고 동쪽게이트가 1개인 경우와 같다(dp[1][1])
* 그렇다면 DP[2][4] = DP[1][3] + DP[1][2] + DP[1][1]이 된다. 하지만  dp[1][2]+dp[1][1]는 dp[2][3]로 나타낼 수 있으므로 
* dp[2][4] = dp[1][3] + dp[2][3]이다.
* 따라서 점화식은 dp[i][j] = dp[i-1][j-1] + d[i][j-1];
* 2.시간복잡도
* O(N*M), N, M < 30 따라서 가능
* 3.변수형
* int : 
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[30][30];
//
//int main(void) {
//
//	int T;
//	cin >> T;
//	
//	for (int i = 1; i < 30; i++) 
//		dp[1][i] = i;
//
//	for (int i = 2; i < 30; i++) {
//		for (int j = 1; j < 30; j++) {
//			dp[i][j] = dp[i - 1][j - 1] + dp[i][j-1];
//		}
//	}
//
//	while(T--){
//		int N, M;
//		cin >> N >> M;
//
//		cout << dp[N][M] << "\n";
//	}
//
//	return 0;
//}
//2023-02-26 복습
/*
* 1.아이디어
* dp문제로 등차수열로 풀어도 되지만 dp적으로 생각해보자
* 2 3일경우와 2 4 일 경우를 생각해보면
* 2 3일 경우
* 1 1이 연결될 때 2 2, 2 3 이 가능하다. 이는 1 2의 경우와 같다고 할 수 있다.
* 1 2가 연결될 때 2 3 이 가능하다. 이는 1 1의 경우와 같다고 할 수 있다.
* 따라서 dp[2][3] = dp[1][2] + dp[1][1]이다.
* 2 4일 경우
* 1 1이 연결될 때 2 2, 2 3, 2 4가 가능하다. 이는 1 3의 경우와 같다.
* 1 2가 연결될 때 2 3, 2 4 가 가능하다. 이는 1 2의 경우와 같다.
* 1 3이 연결될 때 2 4가 가능하다 이는 1 1의 경우와 같다.
* 이때 1 1과 1 2는 dp[2][3]과 같으므로
* dp[2][4] = dp[1][3] + dp[2][3] 이다.
* 따라서 점화식은 dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
*
*/
#include <iostream>

using namespace std;

int dp[30][30];

int main(void) {

	for (int i = 1; i < 30; i++)
		dp[1][i] = i;

	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < 30; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		cout << dp[N][M] << "\n";
	}

	return 0;
}