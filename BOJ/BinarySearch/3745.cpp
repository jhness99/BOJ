/*
* 1.아이디어
* LIS문제이다. 이때 길이가 최대 100000이기 때문에 DP로는 불가능, 즉 이분탐색을 사용해야 한다.
* 
* 이분탐색 LIS풀이법
* 첫 문자를 LIS백터에 넣고, 다음 숫자가 LIS백터의 가장 마지막 숫자보다 클 경우, push_back
* 만약 같거나 작을경우, 이분탐색을 사용해 자신과 같거나 큰 수 위치에 해당 수를 넣는다.
* 
* 2.시간복잡도
* 이분탐색을 N번 반복하므로 N*O(logN) O(NlogN), N<=100000 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	while (cin>>N) {
		vector<int> LIS;
		vector<int> input(N);
		for (auto& i : input)
			cin >> i;

		LIS.push_back(input[0]);
		for (int i = 1; i < N; i++) {
			if (LIS.back() < input[i])
				LIS.push_back(input[i]);
			else {
				int start = 0;
				int end = LIS.size() - 1;

				while (start < end) {
					int mid = (start + end) / 2;
					if (LIS[mid] >= input[i])
						end = mid;
					else
						start = mid + 1;
				}
				LIS[end] = input[i];
			}
		}

		cout << LIS.size() << "\n";
	}

	return 0;
}