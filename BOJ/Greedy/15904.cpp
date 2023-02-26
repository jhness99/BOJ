/*
* 1.아이디어
* string으로 문자열을 받아온다.
* 받아온 문자열에 UCPC가 순서대로 나오는지 체크
* 2.시간복잡도
* stirng의 길이만큼 탐색하므로 O(N), 따라서 가능
* 3.변수형
* string : 문자열을 받아와야하므로 string
*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//
//	char Check[] = { 'U', 'C', 'P', 'C' };
//	string str; 
//	getline(cin, str);
//	
//	int checkIdx = 0;
//	for (auto& c : str) {
//		if (c == Check[checkIdx] && checkIdx < 4) {
//			checkIdx++;
//		}
//		if (checkIdx == 4)
//			break;
//	}
//	if (checkIdx == 4)
//		cout << "I love UCPC";
//	else
//		cout << "I hate UCPC";
//
//	return 0;
//}
//2023-02-26 복습
/*
* 1.아이디어
* U,C,P,C를 배열에 저장, 문자열을 받아서 문자열을 순회, index = 0;
* 만약 문자열에 check[index] 가 나온다면, index 증가
* index가 4라면 i love UPCP, 4가 아니라면 I hate UPCP출력
*
* 2.시간복잡도
* O(N), N<=1000이므로 가능
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string str;
	char check[] = { 'U', 'C', 'P', 'C' };
	getline(cin, str);

	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == check[index])
			index++;

		if (index == 4)
			break;
	}

	if (index == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}