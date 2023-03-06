//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	int A = 0, B = 0, C = 0;
//	int Seconds = 0;
//
//	cin >> Seconds;
//
//	while (Seconds > 9) {
//		if (Seconds >= 300) {
//			A += Seconds / 300;
//			Seconds %= 300;
//		}
//		else if (Seconds >= 60) {
//			B += Seconds / 60;
//			Seconds %= 60;
//		}
//		else if (Seconds >= 10) {
//			C += Seconds / 10;
//			Seconds %= 10;
//		}
//	}
//	if (Seconds != 0) {
//		cout << -1;
//		return 0;
//	}
//	cout << A << " " << B << " " << C;
//
//	return 0;
//}

//2023-02-01 복습
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	int A = 0, B = 0, C = 0;
//
//	int T;
//	cin >> T;
//
//	A = T / 300;
//	B = (T % 300) / 60;
//	C = (T % 60) / 10;
//
//	if (T % 10 != 0)
//		cout << -1;
//	else
//		cout << A << " " << B << " " << C;
//
//	return 0;
//}
//2023-03-06 복습
/*
* 1.아이디어
* 단순한 그리디 문제이다
* 300 60 10으로 나눠서 나온 몫을 저장하고 이전에 한 연산의 나머지로 연속으로 다시 나누면 끝
*/
#include <iostream>

using namespace std;

int main(void) {

	int timer[] = { 300,60,10 };
	int T;
	cin >> T;

	int Count[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++) {
		Count[i] = T / timer[i];
		T %= timer[i];
	}
	if (T != 0)
		cout << -1;
	else
		for (auto& i : Count)
			cout << i << " ";

	return 0;
}