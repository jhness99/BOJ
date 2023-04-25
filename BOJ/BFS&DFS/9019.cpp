/*
* 1.아이디어
* 각각의 수에서 모든 경우를 확인해야한다. 그리고 수가 많이 커질경우 mode 연산을 하므로 방문을 확인하는 visited는 10000의 크기로 하면 된다.
* BFS를 사용해 모든 경우를 확인하면 된다.
* BFS로 확인하다가 찾으려는 수와 현재 변화한 수가 같다면 여태 해온 연산을 출력해주면 된다.
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[10000];

void BFS(int startNum, int TargetNum) {
	queue<pair<int, string>> q;
	q.push({ startNum, "" });
	visited[startNum] = true;
	while (!q.empty()) {
		int num = q.front().first;
		string op = q.front().second;
		q.pop();

		if (num == TargetNum) {
			cout << op << "\n";
			return;
		}

		int D = (num * 2) % 10000;
		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, op + "D" });
		}
		int S = num - 1 < 0 ? 9999 : num - 1;
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, op + "S" });
		}
		int L = (num % 1000) * 10 + (num / 1000);
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, op + "L" });
		}
		int R = (num / 10) + (num % 10) * 1000;
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, op + "R" });
		}
	}
}

int main(void) {

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		BFS(a, b);
	}

	return 0;
}