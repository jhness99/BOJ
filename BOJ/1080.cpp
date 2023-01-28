#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

	int N, M;
	int cnt = 0;
	cin >> N >> M;

	vector<vector<int>> v1(N, vector<int>(M));
	vector<vector<int>> v2(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M ; j++) {
			v1[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			v2[i][j] = temp[j] - '0';
		}
	}

	//두 행렬을 비교해서 해당하는 위치가 다를경우
	//3x3 범위를 전부 수를 바꾸어준다.
	//이때 3x3이 안될경우는 바꾸지 않는다. 따라서 N-2, M-2까지만 탐색해준다.
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			if (v1[i][j] != v2[i][j]) {
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						v1[k][l] = (v1[k][l] == 0 ? 1 : 0);
					}
				}
				cnt++;
			}
		}
	}

	//행렬의 모든 수를 탐색하며 다를경우 -1을 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v1[i][j] != v2[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt;
	return 0;
}