//2022-09-21 코드
/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int map[22][22] = { 0, };
int Distance[22][22] = { 0 , };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, x, y, babySize = 2, second = 0; 
int eatfish = 0;

vector<pair<int, int>> fish;

bool compare(pair<int, int> a, pair<int, int> b) {

	return a.second < b.second;
}

void growUp(void) {
	if (eatfish >= babySize) {
		eatfish -= babySize;
		babySize++;
	}
}

void reset(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Distance[i][j] = -1;
		}
	}
	map[y][x] = 0;
	Distance[y][x] = 0;
	fish.clear();
	fish.shrink_to_fit();
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ x, y });
	
	while (!q.empty()) {
		auto queue = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = queue.first + dx[i];
			int ny = queue.second + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
			if (Distance[ny][nx] != -1) continue;
			if (map[ny][nx] > babySize) continue;
			else if (map[ny][nx] == babySize || map[ny][nx] == 0) {
				Distance[ny][nx] = Distance[queue.second][queue.first] + 1;
				q.push({ nx,ny });
			}
			else if (map[ny][nx] < babySize && map[ny][nx] >= 1) {
				Distance[ny][nx] = Distance[queue.second][queue.first] + 1;
				fish.push_back({ nx,ny });
				q.push({ nx,ny });
			}
		}
	}
}

bool eatFish(void) {
	if (fish.size() == 0) {
		cout << second << endl;
		return true;
	}
	else if (fish.size() == 1) {
		x = fish[0].first;
		y = fish[0].second;
		map[y][x] = 0;
		eatfish++;
		second += Distance[y][x];
	}
	else {
		int mindist = 1e5;
		for (auto& q : fish) {
			mindist = min(mindist, Distance[q.second][q.first]);
		}
		
		vector<pair<int, int>> minfish;
		for (auto& q : fish) {
			if (mindist == Distance[q.second][q.first]) {
				minfish.push_back({ q.first,q.second });
			}
		}
		if (minfish.size() == 1) {
			x = minfish[0].first;
			y = minfish[0].second;
			map[y][x] = 0;
			second += Distance[y][x];
			eatfish++;
		}
		else {
			sort(minfish.begin(), minfish.end(), compare);
			x = minfish[0].first;
			y = minfish[0].second;
			second += Distance[y][x];
			map[y][x] = 0;
			eatfish++;
		}
	}
	return false;
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				x = j;
				y = i;
			}
		}
	}
	while (true) {
		reset();
		growUp();
		bfs();
		if (eatFish()) {
			return 0;
		}	
	}
	return 0;
}
*/
//2023-01-14 코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 20		//최대크기 20

using namespace std;

int Distance[MAX][MAX];		//해당 칸 방문 여부와 시작위치에서부터 그 칸까지의 거리
int map[MAX][MAX];		
int N = 0;					
int sX, sY;					//상어의 위치
int Second = 0;				//걸린시간
int babySize = 2;
int eatfish = 0;			//성장하기위한 물고기먹은수
vector<pair<int, int>> fish;//물고기의 위치를 저장하는 벡터
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

//문제에서 같은 길이의 위치일경우 좀 더 왼쪽 위의 물고기를 먹으라고 했으므로
//기본적인 sort에서는 first의 값으로만 정렬하므로 second의 값까지 고려해서 정렬
//이렇게 되면 왼쪽 가장 위 로 내림차순이 되므로 문제조건 만족
bool compare(const pair<int, int>& f1, const pair<int, int>& f2) {
	return f1.second < f2.second;
}

//memset(distence, -1, sizeof(int)*N*N);
void resetDistance() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Distance[i][j] = -1;
		}
	}
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sX = j;
				sY = i;
			}
		}
	}
	resetDistance();
}

void reset() {
	resetDistance();

	Distance[sY][sX] = 0;
	map[sY][sX] = 0;
	fish.clear();
	fish.shrink_to_fit();
}

//맵을 탐색하면서 물고기일경우 해당물고기의 위치를 저장해주고 아닐경우 지나가는 깊이우선탐색
void bfs() {
	queue<pair<int, int>> q;
	q.push({ sX, sY });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;	//맵을 탈출했을경우
			if (Distance[ny][nx] != -1) continue;					//방문을 이미 했을경우
			if (map[ny][nx] > babySize) continue;					//상어보다 물고기가 클 경우 
																	//이러한 경우일경우 조건으로 돌아감
			//물고기가 상어보다 작고, 빈 칸이 아닌 물고기일경우 == 물고기 먹기 가능
			else if (map[ny][nx] < babySize && map[ny][nx] >= 1) {	
				fish.push_back({ nx, ny });//고를 물고기리스트로 추가
				q.push({ nx, ny });
				Distance[ny][nx] = Distance[y][x] + 1;
			}
			//물고기가 상어랑 크기가 같고 맵이 빈 칸일경우 == 이동가능
			else if (map[ny][nx] == babySize || map[ny][nx] == 0) {
				q.push({ nx, ny });
				Distance[ny][nx] = Distance[y][x] + 1;
			}
		}
	}
}

void growUp(void) {
	if (eatfish >= babySize) {
		eatfish -= babySize;
		babySize++;
	}
}

bool eatFish() {
	//잡아먹을 물고기가 없을경우
	if (fish.size() == 0) {
		cout << Second << endl;
		return false;
	}
	//잡아먹을 수 있는 물고기가 단 1마리일경우
	if (fish.size() == 1) {
		auto target = fish.front();
		Second += Distance[target.second][target.first];
		sX = target.first;
		sY = target.second;
		eatfish++;
	}
	else {
		int minDis = 100000;

		//가장 거리가 짧은 물고기 탐색
		for (auto& f : fish) {
			minDis = min(minDis, Distance[f.second][f.first]);
		}
		vector<pair<int, int>> minfish;
		for (auto& f : fish) {
			if (minDis == Distance[f.second][f.first]) {
				minfish.push_back({ f.first,f.second });
			}
		}
		//가장 거리가 짧은 물고기가 한마리일경우
		if (minfish.size() == 1) {
			auto target = minfish.front();
			Second += Distance[target.second][target.first];
			sX = target.first;
			sY = target.second;
			eatfish++;
		}
		//가장 거리가 짧은 물고기가 여러마리 일 경우
		else {
			//왼쪽가장 위에 있는 물고기를 기준으로 오름차순
			sort(minfish.begin(), minfish.end(), compare);
			auto target = minfish.front();
			Second += Distance[target.second][target.first];
			sX = target.first;
			sY = target.second;
			eatfish++;
		}
	}
	return true;
}

int main(void) {
	Input();

	do {
		reset();	//상어를 기준으로 체크했던 거리 및 물고기 배열 초기화
		growUp();	//상어가 물고기를 자신크기만큼 먹었을 경우 성장시킴
		bfs();		//물고기 탐색
	} while (eatFish());	//먹을 물고기가 없을경우 반복종료

	return 0;
}