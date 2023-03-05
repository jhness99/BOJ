//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//	int change = 1000;
//	int price = 0;
//	int cnt = 0;
//
//	cin >> price;
//
//	change -= price;
//
//	while (change != 0) {
//		if (change >= 500) {
//			cnt += change / 500;
//			change %= 500;
//		}
//		else if (change >= 100) {
//			cnt += change / 100;
//			change %= 100;
//		}
//		else if (change >= 50) {
//			cnt += change / 50;
//			change %= 50;
//		}
//		else if (change >= 10) {
//			cnt += change / 10;
//			change %= 10;
//		}
//		else if (change >= 5) {
//			cnt += change / 5;
//			change %=  5;
//		}
//		else if (change >= 1) {
//			cnt += change / 1;
//			change %= 1;
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}
//2023-03-04 복습
/*
* 1.아이디어
* coin을 순서대로 저장하고 거스름돈을 탐욕적이게 얻는다
* 개수를 거스름돈 / 동전값어치의 몫으로 구하고 거스름돈을 동전값어치의 나머지로 갱신한다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>

using namespace std;

int main(void) {

	int change;
	int cnt = 0;
	int coin[] = { 500,100,50,10,5,1 };
	cin >> change;

	change = 1000 - change;

	while (change > 0) {
		for (auto& i : coin) {
			if (change >= i) {
				cnt += change / i;
				change %= i;
			}
		}
	}

	cout << cnt;
	return 0;
}