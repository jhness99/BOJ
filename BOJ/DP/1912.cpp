/*
* 1.아이디어
* i번째에서 시작할때,
* dp[0] = arr[0], dp[i] = arr[i], if(dp[i] + dp[i-1] >= 0)dp[i] += dp[i-1],
* 이렇게 하면 해당값을 더했을때 0이 될 경우, 즉 더 감소할경우를 막을 수 있다.
* 2.시간복잡도
* O(N), N <= 100000이므로 가능
* 3.변수형
* int : 각 수의 최대가 1000이기 때문에 int
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[100000];

int main(void) {

	int N;
	cin >> N;

	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	dp[0] = v[0];
	int Max = v[0];		//-1로 초기화 했다가 수의 범위가 -1000까지 있다는 사실을 까먹어서 첫 위치로 변경했다.
	for (int i = 1; i < N; i++) {
		//v[i]의 값과 이전값의 합 + v[i]값을 비교해서 더 큰 값을 결과값으로 넣음
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		Max = max(Max, dp[i]);
	}
	cout << Max;

	return 0;
}