#include <iostream>

using namespace std;

int main(void) {
	int change = 1000;
	int price = 0;
	int cnt = 0;

	cin >> price;

	change -= price;

	while (change != 0) {
		if (change >= 500) {
			cnt += change / 500;
			change %= 500;
		}
		else if (change >= 100) {
			cnt += change / 100;
			change %= 100;
		}
		else if (change >= 50) {
			cnt += change / 50;
			change %= 50;
		}
		else if (change >= 10) {
			cnt += change / 10;
			change %= 10;
		}
		else if (change >= 5) {
			cnt += change / 5;
			change %=  5;
		}
		else if (change >= 1) {
			cnt += change / 1;
			change %= 1;
		}
	}
	cout << cnt;

	return 0;
}