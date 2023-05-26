/*
* 1.아이디어
* 
*/
#include <iostream>
#include <queue>
using namespace std;

int start, target;
int Time, cnt;
bool visited[100001];

void BFS() {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int dist = q.front().first;
		int t = q.front().second;
		q.pop();

		visited[dist] = true;

		if (cnt &&dist == target && Time == t) cnt++;
		if (!cnt && dist == target) {
			Time = t;
			cnt++;
		}
		if (dist * 2 <= 100000 && !visited[dist * 2]) q.push({ dist * 2, t + 1 });
		if (dist + 1 <= 100000 && !visited[dist + 1]) q.push({ dist + 1, t + 1 });
		if (dist - 1 >= 0 && !visited[dist - 1]) q.push({ dist - 1, t + 1 });
	}
}

int main(void) {

	cin >> start >> target;

	BFS();

	cout << Time << "\n" << cnt;

	return 0;
}