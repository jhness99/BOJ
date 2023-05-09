/*
* 1.아이디어
* 이 문제는 각 구역을 하나의 노드로 계산해서 각 노드가 모두 연결 되도록 하는 최단거리, 
* 즉 크루스칼 알고리즘을 사용해 최소 스패닝트리를 만들면 된다.
* 
* 그러기 위해서 순서대로 진행해야 한다.
* 첫번째, 각 구역을 노드화 하기 위해 넘버링 해서 숫자로 매칭시킨다.
* 두번째, 넘버링 된 구역끼리의 최단거리를 구한다.
* 세번째, 최단거리를 정렬하고 해당 최단거리를 사용해 유니온파운드(디스조인트 셋)을 사용해서 최소 스패닝 트리를 구현해준다.
* 
* 이러한 순서로 구현하면 된다.
* 
* 첫번째는 DFS로 구현해주었다.
* DFS를 사용해서 땅을 탐색 후 숫자를 붙여줬다.
* 
* 두번째는 최단거리를 구하기 위해 모든 땅을 입력때 벡터에 저장해주고 해당 벡터에 모든 값을 탐색해주었다.
* 모든 방향(상하좌우)를 확인해주고 만약 시작한 땅과 다른 땅이 나온다면 다리가 연결 가능한 것이므로
* 해당 다리의 길이와 연결된 두 구역의 숫자를 Bridge 백터에 저장해준다. 나중에 가중치(길이)를 기준으로 오름차순 해야하므로 
* 저장하는 형식을 (길이, 시작, 끝)의 구조로 저장한다.
* 
* 세번째는 저장한 Bridge 벡터를 오름차순으로 정렬해서 가장 가중치(길이)가 짧은 다리부터 노드를 연결해준다.
* 이때 노드 연결을 가장 숫자가 작은 노드가 부모가 되도록 연결한다.
* 이렇게 해서 모든 노드가 1을 가리키지 않으면 연결된것이 아니게 되도록 해서 연결을 확인할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;

int MAP[10][10];
bool visited[10][10];
int parent[7];
int AreaCnt= 0;

vector<pair<int, int>> Area;
vector<pair<int, pair<int, int>>> Bridge;

void DFS(int x, int y, int Number) {
	MAP[y][x] = Number;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
		if (visited[ny][nx] || !MAP[ny][nx]) continue;
		visited[ny][nx] = true;
		DFS(nx, ny, Number);
	}
}

void NumberingArea() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!MAP[i][j]) continue;
			if (visited[i][j]) continue;
			DFS(j, i, ++AreaCnt);
		}
	}
}

void MakeBridge(int x, int y, int dir) {
	int len = 0;
	int start = MAP[y][x];

	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (0 > nx || nx >= M || 0 > ny || ny >= N) break;

		if (!MAP[ny][nx]) {
			x = nx;
			y = ny;
			len++;
		}
		else if (MAP[ny][nx] && len >= 2 && start != MAP[ny][nx]) { 
			Bridge.push_back(make_pair(len, make_pair(start, MAP[ny][nx])));
			break;
		}
		else break;
	}
}

int Find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u != v) {
		if (u < v)
			parent[v] = u;
		else
			parent[u] = v;
	}
};

bool SameParent(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u != v)
		return false;
	return true;
}

int main(void) {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
				Area.push_back({ j, i });
		}
	}

	NumberingArea();

	for (int i = 0; i < Area.size(); i++) {
		for (int j = 0; j < 4; j++)
			MakeBridge(Area[i].first, Area[i].second, j);
	}
	
	sort(Bridge.begin(), Bridge.end());
	
	for (int i = 1; i <= AreaCnt; i++)
		parent[i] = i;

	int answer = 0;

	for (int i = 0; i < Bridge.size(); i++) {
		if (!SameParent(Bridge[i].second.first, Bridge[i].second.second))
		{
			Union(Bridge[i].second.first, Bridge[i].second.second);
			answer += Bridge[i].first;
		}
	}
	for (int i = 1; i <= AreaCnt; i++) {
		if (Find(i) != 1) {
			cout << "-1";
			return 0;
		}
	}
	cout << answer;

	return 0;
}