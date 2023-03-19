/*
* 1.아이디어
* 입력받은 보드에 0이 나올경우 3가지 경우를 모두 확인해서 해당 자리에 없는 숫자를 찾는다.
* 만약 0이 2개이상 나온다면 해당연산은 실패하게 한다.
* 
* (맞는 아이디어)
* 빈칸의 위치를 저장하는것은 맞지만 항상 빈칸이 가능할거라고 생각하면 안된다.
* 따라서 백트래킹을 사용해 해당 빈칸이 모든 수를 다 넣어봐야하는것이다.
* 이유는 칸이 여러개 비어있을경우 들어갈 수 있는 수의 개수가 더 늘어날 수 있으므로
* 모든 경우의 수를 확인해야 되고, 이를 백트래킹기법으로 모든위치를 다 확인해서 체크해야한다.
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int N;
bool found = false;
vector<pair<int, int>> zero;

bool Check(pair<int, int> loc) {
	int x = loc.second;
	int y = loc.first;

	for (int i = 0; i < 9; i++) {
		if (board[y][i] == board[y][x] && i != x)
			return false;
		if (board[i][x] == board[y][x] && i != y)
			return false;
	}
	int startX = (x / 3) * 3;
	int startY = (y / 3) * 3;
	for (int i = startY; i < startY + 3; i++) {
		for (int j = startX; j < startX + 3; j++) {
			if (board[i][j] == board[y][x]) {
				if (i != y && j != x)
					return false;
			}
		}
	}
	return true;
}

void sudoku(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		found = true;
		return;
	}
	int x = zero[cnt].second;
	int y = zero[cnt].first;
	for (int j = 1; j <= 9; j++)
	{
		board[y][x] = j;
		if (Check(zero[cnt]))
			sudoku(cnt + 1);
		if (found)
			return;
	}
	board[y][x] = 0;
	return;
}

int main(void) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				N++;
				zero.push_back({ i, j });
			}
				
		}
	}

	sudoku(0);

	return 0;
}