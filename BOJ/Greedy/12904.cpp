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
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	string S;
//	string T;
//	int answer = 0;
//	cin >> S >> T;
//
//	/*
//	* 틀린답
//	while (S.length() <= T.length()) {
//		S += 'A';
//		if (S == T) {
//			cout << 1;
//			return 0;
//		}
//		reverse(S.begin(), S.end());
//		S += 'B';
//		if (S == T) {
//			cout << 1;
//			return 0;
//		}
//	}
//	cout << 0;
//	return 0;
//	*/
//
//	while (1) {
//		
//		//만약 S와 T가 길이가 같은데 같다면 1 다르다면 초기화값(0)
//		if (S.length() == T.length()) {
//			if (S == T)
//				answer = 1;
//			break;
//		}
//
//		//만약 마지막이 A일경우, 즉 1번연산이 바로직전에 끝났을 경우
//		if (T.back() == 'A') {
//			T.pop_back();
//		}
//		//만약 마지막이 B일경우, 즉 2번연산이 바로 직전에 끝났을 경우
//		else {
//			T.pop_back();
//			reverse(T.begin(), T.end());
//		}
//	}
//	cout << answer;
//	return 0;
//}
//2023-02-22 복습
/*
* 1.아이디어
* 1번연산과 2번연산은 각각 해당 연산을 수행하고 나면 뒤에 A, B가 있게 된다.
* 따라서 문자열을 받았을 때 뒤의 문자를 보면 무슨 연산을 했는 지 알 수 있다는 것이다.
* A가 뒤라면 1번연산을 반대로 해주고 B가 뒤라면 2번연산을 반대로 해준다.
* 2.시간복잡도
* O(T), T<=1000, 따라서 가능
* 3.변수형
*/
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	string S, T;
//	int answer = 0;
//	cin >> S >> T;
//
//	while (true) {
//		if (S.size() == T.size()) {
//			if (S == T)
//				answer = 1;
//			break;
//		}
//		if (T.back() == 'A') {
//			T.pop_back();
//		}
//		else {
//			T.pop_back();
//			reverse(T.begin(), T.end());
//		}
//	}
//	cout << answer;
//
//	return 0;
//}
//2023-03-15 복습
/*
* 1.아이디어
* 2가지의 연산이 있다. 이제 해당 문자열의 가능한 조건을 파악해서 역순으로 하다가 원하는 문자열이 나온다면 종료해주면 된다.
* 이때 2가지의 연산은 구분이 가능하다. 구분하는 방법은 1번연산은 A가 뒤에 붙고 2번연산은 마지막에 B가 붙는다.
* 즉, 주어진 문자열의 맨 뒤가 어떤 문자인지 보고 해당 문자로 몇번연산을 했는지 역순으로 생각해
* 해당 연산을 반대로 해주면 되는것이다.
* 예를 들어 ABBA의 경우 A가 마지막에 있으므로 1번 연산을 한 것이라고 추측할 수 있고 1번 연산을 역순으로 해주면
* ABB가 된다. 여기서는 B가 마지막에 있으므로 2번 연산을 한 것이라고 추축할 수 있고 2번연산을 역순으로 해주면 BA가 된다
* BA는 A가 뒤에 있으므로 1번연산을 해주고 그러면 B가 나온다. 따라서 해당문자열은 B를 만들수 있다.
*
* 2.시간복잡도
* O(N) N<=1000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	string str1;
	string str2;

	cin >> str1 >> str2;

	while (!str2.empty()) {
		if (str1 == str2) {
			cout << 1;
			return 0;
		}
		if (str2.back() == 'A')
			str2.pop_back();
		else if (str2.back() == 'B') {
			str2.pop_back();
			reverse(str2.begin(), str2.end());
		}
	}
	cout << 0;

	return 0;
}