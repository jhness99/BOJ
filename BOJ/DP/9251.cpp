/*
* 1.아이디어
* LCS문제이다. 이때 S는 문자열이 아니라 수열이다.
* 2개의 문자열을 받아온 후 2차원 배열을 만들어 하나씩 확인한다.
* 만약 문자열1의 i번째와 문자열2의 j번째가 같다면, i-1, j-1 번째의 길이에 1을 더한 값을 넣어준다.
* 왜 이렇게 하냐면, 문자열1의 i-1번째와 문자열2의 j-1번째에서 각각 다음 문자열을 확인했을 때 추가해야하는 값이므로
* 현재 확인중인 문자열의 각각 전 문자까지의 수열의 길이에서 1을 추가해주는 것이다.
* 만약 다르다면, 문자열1 i-1이나 문자열2의 j-1중에서 가장 큰 길이를 가져야 한다.
* 따라서 점화식은
* if(str1[i] == str2[j])
*	dp[i][j] = dp[i-1][j-1] + 1;
* else
*	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
* 2.시간복잡도
* O(N*M) , N<=1000, M<=1000 이므로 가능
* 3.변수형
* int
*/
#include <iostream>

using namespace std;

int dp[1001][1001];

int main(void) {

	string str1;
	string str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[str1.length()][str2.length()];

	return 0;
}