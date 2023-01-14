//2022-09-21 �ڵ�
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
//2023-01-14 �ڵ�
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 20		//�ִ�ũ�� 20

using namespace std;

int Distance[MAX][MAX];		//�ش� ĭ �湮 ���ο� ������ġ�������� �� ĭ������ �Ÿ�
int map[MAX][MAX];		
int N = 0;					
int sX, sY;					//����� ��ġ
int Second = 0;				//�ɸ��ð�
int babySize = 2;
int eatfish = 0;			//�����ϱ����� ����������
vector<pair<int, int>> fish;//������� ��ġ�� �����ϴ� ����
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

//�������� ���� ������ ��ġ�ϰ�� �� �� ���� ���� ����⸦ ������� �����Ƿ�
//�⺻���� sort������ first�� �����θ� �����ϹǷ� second�� ������ ����ؼ� ����
//�̷��� �Ǹ� ���� ���� �� �� ���������� �ǹǷ� �������� ����
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

//���� Ž���ϸ鼭 ������ϰ�� �ش繰����� ��ġ�� �������ְ� �ƴҰ�� �������� ���̿켱Ž��
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

			if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;	//���� Ż���������
			if (Distance[ny][nx] != -1) continue;					//�湮�� �̹� �������
			if (map[ny][nx] > babySize) continue;					//���� ����Ⱑ Ŭ ��� 
																	//�̷��� ����ϰ�� �������� ���ư�
			//����Ⱑ ���� �۰�, �� ĭ�� �ƴ� ������ϰ�� == ����� �Ա� ����
			else if (map[ny][nx] < babySize && map[ny][nx] >= 1) {	
				fish.push_back({ nx, ny });//�� ����⸮��Ʈ�� �߰�
				q.push({ nx, ny });
				Distance[ny][nx] = Distance[y][x] + 1;
			}
			//����Ⱑ ���� ũ�Ⱑ ���� ���� �� ĭ�ϰ�� == �̵�����
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
	//��Ƹ��� ����Ⱑ �������
	if (fish.size() == 0) {
		cout << Second << endl;
		return false;
	}
	//��Ƹ��� �� �ִ� ����Ⱑ �� 1�����ϰ��
	if (fish.size() == 1) {
		auto target = fish.front();
		Second += Distance[target.second][target.first];
		sX = target.first;
		sY = target.second;
		eatfish++;
	}
	else {
		int minDis = 100000;

		//���� �Ÿ��� ª�� ����� Ž��
		for (auto& f : fish) {
			minDis = min(minDis, Distance[f.second][f.first]);
		}
		vector<pair<int, int>> minfish;
		for (auto& f : fish) {
			if (minDis == Distance[f.second][f.first]) {
				minfish.push_back({ f.first,f.second });
			}
		}
		//���� �Ÿ��� ª�� ����Ⱑ �Ѹ����ϰ��
		if (minfish.size() == 1) {
			auto target = minfish.front();
			Second += Distance[target.second][target.first];
			sX = target.first;
			sY = target.second;
			eatfish++;
		}
		//���� �Ÿ��� ª�� ����Ⱑ �������� �� ���
		else {
			//���ʰ��� ���� �ִ� ����⸦ �������� ��������
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
		reset();	//�� �������� üũ�ߴ� �Ÿ� �� ����� �迭 �ʱ�ȭ
		growUp();	//�� ����⸦ �ڽ�ũ�⸸ŭ �Ծ��� ��� �����Ŵ
		bfs();		//����� Ž��
	} while (eatFish());	//���� ����Ⱑ ������� �ݺ�����

	return 0;
}