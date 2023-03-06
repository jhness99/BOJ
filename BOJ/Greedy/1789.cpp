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
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	long long S; int N = 0;
//	cin >> S;
//
//	long long temp = 0;
//	long long num = 1;
//	while (true) {
//		if (temp > S)
//			break;
//		temp += num++;
//		N++;
//	}
//	cout << N - 1;
//
//	return 0;
//}
//2023-03-06 복습
/*
* 1.아이디어
* 가장 많은 수가 더해저야 하므로 1부터 시작
* sum에 누적합을 구해주다가 S와 비교해서 더 커진다면, 거기서 종료하고 마지막으로 더한 index를 출력
*
* 이때 200은 19까지 더했을때 190인데 왜 답이 19이냐면 19가 더해지는게 아니라 그 차레에 29가 더해져서 200을 완성하게 됨.
* 즉, 200을 초과하는 시점-1이 더해지는 숫자의 최대개수인것이다.
*
* 2.시간복잡도
* O(N) 따라서 가능
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int main(void) {

	long long S;
	cin >> S;

	long long i = 1;
	long long sum = 0;
	while (true) {
		if (sum + i > S) {
			cout << i - 1;
			return 0;
		}
		sum += i;
		i++;
	}

	return 0;
}