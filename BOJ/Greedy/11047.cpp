/*
* 1.아이디어
* 입력받은 동전을 배열에 저장해서 배열별로 나눠서 몫이 나오는 경우,
* cnt += K/coin[i], K%=coin[i]를 한다. K가 0이되면 종료한다.
* 
* 2.시간복잡도
* O(N), N<=10 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, K, cnt = 0;
	cin >> N >> K;
	vector<int> coin(N);
	for (auto& i : coin)
		cin >> i;

	sort(coin.begin(), coin.end(), greater<int>());

	for (auto& i : coin) {
		if (K == 0)
			break;

		cnt += K / i;
		K %= i;
	}

	cout << cnt;

	return 0;
}