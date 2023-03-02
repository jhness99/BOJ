/*
* 1.아이디어
* 걸리는 시간순으로 오름차순 정렬하고
* 가장 빨리 걸리는 사람부터 먼저 인출하게 한다.
* 
* 정렬하고 이전에 걸린시간 + 자기시간해서 answer를 갱신해준다.
* 2.시간복잡도
* O(N) N<= 1000 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, answer = 0, sum = 0; //sum : 이전에 걸린시간들의 합
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		sum += v[i];
		answer += sum;
	}

	cout << answer;
	return 0;
}