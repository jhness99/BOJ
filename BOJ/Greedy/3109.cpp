/*
* 그래프 문제는 익숙해서 생각보다 쉽게 푼 문제
* dfs와 그리드를 활용하면된다. 해당 문제에 들어간 그리드 요소는 바로 dy의 -1,0,1인데,
* 이러한 순서로 탐색을 하게되면 제일 위에있는 노드부터 확인해서 연결하기 때문에 가장 많이 연결할 수 있게 된다. 
* 나머지는 dfs문제와 같고, 나는 해당 경로를 확인해보기 위해 재귀를 할 때 이동했던 경로에 
* 파이프의 번호를 표기해 이동경로를 체크했다.
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int dy[] = {-1,0,1};		//dx가 없는 이유는 왼쪽에서 오른쪽을 이동하므로 무조건 1만큼 상승하기 때문이다.
//int R, C;
//int cnt = 0;
//char map[10001][501];
//bool visited[10001][501] = {false, };
//
////파이프를 설치하기위해 가장 탐욕적(짧고 가장 위쪽에)으로 탐색할 DFS
//bool dfs(int x, int y) {
//	visited[y][x] = true;		
//
//	//만약 탐색중인 위치가 가장 오른쪽이였을 경우 탐색을 종료하고 백트래킹으로 돌아가면서 이동경로 체크
//	if (x == C-1) {
//		cnt++;
//		map[y][x] = cnt + '0';
//		return true;
//	}
//
//	for (int i = 0; i < 3; i++) {
//		int nx = x + 1;
//		int ny = y + dy[i];
//
//		if (0 <= nx && nx < C && 0 <= ny && ny < R) {
//			if (visited[ny][nx]) continue;
//			if (map[ny][nx] == 'x') continue;
//
//			//가장 탐욕적인 경로를 찾았을 경우, 탐색을 백트래킹으로 돌아가면서 이동경로를 체크
//			if (dfs(nx, ny)) {
//				map[y][x] = cnt+'0';
//				return true;
//			}
//		}	
//	}
//	return false;
//}
//void printMap() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cout << map[i][j];
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}
//
//int main(void) {
//
//	cin >> R >> C;
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> map[i][j];
//		}
//	}
//	
//	for (int i = 0; i < R; i++) {
//		dfs(0, i);
//		printMap();
//	}
//	cout << cnt;
//
//	
//	return 0;
//}
//2023-02-20 복습
/*
* 1.아이디어
* DFS를 사용해 풀어준다.
* 왼쪽 끝 부터 시작해서 오른쪽 대각선 위 ,중간, 아래순으로 이동해준다. //그리디요소
* 만약 이동하다가 건물(X)를 만나거나 방문한 곳이거나 경계를 넘었다면 continue
* 아니라면 해당 위치로 진행하는데 DFS(nx, ny), 방문할 위치에서 다시 시작
* 만약 x 가 도착지점이라면 true반환, cnt++
* 2.시간복잡도
* O(RC),R <= 10000, C<=500 따라서 가능
* 3.변수형
* map[10000][500] : 입력받은 map 저장
*/
#include <iostream>

using namespace std;

char map[10000][500];
int dy[] = { -1,0,1 };
bool visited[10000][500];

int R, C, cnt = 0;

bool DFS(int x, int y) {
	if (x == C - 1) {
		cnt++;
		return true;
	}
	for (int i = 0; i < 3; i++) {
		int nx = x + 1;
		int ny = y + dy[i];

		if (0 > ny || ny >= R || nx >= C) continue;
		if (visited[ny][nx] || map[ny][nx] == 'x') continue;

		visited[ny][nx] = true;
		if (DFS(nx, ny))
			return true;
	}
	return false;
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < R; i++) {
		DFS(0, i);
	}
	cout << cnt;

	return 0;
}