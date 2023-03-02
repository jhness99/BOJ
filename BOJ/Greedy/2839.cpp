/*
* 1.아이디어
* 그리디 풀이
* 
* 만약 5로 나누어 떨이지지 않는다면 3을 빼고 cnt++, 만약 5로 나누어 떨어진다면 cnt += N/5, break;
* 만약 N == 0 즉, N이 완전하게 3, 5 봉지로 나누어 떨어지지 않는다면, -1출력 나올경우 answer 출력
* 2.시간복잡도
* O(N), N<=5000 따라서 가능
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int main(void) {

	int N, answer=0;
	cin >> N;

	while (N > 0) {
		if (N % 5 == 0) {
			answer += N / 5;
			N %= 5;
			break;
		}
		N -= 3;
		answer++;
	}
	if (N == 0)
		cout << answer;
	else
		cout << -1;

	return 0;
}