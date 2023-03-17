/*
* 1.아이디어
* 단순계산으로 하려면 총 예산값을 기준으로 지방수만큼 반복해야하므로 O(NM) N<=10000,M<=1000000000 이므로 불가능
* 따라서 이분탐색으로 접근해야함
* 
* 입력한 지방의 예산의 최대값을 구해서 1부터 최대값까지를 기준으로 이분탐색을 한다.
* start end mid로 이분탐색 기초를 만든 후 mid와 각 지방의 예산을 비교해서 만약 mid가 같거나 크다면, 예산만큼 total에 더하고
* 만약 mid가 더 작다면, mid만큼 total에 더한다. total이 M보다 크다면, end = mid - 1, total이 M보다 작다면, start = mid + 1, answer = mid;
* 
* start > end 가 될 때까지 반복한다. 
* 2.시간복잡도
* O(NlogM), N<=10000,M<=1000000000 이므로 가능
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M, Max = -1, answer = 0;
//	cin >> N;
//
//	vector<int> v(N);
//	for (auto& i : v) {
//		cin >> i;
//		Max = max(Max, i);
//	}
//		
//	cin >> M;
//
//	int start = 1;
//	int end = Max;
//	while (start <= end) {
//		int mid = (start + end) / 2;
//		int total = 0;
//		for (int i = 0; i < N; i++) {
//			if (v[i] > mid)
//				total += mid;
//			else
//				total += v[i];
//		}
//		if (total > M)
//			end = mid - 1;
//		else {
//			start = mid + 1;
//			answer = mid;
//		}
//	}
//	cout << answer;
//
//	return 0;
//}
//2023-03-17 복습
/*
* 1.아이디어
* 단순계산으로 하려면 총 예산값을 기준으로 지방수만큼 반복해야하므로 O(NM) N<=10000,M<=1000000000 이므로 불가능
* 이분탐색으로 접근한다.
* 입력값중 최대값을 right 1을 left로 해서 이분탐색을 한다.
* 이때 mid를 구하고 mid값보다 필요한 예산이 더 적으면, 해당 예산을 전부 더하고
* 만약 mid보다 크다면, mid를 total에 더해준다.
* 나온 total과 M을 비교해서, total이 M보다 크댜면, end = mid - 1,
* total이 M과 같거나 작다면, start = mid + 1; answer = mid;
* 2.시간복잡도
* 이분탐색을 사용하면 O(logMax), 해당 이분탐색 안에서 N번만큼 반복하므로, O(NlogMax) N<=10000, Max <=100000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, answer = 0;
	cin >> N;

	int Max = -1;
	vector<int> input(N);
	for (auto& i : input) {
		cin >> i;
		Max = max(Max, i);
	}

	cin >> M;

	int left = 1;
	int right = Max;

	while (left <= right) {
		int mid = (left + right) / 2;
		int total = 0;
		for (int i = 0; i < N; i++) {
			if (input[i] > mid)
				total += mid;
			else
				total += input[i];
		}
		if (total > M)
			right = mid - 1;
		else {
			left = mid + 1;
			answer = mid;
		}
	}

	cout << answer;

	return 0;
}