/*
* 1.아이디어
* 입력받은 노드로 그래프를 만든다.
* 해당 그래프를 만든 후 DFS를 사용해 시작위치에서부터 끝 위치까지 이동하면서 확인한다.
* 도착지점까지 도착했다면 여태까지의 거리를 출력한다.
* 
* 처음에는 int dist를 따로 함수의 매개변수로 주지 않았지만, 종료분기가 애매해져서 추가함.
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, answer;
bool visited[1001];
vector<pair<int, int>> Graph[1001];

void DFS(int node, int target, int dist) {
	visited[node] = true;
	if (node == target) {
		answer = dist;
		return;
	}
	for (int i = 0; i < Graph[node].size(); i++) {
		int nextNode = Graph[node][i].first;
		int Cost = dist + Graph[node][i].second;
		if (visited[nextNode]) continue;
		visited[nextNode] = true;
		DFS(nextNode, target, Cost);
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		Graph[u].push_back({ v,c });
		Graph[v].push_back({ u,c });
	}

	for (int i = 0; i < M; i++) {
		memset(visited, false, sizeof(visited));
		int Start, End;
		cin >> Start >> End;
		DFS(Start, End, 0);
		cout << answer << "\n";
	}

	return 0;
}