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
//#include <iostream>
//using namespace std;
//
//long long dp[101][101];		//자료형 int로해서 틀림
//int map[101][101];
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	dp[1][1] = 1;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (dp[i][j] == 0 || (i == N && j == N)) continue;
//
//			int Value = map[i][j];
//			int Down = Value + i;
//			int Right = Value + j;
//
//			if (Down < N) dp[Down][j] = dp[Down][j] + dp[i][j];
//			if (Right < N) dp[i][Right] = dp[i][Right] + dp[i][j];
//		}
//	}
//
//	cout << dp[N][N];
//	return 0;
//}
//2023-03-09 복습
/*
* 1.아이디어
* NxN의 map과 dp를 만든다
* 이때 dp[i][j]는 i행 j열이 시작위치에서 도착할 수 있는 경로의 개수를 의미한다.
* dp는 모두 0으로 초기화하고 0인값은 확인하지 않음
* 0이 아니고 해당 수가 N을 넘지 않았다면, 해당값을 기준으로 오른쪽과 아랫쪽을 모두 계산
* 계산하고 만약 범위를 넘지않고 갈 수 있다면, dp[ny][nx] = dp[i][j] + dp[ny][nx]를 한다.
* 이러면 해당 경로로 가는 경로의 개수가 늘어나게 된다.
*
* 마지막으로 dp[N][N]을 해서 값을 가져오면 해당 값이 정답이 된다. N행 N열로 가는 모든 경로의 개수이기 때문이다.
*
* 2.시간복잡도
* O(N^2) N<=100 따라서 가능
* 3.변수형
* long long dp : 경로의 개수가 최대 2^63 - 1 이므로 long long으로 선언
*/
#include <iostream>

using namespace std;

long long dp[101][101];
int map[101][101];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

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
			if (dp[i][j] == 0 || (i == N && j == N))
				continue;

			int nx = j + map[i][j];
			int ny = i + map[i][j];

			if (nx <= N) dp[i][nx] = dp[i][nx] + dp[i][j];
			if (ny <= N) dp[ny][j] = dp[ny][j] + dp[i][j];
		}
	}

	cout << dp[N][N];

	return 0;
}