/*
* 1.아이디어
* 
*/
#include <iostream>
#include <queue>

using namespace std;

int N;
int MAP[1001];
bool visited[1001];

int BFS() {
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visited[1] = true;
	while (!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		int value = MAP[node];
		q.pop();

		if (node == N)
			return cnt;

		for (int i = 1; i <= value; i++) {
			if (visited[node + i]) continue;
			visited[node + i] = true;
			q.push({ node + i, cnt + 1 });
		}
	}
	return -1;
}

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> MAP[i];
	}

	cout << BFS();

	return 0;
}