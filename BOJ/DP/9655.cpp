/*
* 1.아이디어
* 돌이 짝수개일 때는 창영이가 이기게 되고 돌이 홀수개일 때는 상근이가 이기게 된다.
* 2.시간복잡도
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	if (N % 2 == 0)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}