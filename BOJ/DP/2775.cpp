/*
* 1.아이디어
* arr[15][15]배열생성
* arr[0][1] ~ arr[0][14]를 1~14로 설정
* arr[k][n] = arr[k-1][n] + arr[k][n-1]
* 2.시간복잡도
* O(N^2), N <= 14 따라서 가능
* 3.변수형
* int : 
*/
//#include <iostream>
//
//using namespace std;
//
//int arr[15][15];
//
//int main(void) {
//
//	for (int i = 1; i < 15; i++) {
//		arr[0][i] = i;
//	}
//
//
//	for (int i = 1; i < 15; i++) {
//		for (int j = 1; j < 15; j++) {
//			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
//		}
//	}
//
//	int T;
//	cin >> T;
//	while (T--) {
//		int k, n;
//		cin >> k >> n;
//		cout << arr[k][n] << "\n";
//	}
//
//	return 0;
//}
//2023-02-23 복습
/*
* 1.아이디어
* dp풀이
* a층의 b호의 경우 a-1층의 1~b호까지의 합이라고 했다.
* 이때 a층 b-1호는 이미 a-1층 1~b-1호까지의 합이다.
* 따라서 dp[a][b] = dp[a-1][b] + dp[a][b-1] 이다.
* 2.시간복잡도
* O(KN), N,K<=14
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int dp[15][15];

int main(void) {

	for (int i = 1; i <= 14; i++)
		dp[0][i] = i;

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;

		cout << dp[a][b] << endl;
	}

	return 0;
}