#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string str;
	string answer = "";
	cin >> str;

	int strSize = str.length();
	int prewChar;
	int stackX = 0;
	for (int i = 0; i < strSize; i++) {
		if (str[i] == 'X') 
			stackX++;

		if (str[i] == '.') {
			answer += '.';
			if (stackX % 2 != 0)
				break;
		}

		if (stackX == 2 && str[i+1] != 'X') {
			answer += "BB";
			stackX = 0;
		}
		else if (stackX == 4) {
			answer += "AAAA";
			stackX = 0;
		}	
	}

	if (stackX % 2 != 0) cout << -1;
	else cout << answer;

	return 0;
}
//2023-03-14 복습
/*
* 1.아이디어
* 입력한 문자열에서 .이나 빈공간이 나올때까지 진행해서 X가 나온수를 카운팅한다
* 만약 홀수거나 0이면 -1을 출력하고 아닐경우 4로 나눈 몫만큼 AAAA를 넣고 나머지만큼 BB를 넣는다.
*
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>

using namespace std;

int main(void) {

	string str;
	cin >> str;

	string answer;
	int Xcnt = 0;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == 'X')
			Xcnt++;
		else {
			while (true) {
				if (Xcnt % 2 != 0) {
					cout << -1;
					return 0;
				}
				if (Xcnt == 0)
					break;
				if (Xcnt / 4 != 0) {
					answer += "AAAA";
					Xcnt -= 4;
				}
				else {
					answer += "BB";
					Xcnt -= 2;
				}
			}
			if (str[i] == '.')
				answer += ".";
		}
	}

	if (answer.size() != 0)
		cout << answer;
	else
		cout << -1;

	return 0;
}