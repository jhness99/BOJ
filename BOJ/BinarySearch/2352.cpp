/*
* 1.아이디어
*  포트를 연결할 때 겹치는 선이 있어서는 안된다. 그러기 위해서는 이전에 이은 선 보다 자신이 더 커야한다.
* 이것은 LIS 가장 긴 증가하는 수열이라고 생각할 수 있다.
* 따라서 LIS처럼 풀면 된다. 하지만 N<=40000 이므로 dp의 시간복잡도 O(N^2)로 불가능하다. 따라서 이분탐색으로 접근한다.
* 
* LIS 이분탐색으로 풀기
* 첫번째 수를 먼저 LIS백터에 넣고 다음 수부터 확인한다.
* 만약 가장 마지막 수보다 크면 push_back하고
* 더 작을경우 이분탐색으로 LIS의 수 중에 확인하고 가장 먼저 확인하는 수와 같거나 큰 수의 위치에 확인하는 수를 넣는다.
* 
* 2.시간복잡도
* O(NlogN), N<=40000, 따라서 가능
* 
* 3.변수형
* 
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<int> input(N);
	vector<int> LIS;
	for (auto& i : input)
		cin >> i;

	int left = 0;
	int right = N - 1;
	
	LIS.push_back(input[0]);
	for (int i = 1; i < N; i++) {
		if (LIS.back() < input[i]) {
			LIS.push_back(input[i]);
		}
		else {
			int index = 0;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (LIS[mid] < input[i])
					left = mid + 1;
				else {
					right = mid - 1;
					index = mid;
				}
			}
			LIS[index] = input[i];
		}
	}

	return 0;
}