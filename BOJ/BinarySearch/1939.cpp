/*
* 1.아이디어
* 입력받은 값을 vector<pair<int, int>> graph[100001]로 초기화
* 이때 first는 다음 섬 좌표이고, second는 다음 좌표로 가는 다리의 중량제한이다.
* 
* 제일 큰 중량제한을 right, 최소1이므로 left = 1로 초기화
* 
* mid를 구한 후 BFS를 사용해 물건이 무게가 mid일경우 목적지에 도착할 수 있는지 체크,
* 이때 가능하면, mid를 증가시키기 위해 left = mid + 1 answer = mid;
* 불가능 하다면, mid를 감소시키기 위해 right = mid - 1
* right<left가 될 때까지 반복
*  
* 이때 사용하는 BFS는 전형적인 BFS이고 cost를 이용해서 주어진 cost보다 같거나 작은 다리로만 이동해서 목적지 찾음
* 
* 2.시간복잡도
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//vector<pair<int, int>> graph[100001];
//bool visited[100001];
//
//int N, M, start, finish;
//
//bool BFS(int cost) {
//	queue<int> q;
//	q.push(start);
//	visited[start] = true;
//
//	while (!q.empty()) {
//		int curFactory = q.front();
//		q.pop();
//
//		if (curFactory == finish) {
//			return true;
//		}
//
//		for (int i = 0; i < graph[curFactory].size(); i++) {
//			int next = graph[curFactory][i].first;
//			int nextCost = graph[curFactory][i].second;
//
//			if (!visited[next] && cost <= nextCost) {
//				visited[next] = true;
//				q.push(next);
//			}
//		}
//	}
//
//	return false;
//}
//
//int main(void) {
//
//	cin >> N >> M;
//
//	int answer = 0;
//	int maxCost = -1;
//
//	for (int i = 0; i < M; i++) {
//		int num1, num2, cost;
//		cin >> num1 >> num2 >> cost;
//		graph[num1].push_back({ num2, cost });
//		graph[num2].push_back({ num1, cost });
//		maxCost = max(cost, maxCost);
//	}
//
//	cin >> start >> finish;
//
//	int left = 1;
//	int right = maxCost;
//
//	while (left <= right) {
//
//		memset(visited, false, N+1);
//
//		int mid = (left + right) / 2;
//		if (BFS(mid)) {
//			left = mid + 1; 
//			answer = mid;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-22 복습
/*
* 1.아이디어
* 그래프를 vector<pair<int, int>>로 저장하는데 first는 다음섬의 번호이고 second는 해당 다리의 중량제한이다.
*
* 이분탐색을 통해 모든 다리를 확인한다. 다리의 최대값과 최솟값을 right left로 지정하고 이분탐색을 한다.
* mid로 무게제한을 두고 그래프를 탐색했을 때 공장에 도착할 수 있다면, left = mid - 1 , answer = mid;
* 불가능 하다면 right = mid + 1;한다.
*
* 위 그래프탐색은 DFS로 진행한다. cost를 받아와 해당 cost보다 중량제한이 작다면, 이동할 수 없도록 제한한다.
*
* 2.시간복잡도
* 이분탐색에 O(log10^9), BFS에서 최대 M번 호출되므로 O(Mlog10^9) M<=100000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

vector<pair<int, int>> graph[100001];
bool visited[100001];

int start;
int target;

bool BFS(int cost) {
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int index = q.front();
		q.pop();

		if (index == target)
			return true;

		for (int i = 0; i < graph[index].size(); i++) {
			int nextNode = graph[index][i].first;
			int nextCost = graph[index][i].second;

			if (nextCost >= cost && !visited[nextNode]) {
				visited[nextNode] = true;
				q.push(nextNode);
			}
		}
	}
	return false;
}

int main(void) {

	int N, M, answer = 0;
	cin >> N >> M;

	int Max = -1;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		graph[A].push_back({ B, C });
		graph[B].push_back({ A, C });
		Max = max(Max, C);
	}
	cin >> start >> target;
	int left = 1;
	int right = Max;

	while (left <= right) {
		int mid = (left + right) / 2;
		memset(visited, false, N + 1);
		if (BFS(mid)) {
			left = mid + 1;
			answer = mid;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}