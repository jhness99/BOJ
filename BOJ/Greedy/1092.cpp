/*
* 1.아이디어
* 실어야 할 화물과 크레인을 내림차순으로 정렬
* 크레인이 실을수 있는 무게가 더 크다면 cnt를 올린다
* cnt가 크레인수만큼 오르거나 모든 크레인보다 화물이 무거우면 asnwer++
* 2.시간복잡도
* sort를 사용했으므로 O(NlogN)
* 3.변수
* vector<int> : 크레인의 무게와 화물의 무게를 저장
* int : 화물의 최대개수는 10000, 크레인의 개수는 50 이므로 최대 시간은 10000, 따라서 int
*/
/*
* 문제풀이
* 내가 생각한 아이디어대로 푸는 문제는 맞았지만, 우선순위 큐를 사용해보려했는데 오류가 떴다.
* 반례를 생각해보니 문제를 알았다. 나는 우선순위큐를 사용해 가장 큰 값만 가져오려고 했다.
* 하지만 반례를 생각해보니 20 19 18의 크래인과 20 20 18의 짐이 있다면, 
* 첫번째 이동에서 20에 20, 19에 18이 들어가고 다음에 20에 20이 들어가면서 2회가 된다.
* 하지만 내가 짠 로직대로라면 20에 20이 들어가고 다음에 우선순위 큐의 top이 20이므로 18은 첫번째에 들어갈수 가 없다.
* 따라서 아이디어 자체는 맞았으나 우선순위큐를 사용해 top을 사용한 내 풀이는 틀렸다.
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, M, answer = 0;
	cin >> N;
	vector<int> c(N);
	for (auto& i : c)
		cin >> i;

	cin >> M;
	vector<int> w(M);
	for (auto& i : w)
		cin >> i;

	sort(c.begin(), c.end(), greater<>());
	sort(w.begin(), w.end(), greater<>());

	//정렬했을 때 가장 무거운 무게를 옮길수있는 크래인보다 더 무거운 박스가 있을경우 불가능
	if (c[0] < w[0]) {
		cout << -1;
		return 0;
	}

	while (!w.empty()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < w.size(); j++) {

				if (c[i] >= w[j]) {
					w.erase(w.begin() + j);
					break;
				}
			}
		}
		answer++;
	}

	cout << answer;

	return 0;
}