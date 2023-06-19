/*
* 1.아이디어
* 그래프로 만들어서 확인한다.
* 그래프를 이용해 해당 수보다 더 무겁거나 가벼운 구슬의 수를 계산해주면 된다.
* 가운대가 불가능한 경우를 구해야 한다.
* 가운대가 가능하려면 무거운 구슬과 가벼운 구슬의 수가 (N-1)/2여야 한다.
* 아직 모든 관계도가 나온것이 아니므로 1가지 생각할 수 있다
* 적은경우는 관계에 따라 더 많아져서 가운대가 가능할 수 있지만
* (N-1)/2보다 클 경우는 무조건 불가능하다.
* 따라서 해당조건을 기준으로 무거운 구슬과 가벼운 구슬의 수가 (N-1)/2보다 클 경우
* 절대 불가능하므로 answer++를 해준다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool visited[100];

int BFS(vector<int> graph[], int node) {
	fill(visited, visited + 100, false);
	queue<int> q;
	int cnt = 0;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int Node = q.front();
		q.pop();

		for (int i = 0; i < graph[Node].size(); i++) {
			int nextNode = graph[Node][i];
			if (visited[nextNode]) continue;
			visited[nextNode] = true;
			q.push(nextNode);
			cnt++;
		}
	}

	return cnt;
}

int main(void) {

	cin >> N >> M;

	int answer = 0;
	vector<int> HeavyGraph[100];
	vector<int> LightGraph[100];

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		HeavyGraph[v].push_back(u);
		LightGraph[u].push_back(v);
	}

	int baseNum = (N - 1) / 2;

	for (int i = 1; i <= N; i++) {
		int HeavyCnt = BFS(HeavyGraph, i);
		int LightCnt = BFS(LightGraph, i);

		if (HeavyCnt > baseNum || LightCnt > baseNum) answer++;
	}

	cout << answer;

	return 0;
}