#include <iostream>

using namespace std;

int main(void) {

	int A = 0, B = 0, C = 0;
	int Seconds = 0;

	cin >> Seconds;

	while (Seconds > 9) {
		if (Seconds >= 300) {
			A += Seconds / 300;
			Seconds %= 300;
		}
		else if (Seconds >= 60) {
			B += Seconds / 60;
			Seconds %= 60;
		}
		else if (Seconds >= 10) {
			C += Seconds / 10;
			Seconds %= 10;
		}
	}
	if (Seconds != 0) {
		cout << -1;
		return 0;
	}
	cout << A << " " << B << " " << C;

	return 0;
}