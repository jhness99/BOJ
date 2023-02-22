/*
* 1.아이디어
* 입력받은 String을 char하나씩 stack에 넣는다.
* 만약 A가 나왔고, A의 다음이 P라면, 스택을 4번 pop해서 나온 문자가 ppap인지 확인한다.
* 만약 ppap가 나왔다면 스택에 p를 넣어준다.
* 
* 끝난후, stack에 p가 단 한개 존재한다면 ppap 아니면 np이다.
* 
* 아이디어는 맞았으나 더욱 편하게 할 수 있다.
* 첫번째는 따로 deque를 만들지말고 str에서 처리를 해주는 것이다.
* 두번째는 p의 갯수를 기준으로 A가 나왔을 때 p의개수가 2개이상이고 다음문자가 P라면, PPAP가 완성된것이므로 p를 1개 줄여주고
* 그 다음 위치부터 확인한다. 끝난후에 P가 1일경우, PPAP이다.
* 2. 시간복잡도
* 문자열의 길이가 1000000이 최대이므로 O(N), 따라서 가능
* 3.변수형
*/
#include <iostream>

using namespace std;

int main(void) {

	string str;
	cin >> str;

	int pCount = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'P') {
			pCount++;
			continue;
		}
		if (pCount >= 2 && str[i + 1] == 'P') {
			i++;
			pCount--;
		}
		else {
			cout << "NP";
			return 0;
		}
		
	}

	if (pCount == 1) {
		cout << "PPAP\n";
	}
	else {
		cout << "NP\n";
	}
	
	return 0;
}