/*
* 1.아이디어
* 트리를 만들고 트리를 모두 순회하면서 노드의 개수를 구하면 된다.
* 매번 각 노드를 루트로 한 부분트리의 노드개수를 구하면 너무 많은 연산을 하게된다.
* 따라서 dp를 사용해서 모든 노드를 dfs로 순회하고 재귀로 돌아올 때 각각의 노드를 기준으로한 노드의 개수를
* 저장해서 연산을 1번만 하고 그 다음은 dp에 저장된 개수를 사용해서 연산의 횟수를 대폭줄여준다.
* 
* 구조자체는 맞았는데 틀렸길래 다른사람의 풀이를 봤는데 차이가 ios_base::sync_with_stdio(false)만 있는 것을 보고
* 추가해줬더니 시간초과에 걸리지 않았다.
* 아마도 많은 입력을 줬을경우 시간초과가 걸리는 것 같다.
* 
*/
#include <iostream>
#include <vector>

using namespace std;

int N, root;

vector<int> Graph[100001];
int Node[100001];
bool visited[100001];

int DFS(int node) {
	if (Node[node] != 0) return Node[node];
	visited[node] = true;

	int temp = 1;
	for (int i = 0; i < Graph[node].size(); i++) {
		int nextNode = Graph[node][i];
		if (visited[nextNode]) continue;
		temp += DFS(nextNode);
	}
	Node[node] = temp;
	return temp;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> N >> root >> T;

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;

		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	DFS(root);

	while (T--) {
		int q;
		cin >> q;

		cout << Node[q] << "\n";
	}

	return 0;
}