/*
* 1.아이디어
* 길이가 3이고 아래와 위를 기준으로 계산할 때 나오는 경우의 수는 다음과 같다.
* 1 0 1		0 0 1 (arr[0][2]기준으로 나온 경우의 수)
* 0 1 0		1 0 0 
* 0 1 0		1 0 0 (arr[1][2]기준으로 나온 경우의 수)
* 1 0 1		0 0 1
* 이를 보면 알 수 있다싶이 
* 첫번째 줄의 경우, dp[0][2] = arr[0][2] + max(arr[1][0], arr[1][1] + arr[0][0])
* 두번째 줄의 경우, dp[1][2] = arr[1][2] + max(arr[0][0], arr[0][1] + arr[1][0])
* arr[1][0]은 dp[1][0]이고, arr[0][0]은 dp[0][0]으로 할 수 있고
* arr[1][1] + arr[0][0]은 dp[1][1]이고, arr[0][1] + arr[1][0]은  dp[0][1]
* 따라서 점화식은
* dp[0][i] = arr[0][i] + max(dp[1][i-2], dp[1][i-1])
* dp[1][i] = arr[1][i] + max(dp[0][i-2], dp[0][i-1])
* 2.시간복잡도
* O(2N), N<=100000, 따라서 가능
* 3.변수형
* int : 최대 100의 수가 100000번 나올 수 있으므로 int
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[2][100001];
//int arr[2][100001];
//
//int main(void) {
//
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int N;
//		cin >> N;
//
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//		for (int i = 0; i < N; i++) {
//			dp[0][i] = arr[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
//			dp[1][i] = arr[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
//		}
//
//		cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
//	}
//
//	return 0;
//}
//2023-03-22 복습
/*
* 1.아이디어
* 스티커의 상하좌우가 중복되면 안되므로 대각선의 경우와 대각선의 경우를 안 포함하는 경우 2가지를 봐야한다.
* 예를들어
* 1 0 1   0 0 1
* 0 1 0   1 0 0
* 이런식으로 대각선과 대각선 옆을 확인해서 계산해야 한다. 해당 값은 단순한 스티커 값이 아니라 dp로 해당위치를 골랐을 때
* 가장 큰 가치를 저장한 것이다.
* 2.시간복잡도
* O(N), N<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int dp[2][100001];
int arr[2][100001];

int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[1][1] + arr[0][0];

		for (int i = 2; i < N; i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
		}

		cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
	}

	return 0;
}