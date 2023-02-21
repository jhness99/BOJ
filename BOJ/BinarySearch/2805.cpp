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