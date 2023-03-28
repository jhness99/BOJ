/*
* 1.아이디어
* 스도쿠-2580 문제와 비슷한 문제다. 백트래킹으로 모든 경우를 확인해주면 된다.
* 
* 우선 우리가 채워야 하는 위치와 개수를 저장한다.
* DFS를 사용해 모든 빈 칸에 가능한 모든 경우를 확인하는데 이때 하나의 수를 넣을 때 마다 해당수가 가능한지 확인을 해줘야 한다.
* 가능할경우 다음 빈칸을 채워준다. 최종적으로 모든 위치를 넣어줬을 때, check를 통과한다면 가능한 경우이므로
* 해당 보드를 출력해주고 모든 재귀로 호출한 DFS를 종료해주면 된다.
* 
* 이때 check함수는 해당 위치의 열, 행, 해당 빈칸이 어디 3x3에 해당하는지를 찾아 해당 열 행 사각형에 같은 수가 있을경우를 체크한다.
* 
* 
* 2.시간복잡도
* 
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> blanks;
vector<string> board(9);
int N;
bool found = false;

bool Check(pair<int, int> blank) {
	int x = blank.first;
	int y = blank.second;

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
			if (board[y][x] == board[i][j] && (x != j && y != i))
				return false;
		}
	}
	return true;
}

void sudoku(int cnt) {
	if (cnt == N) {
		for (auto& s : board)
			cout << s << "\n";
		found = true;
		return;
	}
	int x = blanks[cnt].first;
	int y = blanks[cnt].second;
	for (int i = 1; i < 10; i++) {
		board[y][x] = '0' + i;
		if (Check(blanks[cnt])) {
			sudoku(cnt + 1);
		}
		if (found)
			return;
		board[y][x] = 0;
	}
}

int main(void) {

	for (auto& s : board) {
		cin >> s;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '0') {
				N++;
				blanks.push_back({ j, i });
			}
		}
	}
	sudoku(0);

	return 0;
}