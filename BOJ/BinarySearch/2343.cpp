/*
* 1.아이디어
* 강의수가 100000이므로 단순반복으로 불가능
* 따라서 이분탐색으로 접근
* 
* 입력값을 전부 더한값을 end, start= 1로 초기화
* 
* mid구하기
* 입력값을 처음부터 더하면서 sum+arr[i]가 mid를 넘을경우, cnt++, 
* 위 연산이 끝나고 cnt < M일 경우 cnt가 더 커저야 하므로, mid값을 줄이기 위해 end = mid - 1;
* cnt >= M 일경우 cnt가 줄어들어야 하므로 mid값을 키우기 위해 start = mid + 1, answer = mid
* left>right이 될 때까지 반복
* 
* 헷갈린 부분
* start를 입력의 최대값으로 설정해야한다. 그 이유는 블루레이가 각각 개별파일을 가질 때 가장 작을 수 있는 경우는 
* 입력중 가장 큰 값이1개 들어가는 상황을 고려했을때, 가장 큰 값이 블루레이 용량의 최솟값이라고 할 수 있다.
* 
* 2.시간복잡도
* O(Nlog(sum)), Sum <= 1000000000, N <= 100000 이므로 가능
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M, answer = 0;
//	cin >> N >> M;
//	
//	int start = 1;
//	int end = 0;
//	vector<int> input(N);
//	for (auto& i : input) {
//		cin >> i;
//		end += i;
//		start = max(start, i);
//	}
//
//	while (start <= end) {
//		int mid = (start + end) / 2;
//		int sum = 0;
//		int cnt = 1;
//		for (int i = 0; i < N; i++) {
//			if (mid < sum + input[i]) {
//				sum = 0;
//				cnt++;
//			}
//			sum += input[i];
//		}
//		if (M < cnt) {
//			start = mid + 1;
//		}
//		else {
//			end = mid - 1;
//			answer = mid;
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-22 복습
/*
* 1.아이디어
* 강의의 총 수는 10만개, 이를 순서대로 조합해서 나누기엔 너무 많이 고려해야한다.
* 따라서 이분탐색으로 접근한다.
* 이분탐색으로 할 때의 수는 블루레이를 넣을 수 있는최소의 용량,
* 즉, 강의들의 최대시간이 left, 모든 강의의 합이 right가 되야한다.
*
* right 와 left를 구하고 이분탐색을 진행해보자.
* mid를 만들고 total을 만들어 더했을 때 mid보다 커진다면, 종료하고 cnt를 올린다.
* cnt와 M을 비교해서 cnt가 더 클경우, left = mid + 1,
* cnt와 M을 비교해서 cnt가 같거나 작을경우, right = mid - 1, answer = mid;
* 2.시간복잡도
* 값의 최대가 1000000000이고 이분탐색을 한다. 해당 이분탐색에 N번 반복하는 반복문이 있으므로,
* O(Nlog10^9) N<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, M, answer = 0;
	cin >> N >> M;

	int left = 0;
	int right = 0;

	vector<int> input(N);
	for (auto& i : input) {
		cin >> i;
		right += i;
		left = max(left, i);
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		int total = 0;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (total + input[i] > mid) {
				total = input[i];
				cnt++;
			}
			else
				total += input[i];
		}

		if (M < cnt) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			answer = mid;
		}
	}

	cout << answer;

	return 0;
}