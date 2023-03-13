/*
* 1.아이디어
* 모든 휴게소 끼리 오름차순정렬하고 서로의 거리를 저장
* 
* 해당 거리들을 거리끼리 가장 큰 값을 start, 0을 end로 해서 이분탐색을 한다.
* 중간값 mid를 만들어서 각 휴게소 끼리의 거리를 mid로 나누고 나온 값을 total에 저장한다.
* 이때 몫이 해당 사이 거리에 최대한 텀이 길게 설치할 수 있는 값인 mid를 기준으로
* 몇개나 설치 할 수있는지이다.
* 만약 total이 M과 같거나 크다면, mid가 커져야 하므로 start = mid + 1, answer = mid;
* 만약 total이 M보다 작다면, end = mid - 1
* 
* (틀린부분)
* 전부 맞았고 모든 아이디어도 맞았지만 조건을 하나 생각을 안했다.
* 그것은 이미 휴게소가 설치 된 곳은 확인해서 빼줘야 한다는 것이다. 
* 같은위치에 2개의 휴게소가 있을 수 없으므로 제거해야했다.
* 
* if (dist[i] % mid == 0)
	total--;

* 2.시간복잡도
* 휴계소가 50개므로 사이거리는 49, 최대 사이 거리는 998, 따라서 O(NlogL) 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, M, L, answer = 0;
	cin >> N >> M >> L;

	vector<int> dist;
	vector<int> loc(N);
	for (auto& i : loc)
		cin >> i;

	loc.push_back(0);
	loc.push_back(L);

	sort(loc.begin(), loc.end());

	for (int i = 0; i <= N; i++) {
		int temp = loc[i + 1] - loc[i];
		dist.push_back(temp);
	}
 
	dist.begin();
	int start = 1;
	int end = L;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		int total = 0;
		for (int i = 0; i < dist.size(); i++) {
			total += dist[i] / mid;
			//이 부분을 생각못함
			if (dist[i] % mid == 0)
				total--;
		}
		if (total <= M) {
			end = mid - 1;
			answer = mid;
		}
		else
			start = mid + 1;
	}

	cout << answer;

	return 0;
}