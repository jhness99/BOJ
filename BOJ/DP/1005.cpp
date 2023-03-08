/*
* 1.아이디어
* 입력받은 값을 그래프로 만들어서 저장한다.
* 모든 그래프를 순회하면서 자신의 소요시간을 다음 그래프의 소요시간에 더한다.
* 소요시간이 이미 있다면 더 큰값으로 갱신해준다. 이유는 최대값 시간동안 대기해야하기 때문에 가장 큰 값이 최소시간이 된다.
* 2.시간복잡도
* O(N+K), N<=1000, K<=100000, 따라서 가능
* 3.변수형
* int result[] : 결과를 저장하기위한배열
* int time[] : 각 건물의 건설시간을 저장한 배열
* int edgeCnt : 해당 건물을 만들기 위해 지어야 하는 건물 수를 저장, 즉 그래프에 연결 되있는 간선의 수를 저장
* vector<vector<int>> graph : 건물의 순서를 저장하는 그래프
* queue<int> q : 그래프를 탐색할 큐
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//
//	int T;
//	cin >> T;
//	while (T--) {
//		int N, K;
//		cin >> N >> K;
//
//		int result[1001] = { 0, };
//		int time[1001] = { 0, };
//		int edgeCnt[1001] = { 0, };
//		vector<vector<int>> graph(N + 1);
//		queue<int> q;
//
//		for (int i = 1; i <= N; i++)
//			cin >> time[i];
//
//		
//		for (int i = 0; i < K; i++) {
//			int X, Y;
//			cin >> X >> Y;
//			graph[X].push_back(Y);
//			edgeCnt[Y]++;
//		}
//
//		int W;
//		cin >> W;
//
//		for (int i = 1; i <= N; i++) {
//			if (edgeCnt[i] == 0) {
//				q.push(i);
//			}
//			result[i] = time[i];
//		}
//
//		while (!q.empty()) {
//			int index = q.front();
//			q.pop();
//			
//			for (int i = 0; i < graph[index].size(); i++) {
//				int next = graph[index][i];
//				edgeCnt[next]--;
//				result[next] = max(result[next], result[index] + time[next]);
//				if (edgeCnt[next] == 0) {
//					q.push(next);
//				}
//			}
//		}
//		cout << result[W] << endl;
//	}
//
//	return 0;
//}
//2023-03-08 복습
/*
* 1.아이디어
*
* 각 노드에서 걸리는 시간을 저장한다.
* 각 노드의 관계를 그래프로 만든다.
* 이때 각 노드가 부모노드에게 연결되있는 간선의 수를 저장한다.
*
* 각 노드가 총 걸리는 시간도 만들어준다. 해당 노드는 가장먼저 자기자신이 걸리는 시간을 넣는다.
* 먼저 큐에 부모노드로 연결된 간선이 0인 노드들을 q에 넣는다.
* 각 큐의 연결된 노드들을 해당 노드의 값만큼 총 걸리는 시간을 갱신한다.
* 갱신할 때 탐색중인 노드의 기존 시간과 부모노드의 총 시간과 자식노드의 시간을 더한 시간중 더 큰 시간으로 갱신해준다.
* 부모노드에 연결되있는 간선또한 --해준다. 그리고 만약 간선이 0이라면, 해당 노드는 더이상 갱신 할 수 없으니
* q.push(next)를 해서 그 노드가 부모가 되어 자식노드들을 확인하고 갱신해준다.
*
* 2.시간복잡도
* O(N+K), N<=1000, K<=100000, 따라서 가능
* 3.변수형
* ivector<int> result : 결과를 저장하기위한배열
* vector<int> time : 각 건물의 건설시간을 저장한 배열
* vector<int> edgeCnt : 해당 건물을 만들기 위해 지어야 하는 건물 수를 저장, 즉 그래프에 연결 되있는 간선의 수를 저장
* vector<vector<int>> graph : 건물의 순서를 저장하는 그래프
* queue<int> q : 그래프를 탐색할 큐
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> result(N + 1);
		vector<int> time(N + 1);
		vector<vector<int>> graph(N + 1);
		vector<int> edgeCnt(N + 1);
		queue<int> q;

		for (int i = 1; i <= N; i++)
			cin >> time[i];

		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			graph[X].push_back(Y);
			edgeCnt[Y]++;
		}
		int W;
		cin >> W;

		for (int i = 1; i <= N; i++) {
			if (!edgeCnt[i])
				q.push(i);
			result[i] = time[i];
		}

		while (!q.empty()) {
			int index = q.front();
			q.pop();

			for (int i = 0; i < graph[index].size(); i++) {
				int next = graph[index][i];
				edgeCnt[next]--;
				result[next] = max(result[next], time[next] + result[index]);
				if (edgeCnt[next] == 0) {
					q.push(next);
				}
			}
		}
		cout << result[W] << "\n";
	}

	return 0;
}