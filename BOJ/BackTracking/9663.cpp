/*
* 1.아이디어
* N-Queen은 유명한 백트래킹 문제이므로 푸는법은 알고있지만 막상 코드로 구현하려니 이해가 잘 안됬다.
* 
* 기본적인 로직은 이렇다.
* board[i] i행의 퀸의 열을 저장함 예를 들어 0행 1열에 있다면 board[0] == 1
* 이제 0행부터 0~N-1까지의 숫자를 넣어 확인한다
* 넣어주고 확인해서 위에 이미 기록한 퀸의 공격반경과 겹친다면 false, 안겹친다면 true를 반환한다.
* 내가 구현하기 힘들었던 부분이 바로 이 부분인데 이 부분은 이렇게 하면 된다.
* 
* 기본적으로 공격방향은 아래와 대각선 방향을 확인한다.
* 이때 0부터 확인하려고 하는 곳 까지의 모든 행을 확인하는데 해당 행들의 퀸 위치가 바로 아래면 안되므로 
* board[y] == board[i] 일경우 false, 대각선또한 확인해줘야하므로 두 위치의 세로길이와 가로길이가 같다면 대각선에 있는것이므로
* abs(board[y] - board[i]) == y - i 일경우 false반환한다. 이 로직은 0->y-1까지 진행되고 만약 모든 퀸에대해 공격범위에 안 닫는다면 true를 반환한다.
* 
* 해당 확인로직이 true라면, 행의 위치를 1 올려 nqueen(y+1)을 해준다.
* 
*/
#include <iostream>

using namespace std;

int N, answer;

int board[15];

bool check(int y) {
	for (int i = 0; i < y; i++) {
		if (board[i] == board[y] || abs(board[y] - board[i]) == y - i)
			return false;
	}
	return true;
}

void nqueen(int y) {
	if (y == N)
		answer++;
	else {
		for (int i = 0; i < N; i++) {
			board[y] = i;
			if(check(y))
				nqueen(y + 1);
		}
	}
}

int main(void) {

	cin >> N;
	
	nqueen(0);

	cout << answer;

	return 0;
}