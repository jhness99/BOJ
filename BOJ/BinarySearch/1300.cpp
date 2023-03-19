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
//#include <iostream>
//using namespace std;
//
//int main(void) {
//
//	long long N, K, answer = 0;
//
//	cin >> N >> K;
//
//	long long start = 1;
//	long long end = N * N;
//
//	while (start <= end) {
//		long long mid = (start + end) / 2;
//		long long cnt = 0;
//
//		for (int i = 1; i <= N; i++) {
//			cnt += min(N, (long long)mid / i);
//			if(i > mid) break;
//		}
//
//		if (cnt < K)
//			start = mid + 1;
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
//2023-03-19 복습
/*
* 1.아이디어
* 다시풀어봐도 어려운 문제다.
* 코드와 아이디어를 다시봐도 어려웠다.
* 이번엔 아이디어를 좀 더 구체적으로 적는다.
*
* 기본적으로 NxN 배열을 만들면, 각 행 열을 값을 곱해서 넣는다.
* 이것은 결국 행 x 열 이므로 행에 따라서 결정된다.
* 이것이 무슨 의미가 있나 하면 이렇게 생각해볼 수 있다.
* 만약 5*5 배열에서 15라는 수로 탐색을 하려한다.
* 3행에서 확인을 하려고 할 때 숫자를 보면 3 6 9 12 15가 있다.
* 이 수는 모두 자신의 열 1 2 3 4 5 에서 행 3을 곱한 값이다.
* 그렇다면 이 행에서 자신과 같거나 작은 수를 발견하려면 어떻게 해야 하겠는가
*
* 바로 자신을 행으로 나누는것이다. 그 값이 열의 최대값과 비교해서 더 작을경우, 해당 값까지만 넘을 수 있고
* 만약 초과하거나 같다면, 해당 열 크기만큼의 수보다 자신이 크다는 뜻이다.
*
* 해당 문제는 1~N*N을 최대 크기로 두고 mid를 만들어 이분탐색을 하면서
* mid를 기준으로 해당 배열에서 몇번째로 큰 수인지를 확인하는 것이다.
*
* 따라서 식은 이런식으로 하면 된다.
* for(int i = 1; i <= N; i++){
*	cnt += min(N, (long long)mid / i) 이때 cnt는 나보다 작은 수들의 개수이고 행 열 모두 N이므로 열의 최대치 N과 비교한다.
*	if(i > mid) break; //더이상 할 필요가 없으므로 종료한다.
* }
* 이렇게 나온 cnt가 K보다 크다면, end = mid - 1;
* k와 같거나 작다면, star = mid + 1, answer = mid;
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
			if (i > mid) break;
		}
		if (cnt < K) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			answer = mid;
		}
	}

	cout << answer;

	return 0;
}