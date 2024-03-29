/*
* 1.아이디어
* 백팩문제로써 이해할 수 있다. 
* dp[N+1][K+1]의 배열을 초기화 한다.
* 입력받은 순서대로 확인한다.
* dp[i-1][j]와 물건의 가치 + dp[i-1][j-확인하고있는 물건의 무게]와 비교해서 더 큰 값인경우 해당 값을 초기화 해준다.
* dp[N][K]가 답이 되게 된다
* 2.시간복잡도
* O(N*K), N(1 ≤ N ≤ 100) K(1 ≤ K ≤ 100000), 이므로 가능
* 3.변수형
* int :
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[101][100001];
//pair<int, int> item[101];
//
//int main(void) {
//
//	int N, K;
//	cin >> N >> K;
//
//	for (int i = 1; i <= N; i++)
//		cin >> item[i].first >> item[i].second;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= K; j++) {
//			//해당 물건의 무게를 넣을 수 있는경우
//			if (j >= item[i].first)
//				//1개 넣는대 만약 남는 무게가 있다면, 이제까지 확인했던 물건들을 넣을 때 가장 큰 값을 추가로 넣어줌
//				//ex)가방 무게가 7일때 이전에 3이 들어갔을 때의 가치 + 4가 들어갔을 때의 가치
//				dp[i][j] = item[i].second + dp[i - 1][j - item[i].first];
//			//이전 물건을 넣었을때의 값과 비교해서 최대값 갱신
//			dp[i][j] = max(dp[i - 1][j], + dp[i][j]);
//		}
//	}
//
//	cout << dp[N][K];
//
//	return 0;
//}
//2023-03-19 복습
/*
* 1.아이디어
* 백팩문제이다.
* dp[i][j] i번째 물건까지 고려했을때 j무게만큼 들었을 때의 가치
* 모든 물건을 확인하는데 확인하는 물건이 j다 같거나 작을경우, dp[i][j]에 해당 가치를 갱신해준다.
* 이때 만약 dp[i-1][j-w[i].first] + w[i].second와 dp[i-1][j]를 비교해서 더 큰 값으로 갱신한다.
* 2.시간복잡도
* O(NK), N<=100, K<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main(void) {

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> item(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> item[i].first >> item[i].second;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= item[i].first)
				dp[i][j] = dp[i - 1][j - item[i].first] + item[i].second;
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	cout << dp[N][K];

	return 0;
}