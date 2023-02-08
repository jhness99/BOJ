/*
* 1.아이디어
* 구성할 수 있는 타일이 2x1 1x2 2x2가 되었는데 길이가 N일때 1칸이 남았을 때 할 수 있는 경우의 수는 (N-1)*1번 이고
* 2칸이 남았을때 할 수 있는 경우의 수는 (N-2)*3이다 하지만 여기서 (N-1)의 패턴이랑 곂치는 부분이 있으므로  (N-2)*2
* 따라서 dp[i] = dp[i-1] + dp[i-2]*2
* 2.시간복잡도
* O(N), N <= 1000이므로 가능
* 3.변수형
* int : 10007 나머지 연산을 해주므로 최대값이 10006 따라서 int
*/
#include <iostream>

using namespace std;

int dp[1001];

int main(void) {

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;

	cout << dp[N];

	return 0;
}