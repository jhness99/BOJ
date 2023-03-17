/*
* 1.아이디어
* 각 상담은 pair<int, int>로 저장한다.
* 최대값을 0으로 설정하고 0부터 for문을 시작한다.
* dp[i]와 Max값을 max연산해서 dp[i]에 넣어준다. 이것이 왜 필요하냐면 가능한 모든 스케쥴을 하는 것이 아니라 가장 큰 스케쥴이 나오도록 하기위해
* 고의적으로 쉬어도 되기 때문에 Max값과 비교해서 dp[i]값을 갱신 해줘서 더 많은 수익을 얻을 수 있도록 한다.
* 따라서, dp[i] = Max = max(dp[i], Max);
* if(schedule[i].first + i <= N) 조건을 확인하고 만약 true라면
* dp[i+schedule[i].first] = max(dp[i]+schedule[i].second, dp[i+schedule[i].first]);
* 
* 결국 답은 Max가 된다.
* 2.시간복잡도
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int dp[16];
//pair<int, int> schedule[16];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//	
//	for (int i = 0; i < N; i++)
//		cin >> schedule[i].first >> schedule[i].second;
//
//	int Max = 0;
//	for (int i = 0; i <= N; i++) {
//		dp[i] = Max = max(dp[i], Max);
//		if (schedule[i].first + i <= N) 
//			dp[i + schedule[i].first] = max(dp[i + schedule[i].first], dp[i] + schedule[i].second);
//	}
//
//	cout << Max;
//
//	return 0;
//}
//2023-03-17 복습
/*
*1.아이디어
* dp[i]는 i일까지 한 상담으로 얻는 돈의 최대치를 의미한다.
* i일을 시작으로 dp[i + 해당 상담이 걸리는 시간] 과 dp[i] + 해당 상담의 금액을 비교해서 더 큰 값을 dp[i + 해당 상담이 걸리는 시간]에 갱신해준다.
* dp[i]와 Max값을 max연산해서 dp[i]에 넣어준다. 이것이 왜 필요하냐면 가능한 모든 스케쥴을 하는 것이 아니라 가장 큰 스케쥴이 나오도록 하기위해
* 고의적으로 쉬어도 되기 때문에 Max값과 비교해서 dp[i]값을 갱신 해줘서 더 많은 수익을 얻을 수 있도록 한다.
*2.시간복잡도
* O(N) N <= 15 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[16];

int main(void) {

	int N;
	cin >> N;

	vector<pair<int, int>> input(N + 1);
	for (int i = 0; i < N; i++)
		cin >> input[i].first >> input[i].second;

	int Max = -1;
	for (int i = 0; i <= N; i++) {
		dp[i] = Max = max(dp[i], Max);
		if (input[i].first + i <= N) {
			dp[i + input[i].first] = max(dp[i + input[i].first], dp[i] + input[i].second);
		}
	}

	cout << Max;

	return 0;
}