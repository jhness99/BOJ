/*
* 틀린이유
* 1. while의 조건문에서 달성해야할 S와 totalNum+i(여태 더해온 수 + 다음수)가 같을 때를 고려하지 않음
* 2. 자료형이 long long 형인데 int를 사용
*/
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	long long S = 0;		//int 사용해서 오류남
//
//	cin >> S;
//	long long i = 1;		//int 사용해서 오류남
//	int N = 0;
//	long long totalNum = 0;
//	while (totalNum + i <= S) {		//같을 경우 고려하지 않아 오류남
//		N++;
//		totalNum += i;
//		i++;
//	}
//
//	cout << N;
//
//	return 0;
//}

//2023-02-01 복습
/*
* 문제풀이
* 놀랍게도 같은 이유로 또 틀렸다.
* long long 을 안 사용했고, temp와 S가 같을 때를 고려하지 않았다.
*/
#include <iostream>

using namespace std;

int main(void) {

	long long S; int N = 0;
	cin >> S;

	long long temp = 0;
	long long num = 1;
	while (true) {
		if (temp > S)
			break;
		temp += num++;
		N++;
	}
	cout << N - 1;

	return 0;
}