/*
* 1.아이디어
* graph에 모든 위치를 순회해야 한다.
* 양방향으로 갈 수 있도록 그래프를 입력받는다.
* 1부터 N까지의 모든 노드를 시작으로 BFS를 해준다.
* 
* BFS에서 연결된 모든 노드를 중복없이 순회하면서 모든 노드로 가는 길이를 저장해준다.
* 모든 연산이 끝난 후 시작노드에서 나머지 노드로 가는 모든 경로의 횟수를 저장해서 그것을 answerCnt와 비교해서
* 더 작다면 그 값으로 갱신해주고 해당 start노드를 answer로 바꿔준다.
* 
* 이렇게 되면 모든 노드를 확인해 해당 노드들의 나머지 노드와의 거리를 모두 확인해서
* 해당값이 최소값이라면 그 값을 갱신해줄수있다.
* 2.시간복잡도
* N개의 노드를 확인하고 각 노드의 총M개가 있을 수 있으므로 O(NM), N<=100, M<=5000 따라서 가능 
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
int N, M;
int answer;
int answerCnt = 1000000000;

void BFS(int start) {
	bool visited[101] = { false , };
	queue<pair<int,int>> q;
	visited[start] = true;
	q.push({ start , 0});

	int temp = 0;

	while (!q.empty()) {
		int index = q.front().first;
		int cnt = q.front().second + 1;
		q.pop();
		auto indexGraph = graph[index];
		for (int i = 0; i < indexGraph.size(); i++) {
			int nextNode = indexGraph[i];
			if (visited[nextNode]) continue;
			visited[nextNode] = true;
			temp += cnt;
			q.push({ nextNode , cnt});
		}
	}
	if (answerCnt > temp) {
		answer = start;
		answerCnt = temp;
	}
}

int main() {

	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		BFS(i);
	}

	cout << answer;

	return 0;
}