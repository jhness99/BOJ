//#include <iostream>
//
//using namespace std;
//
//int dp[5001];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	//DP방식
//	dp[3] = 1;
//	dp[5] = 1;
//
//	for (int i = 6; i <= N; i++) {
//		if (dp[i - 3]) dp[i] = dp[i - 3] + 1;
//		if (dp[i - 5]) dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
//	}
//
//	if (dp[N] == 0)
//		cout << -1;
//	else cout << dp[N];
//
//	/*
//	* 그리디 방식
//	int N;
//	int cnt = 0;
//	cin >> N;
//
//	while (N >= 0) {
//		if (N % 5 == 0) {
//			cnt += N / 5;
//			cout << cnt;
//			return 0;
//		}
//		N -= 3;
//		cnt++;
//	}
//	cout << -1;*/
//
//	return 0;
//}
//2023-02-21 복습
/*
* 1.아이디어
* 그리디와 DP풀이법이 있는데 이번엔 DP로 풀어보려고 한다.
* dp[N]은 무게가 N일때 봉지의 개수이다.
* dp[3], dp[5]는 1이다.
* 그 외 나머지는 -1로 초기화 한다.
* 기본적으로 더 적은 값을 확인하는 5kg봉투부터 확인하고
* 아닐경우 3kg봉투도 확인해준다.
* 그래서 ikg일 경우, i-5kg과 i-3kg 중 더 작은 쪽에서 +1한 값이 나온다.
* 2.시간복잡도
* O(N), N<= 5000, 따라서 가능
* 3.변수형
* int : 아무리 많아도 봉투는 int범위 안에서 가능
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {


	int N;
	cin >> N;

	vector<int> dp(5001, -1);

	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (dp[i - 5] != -1)
			dp[i] = dp[i - 5] + 1;
		else if (dp[i - 3] != -1)
			dp[i] = dp[i - 3] + 1;
	}

	cout << dp[N];

	return 0;
}