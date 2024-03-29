/*
* 1.아이디어
* N개의 심사대 M번 사용하게 되면 시간초과가 걸리므로 이분탐색으로 접근해야함
* 
* 입력받은 각 심사대에서 걸리는 시간을 배열에 저장
* 
* 그리고 start = 0, end = 최악의 경우 가장 오래걸리는 시간(친구수*가장 오래걸리는 심사대가 걸리는 시간)으로 초기화
* 이때 start와 end, mid의 값이 너무 크므로 long long으로 선언
* 
* 두 수의 가운대값 mid를 만들고, 심사 하는데 걸리는 시간이 mid라 가정하고
* 각각의 심사대에서 최대 몇번까지 심사를 할 수 있는지 확인
* total = mid / input[i]로 최대 얼마나 많은 사람을 심사할 수 있는지 확인
* 
* 최종적으로 나온 total의 값과 M의 값을 비교해서 만약 total이 M보다 크다면, end = mid - 1
* 만약 total이 M과 같거나 작다면, start = mid + 1, answer = mid;
* 
* 이 과정을 start >= end가 될 때까지 반복
* 
* (틀린부분)
* total = mid / input[i]을 할때
* if (total > M)		
	break;
* 를 안해줘서 틀림
* 만약 N이 100000이고 M이 1000000000이고 모든 input이 1개의 10^9와 1로 이루어져있다면,
* mid가 최대 10^9*10^9, 따라서 10^18이 된다.
* 절반을 하면 5*10^17 이 되는데 이때 cnt를 갱신해주면 5*10^17을 N번 더해야 한다.
* 5*10^22가 되고 long long을 넘어버리기 때문에 M을 초과하면 즉시 나가줘야 한다.
* 
* 2.시간복잡도
* 3.변수형
* long long : 수가 너무 커지므로 answer, mid, start, end 모두 long long 사용
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	long long answer = 0;
//	int N, M;
//	cin >> N >> M;
//
//	long long Max = -1;
//	vector<int> input(N);
//	for (auto& i : input) {
//		cin >> i;
//		Max = max(Max, (long long)i);
//	}
//		
//	long long start = 1;
//	long long end = Max * M;
//	long long mid;
//
//	while (start <= end) {
//		mid = (start + end) / 2;
//		long long total = 0;
//		for (int i = 0; i < N; i++) {
//			total += mid / input[i];
//			if (total > M)	
//				break;
//		}
//		if (total < M) {
//			start = mid + 1;	
//		}
//		else {
//			end = mid - 1;
//			answer = mid;
//		}
//			
//	}
//	
//	cout << answer;
//
//	return 0;
//}
//2023-04-09 복습
/*
* 1.아이디어
* N개의 심사대를 사용하는 M명의 사람이 차례대로 사용하게 해야한다.
* M이 최대 10억이므로 일일히 확인하면 시간이 너무 오래걸린다. 따라서 시간이 주어졌을 때 해당 시간안에 몇명의 사람을 받을 수 있는지 확인하는편이
* 더 빠르게 구할 수 있게 된다. 따라서 이분탐색을 사용해야한다.
*
* left를 1, right를 가장 큰 값*M을 해서 이분탐색을 해야한다. 따라서 left, right, mid 모두 long long으로 선언한다.
* 그리고 이분탐색을 해서 mid에 각 심사대의 시간을 나눈 몫을 total에 더해준다. 이 수는 해당 심사대가 mid시간동안 받을 수 있는 사람의 수 이다.
* 그래서 구한 total이 M과 비교했을 때 작다면, start = mid + 1, 을 하고
* total이 M과 같거나 크다면, end = end + 1, answer = mid;
*
* 2.시간복잡도
*
* 3.변수형
* long long : 수가 너무 커지므로 answer, mid, start, end 모두 long long 사용
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	long long answer = 0;
	int N, M;
	cin >> N >> M;

	long long Max = -1;
	vector<int> input(N);
	for (auto& i : input) {
		cin >> i;
		Max = max((int)Max, i);
	}

	long long left = 1;
	long long right = Max * M;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long total = 0;
		for (auto& i : input) {
			total += mid / i;
			if (total > M)
				break;
		}
		if (total < M)
			left = mid + 1;
		else {
			right = mid - 1;
			answer = mid;
		}
	}

	cout << answer;

	return 0;
}