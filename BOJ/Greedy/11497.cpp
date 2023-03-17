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
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(void) {
//	int T, N;
//	cin >> T;
//	for (int testCase = 0; testCase < T; testCase++) {
//		int answer = 0;		//난이도
//		cin >> N;
//		vector<int> v(N);
//		for (auto& i : v)
//			cin >> i;
//
//		sort(v.begin(), v.end());
//		//오름차순으로 2번째 뒤에있는 수와 빼서 나온 값을 현재 난이도(현재까지 가장 큰 난이도)와 비교
//		for (int i = 0; i < v.size() - 2; i++) {
//			answer = max(answer, v[i+2]-v[i]);
//		}
//		cout << answer << "\n";
//	}
//	return 0;
//}
//2023-02-24 복습
/*
* 1.아이디어
* 수열을 정렬해서 가장 큰 수를 기준으로 양쪽에 내림차순으로 수를 정렬한다고 생각해보자
* 예를들어 1 2 3 6 7 9 일 경우 3 7 9 6 2 1로 정리할 수 있고, 각 수는 자신의 위치 -2, +2의 수와 비교한다.
* 따라서 -2와 +2를 비교하면 되는데, 이때 -2한 값은 안해도 된다. 이유는 -2한 값이 이미 +2에서 해당 값을 비교했기 때문이다
* 2.시간복잡도
* 정렬을 사용했으므로 O(NlogN), N<=10000, 따라서 가능
* 3.변수형
*
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int N, Max = -1;
//		cin >> N;
//
//		vector<int> v(N);
//		for (auto& i : v)
//			cin >> i;
//
//		sort(v.begin(), v.end());
//
//		for (int i = 0; i < N - 2; i++)
//			Max = max(Max, v[i + 2] - v[i]);
//
//		cout << Max;
//	}
//
//	return 0;
//}
//2023-03-17 복습
/*
*1.아이디어
* 입력받은 수가 있을 때 가장 큰 수를 가운데 두고 양 옆에 그 다음 큰수로 둘러 싸는 형태의 수열을 하면
* 사이사이의 간격이 최소가 되서 그중 가장 큰 값을 구하면 된다.
*
*우선 정렬을 하고 i N - 2까지 반복하며 i + 1과 i + 2사이의 값을 구해서 더 큰 값이 나올때마다 갱신하는 것이다.
* 2.시간복잡도
* sort를 사용하므로 O(NlogN), N <= 10000 따라서 가능
* /
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		vector<int> input(N);
		for (auto& i : input)
			cin >> i;

		sort(input.begin(), input.end());

		int answer = input[N - 1] - input[N - 2];
		for (int i = 0; i < N - 2; i++) {
			answer = max(answer, input[i + 2] - input[i]);

			//이건 안해도 된다. 그 이유는 오름차순 정렬되있기 때문에 
			//무조건 i+1위치의 것보다 크다. 가장 작은 최대값을 구해야 하므로 i+1은 고려하지 않아도 되는것이다. 해도 답은 맞았다..
			answer = max(answer, input[i + 1] - input[i]);

		}
		cout << answer << "\n";
	}


	return 0;
}