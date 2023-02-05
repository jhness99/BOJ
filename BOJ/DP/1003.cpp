/*
* 1.아이디어(dp문제)
* 0과 1을 출력한 수가 피보나치형식으로 늘어나므로, dp[i] = dp[i-1] + dp[i-2]
* 0과 1의 수를 따로 계산
* 2.시간복잡도
* O(N) N <= 40 이므로 가능
* 3.변수형
* int : 40까지 계산해도 10억이므로 int형 가능
*/
#include <iostream>

using namespace std;
//
//long long fiboarr[50] = { 0,1, };
//long long fibo(int N)
//{
//    if (N == 0 || N == 1)
//        return fiboarr[N];
//    else if (fiboarr[N] == 0)
//        fiboarr[N] = fibo(N - 1) + fibo(N - 2);
//    return fiboarr[N];
//}
//int main() {
//    int T;
//    cin >> T;
//    int tmp;
//    for (int i = 0; i < T; i++){
//        cin >> tmp;
//        if (tmp == 0)
//            cout << "1 0" << '\n';
//        else
//            cout << fibo(tmp - 1) << ' ' << fibo(tmp) << '\n';
//    }
//}

pair<int, int> Count[41];

int main(void) {
	int T;
	cin >> T;

	Count[0] = { 1,0 };
	Count[1] = { 0,1 };
   
	for (int i = 2; i <= 40; i++) {
		int first = Count[i - 1].first + Count[i - 2].first;
		int second = Count[i - 1].second + Count[i - 2].second;
		Count[i] = {first, second};
	}

	while (T--) {
		int N;
		cin >> N;
		
		cout << Count[N].first << " " << Count[N].second << "\n";
	}
}
