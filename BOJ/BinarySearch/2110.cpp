/*
* 1.아이디어
* 최대거리가 10억, 집의 개수가 20만, 단순반복으로 푼다면 시간복잡도가 너무 오래걸리므로 이진탐색으로 접근한다.
* 
* 입력받은 집의 위치를 정렬한다
* 거리의 최대값과 최소값을 구한다. left = 1 최소값, right = house[n-1] - house[0] 최대값
* 얻은 left right로 mid(중간값)를 구한다.
* 모든 집을 순환하면서 집과 집의 거리를 확인하고 만약 mid보다 크다면 공유기 카운트를 1올리고 확인한 집을 기준으로
* 다시 mid보다 큰 거리가 나올때까지 확인하다가 더 큰 값이 나오면 위 과정을 반복한다.
* 반복이 끝난 후 공유기 카운트가 입력받은 공유기개수보다 작다면 right = mid - 1, 크다면 left = min + 1, answer = max(answer, mid)를 한다
* max로 answer를 갱신해주는 이유는 가장 인접한, 최대의 거리이기 때문에 공유기를 모두 설치하면서, 가장 인접하는 것 중에 최대의 값을 반환해야하기 때문이다.
* 위 로직이 left > right가 될 때까지 반복한다.
* 
* 2.시간복잡도
* 최대거리를 기준으로 이분탐색을 하므로 O(log10억) * 20만, 따라서 가능
* 3.변수형
* int
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	
	int N, C;
	cin >> N >> C;

	vector<int> house(N);	
	for (auto& i : house)
		cin >> i;

	sort(house.begin(), house.end());

	int left = 1;
	int right = house.back() - house[0];
	int answer = 0;

	while (left <= right) {
		int mid = (right + left) / 2;
		int Count = 1;

		int start = house[0];
		for(int i = 1; i < N; i++){
			if ((house[i] - start) >= mid) {
				Count++;
				start = house[i];
			}
		}
		if (Count < C)
			right = mid - 1;
		else {
			answer = max(answer, mid);
			left = mid + 1;
		}
	}
	cout << answer;
	
	return 0;
}