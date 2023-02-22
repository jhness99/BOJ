/*
* 1.아이디어(dp문제)
* 0과 1을 출력한 수가 피보나치형식으로 늘어나므로, dp[i] = dp[i-1] + dp[i-2]
* 0과 1의 수를 따로 계산
* 2.시간복잡도
* O(N) N <= 40 이므로 가능
* 3.변수형
* int : 40까지 계산해도 10억이므로 int형 가능
*/
//#include <iostream>
//
//using namespace std;
//
//
//pair<int, int> Count[41];
//
//int main(void) {
//	int T;
//	cin >> T;
//
//	Count[0] = { 1,0 };
//	Count[1] = { 0,1 };
//   
//	for (int i = 2; i <= 40; i++) {
//		int first = Count[i - 1].first + Count[i - 2].first;
//		int second = Count[i - 1].second + Count[i - 2].second;
//		Count[i] = {first, second};
//	}
//
//	while (T--) {
//		int N;
//		cin >> N;
//		
//		cout << Count[N].first << " " << Count[N].second << "\n";
//	}
//}
//2023-02-22 복습
/*
* 1.아이디어
* 여러가지 방법으로 풀 수 있는데, 기본적으로 fibo(3) = fibo(2)+ fibo(1)이기 때문에 각 함수의 0,1출력의 횟수의 합이 fibo(3)의 0, 1 출력수이다.
* 따라서 기본값 1 0, 0 1을 기준으로 dp[i] = dp[i-1] + dp[i-2]를 해주면 된다.
* 점화식
* zero[i] = zero[i-1] + zero[i-2], one[i] = one[i-1] + one[i-2]
* 2.시간복잡도
* O(N) N <= 41, 따라서 가능
* 3.변수형
* int One[N], int Zero[N] : 숫자N의 1과 0을 출력하는 횟수를 저장한 배열
*/
#include <iostream>

using namespace std;

int Zero[41];
int One[41];

int main(void) {

	Zero[0] = 1;
	Zero[1] = 0;
	One[0] = 0;
	One[1] = 1;

	for (int i = 2; i <= 40; i++) {
		Zero[i] = Zero[i - 1] + Zero[i - 2];
		One[i] = One[i - 1] + One[i - 2];
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << Zero[N] << " " << One[N] << "\n";
	}

	return 0;
}