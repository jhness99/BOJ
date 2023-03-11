/*
* 1.아이디어
* 과자의 길이가 최대 10억이므로 1부터 10억까지 다 확인하기에는 시간이 부족하다.
* 따라서 이분탐색을 사용하면된다.
* 1과 가장 긴 막대를 각각 start, end로 지정하고 이분탐색을 시작한다
* 두 거리의 중간인 mid로 모든 막대를 나누어서 나오는 몫을 저장한다.
* 이 값이 mid값으로 막대를 나누어줬을 때 줄 수 있는 막대과자의 수이다.
* 이 값이 조카의 수와 같거나 적다면, end = mid - 1, answer = mid;
* 이 값이 조카의 수보다 크다면, start = mid + 1;
* 
* 2.시간복잡도
* O(NlogL) L<=1000000000 N<=1000000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, answer = 0;
	cin >> M >> N;
	
	int Max = -1;
	vector<int> snack(N);
	for (auto& i : snack) {
		cin >> i;
		Max = max(Max, i);
	}
		

	int start = 1;
	int end = Max; // 정렬되있는줄 알아서 snack.back()으로 썻다.

	while (start <= end) {
		int mid = (start + end) / 2;
		long long total = 0;
		for (int i = 0; i < N; i++) {
			total += snack[i] / mid;
		}
		if (total >= M) {
			start = mid + 1;
			answer = mid;
		}
		else
			end = mid - 1;
			
	}

	cout << answer;

	return 0;
}