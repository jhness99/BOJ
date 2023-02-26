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
#include <iostream>

using namespace std;

int main(void) {

	long long X, Y;
	int answer = -1;
	cin >> X >> Y;

	int Z = Y * 100 / X ;

	if (Z >= 100) {
		cout << -1;
		return 0;
	}

	int start = 1;
	int end = 1000000000;

	while (start <= end) {
		int mid = (start + end) / 2;
		int newZ = (100 * (Y + mid)) / (X + mid);

		if (newZ > Z) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << answer;

	return 0;
}