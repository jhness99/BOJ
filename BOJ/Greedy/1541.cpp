/*
* 1.최소로 만들기 위해선 -기호 이후의 수들을 전부 -로 해주면 된다.
* 예를 들어 40-20+30-40+20 의 경우도 40-(20+30)-(40+20) 로 해주면 되고 이는 40-20-30-40-20와 같다
* 즉,-이후의 수들을 전부 빼주면 되는것이다.
* 
* 2.시간복잡도
* 3.변수형
* 
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string str;
	int answer = 0;
	bool flag = false;
	cin >> str;

	string temp = "";
	for(int i = 0; i <= str.size(); i++){
		
		if (str[i] != '+' && str[i] != '-' && str[i] != '\0') {
			temp += str[i];
		}
		else {
			int num;
			num = stoi(temp);
			if (!flag) {
				answer += num;
			}
			else {
				answer -= num;
			}
			if (str[i] == '-')
				flag = true;

			temp = "";
		}
	}
	cout << answer;

	return 0;
}