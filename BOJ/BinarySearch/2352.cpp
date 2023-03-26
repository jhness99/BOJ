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
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	vector<int> input(N);
//	vector<int> LIS;
//	for (auto& i : input)
//		cin >> i;
//
//	int left = 0;
//	int right = N - 1;
//	
//	LIS.push_back(input[0]);
//	for (int i = 1; i < N; i++) {
//		if (LIS.back() < input[i]) {
//			LIS.push_back(input[i]);
//		}
//		else {
//			int index = 0;
//			while (left <= right) {
//				int mid = (left + right) / 2;
//				if (LIS[mid] < input[i])
//					left = mid + 1;
//				else {
//					right = mid - 1;
//					index = mid;
//				}
//			}
//			LIS[index] = input[i];
//		}
//	}
//
//	return 0;
//}
//2023-03-26 복습
/*
* 1.아이디어
* 가장 긴 증가하는 부분수열을 찾으면 된다.
* 그 이유는 겹치지 않아야 하므로 다음 포트보다 작아야 하기 때문에 LIS라고 할 수 있다.
*
* LIS의 길이를 구하면 되는데 주어지는 값이 40000인데 dp로 풀게되면 O(N^2)이므로 불가능하다.
* 따라서 이분탐색으로 LIS를 풀어주면 된다.
*
* LIS로 이분탐색을 하는방법은 다음과 같다.
* 가장 첫번째 수를 LIS에 push_back 해주고
* 그 다음부터는 LIS의 back보다 input[i]가 클 때 push_back,
* 같거나 작다면, 이분탐색을 사용해 input[i]의 lower_bound에 넣는다.
*
* left와 right는 각각 0, LIS.size()-1로 설정
* mid를 구해 LIS[mid]와 input[i]를 비교
* LIS[mid] < input[i] left = mid + 1
* LIS[mid] >= input[i] right = mid -1, index = mid;
* Lis[index] = input[i];
*
* 2.시간복잡도
* N번 반복해서 이분탐색을 하므로 O(NlogN) N<=40000, 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, answer = 1;
	cin >> N;

	vector<int> LIS;
	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	LIS.push_back(input[0]);
	for (int i = 1; i < N; i++) {
		if (LIS.back() < input[i]) {
			LIS.push_back(input[i]);
			answer++;
		}
		else {
			int left = 0;
			int right = LIS.size() - 1;
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

	cout << answer;

	return 0;
}