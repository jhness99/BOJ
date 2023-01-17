/*
* 틀린이유
* 1. while의 조건문에서 달성해야할 S와 totalNum+i(여태 더해온 수 + 다음수)가 같을 때를 고려하지 않음
* 2. 자료형이 long long 형인데 int를 사용
*/
#include <iostream>

using namespace std;

int main(void) {

	long long S = 0;		//int 사용해서 오류남

	cin >> S;
	long long i = 1;		//int 사용해서 오류남
	int N = 0;
	long long totalNum = 0;
	while (totalNum + i <= S) {		//같을 경우 고려하지 않아 오류남
		N++;
		totalNum += i;
		i++;
	}

	cout << N;

	return 0;
}