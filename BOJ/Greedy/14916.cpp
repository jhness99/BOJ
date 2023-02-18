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
#include <iostream>

using namespace std;

int main(void) {

	int N, answer = 0;
	cin >> N;

	while (N > 1) {
		if (N >= 5 && (N - 5 >= 5 || ((N - 5) % 2 == 0))) {
			N -= 5;
			answer++;
		}
		else {
			N -= 2;
			answer++;
		}
	}
	if (N == 1)
		answer = -1;

	cout << answer;

	return 0;
}