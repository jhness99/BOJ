/*
* 1.아이디어
* 문제에 있는 조건을 수식으로 옮기지 못해서 햇갈렸다. 
* 해당 부분만 이해했다면 이분탐색으로 풀 수 있었을 것 같다.
* 
* 결국 찾아봐서 조건을 수식으로 옮긴것을 보니 아이디어가 완벽하게 생각났다.
* 
* 먼저 사냥꾼의 사대위치를 정렬한다.
* 동물의 위치를 pair로 입력받는다.
* 입력받은 위치를 하나하나 확인한다.
* 
* start = 0, end = 사대의 크기-1 을 해서 초기화
* mid를 만들어 사냥꾼 사대의 x위치를 받아와서 abs(vec[mid] - x) <= L - y 가 성립한다면, 해당 동물의 위치는 
* 탐색하고있는 사대에서 맞출수 있다. 맞출수 있다면 answer++ 한다.
* |vec[mid] - x| <= L - y 가 포함되는 경우라면 포함되지 않는경우는 |vec[mid] - x| > L - y이다. 절대값이므로 -와 +를 모두 고려해야 한다.
* 따라서 vec[mid] > L - y + x, vec[mid] <= L - y + x 2가지 경우를 고려해야한다.
* vec[mid] > L - y + x 일때 왼쪽으로 이동해야 하므로 mid가 더 작아져야 한다. 따라서 end = mid - 1
* vec[mid] <= L - y + x 일때 오른쪽으로 이동해야 하므로 mid가 더 커져야 한다. 따라서 start = mid + 1
* 
* 2.시간복잡도
* 각 동물을 기준으로 사대를 이분탐색으로 확인하므로 O(NlogM), N, M<=100000, 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, L, answer = 0;
	cin >> M >> N >> L;

	vector<int> Hunter(M);
	for (auto& i : Hunter)
		cin >> i;

	vector<pair<int, int>> animal(N);
	for (auto& p : animal)
		cin >> p.first >> p.second;

	sort(Hunter.begin(), Hunter.end());

	for (int i = 0; i < N; i++) {
		int x = animal[i].first;
		int y = animal[i].second;
		int start = 0;
		int end = Hunter.size() - 1;
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (abs(Hunter[mid] - x) <= L - y) {
				answer++;
				break;
			}
			if (Hunter[mid] > L - y + x)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}

	cout << answer;

	return 0;
}