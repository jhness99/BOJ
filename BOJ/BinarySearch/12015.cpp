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
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);;
//	int N, cnt = 1;
//	cin >> N;
//
//	vector<int> input(N), LIS;
//	
//	for (auto& i : input)
//		cin >> i;
//
//	LIS.push_back(input[0]);
//	for (int i = 1; i < N; i++) {
//		if (LIS.back() < input[i]) {
//			LIS.push_back(input[i]);
//			cnt++;
//		}
//		else {
//			int start = 0;
//			int end = LIS.size() - 1;
//			int mid = end;
//			while (start < end) {
//				mid = (start + end) / 2;
//				if (LIS[mid] < input[i])
//					start = mid + 1;
//				else
//					end = mid;
//			}
//			LIS[mid] = input[i];
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}
//2023-03-17 복습
/*
* 1.아이디어
* LIS문제인데 수열의 크기가 100만이므로 dp로 구현하기는 불가능. 따라서 이분탐색으로 접근한다.
*
* LIS 이분탐색으로 구현
* LIS 백터를 만들어 해당 백터를 갱신하면서 최대길이를 찾을 것이다.
* 먼저 가장 첫번째 수를 LIS 백터에 push_back을 한다.
* 다음 수부터 확인하면서 LIS백터의 back()보다 크다면, push_back 작다면 이분탐색으로 위치를 찾아 LIS를 갱신해준다.
*
* 우리가 찾아야 하는 것은 확인하는 수와 같거나 큰 수중 가장 먼저나오는 수다. 해당 수는 lower_bound로도 찾을 수 있다.
* 해당 수를 찾는 이분탐색은 left = 0, right = LIS.size()로 설정하고 mid를 만든다.
* LIS[mid]의 값이 내가 확인하는 값과 같거나 큰 경우, right = mid - 1;
* LIS[mid]의 값이 내가 확인하는 값보다 작을경우, left = mid + 1, index = mid
* LIS[index] = arr[i]로 갱신해주면 된다.
*
* 2.시간복잡도
* 이분탐색을 사용했으므로 O(logN) N번 반복하므로 O(NlogN) 따라서 가능
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
			int left = 0;
			int right = LIS.size() - 1;
			int index = 0;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (LIS[mid] < input[i]) {
					left = mid + 1;
				}
				else {
					index = mid;
					right = mid - 1;
				}
			}
			LIS[index] = input[i];
		}
	}

	cout << LIS.size();

	return 0;
}