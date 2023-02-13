//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M;
//	int cnt = 0;
//	cin >> N >> M;
//
//	vector<vector<int>> v1(N, vector<int>(M));
//	vector<vector<int>> v2(N, vector<int>(M));
//
//	for (int i = 0; i < N; i++) {
//		string temp;
//		cin >> temp;
//		for (int j = 0; j < M ; j++) {
//			v1[i][j] = temp[j] - '0';
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		string temp;
//		cin >> temp;
//		for (int j = 0; j < M; j++) {
//			v2[i][j] = temp[j] - '0';
//		}
//	}
//
//	//두 행렬을 비교해서 해당하는 위치가 다를경우
//	//3x3 범위를 전부 수를 바꾸어준다.
//	//이때 3x3이 안될경우는 바꾸지 않는다. 따라서 N-2, M-2까지만 탐색해준다.
//	for (int i = 0; i < N-2; i++) {
//		for (int j = 0; j < M-2; j++) {
//			if (v1[i][j] != v2[i][j]) {
//				for (int k = i; k < i + 3; k++) {
//					for (int l = j; l < j + 3; l++) {
//						v1[k][l] = (v1[k][l] == 0 ? 1 : 0);
//					}
//				}
//				cnt++;
//			}
//		}
//	}
//
//	//행렬의 모든 수를 탐색하며 다를경우 -1을 출력
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (v1[i][j] != v2[i][j]) {
//				cout << -1;
//				return 0;
//			}
//		}
//	}
//
//	cout << cnt;
//	return 0;
//}
//2023-02-13 복습
/*
* 1.아이디어
* 배열을 입력받아서 3x3을 변환해주는 연산을 하고 연산이 끝나고 두개의 배열이 서로 같은지 확인하면 된다.
* 이때 해당 연산은 3x3이므로 3x3보다 작으면 -1을 반환하고 3x3이 정확하게 바꿔야 하므로 4x4행렬의 경우 0,1의 인덱스만 연산을
* 할 수 있다.
* 2.시간복잡도
* O(NM) N,M<= 50, 따라서 가능
* 3.변수형
* int :
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, M, answer = 0;
	cin >> N >> M;

	vector<vector<char>> map1(N, vector<char>(M));
	vector<vector<char>> map2(N, vector<char>(M));

	for (auto& v : map1)
		for (auto& i : v)
			cin >> i;

	for (auto& v : map2)
		for (auto& i : v)
			cin >> i;

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (map1[i][j] != map2[i][j]) {
				for (int k = i; k <= i + 2; k++) {
					for (int l = j; l <= j + 2; l++) {
						if (map1[k][l] == '1')
							map1[k][l] = '0';
						else
							map1[k][l] = '1';
					}
				}
				answer++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map1[i][j] != map2[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << answer;

	return 0;
}