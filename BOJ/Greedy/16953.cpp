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
#include <iostream>

using namespace std;

int main(void) {
	int num1, num2, cnt = 0;
	cin >> num1 >> num2;

	while (num1 < num2) {
		if (num2 % 2 == 0) {
			num2 = num2 / 2;
			cnt++;
		}
		else if (num2 % 10 == 1) {
			num2 = num2 / 10;
			cnt++;
		}
		else break;
	}

	if (num1 == num2)
		cout << cnt+1;
	else
		cout << -1;
	return 0;
}