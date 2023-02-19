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
}