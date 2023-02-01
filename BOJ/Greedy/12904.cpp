/*
* 문제풀이
* 구현자체는 쉬운문제이나 발상이 어려웠다. 애초에 문제를 잘못 이해했는데, 
* 문자열에 A를 붙이는 연산과 문자열을 뒤집고 B를 붙이는 연산을
* 둘 다 순서대로 무조건 해야되는줄 알았다. 사실 둘 중 하나를 선택해서 하는 것이므로 아에 틀린 생각이였다.
* 결국 찾아본 결과 역으로 T에서 S로 가는 연산을 하면된다. 하지만 2개의 연산중 어떤것을 역으로 하면서
* 돌아가야 될지 햇갈릴 수 있지만, 사실 2개의 연산이 나오는 경우는 한정되어있다.
* 왜냐하면 1번연산이 끝나면 무조건 A가 마지막에 있어야하고 2번째 연산이 끝나면 무조건 B가 마지막에 있어야한다.
* 따라서 마지막에 있는 알파벳을 보고 바로 직전에 무슨 연산을 했는지 추리 해낼수 있고, 이를 이용해 역으로 연산해서 
* S가 나오는지 안나오는지를 확인하면 되는 문제였다.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string S;
	string T;
	int answer = 0;
	cin >> S >> T;

	/*
	* 틀린답
	while (S.length() <= T.length()) {
		S += 'A';
		if (S == T) {
			cout << 1;
			return 0;
		}
		reverse(S.begin(), S.end());
		S += 'B';
		if (S == T) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
	*/

	while (1) {
		
		//만약 S와 T가 길이가 같은데 같다면 1 다르다면 초기화값(0)
		if (S.length() == T.length()) {
			if (S == T)
				answer = 1;
			break;
		}

		//만약 마지막이 A일경우, 즉 1번연산이 바로직전에 끝났을 경우
		if (T.back() == 'A') {
			T.pop_back();
		}
		//만약 마지막이 B일경우, 즉 2번연산이 바로 직전에 끝났을 경우
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	cout << answer;
	return 0;
}