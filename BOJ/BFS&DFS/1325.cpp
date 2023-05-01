/*
* 1.아이디어
* 그래프를 연결해서 하나하나 방문해서 방문표시를 한다.
* 더이상 방문할 수 없다면 방문한 수 를 출력해주면 된다.
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> Graph[10001];
vector<pair<int,int>> answer;
bool visited[10001];

int cnt;

void DFS(int num) {
	visited[num] = true;
	
	for (int i = 0; i < Graph[num].size(); i++) {
		int nextNode = Graph[num][i];
		if (!visited[nextNode]) {
			cnt++;
			DFS(nextNode);
		}	
	}
}

int main(void) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, Max = -1;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> v >> u;

		Graph[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		DFS(i);
		answer.push_back({ i , cnt });
		Max = max(Max, cnt);
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		if (answer[i].second == Max)
			cout << answer[i].first << " ";
	}

	return 0;
}