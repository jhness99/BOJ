/*
* 1.아이디어
* 팀원들이 서로서로를 가리키는 순환형태가 되어야 팀으로 구성할 수 있다.
* 따라서 순환하지 않는 노드를 찾아서 하나하나 확인해주면 된다.
* 
* (틀린부분)
* 우선 내가 한 방법자체는 틀리지 않았지만 시간초과가 나오게 됬다.
* 따라서 시간을 줄여주기 위해 visited 와 done을 사용했다
* visited는 방문 여부를 알려주고 done은 사이클 여부를 확인해줬다.
* 
* 방문을 하지 않았다면 다음 노드를 확인해주고
* 방문은 했지만 사이클여부를 모를경우 사이클인지 확인을 해준다.
* 사이클이라면 cnt가 올라가게 되서 나중에 전체개수에서 사이클인 node개수를 빼서 사이클이 아닌 node수를 알 수 있다.
* 사이클인지 확인을 했다면 done을 true로 해서 dfs로 계속 호출해온 node들을 백트래킹으로 사이클인지 확인했다고 체크를 해준다.
* 이 로직을 진행한 노드들은 모두 방문, 사이클인지아닌지 확인 후 사이클인경우의 노드 수 까지 확인했으므로 더이상 확인할 필요가 없다.
* 따라서 main함수에서 visited[i] 가 true일경우는 dfs를 하지 않아 시간사용을 좀 더 줄인다.
* 
* 
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph;
bool visited[100001];
bool done[100001];
int N;
int cnt;

void DFS(int node) {
	visited[node] = true;
	int next = graph[node];
	if (!visited[next]) {
		DFS(next);
	}
	else if (!done[next]) {
		for (int i = next; i != node; i = graph[i]) {
			cnt++;
		}
		cnt++;
	}
	done[node] = true;
}

int main(void) {

	int T;
	cin >> T;
	while (T--) {
		
		cin >> N;
		graph = vector<int>(N + 1);

		memset(visited, false, sizeof(visited));

		for (int i = 1; i <= N; i++) 
			cin >> graph[i];
		
		for (int i = 1; i <= N; i++) {
			if(!visited[i])
				DFS(i); 
		}
		cout << N-cnt << "\n";
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
	}

	return 0;
}