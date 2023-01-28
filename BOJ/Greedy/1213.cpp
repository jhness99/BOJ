#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	string str;
	string answer = "";
	string reverseAnswer = "";
	char lastAlpha;
	int Odd_cnt = 0;
	char Odd_char;
	int Alphabet[26] = { 0, };

	cin >> str;

	for (auto& c : str) {
		Alphabet[c - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (Alphabet[i] == 0) continue;
		if (Alphabet[i] % 2 == 1) {
			Odd_cnt++;
			Odd_char = i + 'A';
		}
	}
	if (Odd_cnt >= 2) {
		cout << "I'm Sorry Hansoo" << endl;
		return 0;
	}

	for (int i = 0; i < 26; i++) {
		if (Alphabet[i] == 0) continue;
		int half = Alphabet[i] / 2;

		for (int j = 0; j < Alphabet[i] / 2; j++)
		{
			answer += (i + 'A');
		}
	}
	reverseAnswer = answer;
	reverse(reverseAnswer.begin(), reverseAnswer.end());

	if (Odd_cnt != 0) {
		answer += Odd_char;
	}

	answer += reverseAnswer;
	cout << answer << endl;
	return 0;
}