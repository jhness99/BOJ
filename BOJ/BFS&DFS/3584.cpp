/*
* 1.아이디어
* 입력을 트리로 저장
* 
* 가장 마지막의 2개의 수를 기준으로 DFS시작
* DFS에서 해당 노드에서 탐색이 끝난 후 깊이를 Check에 저장해서 해당 노드의 깊이를 저장
* 
* 깊이가 0이 아니면 해당 값을 answer에 저장한다.
* 
* 루트를 고려하지 못해서 오류생김
* 루트를 고려하기 위해 사용하지 않는 노드 0에 루트를 저장해서 0부터 시작해서 루트를 확인하게 코드 변경
* 
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int answer;
vector<int> graph[10001];
int Node[10001];
int Check[10001];

bool DFS(int Node, int depth, int target) {
	if (Node == target) {
		return true;
	}
	for (int i = 0; i < graph[Node].size(); i++) {
		int index = graph[Node][i];

		if (DFS(index, depth + 1, target)) {
			if (Check[index] == 0)
				Check[index] = depth;
			else {
				if (Check[answer] < Check[index]) 
					answer = index;
			}
			return true;
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N;
		answer = 0;
		cin >> N;

		memset(Check, 0, sizeof(Check));
		memset(Node, 0, sizeof(Node));

		for (int i = 0; i < N - 1; i++) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			Node[v]++;
		}

		int root = 0;
		for (int i = 1; i <= N; i++) 
			if (Node[i] == 0) root = i;
		
		int num1, num2;
		cin >> num1 >> num2;

		graph[0].push_back(root);//루트를 고려하기 위해 0노드(사용안함)에 루트 저장

		DFS(0, 1, num1);
		DFS(0, 1, num2);

		cout << answer << "\n";

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}
	}

	return 0;
}