/*
* 1.아이디어
* dp[i]에서 i가 홀수인 경우는 체크하지 않는다. 이유는 2x1타일은 1x1타일의 2개가 붙어있으므로 홀수가 나오면 다 채울수 없다.
* 그리고 dp[4]부터 짝수로 갈 때마다 고유한 형태가 2개씩 나온다.
* dp[2]일경우 3개의 경우가 나오고 
* dp[4]일 경우 dp[2]의 경우가 dp[2]개 만큼 나오고 dp[4]의 고유한 모양 2개를 더한 값이 경우의 수다. dp[4] = dp[2]*dp[2] + 2
* dp[6]일 경우 dp[2]가 dp[4]만큼 나오는 경우, dp[4]의 고유의 모양 2개가 dp[2]만큼 나오는 경우, dp[6]의 고유의 모양 2개가 나오는 경우이다. 
* 따라서 dp[6] = dp[4]*dp[2] + dp[2]*2 + 2;
* dp[8]일 경우 dp[2]가 dp[6]만큼 나오는 경우, dp[6]의 고유의 모양 2개가 dp[2]만큼 나오는 경우, dp[4]의 고유의 모양 2개가 
* dp[4]개만큼 나오는 경우, dp[8]의 고유의 모양 2개가 나오는 경우이다. 
* 따라서 dp[8] = dp[6]*dp[2] + dp[4] * 2 + dp[2] * 2 + 2;
* 따라서 점화식은,
* i 4->N i+=2
* dp[i] = dp[i - 2] * 3;
* j 4->N j+=2		
* dp[i] += dp[i - j] * 2;
* 2.시간복잡도
* O(N^2), N<=30, 따라서 가능
* 3.변수형
* int : 
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[31];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	dp[0] = 1;
//	dp[1] = 0;
//	dp[2] = 3;
//
//	for (int i = 4; i <= N; i+=2) {
//		dp[i] = dp[i - 2] * 3;
//		for (int j = 4; j <= i; j+=2) {
//			dp[i] += dp[i - j] * 2;
//		}
//	}
//
//	cout << dp[N] << endl;
//	return 0;
//}
//2023-03-03 복습
/*
* 1.아이디어
* 해당 문제에는 특징이 여러가지가 있다.
* -1 짝수N만이 타일을 완성할 수 있다.
* -2 4부터 2씩 늘어날 때마다 자신만의 패턴을 가지게 된다.
* -3 이전에 만든 패턴에 N이 2일때의 경우의수가 추가되므로 dp[2] = 3, 따라서 dp[i] = dp[i-2]*3을 해주면된다.
*
* 특징2로 인해 4부터 고유의 패턴을 제외한 나머지부분도 더해줘야한다.
* 예를들어 4의 경우는 4가 고유의 패턴을 2개를 가진다.
* 6은 6의 고유의 패턴과 4의 고유의 패턴을 모두 고려해야한다.
* 6의경우 2개지만 4의경우 4의 고유의 패턴 * dp[2]
* 즉, dp[i] = dp[i-2] * 3 과 dp[i] += dp[i-j] * 2 (이때 j는 +2씩 커지며 i만큼 커진다.)
*
* 2.시간복잡도
* O(N)
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int dp[31];

int main(void) {

	int N;
	cin >> N;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[N] << endl;
	return 0;
}