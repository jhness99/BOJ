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
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//pair<int, int> line[100];
//int dp[100];
//
//int main(void) {
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) 
//		cin >> line[i].first >> line[i].second;
//	
//	sort(line, line + N);
//
//	int Max = -1;
//	for (int i = 0; i < N; i++) {
//		dp[i] = 1;
//		for (int j = 0; j < i; j++) {
//			if (line[i].second > line[j].second && dp[j] >= dp[i])
//				dp[i] = dp[j] + 1;
//		}
//		Max = max(Max, dp[i]);
//	}
//
//	cout << N - Max;
//
//	return 0;
//}
//2023-03-06 복습
/*
* 1.아이디어
* LIS와 비슷하게 풀면된다.
*
* 입력받은 수를 A 기준으로 오름차순 정렬한다.
* 그러면 B는 A를 기준으로 나열되는데 이때 우리는 전기줄이 겹치면 안된다.
* 전기줄이 겹치면 안된다는 뜻은 즉,앞의 수가 뒤에수보다 크면 안된다. 만약 클 경우 전기줄이 겹친다.
* 따라서 우리는 앞의 수가 뒤에수보다 작은 수열, 즉 LIS를 만들경우 해당 LIS의 길이가 가장 전기줄을 많이 설치할 수 있는 경우의 전기줄 수이다.
* 이 경우 총 전기줄 - LIS를 하면 내가 없엔 전기줄의 수를 알 수 있다.
*
* LIS는 매번 설명하지만 이런 방법으로 만든다
* for(int i = 0; i < N; i++)
*	dp[i] = 1;
*	for(int j = 0; j < i; j++)
*		if(arr[i] > arr[j] && dp[j] >= dp[i])
*			dp[i] = dp[j] + 1;
*
* 현재 탐색하는 위치의 수열을 1로 초기화 하고 0~i-1까지 수들을 확인하면서
* i번째 수보다 작고, j번째 수를 가진 수열이 i번째 수를 가진 수열보다 크거나 같을경우,
* j번째 숫자가 들어있는 수열에 i를 포함시킨다.(j번째 수가 들어간 수열 + 1(i가 들어감))
*
* 2.시간복잡도
* O(N^2) N<= 100 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100];

int main(void) {

	int N;
	cin >> N;

	vector<pair<int, int>> input(N);

	for (auto& p : input)
		cin >> p.first >> p.second;

	sort(input.begin(), input.end());

	int Max = -1;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[i].second > input[j].second && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
		Max = max(Max, dp[i]);
	}

	cout << N - Max;

	return 0;
}