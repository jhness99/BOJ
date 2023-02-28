/*
* 1.아이디어
* 정렬해서 첫번째부터 자신의 길이와 같거나 작다면 계속 진행하고 자신의 길이 +1
* 만약 더 크다면 break로 나온다.
* 2.시간복잡도
* 정렬을 사용하므로 O(NlogN), N<= 1000
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, L;
	cin >> N >> L;

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	for (int i = 0; i < N; i++) {
		if (input[i] > L)
			break;
		else
			L++;
	}
	cout << L;

	return 0;
}