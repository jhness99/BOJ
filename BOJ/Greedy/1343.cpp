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