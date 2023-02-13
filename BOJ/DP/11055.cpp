/*
* 1.아이디어
* 11053번. 가장 긴 증가하는 부분 수열과 비슷한 문제이다.
* (틀린 아이디어)
* 이문제는 간단하게 생각하면 원래 길이였던 부분을 합으로 바꿔주기만하면 되는 문제이다.
* 따라서 점화식은, 
* i 1->N; j 0->i-1 
* if(v[i] > v[j])
*	dp[i] += v[j];
* 
* (맞은 아이디어)
* 11053번의 점화식 중 해당 번째의 수의 길이를 현재 길이와 비교해서 더 클 경우에만 수열에 포함시켜주는 조건이 있었는데
* 그것을 빼서 해봤는데 안됬다. 반례는 1 8 2 3 9이다. 위 조건에서 dp[i] < dp[j] + v[i]를 추가해야 함
* 2.시간복잡도
* O(N^2), N<=1000 따라서 가능
* 3.변수형
* int : 
*/
#include <iostream>
#include <vector>

using namespace std;

long long dp[1001];

int main(void) {

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	for (int i = 0; i < N; i++) {
		dp[i] = v[i];
		for (int j = 0; j < i; j++)
			if (v[i] > v[j] && dp[i] < dp[j] + v[i])
				dp[i] += v[j];

	}

	long long Max = -1;
	for (int i = 0; i < N; i++)
		Max = max(Max, dp[i]);

	cout << Max;

	return 0;
}