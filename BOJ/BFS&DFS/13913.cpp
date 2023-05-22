/*
* 1.아이디어
* BFS로 갈수있는 모든 경로를 탐색해서 횟수와 위치를 기록해준다. 만약 도착한다면 횟수를 출력해준다.
* 이때 경로를 알아야 하는데 visited와 parent를 사용해서 한 번 간 위치는 다시 갱신하지 않고, 이동했을때
* parent를 사용해 이전의 위치를 기록해서 목표에 도착했을 때 되돌아가면서 시작위치로 돌아갈 때 까지의 위치 순서를
* path백터에 저장한다.
* BFS가 끝난 후 해당 path를 거꾸로 출력해주면 된다.
*/
#include <iostream>
#include <queue>

using namespace std;

int start, target, answer;

bool visited[200001];
int parent[200001];

vector<int> path;

void BFS() {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		visited[x] = true;
		q.pop();
		if (x == target) {
			int idx = x;
			while (idx != start) {
				path.push_back(idx);
				idx = parent[idx];
			}
			cout << time << "\n";
			break;
		}
		if (x * 2 >= 0 && x * 2 <= 200000 && visited[x * 2] == false) {
			q.push(make_pair(x * 2, time + 1));
			visited[x * 2] = true;
			parent[x * 2] = x;
		}
		if (x - 1 >= 0 && x - 1 <= 200000 && visited[x - 1] == false) {
			q.push(make_pair(x - 1, time + 1));
			visited[x - 1] = true;
			parent[x - 1] = x;
		}
		if (x + 1 >= 0 && x + 1 <= 200000 && visited[x + 1] == false) {
			q.push(make_pair(x + 1, time + 1));;
			visited[x + 1] = true;
			parent[x + 1] = x;
		}
	}
}

int main(void) {

	cin >> start >> target;
	
	BFS();

	cout << start << ' ';
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << ' ';

	return 0;
}