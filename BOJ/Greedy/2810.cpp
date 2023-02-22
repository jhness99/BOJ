//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//
//	int N;
//	int CntL = 0;
//	string str;
//	cin >> N;
//	cin >> str;
//
//	
//
//	for (auto& c : str) {
//		if (c == 'L')
//			CntL++;
//	}
//	
//	if (CntL != 0) {
//		N -= CntL/2 -1;
//	}
//	cout << N;
//
//	return 0;
//}
//2023-02-22 복습
/*
* 1.아이디어
* LL이 2개 일경우, 3개의 컵홀더가 필요하고 LL이 3개일경우 4개의 컵홀더가 생김
* 즉, 전체좌석 개수 - (커플석(LL)의 개수 -1)이 컵홀더의 갯수가 된다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int LLcnt = 0;

	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		if (temp == 'L')
			LLcnt++;
	}

	LLcnt /= 2;

	if (LLcnt == 0)
		cout << N;
	else
		cout << N - (LLcnt - 1);

	return 0;
}