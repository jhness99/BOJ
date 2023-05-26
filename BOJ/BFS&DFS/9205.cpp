/*
* 1.아이디어
* BFS로 문제를 푼다.
* 현재위치에서 모든 편의점으로 갈 수 있는 경우를 모두 확인해줘야한다.
* 이때 거리는 1000을 넘어서는 안된다. 맥주1개당 50미터를 가고 최대 20개를 가질 수 있으므로 1000이다.
* 편의점과 편의점, 편의점과 도착지점이 모두 1000거리안에 있어야만 happy 아닐경우 sad를 반환해야 한다. 
*/
#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;
};

int N;
bool visited[100];
Point store[100];
Point Festival; 
Point home;

bool BFS() {
	queue<Point> q;
	q.push(home);
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;

		q.pop();

		if (abs(Festival.x - x) + abs(Festival.y - y) <= 1000) return true;
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {
				visited[i] = true;
				q.push(store[i]);
			}
		}
	}
	return false;
}

int main(void) {

	int T;
	cin >> T;

	while (T--) {

		cin >> N;

		cin >> home.x >> home.y;
		for (int i = 0; i < N; i++)
			cin >> store[i].x >> store[i].y;

		cin >> Festival.x >> Festival.y;

		if(BFS()) cout << "happy\n";
		else cout << "sad\n";

		fill(visited, visited + 100, false);\
	}

	return 0;
}