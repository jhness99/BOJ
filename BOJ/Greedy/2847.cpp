#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	
	int N;
	int cnt = 0;
	cin >> N;
	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	for (int i = N-1; i >= 1; i--) {
		if (v[i] <= v[i - 1]) {
			cnt += v[i - 1] - v[i] + 1;
			v[i - 1] = v[i] - 1;
		}
	}

	cout << cnt;
	return 0;
}