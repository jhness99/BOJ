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
#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int main(void) {
	int N;
	cin >> N;
	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	for (int i = 0; i < N; i++) {
		//기본적으로 수열의 길이는 1이므로
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			//i번째 수가 탐색하고있는 j번째 수보다 크고, 
			//j번째 수가 포함된 수열의 길이가 i번째수가 포함된 수열의 길이보다 같거나 클 경우
			if (v[i] > v[j] && dp[j] >= dp[i]) {
				//i번째위치의 수를 j번째의 수열에 포함시키고 수열의 길이를 1 증가시킴
				dp[i] = dp[j] + 1;
			}
		}
	}
	int Max = -1;
	for (int i = 0; i < N; i++) {
		Max = max(dp[i], Max);
	}
	cout << Max;

	return 0;
 }