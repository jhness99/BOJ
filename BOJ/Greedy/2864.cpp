//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int main(void) {
//
//	string s1, s2;
//	int minNum = 0, maxNum = 0;
//	cin >> s1 >> s2;
//	
//	reverse(s1.begin(), s1.end());
//	reverse(s2.begin(), s2.end());
//
//	for (int i = 0; i < s1.length(); i++) {
//		if (s1[i] == '5') {
//			maxNum += 6 * pow(10, i);
//			minNum += 5 * pow(10, i);
//		}else if (s1[i] == '6') {
//			minNum += 5 * pow(10, i);
//			maxNum += 6 * pow(10, i);
//		}
//		else {
//			minNum += (s1[i] - '0') * pow(10, i);
//			maxNum += (s1[i] - '0') * pow(10, i);
//		}
//	}
//
//	for (int i = 0; i < s2.length(); i++) {
//		if (s2[i] == '5') {
//			maxNum += 6 * pow(10, i);
//			minNum += 5 * pow(10, i);
//		}
//		else if (s2[i] == '6') {
//			minNum += 5 * pow(10, i);
//			maxNum += 6 * pow(10, i);
//		}
//		else {
//			minNum += (s2[i] - '0') * pow(10, i);
//			maxNum += (s2[i] - '0') * pow(10, i);
//		}
//	}
//	cout << minNum << " " << maxNum;
//	return 0;
//}
//2023-02-10 복습
/*
* 1.아이디어
* 문자열로 받아와서 6을 5로 변환시킨 값을 더한것이 최소값, 5를 6으로 변환시킨 값을 더한값이 최대값으로 한다
* 2.시간복잡도
* O(N), 1000000이므로 N은 7 따라서 가능
* 3.변수형
* int :
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string str1;
	string str2;
	int Max = 0;
	int Min = 0;

	cin >> str1 >> str2;

	string temp1 = "";
	string temp2 = "";
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == '5')
			temp1 += '6';
		else
			temp1 += str1[i];
	}
	for (int i = 0; i < str2.length(); i++) {
		if (str2[i] == '5')
			temp2 += '6';
		else
			temp2 += str2[i];
	}
	Max = stoi(temp1) + stoi(temp2);
	temp1 = "";
	temp2 = "";

	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == '6')
			temp1 += '5';
		else
			temp1 += str1[i];
	}
	for (int i = 0; i < str2.length(); i++) {
		if (str2[i] == '6')
			temp2 += '5';
		else
			temp2 += str2[i];
	}
	Min = stoi(temp1) + stoi(temp2);

	cout << Min << " " << Max;

	return 0;
}