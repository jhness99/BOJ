/*
* 1.아이디어
* 가장 긴 증가하는 부분 수열을 반대로 생각하면 된다.
* 기존의 조건에서 arr[i] < arr[j] 로 바꿔주면 된다.
* 2.시간복잡도
* O(N^2), N<=1000 이므로 가능
* 3.변수형
* int :
*/
//#include <iostream>
//
//using namespace std;
//
//int dp[1001];
//int arr[1001];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	for (int i = 1; i <= N; i++)
//		cin >> arr[i];
//	
//	int Max = -1;
//	for (int i = 1; i <= N; i++) {
//		dp[i] = 1;
//		for (int j = 1; j < i; j++) {
//			if (arr[i] < arr[j] && dp[i] <= dp[j]) {
//				dp[i] = dp[j] + 1;
//			}
//		}
//		Max = max(Max, dp[i]);	//무슨 이유인지 모르겠지만 아래에 뒀더니 문제해결 반례를 못찾겠음;;
//	}
//
//	cout << Max;
//
//	return 0;
//}
//2023-03-02 복습
/*
* 1.아이디어
* LIS를 반대로 하면 된다. reverse를 사용해 배열을 반대로 만든 후 LIS를 구해준다.
*
* LIS dp로 구하는법
* dp[i] : i번째 수가 포함된 수열의 최고 길이를 의미한다.
*
* 따라서 dp[i]를 갱신해주는데, j 0->i-1 를 해서 만약 arr[i] > arr[j](j번째 수가 더 작고),
* j번째 수가 포함된 수열이 i번째 포함된 수열보다 같거나 클 경우 우리는 dp[i]를 dp[j]+1로 갱신해준다(j번째 수가 포함된 수열에 i를 추가한다는 뜻)
*
* 2.시간복잡도
* O(N^2), N<=1000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000];

int main(void) {

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	reverse(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
	}

	int Max = -1;
	for (int i = 0; i < N; i++)
		Max = max(Max, dp[i]);

	cout << Max;

	return 0;
}