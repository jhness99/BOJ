/*
* 쉬운문제였지만 까먹었던 개념을 정리한다.
* string의 경우는 문자열을 저장하는 타입인데
* char의 배열같이 사용할 수 있다.
* 이때 잘 생각해야하는데 문자열의 길이기 4면 string의 크기는 5이고
* 마지막은 '\0'로 되어있는데 그 부분도 엄연히 ' '으로 표현되므로
* 아래에 i가 lnput.length()-1까지 간다해도 i+1, 즉 input[input.length()]의 값을 가져올 수 있다
* 이 개념이 오랫만이라 햇갈려서 예외처리를 해주다 다시 찾아보고 정리한다.
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	int answer = 0;
	int cnt[2] = { 0, };
	string input = "";
	cin >> input;
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != input[i+1]) {
			cnt[input[i] - '0']++;
			/*
			if (input[i] == '0') {
				cnt[0]++;
			}
			else {
				cnt[1]++;
			}
			*/
		}
	}
	cout << min(cnt[0], cnt[1]);

	return 0;
}