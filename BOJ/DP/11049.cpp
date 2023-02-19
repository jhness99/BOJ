/*
* 1.아이디어
* 파일합치기-11066와 비슷한 문제이다
* 행렬또한 바로 옆에 있는 행렬이랑만 연산할 수 있으므로 똑같다고 할 수 있다.
* 
* dp[x][y] : x번째 행렬부터 y번째 행렬까지 곱했을 때의 최소의 곱셈 연산 횟수
* 똑같이 범위를 나눠서 계산해주면 된다.
* 여기서도 파일합치기처럼 2개로 나누어서 계산하는데 그 이유는 다음과 같다.
* 행렬은 애초에 여러개를 곱할 때도 2개씩 곱하고 나온 값을 다시 곱하는 형식으로 하기 때문에 2개로 나누는 것이다.
* 이 문제 또한 뒤에 dp계산을 하고 2개로 나뉜 행렬곱을 해주는데 그 이유는 2행렬을 만드는 연산의 수가 dp이기 때문에
* 나누어진 행렬들의 연산횟수 또한 계산해주어야하기 때문이다.
* 따라서 이러한 점화식을 세울 수 있다.
* dp[j][i + j] = min(dp[j][i + j], dp[j][k]+dp[k + 1][i + j] + matrix[j][0]*matrix[k][1]*matrix[i+j][1])
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <limits.h>

using namespace std;

int dp[501][501];
int matrix[501][2];

int main(void) {
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> matrix[i][0] >> matrix[i][1];
	}

	for (int i = 1; i <= N; i++) {
		for (int start = 1; start + i <= N; start++) {
			int end = start + i;
			dp[start][end] = INT_MAX;
			for (int mid = start; mid < end; mid++) {
				dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + matrix[start][0] * matrix[mid][1] * matrix[end][1]);
			}
		}
	}

	cout << dp[1][N];
	return 0;
}