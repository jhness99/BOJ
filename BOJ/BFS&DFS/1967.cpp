/*
* 1.아이디어
* DFS를 사용해 한 노드에서 모든 노드까지의 거리를 확인해서, 찾기 시작한 노드 기준에서 가장 멀리 떨어진 노드를 찾는다.
* 이때 해당 노드를 기준으로 다시 가장 먼 노드를 찾아서 해당 사이의 거리는 해당 트리의 가장 긴 지름이 된다.
* 왼쪽 지점에서 출발한 정점과 가장 멀리 있는 지점은 오른쪽 부분에 있는 지름 길이의 정점이 될 것이고
* 오른쪽 지점에서 출발한 정점과 가장 멀리 있는 지점은 왼쪽 부분에 있는 지름 길이의 정점이 될 것이다.
* 처음 한 아무 노드에서의 가장 긴 노드를 찾는것이 지름기준 오른쪽이나 왼쪽의 노드를 찾는 연산이엿고
* 그 다음 연산이 해당 노드를 기준으로 반대쪽의 노드를 찾는 연산인것이다.
* 
* 2.시간복잡도
* DFS를 사용해 모든 노드를 확인하므로 O(N)이고 DFS를 2번하므로 O(2N), 이때 2는 무시할 수 있으므로 O(N)
* N<=10000이므로 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, answer, targetNode;
int visited[10001];
vector<pair<int, int>> Graph[10001];

void DFS(int node, int length) {
	if (visited[node]) return;

	visited[node] = true;
	if (length > answer) {
		answer = length;
		targetNode = node;
	}
	for (int i = 0; i < Graph[node].size(); i++) {
		DFS(Graph[node][i].first, length + Graph[node][i].second);
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		Graph[u].push_back({ v,w });
		Graph[v].push_back({ u,w });
	}

	DFS(1, 0);

	answer = 0;
	memset(visited, false, sizeof(visited));

	DFS(targetNode, 0);
	cout << answer;

	return 0;
}