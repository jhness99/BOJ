/*
* 문제풀이
* 문제를 이해하느라 시간을 좀 많이 걸렸다. 문제의 주 요점은 센서를 설치해놨는데 센서들의 자료를 수집할 집중국을 설치하고
* 해당 집중국의 수신가능영역의 총 합의 최소를 구하는 문제이다. 그렇다면 먼저 집중국을 설치 해야한다.
* 우선 센서간의 거리를 구하는데, 최소가 되는 거리를 구한다. 센서의 위치를 정렬해서 바로 옆의 거리를 구한다.
* 집중국의 수신가능영역과 영역의 개수는 집중국개수 - 1 이 되게 된다.
* 이때 최소의 영역이 되어야 하므로 가장 작은 거리 순서로 집중국개수 - 1 개를 하면 최소의 거리가 된다.
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, K, answer = 0;;
//
//	cin >> N >> K;
//	
//	vector<int> v(N);
//	vector<int> dist(N-1);
//
//
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end());
//	
//	for (int i = 0; i < v.size() - 1; i++) {
//		dist[i] = v[i + 1] - v[i];
//	}
//
//	sort(dist.begin(), dist.end());
//
//	for (int i = 0; i < dist.size() - (K - 1); i++) {
//		answer += dist[i];
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-14 복습
/*
* 1.아이디어
* 입력된 값들을 정렬해서 서로간의 거리를 저장한다.
* 해당 사이 거리들 중 K개의 집중국을 이용해서 수신가능한 구역을 확인하면, K-1개의 거리를 무시할 수 있다.
* 왜냐하면 범위를 지정했을 때 끝 부분까지 적용이 되므로 1 3 6 7 9 의 경우 1과 3 사이에 1개 6과 9사이에 1개를 두면
* 1 3 6 7 9 모두 적용되고, 3과 6사이의 거리는 수신불가여도 상관이 없으므로  그렇다.
* 따라서 가능한 큰 거리를 k-1개 만큼 처음부터 끝 부분까지의 거리에서 빼주면 되는것이다.
*
* 2.시간복잡도
* sort정렬을 사용했으므로 O(NlogN), N<=100000 따라서가능
* 3.변수형
*
*/
#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

	int N, K, answer = 0;
	cin >> N >> K;

	vector<int> dist;
	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	for (int i = 0; i < N - 1; i++) {
		dist.push_back(input[i + 1] - input[i]);
	}
	/*
	* 반대로 모든 거리에서 k-1개의 거리를 빼면 될것같다고 생각했지만
	* 만약 K > N 라면,input의 최솟값 최댓값 사이의 거리가 아무리 커도 0이기 때문에 틀렸던것이다.
	sort(dist.begin(), dist.end(), greater<>());

	answer = input.back() - input.front();

	for (int i = 0; i < K - 1; i++) {
		answer -= dist[i];
	}
	*/
	sort(dist.begin(), dist.end());

	for (int i = 0; i < N - K; i++)
		answer += dist[i];

	cout << answer;

	return 0;
}