/*
* 1.아이디어
* 주변 집과의 거리들의 합이 가장 작은 집의 위치를 찾는 문제
* 따라서 오름차순으로 정렬하고 그 가운데의 위치하면 모든 집과의 거리가 가장 짧게됨
* 2.시간복잡도
* sort정렬을 사용하므로 O(NlogN) , N <= 200,000 이므로, O(NlogN) 은 약 3500000이다.
* 3.변수형
* vector<int> : N크기의 배열
*/
/*
* 문제풀이
* 모든 위치의 집과의 거리가 가장 짧으려면 중앙에 있어야 하므로 중앙값을 찾으면 되는 문제였다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	
	int N;
	cin >> N;

	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	cout << v[(v.size() % 2 == 0 ? v.size() / 2 - 1 : v.size() / 2)];

	return 0;
}