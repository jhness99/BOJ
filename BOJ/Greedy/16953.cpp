/*
* 1.아이디어
* 입력받은수를 먼저 2로 나눌수있다면 나눈다.
* 나누어지지않는다면 1을 빼는데 단순히 빼는게 아니라 10으로 나눠서 아에 1의자리를 없앤다
* 처음 입력받은 수가 나온다면 횟수를, 만약 입력받은수 이하로 내려간다면 -1을 출력한다.
* 2.시간복잡도
* 1000000000의 수를 나누고 1의자리수를 없에는데 최대한으로 걸리도록 2를 나눠도 O(N)을 충족함
* 3.변수형
* int : 아무리 많이 반복해도 10억 이상이 나오지 않으므로 int
*/
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//	int num1, num2, cnt = 0;
//	cin >> num1 >> num2;
//
//	while (num1 < num2) {
//		if (num2 % 2 == 0) {
//			num2 = num2 / 2;
//			cnt++;
//		}
//		else if (num2 % 10 == 1) {
//			num2 = num2 / 10;
//			cnt++;
//		}
//		else break;
//	}
//
//	if (num1 == num2)
//		cout << cnt+1;
//	else
//		cout << -1;
//	return 0;
//}
//2023-03-07 복습
/*
* 1.아이디어
* 2가지의 연산을 사용한다.
* 2를 곱하는 연산과 1을 추가하는 연산인데 이 2가지 연산을 반대로 한 것은 2를 나누는것, 10을 나머지로 했을 때 1이 나오는지를 확인하는 것이다.
* 둘 다 안된다면 -1을 출력하고 나간다.
*
* 2.시간복잡도
* O(logB), B<=1000000000 따라서 가능
* 3.변수형
*/
#include <iostream>

using namespace std;

int main(void) {

	int A, B, cnt = 1;
	cin >> A >> B;

	while (A < B) {
		if (B % 10 == 1)
			B /= 10;
		else if (B % 2 == 0)
			B /= 2;
		else break;
		cnt++;
	}
	if (A != B)
		cnt = -1;

	cout << cnt;

	return 0;
}