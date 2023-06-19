/*
* 1.아이디어
* 아이디어 자체는 맞았는데 메모리 초과가 나왔다.
* 맞은풀이
* 우선 현재 입력상태 클립보드 상태 회수를 저장하는 state구조체를 만든다.
* 해당 구조체를 기준으로 BFS를 사용해서 모든 경우를 탐색해주면 된다.
* 이때 처음에는 단순하게 현재 이모티콘의 개수를 visited로 설정해줬지만
* 이렇게 되면 클립보드에 저장하는 경우는 visited로 걸러지기 때문에
* visited를 2차원 배열로 설정해서 클립과 현재 이모티콘을 모두 고려해서 방문하도록 설정해야 한다.
* 
*/
#include <iostream>
#include <queue>
using namespace std;

struct State {
	int imoticonCnt;
	int clipboardCnt;
	int cnt;
};
bool visited[2000][2000];
State answer;
int S;

int ans;

void BFS() {
	queue<State> q;
	q.push(answer);
	visited[1][0] = true;

	
	while (!q.empty()) {
		
		int clipCnt = q.front().clipboardCnt;
		int imoCnt = q.front().imoticonCnt;
		int cnt = q.front().cnt;
		q.pop();

		if (imoCnt == S) {
			cout << cnt;
			return;
		}
		
		if (0 < imoCnt && imoCnt < 2000) {
			if (!visited[imoCnt][imoCnt]) {
				visited[imoCnt][imoCnt] = true;
				q.push(State{ imoCnt, imoCnt, cnt + 1 });
			}
			if (!visited[imoCnt - 1][clipCnt]) {
				visited[imoCnt - 1][clipCnt] = true;
				q.push(State{ imoCnt - 1, clipCnt, cnt + 1 });
			}
		}
		if (0 < clipCnt && clipCnt + imoCnt < 2000) {

			if (!visited[imoCnt + clipCnt][clipCnt]) {
				visited[imoCnt + clipCnt][clipCnt] = true;
				q.push(State{ imoCnt + clipCnt, clipCnt, cnt + 1 });
			}
		}
	}
}

int main(void) {


	cin >> S;

	answer.imoticonCnt = 1;
	answer.cnt = 0;

	BFS();

	return 0;
}