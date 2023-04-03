/*
* 1.아이디어
* 수열의 모든 부분수열을 구하는 재귀를 사용해서 모든 조합을 알아낸뒤 조합의 경우를 확인하면 될 것 같다.
* 
* 하려했지만 처음 음식에서 신맛을 곱하는 과정이 번거로워서 그냥 DFS로 구현했다.
* 1보다 큰 경우는 모두 확인해주고 cnt가 N-1보다 커지지 않도록 잘 중단해주면 된다.
*/
#include <iostream>

using namespace std;

int answer = 1000000000;
int N;
pair<int, int> arr[10];
pair<int, int> food[10];

void DFS(int index, int cnt) {
	if (cnt > 0) {
		int s = arr[0].first;
		int b = arr[0].second;
		for (int i = 1; i < cnt; i++) {
			s *= arr[i].first;
			b += arr[i].second;
		}
		answer = min(answer, abs(s - b));
	}
	if (cnt == N)
		return;
	for (int i = index; i < N; i++) {
		arr[cnt] = { food[i].first, food[i].second };
		DFS(cnt + 1, i + 1);
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> food[i].first >> food[i].second;
	}

	DFS(0, 0);

	cout << answer;

	return 0;
}