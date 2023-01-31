/*
* 문제풀이
* 첫 접근방법은 작은수를 순서대로 제거해주기 였는데 4177252841 같은 예외가 있어서 다른방법을 생각했다.
* 계속 체크해주다가 여태 체크했던 수보다 큰 수가 나오면 그 전에 나온 작은 수들을 전부 없에주는것이다.
* 어떻게 구현할지 고민하다가 검색을 해봤는데 deque(스텍)를 사용하면 된다고 해서 deque를 사용해 위 알고리즘을 구현했다.
*/
#include <iostream>
#include <deque>

using namespace std;

int main(void) {

	int N, K;
	string str;
	deque<char> dq;
	cin >> N >> K;
	
	cin >> str;

	for (auto& c : str) {

		//만약 남은 제거횟수가 0이 아니고 deque가 비어잇지 않으면서 dq의 가장 마지막 숫자가 체크해주고있는 수보다 작다면
		//deque를 pop해가며 c보다 작은 수를 모두 제거, 제거하면서 제거횟수도 감소시킴
		while (K && !dq.empty() && dq.back() < c) {
			dq.pop_back();
			K--;
		}
		dq.push_back(c);
	}

	for (int i = 0; i < dq.size() - K; i++)
		cout << dq[i];

	cout << "\n";


	return 0;
}