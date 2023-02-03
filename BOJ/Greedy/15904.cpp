/*
* 1.아이디어
* string으로 문자열을 받아온다.
* 받아온 문자열에 UCPC가 순서대로 나오는지 체크
* 2.시간복잡도
* stirng의 길이만큼 탐색하므로 O(N), 따라서 가능
* 3.변수형
* string : 문자열을 받아와야하므로 string
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	char Check[] = { 'U', 'C', 'P', 'C' };
	string str; 
	getline(cin, str);
	
	int checkIdx = 0;
	for (auto& c : str) {
		if (c == Check[checkIdx] && checkIdx < 4) {
			checkIdx++;
		}
		if (checkIdx == 4)
			break;
	}
	if (checkIdx == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}