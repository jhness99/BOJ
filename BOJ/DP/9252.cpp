/*
* 1.아이디어
* LCS-9251문제와 비슷한 문제다
* 9251문제에서 가장 긴 수열을 출력해주기만 하면 된다.
* LCS문제의 풀이방법은
* DP[1001][1001]로 2차원배열을 만들어준다.
* ACAYKP와 CAPCAK를 비교할 때는 ACAYKP를 기준으로 
* A와 CAPCAK를 하나씩 확인하는 것이다. 이 경우 A, 길이는 1이다
* 그래서 중복되는 경우가 나올경우 길이로 추가해준다.
* AC의 경우를 확인해보자. A만있을경우는 이미 체크 했으므로 C를 확인한다.
* CAPC에서 C가 A뒤에 있으므로 AC가 가능하다. 이때 CAP일때 A가 가능하므로 A, 길이 1이다.
* 따라서 CAP"C"와 C가 겹치므로 CAP와 A의 길이와 문자열에 +1, C를 추가해준다. 따라서 AC, 길이 1
* 이것을 보면 만약 확인하고 있는 알파벳(i)과 대상 문자열의 해당 위치(j)가 같다면,
* dp[i][j] = dp[i-1][j-1] + 1 이라고 할 수 있다.
* 만약 다르더라도 이전 문자열과 길이는 같으므로 
* 다를경우 탐색하는 위치의 위나 아래중 큰 값을 문자열, 길이로 설정한다.
* 
* 이것이 기본적인 LCS문제의 풀이방법인데 여기서 가장 큰 문자열을 찾아야 한다.
* 이것은 vector<string> v를 만들어 v[i]에 문자가 늘어날 때마다 해당 문자를 추가해주고
* 마지막에 길이가 가장 긴 문자열을 출력해주는것으로 구현한다.
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int dp[1001][1001];
//
//int main(void) {
//	
//	string str1;
//	string str2;
//	string ans = "";
//
//	cin >> str1 >> str2;
//
//	for (int i = 1; i <= str1.length(); i++) {
//		for (int j = 1; j <= str2.length(); j++) {
//			if (str1[i - 1] == str2[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//
//	for (int i = str1.length(); i >= 1; i--) {
//		int j_idx = str2.length();
//		for (int j = j_idx; j >= 1; j--) {
//			if (dp[i][j] == dp[i - 1][j]) {
//				j_idx = j;
//				break;
//			}
//			else if (dp[i][j] == dp[i][j - 1]) continue;
//			else {
//				ans = str1[i - 1] + ans;
//			}
//		}
//	}
//
//	cout << dp[str1.size()][str2.size()] << endl;
//	cout << ans;
//
//	return 0;
//}
//2023-03-13 복습
/*
* 1.아이디어
* LCS를 만드는 문제이다. dp로 풀 수 있다.
*
* dp로 LCS를 구현하는법
* dp[i][j]는 문자열1의 i번째까지의 문자열과 문자열2의 j번째까지의 문자열에서의 최장공통수열의 크기를 의미한다.
* 만약 i j를 문자열1,2의 길이를 기준으로 탐색한다고 할 때 str1[i]와 str2[j]가 같다면,
* 우리는 이전에 같은 수가 있었는지를 확인해야 한다. 따라서 dp[i-1][j-1]의 값을 확인한다.
* 이유는 i-1과 j-1의 경우, 현재 같은 수가 포함되지않은 이전의 문자열의 최장공통수열의 길이이기 때문에 해당 수에서 +1로 갱신한 값을
* dp[i][j]에 넣으면 되는것이다.
* 하지만 만약 두 수가 다른경우도 있다. 이 경우에는 i-1 j 와 i j-1 의 경우 중 더 큰 값을 넣어주면 된다.
* 결국 dp[N][M]이 최종적인 LCS가 나오게 된다.
*
* 여기서 우리는 최장수열의 문자열을 출력해야 하는데 이는 거꾸로 돌아가면서 생각하면 된다.
* 먼저 N번째 M번째 수부터 확인해서 만약 자신이 가장 마지막에 있고 바로 위에 수가 줄어든다면, 즉 수열이 작아진다면,
* 해당 수가 바로 최장수열의 문자라는 것이다. 우리는 가장 먼저 최장수열이 늘어난 수를 찾아야 한다.
* 따라서 거꾸로 가주면서 가장 먼저 숫자가 늘어나게 된 수를 찾는 과정인것이다.
*
* 2.시간복잡도
* O(N^2), N<= 1000 따라서 가능
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int dp[1001][1001];

int main(void) {

	string str1;
	string str2;
	string answer;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	int indexJ = str2.size();

	for (int i = str1.size(); i >= 1; i--) {
		for (int j = indexJ; j >= 1; j--) {
			if (dp[i][j] == dp[i - 1][j]) {
				indexJ = j;
				break;
			}
			else if (dp[i][j - 1] == dp[i][j]) continue;
			else
				answer = str1[i - 1] + answer;
		}
	}

	cout << dp[str1.size()][str2.size()] << endl;
	cout << answer;

	return 0;
}