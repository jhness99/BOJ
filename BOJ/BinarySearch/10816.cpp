/*
* 1.아이디어
* 해시맵을 사용한다. 입력값이 나온 횟수를 해시맵에 저장한다.
* 해시맵을 입력받은 값으로 출력한다.
* 
* 이분탐색
* 
* 2.시간복잡도
* 해시맵의 시간복잡도는 O(1), N<=500000, M<= 500000
* 3.변수형
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	int temp;
	cin >> N;

	vector<int> v(N);

	for (auto& i : v)
		cin >> i;
	
	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;

		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << " ";
	}

	/*
	unordered_map<int, int> hm;

	for (int i = 0; i < N; i++) {

		cin >> temp;
		if (hm.find(temp) != hm.end())
			hm[temp]++;
		else
			hm.insert({ temp, 1 });
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (hm.find(temp) != hm.end())
			cout << hm[temp];
		else
			cout << 0;
		cout << " ";
	}*/

	return 0;
}