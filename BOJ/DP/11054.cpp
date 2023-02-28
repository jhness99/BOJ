/*
* 1.아이디어
* 가장 긴 증가하는 부분 수열을 응용해서, 정방향으로, 반대방향으로 1번씩 해준 후
* 해준 dp들을 서로 더한 값중 가장 큰 값을 답으로 하면 된다.
* 가장 긴 증가하는 부분 수열을 만드는 법은
* i를 기준으로, 초기에 dp[i] = 1 을 해준다. 이때 이것의 의미는 아무조건이 없어도 해당 수열 1개만 
* 있을 땐 길이가 1이기 때문이다.
* 그 다음 j를 0부터 i-1까지 증가시키면서 해당 위치의 수를 보고 만약 i보다 작고 dp[j]가 dp[i]와 같거나 크면, 
* 해당 수의 dp[i] = dp[j]+1 를 한다. 이때 dp[j]는 j번째 수의 길이이므로 해당 수를 넣으면 길이가 1더 늘어나기 때문에 1을 더해주는것이다.
* 반대도 확인해주고 둘을 더한 값중 가장 큰 값이 답이 되게 된다.
* 2.시간복잡도
* O(2N^2), N <= 1000이므로 가능
* 3.변수형
* int : 
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int dp[2][1001];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	vector<int> v(N);
//	for (auto& i : v)
//		cin >> i;
//
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < N; j++) {
//			dp[i][j] = 1;
//			for (int k = 0; k < j; k++) {
//				if (v[j] > v[k] && dp[i][j] <= dp[i][k]) {
//					dp[i][j] = dp[i][k] + 1;
//				}
//			}
//		}
//		reverse(v.begin(), v.end());
//	}
//
//	int answer = 0;
//	for (int i = 0; i < N; i++)
//		answer = max(answer, dp[0][i] + dp[1][N-i-1]);
//
//	cout << answer-1;
//
//	return 0;
//}
//2023-02-28
/*
* 1.아이디어
* 가장 긴 바이토닉 부분수열을 푸는 문제인데, 이 문제는 각각 왼쪽 오른쪽을 기준으로한
* 가장 긴 증가하는 수열 LIS를 확인해서 서로를 뺀 값 중 최대값이 가장 긴 바이토닉 수열이다.
*
* 이 문제는 dp로 풀어보자
*
* dp로 풀려면 일단 dp[1001]을 생성한다.
* dp[1] = 1;
* i 1->N
*	dp[i] = 1 이때는 해당 숫자가 있는 수열의 길이가1이라는뜻
*	j 1->j
*		if(arr[i] > arr[j] && dp[i] <= dp[j])
비교중인 i번째수가 j번째보다 크고, j번째 수가 들어간 수열이 i번째 수가 들어간 수열보다 같거나 클경우
*			dp[i] = dp[j]+1
*
* 이것이 dp로 LIS구하는 점화식인데, 이것을 2개 생성해서 서로 빼줌으로써 바이토닉 수열을 만든다.
* 이때 서로 가장 마지막 부분이 겹치므로 -1을 해줘야한다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][1001];
int arr[1001];

int main(void) {

	int N, answer = 0;;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 1;
			for (int k = 0; k < j; k++) {
				if (arr[j] > arr[k] && dp[i][j] <= dp[i][k]) {
					dp[i][j] = dp[i][k] + 1;
				}
			}
		}
		reverse(arr, arr + N);
	}


	for (int i = 0; i < N; i++)
		answer = max(answer, dp[0][i] + dp[1][(N - 1) - i]);

	cout << answer - 1;

	return 0;
}