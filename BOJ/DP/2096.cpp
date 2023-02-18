/*
* 1.아이디어
* (틀린아이디어)
* Min과 Max 배열을 만든다.
* 입력 받은 수를 Max와 Min에 저장한다.
* 새로운 수를 받을 때 위의 수와 비교해서 더 큰 수를 더해주면 된다.
* 예를 들면 1번줄을 초기화 할 때는 0번째(0으로 초기화되있음)을 하나하나 확인해서 초기화 해주는 것이다.
* Max[1][0] += max(Max[0][0], Max[0][1]), Max[1][1] += max(Max[0][0], max(Max[0][1], Max[0][2])), Max[1][2] += max(Max[0][1], Max[0][2])
* 똑같이 Min에도 해주고 마지막번째의 줄에서 가장 큰 수를 찾아주면 된다.
* 
* (맞은아이디어)
* 메모리 제한때문에 틀릴 줄 알았지만 그냥 연습겸 평소dp를 풀던대로 풀어봤다.
* 물론 내가 생각한 알고리즘자체는 맞았다. 그래서 그냥 dp를 무작정 길게 하지 않고
* 한줄을 계속 초기화 하는 식으로 바꿔주면 된다.
* 
* 2.시간복잡도
* O(N), N<=100000, 따라서 가능
* 3.변수형
* int
*/
#include <iostream>

using namespace std;

//int Max[100001][3];		//메모리제한
//int Min[100001][3];

int MaxDP[3];
int MinDP[3];

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < 3; i++) {
		int temp;
		cin >> temp;
		MaxDP[i] = temp;
		MinDP[i] = temp;
	}

	for (int i = 1; i < N; i++) {
		int input[3];
		cin >> input[0] >> input[1] >> input[2];
		int temp0 = MaxDP[0];
		int temp1 = MaxDP[1];
		int temp2 = MaxDP[2];

		MaxDP[0] = max(MaxDP[0], MaxDP[1]) + input[0];
		MaxDP[2] = max(MaxDP[1], MaxDP[2]) + input[2];
		MaxDP[1] = max(max(temp0, temp1), temp2) + input[1];

		temp0 = MinDP[0];
		temp1 = MinDP[1];
		temp2 = MinDP[2];

		MinDP[0] = min(MinDP[0], MinDP[1]) + input[0];
		MinDP[2] = min(MinDP[1], MinDP[2]) + input[2];
		MinDP[1] = min(min(temp0, temp1), temp2) + input[1];
	}
	int maxNum = max(max(MaxDP[0], MaxDP[1]), MaxDP[2]);
	int minNum = min(min(MinDP[0], MinDP[1]), MinDP[2]);

	cout << maxNum << " " << minNum;

	//메모리 제한
	/*for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			Max[i][j] = temp;
			Min[i][j] = temp;
		}
		Max[i][0] += max(Max[i - 1][0], Max[i - 1][1]);
		Max[i][1] += max(Max[i - 1][0], max(Max[i - 1][1], Max[i - 1][2]));
		Max[i][2] += max(Max[i - 1][1], Max[i - 1][2]);

		Min[i][0] += min(Min[i - 1][0], Min[i - 1][1]);
		Min[i][1] += min(Min[i - 1][0], min(Min[i - 1][1], Min[i - 1][2]));
		Min[i][2] += min(Min[i - 1][1], Min[i - 1][2]);
	}

	int maxNum = Max[N][0];
	int minNum = Min[N][0];
	for (int i = 1; i < 3; i++) {
		maxNum = max(maxNum, Max[N][i]);
		minNum = min(minNum, Min[N][i]);
	}

	cout << maxNum << " " << minNum;*/

	return 0;
}