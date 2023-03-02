/*
* 1.아이디어
* dp[1025][1025], arr[1025][1025]선언
* 이 이후부터 아이디어를 짜봤는대 도저히 각이 안나와서 찾아봤다.
* dp[i][j]는 arr[1][1]부터 arr[i][j]까지의 합이다.
* 이는 dp[i][j] = dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1]+arr[i][j] 로 만들수 있다.
* 그리고 만들어진 dp를 기반으로 시작위치와 끝 위치를 기준으로 합을 구하려면
* x2 y2위치는 1 1 ~ x2 y2의 합이므로 dp[x1-1][y2]와 dp[x2][y1-1]만큼 빼주고 중첩된 부분인 dp[x1-1][y1-1]을 더해주면
* x1 y1 부터 x2 y2의 값이 나오는 것이다. 이를 점화식으로 바꾸면
* answer = dp[x2][y2] - dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]
* 정 모르겠으면 https://donggoolosori.github.io/2020/10/13/boj-11660/ 참조
* 2.시간복잡도
* O(N^2), N<= 1024, 따라서 가능
* 3.변수형
* int : 1024*1024*1000이므로 int
*/
//#include <iostream>
//using namespace std;
//
//int dp[1025][1025], arr[1025][1025];
//
//int main(void) {
//	//시간초과 나와서 입력쪽 문제인 것으로 판단해 추가
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, M;
//	cin >> N >> M;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> arr[i][j];
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
//		}
//	}
//	int answer = 0;
//	for (int i = 0; i < M; i++) {
//		int x1, x2, y1, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//
//		answer = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
//		cout << answer << "\n";
//	}
//
//	return 0;
//}
//2023-03-02 복습
/*
* 1.아이디어
* 행렬을 입력받아서 dp를 초기화 해준다. 이때 dp[i][j]는 (0,0)~(j,i) 까지의 수들의 합이다.
* dp를 구하기위해선 해당 위치에서 위, 왼쪽의 dp를 더하고 중첩되는 부분을 뺀 후 자신의 값을 더해주면 된다.
* 이를 점화식으로 표현하면 dp[i][j] = arr[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] 이다.
*
* dp는 완성했고 이제 0,0 부터 시작하는것이 아닌 직접 지정해서 값을 알아내야 한다.
* (x1, y1)부터 (x2, y2)까지 합은, dp[y2][x2] - dp[y2][x1 - 1] - dp[y1-1][x2] + dp[y1-1][x1-1]
*
* 2.시간복잡도
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int dp[1025][1025];
int arr[1025][1025];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = arr[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}