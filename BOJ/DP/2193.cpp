/*
* 1.아이디어
* 길이가 4인 수를 확인하면 1000 1010 1001이 가능하다. 이때 길이가 3인수 는 100 101로 두가지이다. 해당 수에서 길이가 4가 되려면
* 1개의 수를 붙여야 되는데 이때 0은 어떠한 상황에서도 붙일 수 있다. 그리고 길이가 2인 수인 10 에서 확인하는데
* 이때는 길이가 2개인 수들인 10 01 00 을 붙일 수 있다. 하지만 이때 뒤가 0인 수는 길이가 3인 수에서 했으므로 01을 붙일 수 있다.
* 따라서 길이가 3인경우와 2인경우의 모든 경우의 수를 더하면 4의 길이의 경우의 수가 나온다.
* 점화식은 dp[i] = dp[i-1] + d[i-2];
* 2.시간복잡도
* O(N), N<=90, 따라서 가능
* 3.변수형
* long long:
*/
#include <iostream>

using namespace std;

long long dp[91];

int main(void) {

	dp[1] = 1;
	dp[2] = 1;

	int N;
	cin >> N;

	for(int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[N];

	return 0;
}