/*
* 1.아이디어
* 각 하우스 빨강 초록 파랑으로 했을 때 최소비용을 저장하는 배열house[1001][3]
* house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[0] 0, 빨간색을 골랐을 경우의 현재까지 코스트
* 답은 min(house[N][0], min(house[N][1], house[N][2]))
* 2.시간복잡도
* O(N), N<=1000 이므로 가능
* 3.변수형
* int:아무리 코스트가 높아도 1000*1000이므로 int
*/
/*
* 문제풀이
* 각 색깔을 나눠서 생각해서 빨간색을 골랐을때, 이전의 파랑색 초록색의 값을 가져와 최소가 되도록 해주고
* 해당 집에 모든색을 확인했을때, house[해당집]에는 빨, 초, 파를 골랐을 때 최소가 되는 값이 들어있다.
* 이것을 다음 인덱스에서 최소를 구할때 다시 사용되게 되고 해당 인덱스 또한 최소값을 찾을 수 있게 된다.
*/
#include <iostream>

using namespace std;

int house[1001][3];

int main(void) {

	int N;
	cin >> N;

	int cost[3];

	for (int i = 1; i <= N; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[2];
	}
	cout << min(house[N][0], min(house[N][1], house[N][2]));
	return 0;
}