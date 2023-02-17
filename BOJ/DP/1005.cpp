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
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;

		int result[1001] = { 0, };
		int time[1001] = { 0, };
		int edgeCnt[1001] = { 0, };
		vector<vector<int>> graph(N + 1);
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
			if (edgeCnt[i] == 0) {
				q.push(i);
			}
			result[i] = time[i];
		}

		while (!q.empty()) {
			int index = q.front();
			q.pop();
			
			for (int i = 0; i < graph[index].size(); i++) {
				int next = graph[index][i];
				edgeCnt[next]--;
				result[next] = max(result[next], result[index] + time[next]);
				if (edgeCnt[next] == 0) {
					q.push(next);
				}
			}
		}
		cout << result[W] << endl;
	}

	return 0;
}