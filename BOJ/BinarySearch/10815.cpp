/*
* 1.아이디어
* 단순반복으로 하면 시간복잡도가 O(NM)이 되는데 N,M <= 500000이므로 이분탐색(O(logN)을 사용한다.
* 
* 입력값을 정렬한다.
* 
* start와 end를 구한다.
* 확인할 숫자가 입력되면 해당 숫자를 기준으로 이분탐색을 해준다.
* 존재할경우 1 없을경우 0을 출력한다.
* 
* 2.시간복잡도
* O(NlogM), N,M <= 500000, 따라서 가능
* 3.변수형
* int
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	cin >> M;
	while (M--) {
		int target;
		cin >> target;

		int start = 0;
		int end = N - 1;
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (v[mid] == target) {
				cout << "1 ";
				break;
			}
			else if (v[mid] > target){
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		if (start > end)
			cout << "0 ";
	}

	return 0;
}