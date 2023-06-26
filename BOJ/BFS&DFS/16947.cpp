/*
* 1.아이디어
* 먼저 DFS로 사이클을 찾는다. 사이클을 찾았다면 되돌아올때 vector<int> Cycle에 저장해둔다
* 이때 사용하는 DFS는 이렇게 구현한다.
* 1.순서대로 DFS탐색을 하면서 visited에 부모보다 1씩 올려서 저장해준다.
* 2.그러다가 만약 다음 가야할 노드가 이미 방문한 노드일경우, 반환할 값을 해당 노드의 visited 값과 자신의 visited값을 비교해서
* 더 작은것을 설정한다. 이 설정된 값이 바로 사이클이 시작하는 노드의 visited 값인것이다.
* 3.사이클이라고 정해졌으면 되돌아가면서 이전 노드들 또한 사이클임을 확인해줘야한다. 이때 처음 사이클임을 확인하고 
* ans와 visited[nextNode]와 비교해준 곳과 다음노드의 visited가 같거나 작게되는 경우에 flag를 해서 모든것이 끝나고 재귀될 때
* Cycle에 해당 노드가 사이클임을 저장해준다.
* 4.물론 사이클이 아닌 다른 노드또한 모두 확인해줘야 한다. 사이클이 되지 않으면 되돌아올때 절대로 탐색한 nextNode의 visited값이
* 탐색을 시작한 node의 visited 와 작거나같을 수 없기 때문에 문제가 생기지 않는다.
* 
* 해당 DFS를 하고 난 후 Cycle을 queue에 넣어서 BFS를 한다.
* 사이클이 여러개여도 BFS이므로 가장 가까운 사이클과의 사이 거리가 나오게 된다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
vector<int> Graph[3001];
int visited[3001];

vector<int> Cycle;

int DFS(int Parent, int node, int num) {
	int ans = num;
	bool flag = false;
	visited[node] = num;
	for (auto& nextNode : Graph[node]) {
		if (Parent == nextNode) continue;
		if (!visited[nextNode]) {
			int nextNum = DFS(node, nextNode, num + 1);
			if (nextNum <= visited[node]) {
				ans = nextNum;
				flag = true;
			}
		}
		else {
			ans = min(ans, visited[nextNode]);
			flag = true;
		}	
	}
	if(flag)
		Cycle.push_back(node);
	return ans;
}

void BFS() {
	queue<int> q;
	for (auto& i : Cycle) {
		q.push(i);
		visited[i] = 1;
	}
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (auto& nextNode : Graph[curNode]) {
			if (visited[nextNode]) continue;
			visited[nextNode] = visited[curNode] + 1;
			q.push(nextNode);
		}
	}
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;

		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(Graph[i].begin(), Graph[i].end());
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		DFS(0, i, 1);
	}

	fill(visited, &visited[N+1], 0);

	BFS();

	for (int i = 1; i <= N; i++) {
		cout << visited[i] - 1 << " ";
	}

	return 0;
}