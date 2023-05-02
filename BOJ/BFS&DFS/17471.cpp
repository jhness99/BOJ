/*
* 1.아이디어
* 우선 주어진 도시들로 조합을 만든다.
* 조합을 만든 후 계산을 해야한다.
* 이때 조합이 충족해야 하는 조건은 2가지가 있다.
* 첫번째, 모든 도시가 이어져있어야 한다.
* 두번째, 구역에 포함된 도시가 1개 이상이어야 한다.
* 
* 이 2개를 만족하는 조합에서 두 선거구의 값을 빼서 나온 절대값을 최소값인 경우 갱신해주면 된다.
* 
* 2개의 조건을 만족하는지 확인하는 함수 Check를 만들고 만약 만족할경우 계산해주는 Calculate함수를 만든다.
* Check함수 안에서 BFS를 사용해 그래프가 연결 되있는지 확인해준다.
* 
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>W
#include <cstring>

using namespace std;

int N, answer = 10000000;
vector<int> Graph[11];
bool visited[11];
int citizen[11];
bool Select[11];

void Calculate() {
	int A = 0, B = 0;
	for (int i = 1; i <= N; i++) {
		if (Select[i]) A += citizen[i];
		else B += citizen[i];
	}
	answer = min(answer, abs(A - B));
}

bool CheckGraph(const vector<int>& v, bool flag) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(v.front());
	int cnt = 1;

	visited[v.front()] = true;

	while (!q.empty()) {
		int Node = q.front();
		q.pop();
		for (int i = 0; i < Graph[Node].size(); i++) {
			int nextNode = Graph[Node][i];

			if (visited[nextNode]) continue;
			if (Select[nextNode] == flag) {
				q.push(nextNode);
				cnt++;
				visited[nextNode] = true;
			}
		}
	}
	if (cnt == v.size()) return true;
	else return false;
}

bool Check() {
	vector<int> A, B;
	for (int i = 1; i <= N; i++) {
		if (Select[i]) A.push_back(i);
		else B.push_back(i);
	}
	if (A.size() == 0 || B.size() == 0) return false;

	if (!CheckGraph(A, true)) return false;
	if (!CheckGraph(B, false)) return false;

	return true;
}

void DFS(int cnt, int index) {
	if (cnt >= 1) {
		if (Check())
			Calculate();
	}
	for (int i = index; i <= N; i++) {
		if (Select[i]) continue;
		Select[i] = true;
		DFS(cnt + 1, i);
		Select[i] = false;
	}
}

int main(void) {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> citizen[i];

	for (int u = 1; u <= N; u++) {
		int a, v;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> v;
			Graph[u].push_back(v);
		}
	}

	DFS(0, 1);

	if (answer != 10000000)
		cout << answer;
	else cout << -1;

	return 0;
}