/*
* 1.아이디어
* 2번째부터 확인해보자. 1번째는 카드가 1개, 2번째는 2개 이므로 2번째 팩을 1개와 1번째 팩 2개랑 비교해서 더 가격이 비싼것을 고른다.
* 3번째의 경우 3번째카드팩 1개를 사던가 1번째 카드팩1개와 2번째 카드팩1개를 사던가 1번째 카드팩 3개를 사야한다. 하지만 여기서 1번째 카드팩 3개의 경우는
* 앞서 2번째에서 확인을 했기 때문에 (1개짜리 2개 사는 것도 비교해서 확인함) 확인하지 않고 1번째 2번째 와 3번째 카드팩을 비교해서 더 비싼것을 고른다.
* 만약 4번째라면 3번째 카드팩을 고른 가격 + 1번째 카드팩을 고른 가격와 2번째 카드팩2개를 고른 가격과 4번째 카드팩 1개를 고른 가격을 비교한다.
* 이를 점화식으로 나타내면,
* i -> N, j -> i/2
* dp[i] = max(dp[i], dp[i-j] + dp[j])
* 2.시간복잡도
* O(N(N/2)), O(N^2), N <= 1000, 따라서 가능
* 3.변수형
* int : 10000*1000 이므로 int
*/
#include <iostream>

using namespace std;

int dp[1001];
int v[1001];

int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> v[i];

	dp[1] = v[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = v[i];
		for (int j = 1; j <= i / 2; j++) 
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
	}

	cout << dp[N];

	return 0;
}