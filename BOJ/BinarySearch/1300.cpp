/*
* 1.아이디어
* 최대 100000x100000 크기의 배열이 만들어질 수 있으므로 단순하게 배열을 구현해서 확인하는 방법은 불가능
* 따라서 이진탐색으로 접근
* 
* 1~N*N까지의 숫자가 나오는데 그 중 K번째 수를 찾아야 한다.
* 오름차순으로 정렬한 후 K번째이므로, K번째 수는 K-1보다 큰 가장 작은 수라는 뜻이 된다.
* 따라서 배열의 각 행에서 1, N*N 중간값보다 작은 값의 수를 새서 만약 K보다 적다면, start = mid + 1 로 mid를 키우고,
* K보다 중간값보다 작은 값의 수가 같거나 많다면, end = mid - 1, answer = mid;
* 
* 2.시간복잡도
* N번 반복하는 이진탐색을 사용하므로 O(NlogN) N<=100000 따라서 가능
* 3.변수형
* long long : K가 1000000000를 넘으므로 long long
*/
#include <iostream>
using namespace std;

int main(void) {

	long long N, K, answer = 0;

	cin >> N >> K;

	long long start = 1;
	long long end = N * N;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, (long long)mid / i);
			if(i > mid) break;
		}

		if (cnt < K)
			start = mid + 1;
		else {
			end = mid - 1;
			answer = mid;
		}
	}
	
	cout << answer;

	return 0;
}