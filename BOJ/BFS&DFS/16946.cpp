/*
* 1.아이디어
* (틀린 아이디어)
* BFS를 사용해 원래 맵이 벽인 곳 만 탐색을 해주면 된다.
* 해당 위치에서 나머지 위치까지의 모든 방문가능한 칸의 개수를 저장하고 그것을 출력하는 맵에 저장한다.
* 0일경우 0을 저장한다.
* 
* (맞는 아이디어)
* 정답자체는 나오지만 시간초과가 나오게 된다.
* 따라서 검색을 해봤는데 0들로 각각의 구역을 만들어서 넘버링해준다.
* 그 후 1을 탐색할 때 그와 인접한 곳에 번호를 보고 그 번호만큼의 양을 더해주는 방식으로
* 시간소모를 줄였다.
* 
*/
//틀린코드
//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//int N, M;
//
//int map[1000][1000];
//int printMap[1000][1000];
//bool visited[1000][1000];
//
//int BFS(int x, int y) {
//	queue<pair<int, int>> q;
//	q.push({ x,y });
//	visited[y][x] = true;
//	int cnt = 1;
//	while (!q.empty()) {
//		x = q.front().first;
//		y = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
//			if (visited[ny][nx] || map[ny][nx] == 1) continue;
//			cnt++;
//			q.push({ nx, ny });
//			visited[ny][nx] = true;
//		}
//	}
//	return cnt;
//}
//
//int main(void) {
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		string temp;
//		cin >> temp;
//		for (int j = 0; j < M; j++) {
//			map[i][j] = temp[j] - '0';
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (map[i][j] == 1) {
//				memset(visited, false, sizeof(visited));
//				printMap[i][j] = BFS(j, i);
//			}
//			
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << printMap[i][j];
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;
int map[1000][1000];
int AreaNum[1000][1000];
int answer[1000][1000];
bool visited[1000][1000];

bool zeroAreaVisited[10000000];
int ZeroAreaCnt;

vector<int> zeroArea;

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	AreaNum[y][x] = ZeroAreaCnt;
	visited[y][x] = true;
	int cnt = 1;
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
			if (visited[ny][nx] || map[ny][nx] == 1) continue;
			visited[ny][nx] = true;
			AreaNum[ny][nx] = ZeroAreaCnt;
			q.push({ nx,ny });
			cnt++;
		}
	}
	zeroArea.push_back(cnt);
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j] - '0';
		}
	}
	memset(AreaNum, -1, sizeof(AreaNum));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (!map[i][j] && !visited[i][j]) {
				BFS(j, i);
				ZeroAreaCnt++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				set<int> Search;
				for (int dir = 0; dir < 4; dir++) {
					int nx = j + dx[dir];
					int ny = i + dy[dir];

					if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
					if (map[ny][nx]) continue;
					if (Search.find(AreaNum[ny][nx]) == Search.end())
					{
						Search.insert(AreaNum[ny][nx]);
						answer[i][j] = answer[i][j] + zeroArea[AreaNum[ny][nx]];
					}
				}
				answer[i][j]++;
				answer[i][j] %= 10;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << answer[i][j];
		}
		cout << "\n";
	}

	return 0;
}