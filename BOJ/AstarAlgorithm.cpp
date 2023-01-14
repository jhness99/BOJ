/*
* 샘플입력
4 8
0 1 1 0 1 0 1 1
1 0 1 0 0 0 0 1
1 0 1 0 1 0 1 0
2 0 0 1 1 0 1 3

5 10
1 2 1 0 1 0 1 0 1 1
1 0 1 0 0 0 0 0 0 0
1 0 1 0 1 1 1 0 1 0
1 0 1 0 1 3 1 1 1 0
1 0 0 0 1 0 0 0 0 0
*/
#include <iostream>
#include <vector>
#include <set>
#include <stack>

//각 맵의 구성요소
#define WALL 1
#define START 2
#define GOOL 3

constexpr int INF = 1e9;

using namespace std;
using Pair = std::pair<int, int>;
using pPair = std::pair<int, Pair>;

//f g h와 부모의 위치를 저장해주는 구조체 cell 정의
//f = g + h , g는 시작점에서 현재 cell까지의 비용, h는 현재 cell에서 도착지점까지의 거리(이때 장애물은 고려하지 않는다.)
//parentX 와 Y는 이전좌표, 이 cell오기전 cell의 정보를 넣어둔다.
struct cell {
	int f, g, h;
	int parentX, parentY;
};


int M = 0, N = 0;
vector<vector<int>> map;		//칸에 무엇이 있는지 확인시켜줌
vector<vector<cell>> cell_map;	//각 칸의 cell구조체를 넣어서 데이터(F, G H, 부모위치)를 저장해줌
vector<vector<bool>> visited;	//해당 노드를 방문했는지 확인(방문한 노드는 현재 갈 수 있는 노드중 가장 낮은 노드)

int startX;		//시작X위치
int startY;		//시작Y위치
int goolX;		//목표X위치
int goolY;		//목표Y위치
int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { -1,1,0,0,-1,1,1,-1 };
int cost[] = { 10,10,10,10,14,14,14,14 };	//대각선은 1.4 직선은 1의 비용이 들지만 소수점을 제외하기위해 10을 곱해줌

void PrintMap() {
	cout << "\n";
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			map[i][j] == 4 ? cout << "*" : cout << map[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}

//디버그용 visited변수 출력함수
void PrintVisited() {
	cout << "\n";
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j]) cout << 1;
			else cout << 0;
		}
		cout << "\n";
	}
}

//시작에서 목표까지 가면서 맵에 경로를 그려주는 함수
void tracePath() {
	std::stack<Pair> s;
	int x = goolX;
	int y = goolY;

	s.push({ x, y });
	
	//자기자신을 부모로 가지는(시작지점) cell을 발견할 때 까지 부모를 사용해 이동하기 전 cell을 하나하나 탐색
	//탐색한 cell은 stack에 저장해서 시작지점부터 목표까지 순서대로 반환하게 저장
	while (!(cell_map[y][x].parentX == x && cell_map[y][x].parentY == y)) {
		int tempx = cell_map[y][x].parentX;
		int tempy = cell_map[y][x].parentY;
		x = tempx;
		y = tempy;
		s.push({ x, y });
	}

	//시작지점부터 끝지점까지 이동하면서 경로을 체크
	while (!s.empty()) {
		map[s.top().second][s.top().first] = 4;
		//PrintMap();
		s.pop();
	}
}

//nx ny위치부터 목표지점까지 장애물을 고려하지 않은 예상비용을 반환하는 함수
int GethValue(int nx, int ny) {
	return (int)(sqrt(pow(ny - goolY, 2) + pow(nx - goolX, 2))*10);
}


bool ASTAR() {
	//자동으로 정렬되고 중복을 허용하지 않는 set으로 List를 생성
	set<pPair> List;

	//List의 첫번째에 시작위치를 삽입, 이때 set은 앞의 수를 기준으로 순서를 자동으로 정렬해주므로 해당 위치의 F값을 지정해주어서
	//F값이 가장 작은 순으로 오름차순 정렬을 통해 가장 짧은 경로를 가지는 cell을 바로 알 수 있게 된다.
	List.insert({ 0 , {startX, startY} });

	//BFS와 유사하게 진행
	while (!List.empty()) {

		//가장 짧은 경로를 가진 cell위치정보 가져오기
		pPair p = *List.begin();

		//정보를 가져오면 해당 cell정보 삭제
		List.erase(List.begin());

		int x = p.second.first;
		int y = p.second.second;
		visited[y][x] = true;
		
		int ng, nf, nh;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//탐색할 때 맵을 넘지 않도록 설정
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {

				//만약 탐색하는 곳이 목표지점일경우
				if (nx == goolX && ny == goolY) {
					cell_map[ny][nx].parentX = x;
					cell_map[ny][nx].parentY = y;
					tracePath();
					return true;
				}
				//탐색하는 곳이 방문하지 않았고 벽이 아닌 빈 cell일 경우
				else if (!visited[ny][nx] && map[ny][nx] == 0) {

					//탐색을 시키는 cell의 현재 이동비용에 현재탐색을 하게되서 추가된 비용을 계산
					ng = cell_map[y][x].g + cost[i];
					//탐색을 하는 곳과 도착지점의 예상거리 계산
					nh = GethValue(nx, ny);

					nf = ng + nh;

					//만약 탐색을 하려는 위치의 F값이 초기값이거나 현재 위치를 기준으로 탐색했을때 나온 비용이 탐색하는 cell의 기존 비용보다 낮을경우
					if (cell_map[ny][nx].f == INF || cell_map[ny][nx].f > nf) {

						//현재 위치에서의 이동비용이 더 적으므로 갱신을 해준다.
						cell_map[ny][nx].f = nf;
						cell_map[ny][nx].g = ng;
						cell_map[ny][nx].h = nh;

						//부모의 위치도 더 저렴한 비용을 가진 현재 위치로 갱신을 해준다.
						cell_map[ny][nx].parentX = x;
						cell_map[ny][nx].parentY = y;

						//List에 탐색한 노드를 추가해준다.
						List.insert({ nf, { nx, ny } });
					}
				}
			}
		}
	}
	return false;
}



int main(void) {

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		map.push_back(vector<int>());
		cell_map.push_back(vector<cell>());
		visited.push_back(vector<bool>());
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			visited[i].push_back(false);
			map[i].push_back(temp);
			if (temp == 2) {
				startX = j;
				startY = i;
				cell_map[i].push_back({ 0,0,0,j,i });
			}
			else if (temp == 3) {
				goolX = j;
				goolY = i;

				//탐색을 위해서 기본값을 비용이 최대로, 부모는 없도록 초기화
				cell_map[i].push_back({ INF,INF,INF,-1,-1 });
			}
			else {
				cell_map[i].push_back({ INF,INF,INF,-1,-1 });
			}
		}
	}
	if (ASTAR()) PrintMap();
	else cout << "실패" << endl;
	//디버그용
	//PrintVisited();

	return 0;
}
