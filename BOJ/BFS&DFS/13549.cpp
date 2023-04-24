/*
* 1.아이디어
* 먼저 수빈이가 할 수 있는 행동은 3가지가 있다. 뒤로한칸, 앞으로 한칸, 그리고 텔레포트
* 각각 x-1, x+1, x*2의 연산으로 수빈이의 위치를 옮길 수 있다.
* 
* 큰 배열에 얼마나 이동했는지 저장하는 배열을 만들고 해당 배열에 이동해서 도착할때마다 갱신을 해준다.
* 이때 텔레포트는 0초를 사용하므로 갱신하지 않는다.
* 
* BFS로 탐색하다가 수빈이가 동생을 만나면 종료하고 동생의 위치의 check를 확인해서 몇초가 소모되었는지 확인해준다.
*/
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int Check[100001];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	if (N == K) {
		cout << 0;
		return 0;
	}

	deque<int> q;
	q.push_back(N);
	Check[N] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop_front();
		if (temp == K) {
			cout << Check[K] - 1;
			return 0;
		}

		if (temp * 2 < 100001 && !Check[temp * 2]) {
			q.push_front(temp * 2);
			Check[temp * 2] = Check[temp];
		}
		if (temp + 1 < 100001 && !Check[temp + 1]) {
			q.push_back(temp + 1);
			Check[temp + 1] = Check[temp] + 1;
		}
 		if (temp - 1 >= 0 && !Check[temp - 1]) {
			q.push_back(temp - 1);
			Check[temp - 1] = Check[temp] + 1;
		}
	}

	return 0;
}