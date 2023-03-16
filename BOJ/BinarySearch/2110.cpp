/*
* 1.아이디어
* 최대거리가 10억, 집의 개수가 20만, 단순반복으로 푼다면 시간복잡도가 너무 오래걸리므로 이진탐색으로 접근한다.
* 
* 입력받은 집의 위치를 정렬한다
* 거리의 최대값과 최소값을 구한다. left = 1 최소값, right = house[n-1] - house[0] 최대값
* 얻은 left right로 mid(중간값)를 구한다.
* 모든 집을 순환하면서 집과 집의 거리를 확인하고 만약 mid보다 크다면 공유기 카운트를 1올리고 확인한 집을 기준으로
* 다시 mid보다 큰 거리가 나올때까지 확인하다가 더 큰 값이 나오면 위 과정을 반복한다.
* 반복이 끝난 후 공유기 카운트가 입력받은 공유기개수보다 작다면 right = mid - 1, 크다면 left = min + 1, answer = max(answer, mid)를 한다
* max로 answer를 갱신해주는 이유는 가장 인접한, 최대의 거리이기 때문에 공유기를 모두 설치하면서, 가장 인접하는 것 중에 최대의 값을 반환해야하기 때문이다.
* 위 로직이 left > right가 될 때까지 반복한다.
* 
* 2.시간복잡도
* 최대거리를 기준으로 이분탐색을 하므로 O(log10억) * 20만, 따라서 가능
* 3.변수형
* int
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	
//	int N, C;
//	cin >> N >> C;
//
//	vector<int> house(N);	
//	for (auto& i : house)
//		cin >> i;
//
//	sort(house.begin(), house.end());
//
//	int left = 1;
//	int right = house.back() - house[0];
//	int answer = 0;
//
//	while (left <= right) {
//		int mid = (right + left) / 2;
//		int Count = 1;
//
//		int start = house[0];
//		for(int i = 1; i < N; i++){
//			if ((house[i] - start) >= mid) {
//				Count++;
//				start = house[i];
//			}
//		}
//		if (Count < C)
//			right = mid - 1;
//		else {
//			answer = max(answer, mid);
//			left = mid + 1;
//		}
//	}
//	cout << answer;
//	
//	return 0;
//}
//2023-03-16 복습
/*
* 1.아이디어
* 공유기 사이의 거리가 최대 10억이므로 10억을 모두 카운트 하면 시간초과가 생기기 때문에 이분탐색으로 접근
*
* 먼저 입력값을 정렬한다.
* 이분탐색을 하기위해 mid를 구한다.
* 그리고 정렬된 입력값 가장 첫번째부터 시작해서 다음 집까지의 거리가 mid보다 작을경우 무시하고
* 시작부터 그 다음집의 거리를 본다. 만약 해당 거리가 mid와 같거나 큰 경우, 그 위치에 공유기를 설치하고 +1해준다.
* 설치할 수 있는 공유기의 총 개수가 제공되는 공유기 개수와 같거나 많을경우, start = mid + 1, answer =  mid;
* 만약 공유기의 개수가 제공되는 공유기의 개수보다 작을경우, end = mid - 1;
*
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C, answer = 0;
	cin >> N >> C;

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	int left = 0;
	int right = input.back() - input.front();

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;

		int start = input.front();
		for (int i = 1; i < N; i++) {
			if (input[i] - start >= mid) {
				start = input[i];
				cnt++;
			}
		}
		if (cnt < C)
			right = mid - 1;
		else {
			answer = mid;
			left = mid + 1;
		}
	}
	cout << answer;

	return 0;
}