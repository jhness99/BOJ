/*
* 1.아이디어
* 트리를 구현하고 모든 정점을 확인해서 트리의 개수를 구해주면 된다.
* 트리의 개수에 따라 case를 출력해주면 된다.
* 
* 트리의 개수를 확인하기 위해서 트리를 저장한 후 사이클이 나오는 경우는 트리로 치지 않고
* 사이클이 없이 끝난다면 트리로 계산해준다.
* 
* 사이클을 확인하는 DFS를 구현할 때 처음에는 시작부분과 같은 노드가 나오면 
* 사이클임을 판별하려고 했지만 이렇게 하면 처음 시작할 때 부터 안되게 된다.
* ex)if(node == startNode) return false;
* 따라서 방문한 곳을 또 방문하는 경우를 사이클이 나오는 경우라고 판단하고 처리한다.
* 이때 양방향 트리로 구현했기 때문에 자신의 부모또한 확인하는데 이 경우는 예외로 처리해야한다.
* ex)if (nextNode == beforeNode) continue;
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, answer;
vector<vector<int>> graph;
bool visited[501];

bool DFS(int node, int beforeNode) {
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		if (nextNode == beforeNode) continue; //이전 노드를 확인해주어서 부모가 포함되있는 graph[node]에서 예외처리해줌
		if (visited[nextNode]) return false;
		if(!DFS(nextNode, node)) return false;
	}
	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int index = 1;
	while (true) {
		cin >> N >> M;

		if (!N && !M) break;
		
		answer = 0;
		memset(visited, false, sizeof(visited));
		graph = vector<vector<int>>(N + 1);
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= N; i++) {
			if(!visited[i])
				if (DFS(i, 0)) answer++;

		}
		if (answer == 0) 
			cout << "Case " << index << ": No trees.\n";
		else if (answer == 1) 
			cout << "Case " << index << ": There is one tree.\n";
		else 
			cout << "Case " << index << ": A forest of " << answer << " trees.\n";

		index++;
	}

	return 0;
}