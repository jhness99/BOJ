#i/*nclude <iostream>

using namespace std;

int main(void) {

	int n;
	int cnt = 0;

	cin >> n;

	while (n > 1) {
		if (n >= 5 && (n-5 >= 5 || (n - 5)%2 == 0)) {
			n -= 5;
			cnt++;
		}
		else if(n >= 2){
			n -= 2;
			cnt++;
		}
	}

	if (n == 1)
		cnt = -1;

	cout << cnt;
	return 0;
}*/
//2023-02-18
/*
* 1.아이디어
* N >= 5 && (N - 5 >= 5 || ((N - 5) % 2 == 0)) 일때 N-=5, answer++
* 아닐경우 N-=2, answer++;
* 2.시간복잡도
* O(N), N <=100000 따라서 가능
* 3.변수형
* int
*/
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	int N, answer = 0;
//	cin >> N;
//
//	while (N > 1) {
//		if (N >= 5 && (N - 5 >= 5 || ((N - 5) % 2 == 0))) {
//			N -= 5;
//			answer++;
//		}
//		else {
//			N -= 2;
//			answer++;
//		}
//	}
//	if (N == 1)
//		answer = -1;
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-12 복습
/*
* 1.아이디어
* 입력된 수가 1,3 일경우 불가능하므로 -1
* 입력된 수가 5의 나머지를 2로 나누어 떨어진다면, 5로 최대한 나누고 나머지는 2로 나눠서 몫을 더해준다.
* 만약 안된다면, 5나눠서 나온 값 -1해주고 이 값이 5원 동전의 수이다. 그 다음 5로 나눈 나머지에 +5을 해주고 2로 나눈 몫이
* 2원 동전의 개수다 이 둘을 합해준다.
*/
#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	if (N == 1 || N == 3) { cout << -1; return 0; }
	if (N % 5 % 2) cout << N / 5 - 1 + (N % 5 + 5) / 2;
	else cout << N / 5 + N % 5 / 2;

	return 0;
}