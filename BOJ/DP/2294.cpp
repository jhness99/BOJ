/*
* 1.아이디어
* 동전 1과 비슷한 문제이다.
* 불가능한 수인 10001로 dp를 초기화한다.
* i 0->N, j arr[i]->K로 갈 때,
* 해당 동전을 확인하기전 dp[j]와 해당 동전을 추가해서 갱신된 dp[j-arr[i]]를 비교해서 더 작은경우로 dp[j]를갱신해준다.
* 따라서 점화식은
* dp[j] = min(dp[j], dp[j-arr[i]];
* 2.시간복잡도
* O(NK), N<=100, k<=10000, 따라서 가능
* 3.변수형
* int
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[10001];
//int arr[100];
//
//int main(void) {
//
//	int N, K;
//	cin >> N >> K;
//
//	for (int i = 1; i <= K; i++)
//		dp[i] = 10001;
//
//	dp[0] = 0;
//
//
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//		for (int j = arr[i]; j <= K; j++) {
//			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
//		}
//	}
//	
//	if (dp[K] == 10001) cout << -1;
//	else cout << dp[K];
//
//	return 0;
//}
//2023-03-04 복습
/*
* 1.아이디어
* dp[i] : i원을 만드는 가장 적은 수의 동전수
* 동전을 입력받고 동전을 저장해서 1부터 N까지의 수를 확인한다.
* 입력된 동전이 coin[k]이라면 dp[i-coin[k]]과 dp[i]를 비교해서 더 작은 값으로 갱신
*
* 까먹은부분
* if (dp[K] == 100001) cout << -1;
* else cout << dp[K];
* 2.시간복잡도
* O(NK), N<=100, K<= 10000, 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main(void) {

	int N, K;
	cin >> N >> K;
	vector<int> coins(N);

	for (int i = 1; i <= K; i++)
		dp[i] = 100001;

	for (auto& i : coins)
		cin >> i;

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < N; j++) {
			if (i < coins[j])
				continue;

			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}

	if (dp[K] == 100001) cout << -1;
	else cout << dp[K];

	return 0;
}