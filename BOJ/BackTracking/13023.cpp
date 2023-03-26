/*
* 1.아이디어
* ABCDE의 관계라는게 뭔지 몰라서 그 부분만 봤는데 
* 그저 단순하게 깊이가 4라는 뜻이였다. 따라서 깊이가 4가 가능한지만 확인하면 되는 문제였다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[2000];
bool visited[2000];
int isPossible = 0;
int N, M;

void DFS(int cnt, int node) {
	if (cnt == 4) {
		isPossible = 1;
		return;
	}

	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		if (visited[nextNode]) continue;
		
		DFS(cnt + 1, nextNode);
		
	}
	visited[node] = false;
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		DFS(0, i);
		if (isPossible == 1)
			break;
	}

	cout << isPossible;

	return 0;
}