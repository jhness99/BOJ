/*
* 1.아이디어
* 단순한 탐색 문제이다.
* 그래프를 구현하고 시작에서 얼마나 가야하는지를 체크하고 주어진 값만큼 이동해야 도착하는 노드를 모두 저장한 후 오름차순으로 출력하면 된다.
* 
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K, X;
vector<int> Graph[300001];
vector<int> answer;
bool visited[300001];

void BFS() {
	queue<pair<int, int>> q;
	q.push({X, 0});
	visited[X] = true;

	while (!q.empty()) {
		int Node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt == K) {
			answer.push_back(Node);
			continue;
		}
		for (int i = 0; i < Graph[Node].size(); i++) {
			int NextNode = Graph[Node][i];
			if (visited[NextNode]) continue;
			visited[NextNode] = true;
			q.push({ NextNode, cnt + 1 });
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		Graph[u].push_back(v);
	}

	BFS();

	sort(answer.begin(), answer.end());

	if (answer.size() == 0) {
		cout << -1;
		return 0;
	}

	for (auto& i : answer) {
		cout << i << "\n";
	}

	return 0;
}