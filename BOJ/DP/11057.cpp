/*
* 1.아이디어
* 최대 1000까지 가능하고 0~9까지의 수를 확인해야하므로 dp[1001][10]을 만든다.
* 이때 dp[i][j]는 i길이의 경우에 j 숫자를 추가했을 때 늘어나는 오르막 수의 개수를 의미한다
* 예를 들면 dp[2][1]의 경우 10,11 이고 dp[2][2]의 경우 02,12,22 이다. 이전에 나온 값은 중복되므로 추가하지 않는다.
* 이렇게 되면 j가 0~9까지 갈 때 dp[2][j]의 합은 해당 길이일 때 모든 오르막 수의 수를 말하는 것이다.
* 그렇기 때문에 dp[2][j-1] + dp[1][j]는 길이가 2일때 이전까지의 오르막 수의 합 + 길이가 1이였을 때 수 j를 추가했을 때의 오르막 수의 합
* 이 dp[2][j]가 된다고 할 수 있다.
* 따라서 점화식은
* j 1->9, dp[i][j] = dp[i][j-1] + dp[i-1][j] 가 된다.
* 2.시간복잡도
* O(10N), N <= 1000, 따라서 가능
* 3.변수형
* int : 오르막 개수에 10007를 나머지 연산 하므로 int
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[10001][10];
//
//int main(void) {
//
//	int N, answer = 0;
//	cin >> N;
//
//	for (int i = 0; i < 10; i++) {
//		dp[1][i] = 1;
//	}
//
//	for (int i = 2; i <= 1000; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (j == 0) {
//				dp[i][0] = 1;
//				continue;
//			}
//			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
//		}
//	}
//
//	for (int i = 0; i < 10; i++)
//		answer = (answer + dp[N][i]);
//
//	cout << answer % 10007;
//	return 0;
//}
//2023-03-24 복습
/*
* 1.아이디어
* dp[i][j] i 개의 숫자를 골라 0~j까지의 수로 조합을 만들었을 때 나온 조합의 개수
*
* i-1개에서 j숫자를 추가한 경우가 i개에서 j숫자까지의 경우의 수라고 할 수 있다.
* 그렇게 되면 dp[i-1][0]~dp[i-1][j]까지의 합이 dp[i][j]인데 이때 dp[i-1][0]~dp[i-1][j-1]는 dp[i][j-1]이므로
* dp[i][j] = dp[i-1][j] + dp[i][j-1]이다.
*/
#include <iostream>

using namespace std;

int dp[1001][10];

int main(void) {

	int N, answer = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	for (int i = 0; i < 10; i++) {
		answer = (answer + dp[N][i]) % 10007;
	}

	cout << answer;

	return 0;
}