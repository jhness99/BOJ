/*
* 1.아이디어
* A를 기준으로 오름차순 정렬을 한다.
* 정렬된 A를 기준으로 B를 비교하는데, 이때 나오는 수를 LIS(최장증가수열)로 구하면 된다.
* 그 후 전체길이에서 빼주면 빼야하는 최소한의 수가 나온다.
* 입력은 pair<int, int> input[100]
* LIS
* for(int i = 0; i < N; i++){
*	dp[i] = 1;
*	for(int j = 0; j < i;j++){
*		if(input[i] > input[j] && dp[i] <= dp[j])
*			dp[i] = dp[j] + 1;
*		}
* }
* 2.시간복잡도
* O(N^2), N<=100, 따라서 가능
* 3.변수형
* int :
*/
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> line[100];
int dp[100];

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> line[i].first >> line[i].second;
	
	sort(line, line + N);

	int Max = -1;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (line[i].second > line[j].second && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
		Max = max(Max, dp[i]);
	}

	cout << N - Max;

	return 0;
}