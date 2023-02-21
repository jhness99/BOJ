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
void BinarySearch(int start, int end, int target) {
	if (start > end) {
		cout << "0\n";
		return;
	}
	else {
		int mid = start + ((end - start) / 2);
		if (arr[mid] == target) {
			cout << "1\n";
			return;
		}
		else if (arr[mid] > target)
			return BinarySearch(start, mid - 1, target);
		else
			return BinarySearch(mid + 1, end, target);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int X;
		cin >> X;

		BinarySearch(0, N - 1, X);
	}

	return 0;
}