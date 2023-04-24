/*
* 1.아이디어
* BFS를 사용해 위 아래의 이동을 모두 고려해서 범위에만 나가지 않도록 각 층의 횟수를 갱신해줘서 해당 위치까지 가는 최소의 값을 구한다.
* 
* (틀린부분)
* 시도 자체는 맞지만 찾는 곳이 자기자신일 수 있기때문에 Floor 를 1로 해서 고려해야 한다.
* 만약 시작 Floor가 0이라면 해당 위치는 방문하지 않은것으로 치기때문에 
* 예를들어 위로 올라갔다가 s를 방문하고 내려가는 경우는 s에서 그냥 내려가는 것과 차이가 없지만 횟수가 차이가 나므로
* 방문했음을 표기해야 한다는 것이다.
* 
*/
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;

int Floor[1000001];

void BFS(int start) {
	queue<int> q;
	q.push(start);
	
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		
		if (index + U <= F && Floor[index + U] == 0) {
			Floor[index + U] = Floor[index] + 1;
			q.push(index + U);
		}
			
		if (index - D >= 1 && Floor[index - D] == 0) {
			Floor[index - D] = Floor[index] + 1;
			q.push(index - D);
		}
	}
}

int main(void) {
	
	cin >> F >> S >> G >> U >> D;

	Floor[S] = 1;
	BFS(S);

	if (Floor[G])
		cout << Floor[G]-1;
	else
		cout << "use the stairs";

	return 0;
}