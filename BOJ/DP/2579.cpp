/*
* 1.아이디어
* arr[N] 배열에 각 값을 입력받음
* dp[0] = arr[0], dp[1] = arr[0]+arr[1], dp[2] = max(arr[0], arr[1]) + arr[2]
* 첫번째경우)i위치를 기준으로 1칸 아래에서 올라왔을 때
* 이미 2개를 올라갔으므로 1칸전에는 2칸을 넘어 올라왔을 것, 따라서 dp[i-3] + arr[i-1]
* 두번째경우)i위치를 기준으로 2칸 아래에서 올라왔을 때
* 이전에 2칸올라간지 1칸올라온지 상관없는 경우, 따라서 dp[i-2]
* 
* 두가지의 경우를 비교해서 더 큰 값이 해당계단의 가장 높은 점수
* 2.시간복잡도
* O(N),	N<=300이므로 가능
* 3.변수형
* int : 계단의 점수의 최대가 10000이므로 int
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int dp[1001];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//	vector<int> v(N);
//	
//	for (auto& i : v)
//		cin >> i;
//
//	dp[0] = v[0];
//	dp[1] = v[0] + v[1];
//	dp[2] = max(v[0], v[1]) + v[2];
//
//	for (int i = 3; i < N; i++)
//		dp[i] = max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i];
//
//	cout << dp[N - 1];
//
//	return 0;
//}
//2023-02-24 복습
/*
* 1.아이디어
* dp[i]는 i 계단을 올라오기까지의 최대값이다.
* i번째 계단은 2가지 방법으로 올라갈 수 있는데, i-2에서 올라가는것과 i-1이 있다.
* i-2를 올라가는 것은 dp[i-2]라고 할 수있고  dp[i-1]는 arr[i-2]이 포함될 수도있기 때문에 그러면 3칸을 연속으로 가기 때문에 조건을 만족하지 못한다.
* 따라서 dp[i-3] + arr[i-1] 를 비교해야한다.
* dp[i] = arr[i] + max(dp[i-2], dp[i-3] + arr[i-1])
* 2.시간복잡도
* O(N), N<= 300 따라서 가능
* 3.변수형
*/
#include <iostream>

using namespace std;

int dp[301];
int arr[301];

int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	dp[3] = arr[3] + max(arr[1], arr[2]);

	for (int i = 4; i <= N; i++)
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3] + arr[i - 1]);

	cout << dp[N];

	return 0;
}