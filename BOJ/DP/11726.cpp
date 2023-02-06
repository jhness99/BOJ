/*
* 1.아이디어
* dp[n]=dp[n-1]+dp[n-2]
* 2.시간복잡도
* O(N), N<= 1000 따라서 가능
* 3.변수형
* int:
*/
/*
* 문제풀이
* n개의 가로를 가진 직사각형은 각각 n-1 직사각형의 패턴과 n-2직사각형의 패턴을 더한 것과 같다.
* n-2에서 2개 n-1에서 1개 나오지만 n-2의 패턴중 1개는 n-1의 패턴과 겹치므로 각각 1개씩이다.
*/
#include <iostream>

using namespace std;

int dp[1001];

int main(void) {

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	int N;
	cin >> N;
	cout << dp[N];
	return 0;
}
