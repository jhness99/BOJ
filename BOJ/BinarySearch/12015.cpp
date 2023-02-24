/*
* 1.아이디어
* 입력이 100만이므로 DP를 사용한 방법은 시간복잡도가 O(N^2)이므로 불가능 
* 따라서 이분탐색으로 접근해야함
* 
* 이분탐색을 사용하기 위해서 정렬을 할 필요가 있지만, LIS 오름차순이기 때문에 정렬은 필요없다.
* 
* 입력받은 수를 하나하나 저장하는데, 이때 입력된 값이 맨 뒤의 값보다 크다면 그냥 넣고 cnt++를 한다.
* 만약 입력된 값이 맨 뒤의 값보다 같거나 작다면, 입력받은 값보다 크고 가장 앞에있는 수를 찾는다.
* 해당 수의 위치에 입력된 값을 넣는다.
* 2.시간복잡도
* 이분탐색의 시간복잡도 O(logN) * O(N) = O(NlogN), N<=1000000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);;
	int N, cnt = 1;
	cin >> N;

	vector<int> input(N), LIS;
	
	for (auto& i : input)
		cin >> i;

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
			LIS[mid] = input[i];
		}
	}
	cout << cnt;

	return 0;
}