/*
* 1.아이디어
* 조건 3가지를 확인해주면 된다.
* a,b,c가 하나라도 0보다 같거나 작다면, 1 반환
* a,b,c 가 한개라도 20보다 크다면, w(20, 20, 20)반환
* 만약 dp[a][b][c]가 확인한 값이라면, dp[a][b][c]반환
* a<b&&b<c 의 경우 dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1)-w(a,b-1,c)
* 위의 경우가 전부 아닐경우, dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
* 2.시간복잡도
* 
* 3.변수형
* int : 
*/
#include <iostream>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (dp[a][b][c]) return dp[a][b][c];
	if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}

	return 0;
}
//2023-03-06 복습
//단순한 재귀->DP 변환 문제라 코드생략