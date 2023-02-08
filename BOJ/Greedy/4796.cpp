//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//	int L, P, V;
//
//	int i = 1;
//	while(1) {
//		cin >> L;
//		cin >> P;
//		cin >> V;
//
//		if (!L&& !P&& !V)
//			break;
//
//		int temp = 0;
//		temp = (V / P)*L + min(V%P, L);
//		cout << "Case " << i << ": " << temp << "\n";
//		i++;
//	};
//	
//	return 0;
//}
//2023-02-08복습
/*
* 1.아이디어
* (틀린 아이디어)
* 휴가기간 V, 캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다.
* 총 사용가능 기간은 (V/P)*L + (V%P)이다
*
* (맞은 아이디어)
* 위의 아이디어가 틀린이유는 반례 5 8 22를 보면 알 수 있다.
* 22를 8로 나머지연산을 하면 6이 나오게 되는데 5일이 최대로 사용할 수 있는 기간이므로 5와 비교해서 더 작은 값을 더해야한다.
* 총 사용가능 기간은 (V/P)*L + (V%P)이다
* 2.시간복잡도
* O(1)
* 3.변수형
* int :
*/

#include <iostream>

using namespace std;

int main(void) {

	int i = 1;
	while (true) {
		int L, P, V;
		cin >> L >> P >> V;

		if (!L && !P && !V)
			break;

		cout << "Case " << i << ": " << (V / P) * L + min((V % P), L) << "\n";
		i++;
	}

	return 0;
}