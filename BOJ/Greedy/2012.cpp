/*
* 1.아이디어
* 예상등수를 오름차순 정렬
* 예상등수와 해당 위치의 index의 차의 절대값을 불만도에 더해준다.
* 2.시간복잡도
* 정렬을 사용하므로 O(NlogN), N <= 500,000 이므로 가능
* 3.변수형
* long long : 최대 N-1의 값이 N번 더해지므로 N^2 따라서 long long
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	long long answer = 0;
	cin >> N;
	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		answer += abs(v[i] - (i + 1));
	}
	cout << answer;

	return 0;
}