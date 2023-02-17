//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	string str;
//	string answer = "";
//	string reverseAnswer = "";
//	char lastAlpha;
//	int Odd_cnt = 0;
//	char Odd_char;
//	int Alphabet[26] = { 0, };
//
//	cin >> str;
//
//	for (auto& c : str) {
//		Alphabet[c - 'A']++;
//	}
//
//	for (int i = 0; i < 26; i++) {
//		if (Alphabet[i] == 0) continue;
//		if (Alphabet[i] % 2 == 1) {
//			Odd_cnt++;
//			Odd_char = i + 'A';
//		}
//	}
//	if (Odd_cnt >= 2) {
//		cout << "I'm Sorry Hansoo" << endl;
//		return 0;
//	}
//
//	for (int i = 0; i < 26; i++) {
//		if (Alphabet[i] == 0) continue;
//		int half = Alphabet[i] / 2;
//
//		for (int j = 0; j < Alphabet[i] / 2; j++)
//		{
//			answer += (i + 'A');
//		}
//	}
//	reverseAnswer = answer;
//	reverse(reverseAnswer.begin(), reverseAnswer.end());
//
//	if (Odd_cnt != 0) {
//		answer += Odd_char;
//	}
//
//	answer += reverseAnswer;
//	cout << answer << endl;
//	return 0;
//}
//2023-02-17 복습
/*
* 1.아이디어
* 입력받은 알파벳의 숫자를 구하는데, alpha[26]배열에 str[i]-'A'로 전부 int로 만들어서 저장
* 저장할 때 홀수개수만큼 있는 알파벳이 몇개나 있는지 확인, 그리고 가장 마지막에 나온 홀수개수만큼있는 알파벳 찾아냄
* 홀수개수 2개이상 있을경우 팰린드롬이 불가능하기때문에 I'm Sorry Hansoo 출력
* 홀수개수의 알파벳이 1개나 0개일경우, alpha의 절반만큼 해당 알파벳을 더한다.
* 그리고 마지막엔 홀수였던 알파벳을 넣어주고 그 다음엔 이전에 넣었던 알파벳을 역순으로 해주고 더해서 문자열을 만들어 준다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	int oddNum = 0;
	char oddChar;
	int alpha[26] = { 0, };
	string answer = "";
	string str;
	cin >> str;

	for (auto& c : str)
		alpha[c - 'A']++;


	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) continue;
		if (alpha[i] % 2 == 1) {
			oddNum++;
			oddChar = i + 'A';
		}
	}

	if (oddNum >= 2) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < alpha[i] / 2; j++)
			answer += ('A' + i);
	}
	string reverseStr = answer;
	reverse(reverseStr.begin(), reverseStr.end());

	if (oddNum)
		answer += oddChar;
	answer += reverseStr;

	cout << answer;

	return 0;
}