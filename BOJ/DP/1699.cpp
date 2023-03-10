/*
* 1.아이디어
* i가 1->N까지 갈 때, j j*j <= i로 가면서 모든 수의 제곱을 확인해준다.
* i-j*j이 해당 수의 경우의 수 + 1(j제곱으로 인한 늘어난 경우의수)로 계속 진행하면서
* 더 작은수가 나올경우 갱신해주면 최소가 되는 제곱수들의 합을 알 수 있다.
* 따라서 점화식은,
* for(int i = 0; i <= N; i++){
*	dp[i] = i;
*	for(int j = 1; j*j<= i; j++){
*		dp[i] = min(dp[i], dp[i-j*j]+1);
*	}
* }
* 2.시간복잡도
* O(NlogN), N <= 100000 따라서 가능
* 3.변수형
* int :
*/
//#include <iostream>
//using namespace std;
//
//int dp[100001];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		dp[i] = i;
//		for (int j = 0; j * j <= i; j++) {
//			dp[i] = min(dp[i], dp[i - j * j] + 1);
//		} 
//	}
//
//	cout << dp[N];
//
//	return 0;
//}
/*
* 1.아이디어
* dp[i] i를 구성하는 제곱항의 개수
*
* 1,2,3읜 각각 개수가 1,2,3이다.
* 여기서 4부터는 2의 제곱이 있기때문에 달라지는데 이를 확인하는 것은
* dp[i] = max(dp[i], dp[i-j*j]+1)
*
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>

using namespace std;

int dp[100001];

int main(void) {
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= N; i++) {
		dp[i] = i;		//모든 항을 1로 했을때, 즉 자기자신을 기본값으로 두고 가장 작은수로 갱신하도록 하게 함
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}

	cout << dp[N];

	return 0;
}