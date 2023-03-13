/*
* 1.아이디어
* 팰린드롬의 특징에 대해서 알아야한다.
* 팰린드롬은 맨 앞의 숫자와 맨 뒤의 숫자를 제거해도 해당 수는 팰린드롬이다. ex) 1234321 -> 23432 둘다 팰린드롬
* 이 특성을 이용하면된다.
* bool dp[2001][2001]를 만든다. 
* 배열을 입력받고 dp를 초기화 해주는데 i == j 인 경우는 무조건 팰린드롬이므로 true, 그리고 바로 다음수가 같은 경우도 1 1 이런식으로 팰린드롬이므로 true
* 2.시간복잡도
* O(N^2+M), N<=2000 M<=1000000 따라서 가능
* 3.변수형
* bool dp[2001][2001] : dp[i][j]일때, i부터 시작해서 j로 끝나는 수가 팰린드롬인지 저장하는 배열
*/
//#include <iostream>
//
//using namespace std;
//
////dp[i][j]일때, i부터 시작해서 j로 끝나는 수가 팰린드롬인지 저장하는 배열
//bool dp[2001][2001];
//
//int arr[2001];
//
//int main(void) {
//	//시간초과가 걸려서 추가함
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		cin >> arr[i];
//		dp[i][i] = true;
//		if (arr[i - 1] == arr[i])
//			dp[i - 1][i] = true;
//	}
//		
//	for (int i = N; i > 0; i--) {
//		for (int j = N; j >= i; j--) {
//			if (arr[i] == arr[j] && dp[i + 1][j - 1])
//				dp[i][j] = true;
//		}
//	}
//	
//	int T;
//	cin >> T;
//	while (T--) {
//		int start;
//		int end;
//		cin >> start >> end;
//		cout << dp[start][end] << "\n";
//	}
//
//	return 0;
//}
//2023-03-12 복습
/*
* 1.아이디어
* dp[i][j] i부터 j까지의 수가 팰린드롬 일경우 true아닐경우 false
* dp[i][i]의 경우 같은 위치이기 때문에 초기화할때 펠린드롬으로 설정
* arr[i-1] == arr[i] 일경우, dp[i-1][i] 또한 펠린드롬으로 설정
*
* 끝 숫자부터 확인한다. 이때 해당 숫자의 양 옆 즉, 감싸고 있는 수가 같고, 감싸고 있는 수인 dp[i+1][j-1]가 팰린드롬일 경우,
* 해당 수 범위 또한 펠린드롬이기 때문에 dp[i][j] = true이다.
* 2.시간복잡도
* O(N^2+M), N<=2000 M<=1000000 따라서 가능
* 3.변수형
* bool dp[2001][2001] : dp[i][j]일때, i부터 시작해서 j로 끝나는 수가 팰린드롬인지 저장하는 배열
*/
#include <iostream>

using namespace std;

bool dp[2001][2001];
int arr[2001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i][i] = true;
		if (arr[i - 1] == arr[i])
			dp[i - 1][i] = true;
	}

	for (int i = N; i > 0; i--) {
		for (int j = N; j >= i; j--) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1])
				dp[i][j] = true;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int start;
		int end;
		cin >> start >> end;
		cout << dp[start][end] << "\n";
	}

	return 0;
}