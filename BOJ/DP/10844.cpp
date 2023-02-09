/*
* 1.아이디어
* 모든 수열은 가장 마지막에 따라 달라진다. 이게 무슨말이냐면 만약 2자리일경우, 마지막이 2인경우는 32 12 로 2가지다.
* 만약 3자리일 경우 마지막이 3이 될 경우는 123 323 343 543 으로 총 4개인데 이것은 3일경우 앞에 2 4, 로 나눌 수 있고 
* 다시 각각 2자리일때 마지막이 2인 경우, 12 32, 마지막이 4일경우 54, 34 이렇게 나눌 수 있다.
* 이 말은 다시말해서 i개의 자리수를 가진 j로 끝나는 수열의 총 개수는 
* i-1자리수에서 j+1과 j-1이 마지막이였을 때 경우의 수들의 합과 같다고 할 수 있다.
* 따라서 점화식은 dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] 이라고 할 수 있다.
* 2.시간복잡도
* O(N*10), N<=100이므로 가능
* 3.변수형
* long long :
*/
#include <iostream>

using namespace std;

long long dp[101][10];

int main(void) {

	int N;
	long long sum = 0;
	cin >> N;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1]% 1000000000;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[N][i];
	}
	
	cout << sum % 1000000000;

	return 0;
}