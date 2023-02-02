/*
* 1.아이디어
* //중간값과 가장 큰 값의 차가 최소난이도(틀림)
* 주어진 수들이 가장 작은 난이도를 가지려면 최대값을 그보다 작은 2개의 수가 감싸지게 구성되어야한다 ex)7 8 9 -> 7 9 8
* 이렇게 된다면 해당 수열은 i와 i+2번째의 수의 차가 각 수의 인접한 수와의 차 중에서 가장 큰 수가 된다.
* 2.시간복잡도
* O(N) = 10000
* 3.변수
* vector<int> : 해당 케이스때 입력되는 통나무들의 길이 저장 백터
* int : 난이도는 100000-1이 가장 높게 나올수 있는 수 이므로 int
*/
/*
* 문제풀이
* 시작부터 틀린문제. 문제에 예시를 보고 떠올릴 수 있었는데, 그걸 몰랐다.
* 위에 적은 아이디어 처럼 i+2번째 수에 i를 빼서 (정렬되있기때문에 i+2가 i 보다 무조건 크거나 같음) 
* 뺀 값이 기존에 확인했던 다른 난이도들과 비교해서 더 크면 해당 값을 난이도로 저장한다.
* ex)1 2 3 4 5 6 7 8 9 -> 1 3 5 7 9 8 6 4 2 가장 큰 값이 중앙으로 가고 그 좌 우를 그 수보다 1번째, 2번째 작은 수로 감싼다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T, N;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		int answer = 0;		//난이도
		cin >> N;
		vector<int> v(N);
		for (auto& i : v)
			cin >> i;

		sort(v.begin(), v.end());
		//오름차순으로 2번째 뒤에있는 수와 빼서 나온 값을 현재 난이도(현재까지 가장 큰 난이도)와 비교
		for (int i = 0; i < v.size() - 2; i++) {
			answer = max(answer, v[i+2]-v[i]);
		}
		cout << answer << "\n";
	}
	return 0;
}