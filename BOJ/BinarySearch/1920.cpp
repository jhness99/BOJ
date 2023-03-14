/*
* 1.아이디어
* 단순하게 하나하나 계산하면 O(NM), 100000*100000=10000000000이 되므로 불가능
* 
* 그러므로 이분탐색으로 계산
* 입력받은 수를 vector v에 저장해서 오름차순으로 정렬
* 존재하는지 확인할 X를 입력받으면,
* v의 가운데보다 X가 크다면 오른쪽, 아니라면 왼쪽으로 탐색
* 탐색하는 수가 중앙값이라면 1출력
* 만약 더이상 나눌수 없다면 0출력
* 2.시간복잡도
* 이분탐색을 사용했으므로 O(logN), 거기에 M번 하므로 O(MlogN), N,M<=100000이므로 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100000];

/*
* bool BinarySearch(int start, int end, int target) {
	if (start == end) {
		if (arr[start] == target)
			return true;
		return false;
	}
		
	
	int mid = start + ((end - start) / 2);
	if (arr[mid] == target)
		return true;
	else if (arr[mid] > target)
		return BinarySearch(start, mid - 1, target);
	else
		return BinarySearch(mid + 1, end, target);
}
틀린 함수
틀린이유
start 가 end 보다 커지는 경우를 생각하지 않음
따라서 무한루프가 돌게되서 시간초과가 나오게 됨
*/
//void BinarySearch(int start, int end, int target) {
//	if (start > end) {
//		cout << "0\n";
//		return;
//	}
//	else {
//		int mid = start + ((end - start) / 2);
//		if (arr[mid] == target) {
//			cout << "1\n";
//			return;
//		}
//		else if (arr[mid] > target)
//			return BinarySearch(start, mid - 1, target);
//		else
//			return BinarySearch(mid + 1, end, target);
//	}
//}
//
//int main(void) {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int N, M;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + N);
//
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		int X;
//		cin >> X;
//
//		BinarySearch(0, N - 1, X);
//	}
//
//	return 0;
//}
//2023-03-14 복습
/*
* 1.아이디어
* 모든 수를 count해주는 방법은 수의 범위가 -2^31 부터 2^31이라 너무 커서 안된다.
* 그렇다고 M개의 문자를 N번 확인하면 시간초과가 나오게 된다.
* 따라서 해당 문제는 이분탐색을 사용해야 한다.
*
* 우선 입력받은 배열을 정렬한다.
* 이분탐색을 사용해 0과 N-1로 start, end로 지정한다
* mid를 구해 가운대 값을 기준으로 A[mid]값이 입력된 값보다 더 클경우, end = mid - 1;
* 입력된 값이 더 클경우 start = mid + 1 한다
* 만약 A[mid]값이 입력된값과 같다면 1을 출력하고 해당 루프를 종료하고, 만약 찾이 못했다면 0을 출력한다.
* 2.시간복잡도
* O(NlogN) + O(MlogN) N,M<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;

	vector<int> A(N);
	for (auto& i : A)
		cin >> i;

	sort(A.begin(), A.end());

	cin >> M;

	while (M--) {
		int num;
		cin >> num;

		int start = 0;
		int end = N - 1;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (A[mid] > num)
				end = mid - 1;
			else if (A[mid] < num)
				start = mid + 1;
			else {
				cout << "1" << "\n";
				break;
			}
		}
		if (start > end)
			cout << "0" << "\n";
	}

	return 0;
}