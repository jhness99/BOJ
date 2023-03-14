/*
* 1.아이디어
* N<=1000000, M<=2000000000 
* 따라서 단순 브루트포스를 사용하면 최대 O(MN)이 되기 때문에 이진탐색을 사용한다.
* 
* 이진탐색을 이용해 중앙값을 기준으로 잘랐을 때 나오는 나무의 총 길이를 확인한다.
* start을 0, 가장 큰 나무의 길이를 end으로 해서 이진탐색을 한다.
* 확인한 길이가 내가 원하는 길이보다 작다면, end = mid -1
* 확인한 길이가 내가 원하는 길이보다 크거나 같다면, start = mid + 1, answer = mid;
* (자르는 길이를 줄이려면 start를 키우고, 자르는 길이를 늘리려면 end를 줄이면 된다.)
* 이렇게 갱신해주는 이유는 크거나 같을 때 갱신해주고 mid를 조절해 자르는 양을 줄인다면,
* 최종적으로 크거나 같은 경우일 때의 길이가 원하는 만큼을 자르고도 가장 높은 나무를 가지는 자르는 높이이기 때문이다.
* 
* start > end 가 될 때 까지 while 반복
* 2.시간복잡도
* 이분탐색을 사용했고 N만큼 확인해야하므로 O(NlogM)이다.
* 3.변수형
* long long total : 나무의 최대값이 1000000000 이므로 long long
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, M, answer = 0;

	cin >> N >> M;

	int left = 0;
	int right = -1;

	vector<int> tree(N);

	for (auto& i : tree) {
		int temp;
		cin >> temp;
		i = temp;
		right = max(right, temp);
	}
		
	while (left <= right) {
		int mid = (left + right) / 2;
		long long total = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid)
				total += tree[i] - mid;
		}
		if (total < M)
			right = mid - 1;
		else{
			answer = mid;
			left = mid + 1;
		}
	}
	cout << answer;

	return 0;
}
//2023-03-14 복습
/*
* 1.아이디어
* 최대 나무길이가 10억이고 가져갈 나무 길이가 최대 20억이기 때문에
* 최악의 경우 10억번 확인해야하므로 이분탐색을 사용해서 풀어야 한다.
*
* 가장 긴 나무를 right, 0을 left로 하고 이분탐색을 시작
* mid를 구해서 mid로 설정했을 때 각 나무들이 잘리는 값을 total에 저장한다. (total += tree[i] - mid )
* 이때 -가 더해지지 않도록 tree가 mid보다 같거나 클 경우만 더해준다.
* 더한 total이 최소한으로 필요한 양에 근접하도록
* total이 M과 같거나 크다면, mid를 키워줘야 하므로 start = mid + 1, answer = mid;
* total이 M보다 작다면, mid를 줄여줘야 하므로 end = mid -1;
*
* 2.시간복잡도
* 이분탐색에서 N개의 나무만큼 반복하므로, O(NlogMax) N<=100000, 따라서 가능
* 3.변수형
* long long total : 최악의 경우 10억을 100000번 더해야 할 수 있으므로 long long
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, answer = 0;
	cin >> N >> M;

	int Max = -1;
	vector<int> tree(N);
	for (auto& i : tree) {
		cin >> i;
		Max = max(Max, i);
	}

	int left = 0;
	int right = Max;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long total = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] >= mid)
				total += tree[i] - mid;
		}

		if (total >= M) {
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}