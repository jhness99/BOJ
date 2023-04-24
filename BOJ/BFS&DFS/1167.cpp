/*
* 1.아이디어
* 트리의 지름-1967 문제와 같지만 입력방식만 다른 문제이다. 풀이자체는 똑같다.
* 우선 임의의 한 노드에서 가장 먼 노드를 찾고 찾은 노드를 기준으로 가장 먼 노드를 찾아 두 노드간의 거리를 구하면 그 값이 가장 긴 지름이 된다.
* 이런 결과가 나오는 이유는 다음과 같다.
* 어떠한 위치든 간에 한 노드에서 가장 거리가 먼 노드를 찾으면 해당 노드는 트리로 원을 만들었을 때 지름의 왼쪽이나 오른쪽이 된다.
* 그 후 그 노드와 가장 먼 노드를 찾으면 나머지 한쪽이 되는 것이다. 따라서 둘 사이의 거리가 지름이 된다.
* 
* DFS를 사용해 한 노드와의 나머지 노드간의 거리를 확인할 수 있고 그 값중 가장 큰 값으로 값을 갱신해주는 함수가 필요하다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, answer, targetNode;
vector<pair<int, int>> graph[100001];
bool visited[100001];

void DFS(int node, int length){
	if (visited[node]) return;
	visited[node] = true;

	if (answer < length) {
		targetNode = node;
		answer = length;
	}
	for (int i = 0; i < graph[node].size(); i++) {
		auto nextNode = graph[node][i];
		DFS(nextNode.first, length + nextNode.second);
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int u, v, w;
		cin >> u;
		while (true) {
			cin >> v;
			if (v == -1) break;
			cin >> w;

			graph[u].push_back({ v,w });
		}
	}

	DFS(1, 0);

	memset(visited, false, sizeof(visited));
	answer = 0;

	DFS(targetNode, 0);

	cout << answer;

	return 0;
}