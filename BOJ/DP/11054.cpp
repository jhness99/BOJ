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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][1001];

int main(void) {

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 1;
			for (int k = 0; k < j; k++) {
				if (v[j] > v[k] && dp[i][j] <= dp[i][k]) {
					dp[i][j] = dp[i][k] + 1;
				}
			}
		}
		reverse(v.begin(), v.end());
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
		answer = max(answer, dp[0][i] + dp[1][N-i-1]);

	cout << answer-1;

	return 0;
}