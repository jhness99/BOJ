#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);;
	int N, cnt = 0;
	cin >> N;

	vector<int> input(N), LIS;

	for (auto& i : input) {
		cin >> i;
	}

	LIS.push_back(input[0]);
	for (int i = 1; i < N; i++) {
		if (LIS.back() < input[i]) {
			LIS.push_back(input[i]);
			cnt++;
		}
		else {
			int start = 0;
			int end = LIS.size() - 1;
			int mid = end;
			while (start < end) {
				mid = (start + end) / 2;
				if (LIS[mid] < input[i])
					start = mid + 1;
				else
					end = mid;
			}
			LIS[end] = input[i];
		}
	}

	cout << cnt + 1 << "\n";

	return 0;
}z.