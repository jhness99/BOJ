/*
* 문제풀이
* 첫 접근방법은 작은수를 순서대로 제거해주기 였는데 4177252841 같은 예외가 있어서 다른방법을 생각했다.
* 계속 체크해주다가 여태 체크했던 수보다 큰 수가 나오면 그 전에 나온 작은 수들을 전부 없에주는것이다.
* 어떻게 구현할지 고민하다가 검색을 해봤는데 deque(스텍)를 사용하면 된다고 해서 deque를 사용해 위 알고리즘을 구현했다.
*/
//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main(void) {
//
//	int N, K;
//	string str;
//	deque<char> dq;
//	cin >> N >> K;
//	
//	cin >> str;
//
//	for (auto& c : str) {
//
//		//만약 남은 제거횟수가 0이 아니고 deque가 비어잇지 않으면서 dq의 가장 마지막 숫자가 체크해주고있는 수보다 작다면
//		//deque를 pop해가며 c보다 작은 수를 모두 제거, 제거하면서 제거횟수도 감소시킴
//		while (K && !dq.empty() && dq.back() < c) {
//			dq.pop_back();
//			K--;
//		}
//		dq.push_back(c);
//	}
//
//	for (int i = 0; i < dq.size() - K; i++)
//		cout << dq[i];
//
//	cout << "\n";
//
//
//	return 0;
//}
//2023-02-19 복습
/*
* 1.아이디어
* stack으로 풀 수 있다.
* stack에 자신을 넣고 그 다음에 오는 수와 스택의 top을 비교해서 비교하는 수가 더 크다면 현재 있는 스택을 빼주고
* 해당 수를 넣으면 된다.
* 이때 횟수를 정해놨기때문에 횟수가 다 지나면 그냥 넣기만 해줘야한다.
*
* (이번에도 햇갈린 부분)
* k만큼 빼줘야하는이유
* 반례 5 2 19876 를 보면 알 수 있다.
* 아래 코드대로 진행하면 2개를 빼아햐는데 9876에서 6또한 7보다 작기때문에 pop해주는 조건을 만족못한다
* 따라서 dq에 9 8 7 6이 저장되는것이다. 이를 전부 출력하면 출력오류가 나오므로 아직 삭제할 횟수가 남은지 확인하고
* 남은 횟수만큼 출력을 마지막에서 덜 해주면 되는것이다.
* 2.시간복잡도
* 3.변수형
*/
//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main(void) {
//
//	int N, K;
//	string str;
//	deque<char> dq;
//	cin >> N >> K;
//
//	cin >> str;
//
//	for (auto& c : str) {
//		while (K && !dq.empty() && dq.back() < c) {
//			dq.pop_back();
//			K--;
//		}
//		dq.push_back(c);
//	}
//
//	for (int i = 0; i < dq.size() - K; i++)
//		cout << dq[i];
//
//	return 0;
//}
//2023-03-13 복습
/*
* 1.아이디어
* 못참고 내 풀이를 봐버렸다.
* 스택을 사용하면된다.
*
* string으로 받아서 첫번째부터 스택에 넣는데 이때 넣어진 값보다 내 값이 더 크다면, 해당 top을 pop해버리고 넣는다.
*
* (틀린부분)
* 또 같은 부분에서 틀렸다.
* K가 0이 아닌경우도 포함해서 출력해야 되는데 그것을 까먹었다.
*
* 2.시간복잡도
* O(N) N<=500000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <deque>

using namespace std;

int main(void) {

	int N, K;
	cin >> N >> K;

	string str;
	cin >> str;

	deque<char> dq;

	for (int i = 0; i < str.size(); i++) {
		while (K && !dq.empty() && dq.back() < str[i]) {
			dq.pop_back();
			K--;
		}
		dq.push_back(str[i]);
	}

	for (int i = 0; i < dq.size() - K; i++)//틀린부분
		cout << dq[i];

	return 0;
}