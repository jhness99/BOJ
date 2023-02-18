/*
* 1.아이디어
* 가장 긴 증가하는 부분 수열-11053과 비슷한 문제이다.
* 하지만 이 문제는 가장 긴 수열을 출력해야한다.
* 따라서 dp에 숫자를 추가할 때(수열의 길이를 추가) 백터에 해당 숫자 또한 추가해주는것이다.
* 추가하는 방법은 vector<int> LIS[1001]을 선언한다. LIS[1]은 dp[1]처럼 1번째 수의 수열, 그 수열의 길이이다.
* 확인하는 수보다 작고, 해당 수열이 확인하고있는 수가 있는 수열보다 같거나 큰 경우
* 우리는 수열에 확인하는 수를 넣고 수열을 해당수열 + 1을 해줘서 확인하는 수를 해당 수열에 넣어줬었다
* 그 때 확인하는 수(arr[i])가 포함된 수열로 갱신해주는것이다.
* 2.시간복잡도
* O(N^2) N<=1000, 따라서 가능
* 3.변수형
* vector<int> LIS[1001] : 각 숫자의 위치를 기준으로 가장 긴 수열을 저장해주는 배열
* dp[1001] : 각 숫자의 위치를 기준으로 가장 긴 수열의 길이
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
int arr[1001];

int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	vector<int> LIS[1001];
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		LIS[i].push_back(arr[i]);
		for (int j = 1; j < i; j++) {
			//만약 해당수가 탐색하고 있는 arr[i]보다 작으면서 수열은 i번째가 계산중인 수열보다 크거나 같다면
			//dp[j]의 수열에 해당 수를 더해서 dp[i]를 갱신해주고 수열도 LIS[i]에 갱신해준다.
			if (arr[i] > arr[j] && dp[j] >= dp[i]) {
				//수열 갱신작업
				LIS[i].clear();
				LIS[i] = LIS[j];
				LIS[i].push_back(arr[i]);
				//수열 길이 갱신
				dp[i] = dp[j] + 1;
			}
		}
		if (answer.size() < LIS[i].size())
		{
			answer = LIS[i];
		}
	}

	cout << answer.size() << "\n";
	for (auto& i : answer)
		cout << i << " ";

	return 0;
}