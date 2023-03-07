/*
* 1.아이디어
* LIS문제지만 N이 100000이기때문에 dp로 구현하면 시간복잡도가 O(N^2)이므로 불가능
* 따라서 이분탐색으로 접근
* 
* 이분탐색을 이용한 LIS구현방법
* 숫자가 오름차순이어야 하므로 첫번째를 제외한 모든 수를 확인할때는 
* 수열의 마지막 숫자보다 확인하는 수가 더 클 경우, 뒤에 붙여준다.
*
* 만약 뒤의 수보다 작거나 같다면 이분탐색을 해서 탐색하는 수보다 같거나 큰 수랑 교체한다.
* 연산이 끝난후 해당 길이가 연결된 전선의 길이이므로 전체길이 - LIS의 길이가 답이된다.
* 
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N;
	cin >> N;

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
			int mid = 0;
			while (start <= end) {
				mid = (start + end) / 2;
				if (input[i] <= LIS[mid]) {	
					end = mid - 1;
				}
				else
					start = mid + 1;
			}
			LIS[start] = input[i];
		}
	}

	cout << N - LIS.size();

	return 0;
}