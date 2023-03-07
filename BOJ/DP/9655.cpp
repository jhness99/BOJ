/*
* 1.아이디어
* 돌이 짝수개일 때는 창영이가 이기게 되고 돌이 홀수개일 때는 상근이가 이기게 된다.
* 2.시간복잡도
* 3.변수형
* 
*/
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	if (N % 2 == 0)
//		cout << "CY";
//	else
//		cout << "SK";
//
//	return 0;
//}
//2023-03-07 복습
/*
* 1.아이디어
* 1과 3을 가져갈 수 있고 SK와 CY가 게임을 할 때 홀수일경우 무조건 SK가 이기게 되고 짝수이면 CY가 무조건 이기게 된다.
*
*/
#include <iostream>
using namespace std;

int main(void) {

	int N;
	cin >> N;

	cout << ((N % 2 == 0) ? "CY" : "SK");

	return 0;
}