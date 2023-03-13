/*
* 1.아이디어
* (틀린풀이)
* BFS를 사용해서 문제를 푼다.
* q에 넣을 수 있는 조건을 기존 bfs에서 1개 더 추가하는데, 그것은 지금까지 이동하면서 최대와 최소또한 같이 전해줘서
* 해당 값들의 차가 새로 탐색하는 곳을 기준으로 갱신된 최대 최소의 차 보다 클경우, 해당 위치를 큐에 넣어 탐색해준다.
* 
* (맞은풀이)
* 역시 틀릴 줄 알았지만 시도해봤다.
* 입력받은 배열의 최댓값과 최솟값을 저장해서 해당 값을 기준으로 이분탐색을 하는것이였다.
* 이분탐색을 할 때 L R을 최소 최대값으로 지정하고, map[i][j]가 해당 값 사이의 값이여야지만 이동하게 하는것이다.
* L R로 제한을 두고 이동하게 한 다음 만약 도착지점에 도착할 수 있다면, 해당 이동에 사용한 LR값으로 차이를 기존의 값과 비교해
* 더 작은값으로 갱신해주는 것이다. 
* 
* 이 발상을 떠올렸다고 해도 틀렸을 것 같은 부분은 시작부분에 따라 right가 바뀌는 부분이다.
* 만약 시작부분이 left보다 작거나 right보다 크다면, 애초에 탐색이 불가능하므로 그때에는 
* r++을 해준다. 이때 left보다 작은것은 바뀌지 않으므로 결국 불가능하므로 종료
* 결국 저 조건을 통과한다는것은 다시말해 시작부분이 L과 같거나 크고 R과 같거나 작을 경우 시작한다는 뜻이다.
*
* 2.시간복잡도
* 최악의 경우 모든 곳을 탐색하므로, O(N^2) N<=100 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int map[100][100];
bool visited[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, answer = 201;
	cin >> N;

	int Max = -1;
	int Min = 201;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			Max = max(map[i][j], Max);
			Min = min(map[i][j], Min);
		}
	}

	int left = Min;
	int right = Min;

	while (left <= right && right <= Max) {
		if(map[0][0] < left || map[0][0] > right){
			right++;
			continue;
		}
		bool check = false;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		q.push({ 0, 0 });
		visited[0][0] = true;

		while (!q.empty()) {
			auto index = q.front();
			q.pop();

			if (index.first == N - 1 && index.second == N - 1) {
				check = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = index.first + dx[i];
				int ny = index.second + dy[i];

				if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
				if (visited[ny][nx]) continue;

				if (left <= map[ny][nx] && map[ny][nx] <= right) {
					q.push({nx, ny});
					visited[ny][nx] = true;
				}
			}
		}
		if (check) {
			answer = min(answer, right - left);
			if (left != right)	left++;
			else right++;
		}
		else
			right++;
	}

	cout << answer;
	return 0;
}