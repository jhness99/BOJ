/*
* 1.아이디어
* (틀린아이디어)
* 각 수를 저장해서 한층한층 내려갈때마다 이전값에 자신의 값을 더해준다.
* 이때 자신에게 기존값을 비교해서 만약 더 클경우 큰 값으로 바꿔준다.
* 반복하다가 마지막 행에서 열의 최대값을 구하면된다.
* 
* 가장 밑에서 시작해서 위의 수에 아랫수 2개를 비교해 더 큰 수를 위에수에 더해준다
* 가장 위에있는 dp[0][0]이 가장 큰수를 더해 최종결과가 된다.
* 2.시간복잡도
* O(N^2), N <= 500 따라서 가능
* 3.변수형
* int : 삼각형의 각 정수의 최대값이 9999이므로 int
*/
#include <iostream>
#include <vector>

using namespace std;


int main(void) {

	int N;
	cin >> N;

	vector<vector<int>> v(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}
	}
	
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			v[i - 1][j] += max(v[i][j], v[i][j + 1]);
		}
	}

	cout << v[0][0];

	return 0;
}