/*
* 문제풀이
* 문제를 이해하느라 시간을 좀 많이 걸렸다. 문제의 주 요점은 센서를 설치해놨는데 센서들의 자료를 수집할 집중국을 설치하고
* 해당 집중국의 수신가능영역의 총 합의 최소를 구하는 문제이다. 그렇다면 먼저 집중국을 설치 해야한다.
* 우선 센서간의 거리를 구하는데, 최소가 되는 거리를 구한다. 센서의 위치를 정렬해서 바로 옆의 거리를 구한다.
* 집중국의 수신가능영역과 영역의 개수는 집중국개수 - 1 이 되게 된다.
* 이때 최소의 영역이 되어야 하므로 가장 작은 거리 순서로 집중국개수 - 1 개를 하면 최소의 거리가 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, K, answer = 0;;

	cin >> N >> K;
	
	vector<int> v(N);
	vector<int> dist(N-1);


	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size() - 1; i++) {
		dist[i] = v[i + 1] - v[i];
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < dist.size() - (K - 1); i++) {
		answer += dist[i];
	}

	cout << answer;

	return 0;
}