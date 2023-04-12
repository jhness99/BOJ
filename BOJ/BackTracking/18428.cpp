/*
* 1.아이디어
* 백트래킹을 사용해서 3개의 벽을 새우는 모든 경우를 확인해서 선생님의 시야에 학생이 있는지를 확인하면 된다.
* 
* 선생님의 위치를 백터에 따로 저장하고 3개의 벽을 새웠을 때 선생님들의 위치를 기준으로 학생들을 볼 수 있는지 확인해주는
* FindStudent함수를 사용한다.
* 
* 모든 방향을 확인하도록 하고 각 방향에 벽이 나올때까지 확인하다가 벽이 나오면 종료해준다.
* 만약 종료하지 않고 정상적으로 확인이 끝났다면, 해당 벽의 배치일때 학생이 보이지 않는 것이므로 Check변수로 해당 사실을 저장한다.
* Chek가 true라면 진행하고있던 DFS또한 모두 종료해줄수 있도록 Check == true, than return; 을 해준다.
* 
* Check가 true라면 YES, false라면 NO를 출력해준다.
* 2.시간복잡도
* 3.변수형
* 
*/
#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;
bool Check;
char map[6][6];
vector<pair<int, int>> T;

void FindStudent() {
	for (int i = 0; i < T.size(); i++) {
		int x = T[i].first;
		int y = T[i].second;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x;
			int ny = y;
			while (true) {
				nx = nx + dx[dir];
				ny = ny + dy[dir];

				if (0 > nx || nx >= N || 0 > ny || ny >= N) break;;
				if (map[ny][nx] == 'O') break;
				if (map[ny][nx] == 'S') {
					return;
				}
			}
		}
	}
	Check = true;
}

void DFS(int cnt) {
	if (cnt == 3) {
		FindStudent();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 'X') continue;
			map[i][j] = 'O';
			DFS(cnt + 1);
			if (Check)
				return;
			map[i][j] = 'X';
		}
	}
}

int main(void) {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')
				T.push_back({ j, i });
		}
	}

	DFS(0);

	if (Check)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}