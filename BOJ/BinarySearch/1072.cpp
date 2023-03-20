/*
* 1.아이디어
* x가 최대 10억이므로 1부터 10억 까지 단순확인하면 시간초과가 나온다.
* 따라서 이진탐색으로 접근해야한다.
* 
* 게임횟수와 이긴게임을 기준으로 승률 Z를 구한다.
* 만약 Z가 100과 같거나 크다면 -1출력
* 
* start = 1, end = 10억으로 초기화
* 중간값을 구하고 중간값만큼 게임을 진행했을 때의 승률을 계산
* 해당 승률이 기존 Z와 비교해서 크다면, 즉 변화가 있다면 end = mid - 1, mid를 answer 로 저장
* 같거나 더 작을경우, 즉 변화가 없다면 start = mid + 1
* start > end가 될 때까지 반복
* 2.시간복잡도
* 이진탐색을 사용했으므로 O(logN), 여기서 N<= 1000000000 이므로 가능,
* 3.변수형
*/
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	long long X, Y;
//	int answer = -1;
//	cin >> X >> Y;
//
//	int Z = Y * 100 / X ;
//
//	if (Z >= 100) {
//		cout << -1;
//		return 0;
//	}
//
//	int start = 1;
//	int end = 1000000000;
//
//	while (start <= end) {
//		int mid = (start + end) / 2;
//		int newZ = (100 * (Y + mid)) / (X + mid);
//
//		if (newZ > Z) {
//			answer = mid;
//			end = mid - 1;
//		}
//		else {
//			start = mid + 1;
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-20 복습
/*
* 1.아이디어
* 최대값이 10억, 따라서 완전탐색 불가능
* 따라서 이분탐색으로 접근한다. 이분탐색으로 접근할 시 start를 1, end를 10억으로 설정하고 탐색한다.
* 이분탐색을 하기 전에 z를 구해서 만약 100과 같거나 클 경우, -1을 출력한다.
* 이분탐색을 해서 mid를 구하고 mid만큼 이겼을 때의 확률을 구한다.
* 구한 확률이 기존 확률보다 작거나 같다면, start = mid +1,
* 구한 확률이 기존 확률보다 크다면, end = mid -1 ,answer= mid
* 이렇게 하는 이유는 우리는 초과하는 수를 찾아야 하기 때문이다. 초과하는 수중에서도 가장 먼저 나오는 것으로
*
*
* 2.시간복잡도
* X최대값이 10억이므로 O(logX). 따라서 가능
*
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int main(void) {

	long long X, Y;
	int	Z, answer = -1; // 100퍼이상이 아니더라도 불가능할경우도 있으므로 초기값 -1
	cin >> X >> Y;
	Z = Y * 100 / X;

	if (Z >= 100) {
		cout << -1;
		return 0;
	}

	int start = 1;
	int end = 1000000000;

	while (start <= end) {
		int mid = (start + end) / 2;
		int NewZ = (100 * (Y + mid)) / (X + mid);

		if (NewZ > Z) {
			end = mid - 1;
			answer = mid;
		}
		else {
			start = mid + 1;
		}
	}

	cout << answer;

	return 0;
}