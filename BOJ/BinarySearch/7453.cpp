/*
* 1.아이디어
* 각 배열을 저장해줄 arr[4][N] 생성
* 입력을 저장한 후에 A와 B, C와 D끼리 조합해서 백터에 저장 A : arr[0][N] B : arr[1][N] C : arr[2][N] D : arr[3][N]
* 
* 2개의 백터를 오름차순 정렬
* 정렬한 백터 A를 기준으로 백터B에서 해당 수와 더했을 때 0이 되는 수를 찾음, 만약 찾았을 경우 찾은 값의 첫번째부터 마지막까지의 인덱스를 가져와서
* 몇개나 잇는지 확인, 확인 후 answer에 추가
* 
* 2.시간복잡도
* AB와 CD의 조합으로 생기는 원소의 수 = N^2
* 이분탐색을 N^2번 하므로 O(N^2logN) N<=4000 따라서 가능
* 3.변수형
* long long : 최대 나올 수 있는 경우의 수는 N^4 따라서 long long 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, answer = 0;
	vector<int> A;
	vector<int> B;

	cin >> N;

	vector<vector<int>> arr(4, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A.push_back(arr[0][i] + arr[1][j]);
			B.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++) {
		int low = lower_bound(B.begin(), B.end(), -A[i]) - B.begin();
		int high = upper_bound(B.begin(), B.end(), -A[i]) - B.begin();

		answer += high - low;
	}

	cout << answer;

	return 0;
}