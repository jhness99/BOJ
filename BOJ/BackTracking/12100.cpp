/*
* 1.아이디어
* 모든경우를 확인하는 dfs로 하기로 한다.
* 먼저 모든 방향, 즉 합쳐지는 방향을 변수로 저장한다. (dx, dy)
* DFS의 반복문으로 4방향으로 이동시키고, 각 방향 이동이 끝나면 되돌아 오는 연산을 한다.
* 이 과정은 횟수가 5가 되지 않았다면 작동하고 만약 5가 된다면 연산을 하지 않고 최대값을 찾아서 갱신해준다.
* 
* 2.시간복잡도
* 
* 3.변수형
* 
*/
#include <iostream>

using namespace std;

int N, answer = -1;
int map[20][20];
int CopyMap[20][20];
int Selected[5];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void Move_Left() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = j + 1;
				while (k <= N - 1) {
					if (CopyMap[i][k] != 0) {
						Check = true;
						break;
					}
					k++;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[i][k];
					CopyMap[i][k] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (CopyMap[i][j] == CopyMap[i][j + 1]) {
				CopyMap[i][j] = CopyMap[i][j] * 2;
				CopyMap[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = j + 1;
				while (k <= N - 1) {
					if (CopyMap[i][k] != 0) {
						Check = true;
						break;
					}
					k++;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[i][k];
					CopyMap[i][k] = 0;
				}
			}
		}
	}
}

void Move_Right() {
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j > 0; j--) {
			bool Check = false;
			if (CopyMap[i][j] == 0){
				int k = j - 1;
				while (k >= 0){
					if (CopyMap[i][k] != 0){
						Check = true;
						break;
					}
					k--;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[i][k];
					CopyMap[i][k] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > 0; j--) {
			if (CopyMap[i][j] == CopyMap[i][j - 1]) {
				CopyMap[i][j] = CopyMap[i][j] * 2;
				CopyMap[i][j - 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > 0; j--) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = j - 1;
				while (k >= 0) {
					if (CopyMap[i][k] != 0) {
						Check = true;
						break;
					}
					k--;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[i][k];
					CopyMap[i][k] = 0;
				}
			}
		}
	}
}

void Move_Up() {
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N; j++) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = i + 1;
				while (k <= N - 1) {
					if (CopyMap[k][j] != 0) {
						Check = true;
						break;
					}
					k++;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[k][j];
					CopyMap[k][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			if (CopyMap[i][j] == CopyMap[i + 1][j]) {
				CopyMap[i][j] = CopyMap[i][j] * 2;
				CopyMap[i + 1][j] = 0;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = i + 1;
				while (k <= N - 1) {
					if (CopyMap[k][j] != 0) {
						Check = true;
						break;
					}
					k++;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[k][j];
					CopyMap[k][j] = 0;
				}
			}
		}
	}
}

void Move_Down() {
	for (int i = N-1; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = i - 1;
				while (k >= 0) {
					if (CopyMap[k][j] != 0) {
						Check = true;
						break;
					}
					k--;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[k][j];
					CopyMap[k][j] = 0;
				}
			}
		}
	}

	for (int i = N-1; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			if (CopyMap[i-1][j] == CopyMap[i][j]) {
				CopyMap[i][j] = CopyMap[i][j] * 2;
				CopyMap[i-1][j] = 0;
			}
		}
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < N; j++) {
			bool Check = false;
			if (CopyMap[i][j] == 0) {
				int k = i - 1;
				while (k >= 0) {
					if (CopyMap[k][j] != 0) {
						Check = true;
						break;
					}
					k--;
				}
				if (Check == true) {
					CopyMap[i][j] = CopyMap[k][j];
					CopyMap[k][j] = 0;
				}
			}
		}
	}
}

void ResetMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			CopyMap[i][j] = map[i][j];
	}
}

int Find_Max()
{
	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (CopyMap[i][j] > Max)
			{
				Max = CopyMap[i][j];
			}
		}
	}
	return Max;
}


void Play() {
	for (int i = 0; i < 5; i++) {
		int dir = Selected[i];

		switch (dir)
		{
		case 0:
			Move_Right();
			break;
		case 1:
			Move_Down();
			break;
		case 2:
			Move_Left();
			break;
		case 3:
			Move_Up();
			break;
		}
	}
	answer = max(answer, Find_Max());
}


void DFS(int cnt, int dir) {
	if (cnt == 5) {
		ResetMap();
		Play();
		return;
	}
	for (int i = 0; i < 4; i++) {
		Selected[cnt] = i;
		DFS(cnt + 1, dir);
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0, 0);

	cout << answer;

	return 0;
}