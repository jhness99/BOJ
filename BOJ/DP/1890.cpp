/*
* 1.아이디어
* 모든 경우를 탐사할 필요 없다. dp[N][N]을 0으로 초기화 하고 초기위치만 1로 설정한다.
* 그 후 오른쪽 아래쪽을 map의 해당 위치의 값 만큼 이동해서 확인한 후,
* 만약 범위를 나가지 않았다면, dp[ny][j] = dp[ny][j] + dp[i][j](아래쪽), dp[i][nx] = dp[i][nx] + dp[i][j](오른쪽)
* 으로 갱신해준다. 이때 갱신된 값이 해당 경로로 도착할 수 있는 경우의 수이다.
* 2.시간복잡도
* O(N^2), N<=100이므로 가능
* 3.변수형
* int map[101][101] : 입력 데이터를 저장할 맵
* long long dp[101][101] : 시작지점을 기준으로 해당 칸으로 갈 수 있는 경로의 수를 저장한 배열
*/
#include <iostream>
using namespace std;

long long dp[101][101];		//자료형 int로해서 틀림
int map[101][101];

int main(void) {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == 0 || (i == N && j == N)) continue;

			int Value = map[i][j];
			int Down = Value + i;
			int Right = Value + j;

			if (Down < N) dp[Down][j] = dp[Down][j] + dp[i][j];
			if (Right < N) dp[i][Right] = dp[i][Right] + dp[i][j];
		}
	}

	cout << dp[N][N];
	return 0;
}