/*
* 1.아이디어
* arr[15][15]배열생성
* arr[0][1] ~ arr[0][14]를 1~14로 설정
* arr[k][n] = arr[k-1][n] + arr[k][n-1]
* 2.시간복잡도
* O(N^2), N <= 14 따라서 가능
* 3.변수형
* int : 
*/
#include <iostream>

using namespace std;

int arr[15][15];

int main(void) {

	for (int i = 1; i < 15; i++) {
		arr[0][i] = i;
	}


	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << arr[k][n] << "\n";
	}

	return 0;
}
