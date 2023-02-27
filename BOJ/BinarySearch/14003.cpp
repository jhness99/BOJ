#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);;
	int N, cnt = 0;
	cin >> N;

	vector<int> input(N), LIS;
	vector<pair<int, int>> check;
	for (auto& i : input) {
		cin >> i;
		check.push_back({ i, 0 });
	}

	LIS.push_back(input[0]);
	check[0].second = cnt;

	for (int i = 1; i < N; i++) {
		if (LIS.back() < input[i]) {
			LIS.push_back(input[i]);
			cnt++;
			check[i].second = cnt;
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
			check[i].second = end;
		}
	}

	cout << cnt + 1<< "\n";

	vector<int> answer;
	for (int i = N - 1; i >= 0; i--) {
		if (cnt == check[i].second) {
			answer.push_back(check[i].first);
			cnt--;
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}