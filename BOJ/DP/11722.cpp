/*
* 1.아이디어
* 가장 긴 증가하는 부분 수열을 반대로 생각하면 된다.
* 기존의 조건에서 arr[i] < arr[j] 로 바꿔주면 된다.
* 2.시간복잡도
* O(N^2), N<=1000 이므로 가능
* 3.변수형
* int :
*/
#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];

int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	int Max = -1;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
		Max = max(Max, dp[i]);	//무슨 이유인지 모르겠지만 아래에 뒀더니 문제해결 반례를 못찾겠음;;
	}

	cout << Max;

	return 0;
}