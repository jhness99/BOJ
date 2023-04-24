/*
* 1.아이디어
* 모든 입력값을 사용해 그래프를 만들어준다. 그리고 DFS를 사용해 모든 노드를 확인해서 자식이 0이라면 answer++를 해준다.
* 이때 노드의 숫자가 지운 노드일경우 return 해서 그 이후의 값과 해당 값을 확인하지 않는다.
* 
* (틀린부분)
* 
*/
#include <iostream>
#include <vector>
using namespace std;

int N, answer;
int deleteNode;
vector<int> graph[50];

int DFS(int node) {
	if (node == deleteNode) return -1;
	if (graph[node].size() == 0) {
		answer++;
		return 0;
	}
	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		int flag = DFS(nextNode);
		if (flag == -1 && graph[node].size() == 1)
			answer++;
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int startNode = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int u;
		cin >> u;

		if (u == -1) {
			startNode = i;
			continue;
		}
		graph[u].push_back(i);
	}

	cin >> deleteNode;

	DFS(startNode);

	cout << answer;
	
	return 0;
}