/*
* 1.아이디어
* 단순히 탐색하고있는 수(i)보다 작은경우만 체크하면 안된다. 
* 만약 작은것만 체크하면 그 작은수가 점차 증가하는 수열이 아닐 수 있다.
* 따라서 해당 수열에 포함되는지 dp에 이전수열에 포함되는지, 다시 말해 이전 수열의 수보다 더 큰지 확인해야 한다.
* 해당 위치i를 기준으로 0부터 i-1까지 i위치의 수보다 작거나 수열의 길이가 같거나 큰 경우 dp[i] = dp[j] + 1
* 2.시간복잡도
* O(N(N-1)), N<=1000 이므로 가능
* 3.변수형
* int:
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int dp[1001];
//
//int main(void) {
//	int N;
//	cin >> N;
//	vector<int> v(N);
//
//	for (auto& i : v)
//		cin >> i;
//
//	for (int i = 0; i < N; i++) {
//		//기본적으로 수열의 길이는 1이므로
//		dp[i] = 1;
//		for (int j = 0; j < i; j++) {
//			//i번째 수가 탐색하고있는 j번째 수보다 크고, 
//			//j번째 수가 포함된 수열의 길이가 i번째수가 포함된 수열의 길이보다 같거나 클 경우
//			if (v[i] > v[j] && dp[j] >= dp[i]) {
//				//i번째위치의 수를 j번째의 수열에 포함시키고 수열의 길이를 1 증가시킴
//				dp[i] = dp[j] + 1;
//			}
//		}
//	}
//	int Max = -1;
//	for (int i = 0; i < N; i++) {
//		Max = max(dp[i], Max);
//	}
//	cout << Max;
//
//	return 0;
// }
//2023-03-14 복습
/*
* 1.아이디어
* 이제는 익숙해진 LIS 문제이다 범위가 1000까지이므로 DP로 풀어보자
*
* dp로 LIS푸는법
* dp[i]는 i번째 수까지 확인했을 때의 LIS의 길이를 의미한다.
*
* 처음 시작할 때 dp[i]는 최소한 자기자신만 포함되는 경우를 보장받으므로 1을 넣어준다.
* dp[i] = 1
* 그 다음 j를 0부터 j-1까지의 모든 수를 확인해준다.
* j번째수와 i번째 수를 비교해서 i번째 수가 더 크고, j까지 포함한 경우의 LIS길이가 i와 같거나 클 경우, 해당 수를 추가했을 때
* j까지 포함한 경우의 LIS의 길이가 1 늘어나는 것이므로, (arr[i] > arr[j] && dp[j] >= dp[i])
* dp[i]를 dp[j] + 1로 갱신해준다.
*
* 반복이 끝나면 dp 0~N-1까지 가장 큰 값이 LIS가 된다.
*
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[1000];

int main(void) {

	int N, answer = 0;
	cin >> N;

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}