/*
* 1.아이디어
* (틀린 아이디어)
* 3칸 연속으로 불가능하므로 arr[i-1] + dp[i-3]와 dp[i-2]와 비교하게 된다.
* 바로 전의 칸을 고려하면 3연속으로 마시면 안되므로 바로전칸의 전전칸에서 마신 총 와인양을 더해 계산해야하고,
* 전전칸의 경우 따로 고려할 사항은 없으므로 dp[i-2]
* 위의 2가지 경우를 비교해서 더 큰 값을 해당칸의 마신양으로 정해주면 된다.
* 
* (맞는 아이디어)
* 계단문제와 비슷해 보여서 비슷하게 풀려했는데 계단문제와 근본적으로 다른 부분은 탐색하고 있는 i번째가 필수가 아니라는 점이다.
* 따라서 arr[i-1] + dp[i-3] + arr[i] 와 arr[i] + dp[i-2] 와 dp[i-1]를 비교해야 한다.
* 2.시간복잡도
* O(N), N<= 10000, 따라서 가능
* 3.변수형
* int : 7500*1000 이므로 int가능
*/
#include <iostream>

using namespace std;

int dp[10001];
int arr[10001];

int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	int Max = -1;
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
		
	}
	
	cout << dp[N];
	
	return 0;
}