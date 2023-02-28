/*
* 1.아이디어
* (틀린아이디어)
* i날의 주식이 i+1의 주식과 비교해서 올라간다면 소지주식개수 +1, 사용한 돈 totalMoney -= stock[i]
* i날의 주식이 i+1의 주식과 비교해서 내려간다면 소지주식개수 = 0, totalMoney += stock[i]*소지주식개수 
* (맞은아이디어)
* 가장 뒤부터 해당 가격이 여태 나온 가격중 가장 큰 값이면 max값을 갱신
* 갱신된 max값에서 현재 가격을 뺀 값을 totalMoney에 더해줌
* 
* 2.시간복잡도
* N개의 날짜를 모두 확인하므로 O(N), N <= 1000000 이므로 가능
* 3.변수형
* long long : 날별주가는 최대 10000이다. 따라서 10000*500000까지 가능하므로 long long
*/
/*
* 문제풀이
* 틀린 이유는 가장 큰 이익을 남기기 위해선 가장 큰 값에서 팔아야 하는데, 
* 나는 앞에서 확인하다 지금 수보다 작은 수가 나오면, 그 수가 최대라고 가정하고 연산을 해버렸다.
* 이후에 나올 더 큰 수를 고려하지 않아서 틀렸다.
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int N;
//		int maxStock = -1;
//		long long totalMoney = 0;
//		cin >> N;
//		vector<int> stock(N);
//		
//		for (auto& i : stock)
//			cin >> i;
//
//		//만약 max값이 바뀌면, 그 전의 주식 가격때 그 값이 됬을 때 팔았을것이므로
//		//해당 값을 기준으로 이득을 계산해야 한다.
//		for (int i = N - 1; i >= 0; i--) {
//			maxStock = max(maxStock, stock[i]);
//			totalMoney += maxStock - stock[i];
//		}
//		cout << totalMoney << "\n";
//	}
//
//	return 0;
//}
//2023-02-28
/*
* 1.아이디어
* 가장 뒤의 숫자를 기준으로 그 앞의 숫자를 확인한다.
* 만약 기준숫자보다 작다면 그 차를 더해주고 만약 크다면, 기준숫자를 그 숫자로 바꾸어준다.
* 왜 이렇게 뒤에서 하냐면 앞에서 한다면, 해당 수 이후에 나오는 가장 큰 수를 찾는 작업을
* 하기가 힘들기 때문이다.하지만 뒤에서 접근한다면 내 앞에있는 나보다 작은 수와의 차이가
* 곧 이익이기 때문에 쉽게 접근할 수 있다.
*
* 2.시간복잡도
* O(N) N<=1000000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int T;
	cin >> T;

	while (T--) {
		int N;
		long long answer = 0;
		cin >> N;

		vector<int> v(N);
		for (auto& i : v)
			cin >> i;

		int checkNum = v.back();
		for (int i = N - 2; i >= 0; i--) {
			if (v[i] > checkNum) {
				checkNum = v[i];
			}
			else {
				answer += checkNum - v[i];
			}
		}
		cout << answer << "\n";
	}

	return 0;
}