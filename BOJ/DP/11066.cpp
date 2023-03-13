/*
* 1.아이디어
* 예전에 배웠던건대 너무 어렵다...
* 
* 이 문제에서 dp[i][j]란 i번째부터 j번째까지 더한 값의 최소값이라는 뜻이다.
* 이 문제같은 경우에는 범위를 잘 설정해야 한다.
* 예를 들어 40 30 30 50을 잘 조합해서 값을 구하려면, 40/30 30 50. 40 30 / 30 50 이런식으로 2개의 묶음으로 나누는 것이다.
* 이렇게 묶은 그룹의 dp를 구해서 더한값 중 가장 작은 값을 찾으면 된다. 이렇게 2개로 나누는 이유는
* 파일 2개를 1개로 묶어서 계산하는 문제이기 때문에 2개로 나누어 주는 것이고, 
* 인접한 것 끼리만 묶을 수 있기 때문에 따로 조합하지않고 주어진 그룹에서 나눠주는 것이다.
* 묶은 값들을 더한것 + 해당 총 범위의 수의 합을 추가로 합해준다. 그 이유는 임시파일로 만들어 추가해주므로
* 40 30 30 50 의 경우 30 40으로 묶고 30 50으로 묶으면 각각 70 80이 된다. 그리고 이 70 80을 추가로 묶는데 그 값은 40+30+30+50으로
* 40부터 50까지의 합과 같다. 따라서 총 범위의 수들의 합 또한 더해주어야 한다.
* 2.시간복잡도
* O(N^3), N<= 500 따라서 가능
* 3.변수형
* 
*/
//#include <iostream>
//#include <limits.h>
//
//using namespace std;
//
//int dp[501][501];
//int cost[501];
//int sum[501];
//
//int main(void) {
//	int T;
//	cin >> T;
//	while (T--) {
//		int K;
//		cin >> K;
//
//		for (int i = 1; i <= K; i++) {
//			cin >> cost[i];
//			sum[i] = sum[i - 1] + cost[i];
//		}
//
//		for (int i = 1; i <= K; i++) {
//			for (int start = 1; start + i <= K; start++) {
//				int end = start + i;
//				dp[start][end] = INT_MAX;
//
//				for (int mid = start; mid < end; mid++) {
//					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
//				}
//			}
//		}
//		cout << dp[1][K] << "\n";
//	}
//}
//2023-03-13 복습
/*
* 1.아이디어
*
* 진짜 너무 어렵다.. 행렬곱 dp문제는 진짜 익숙해질때까지 반복할 필요를 느꼈다.
*
* dp[i][j] i번째 파일부터 j번째 파일까지 비용의 최소를 저장한다.
* 각 임시파일을 만들기 위해선 인접한 것 끼리 더해줘야 한다. 즉 재배치나 임의의 조합은 안된다는 것이다.
*
* 각 파일별로 코스트를 저장하고 누적합을 저장하는 배열 sum또한 초기화 해준다. 누적합을 만드는 이유는 나중에 나온다.
* 초기화 했다면 2개, 3개, 4개... k개의 길이를 가지는 조합을 생각해본다.
* 예를들면 40 30 30 50의 경우 2개의 조합은 40 30, 30 30, 30 50 이 있다. 이 값들의 dp[start][end]를 구하는 것이다.
* for(int i = 1; i <= k; i++) //각 조합의 길이이다.
*	for(int start = 1; start + i <= k; start++) //start와 조합의 길이 k의 합이 k를 넘어가면 안되므로
*		int end = start + i;
*		dp[start][end] = INT_MAX;
*		for(int mid = start; mid < end;  mid++)
*			dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + sum[end] - sum[start - 1]);
*	마지막에 누적합 sum을 사용하는 이유는 바로 합을 구하면 조합했을 때의 합 + 총 합을 다 계산해야 한다
* 예를 들면 40 30 30 50 의 경우 40+30, 30+50으로 70 80, 70+80 = 150 이다. 150을 만들기 위한 임시파일을 만들때의 비용도
* 생각해야 하므로 탐사한 start와 end 까지의 모든 수를 더해줘야 한다. 따라서 누적합을 만들어 둔 것이다.
* 2.시간복잡도
* O(K^3) K <= 500, 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <limits.h>

using namespace std;

int dp[501][501];
int cost[501];
int sum[501];

int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}
		for (int i = 1; i <= K; i++) {
			for (int start = 1; start + i <= K; start++) {
				int end = start + i;
				dp[start][end] = INT_MAX;

				for (int mid = start; mid < end; mid++) {
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}

	return 0;
}