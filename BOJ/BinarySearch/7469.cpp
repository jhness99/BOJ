/*
* 1.아이디어
* 세그먼트 트리에서 응용된 머지 소트 트리를 사용해야 한다
* 
* 머지 소트 트리를 몰라서 찾아봤다.
* 머지 소트 트리란 세그먼트 트리처럼 범위를 기준으로 수열을 분리해서 
* 해당 범위의 수들을 정렬 한 것을 노드에 넣는다.
* 
* 탐색은 세그먼트 트리의 누적합과 같이 하면 된다. 
* 순서는 범위 안에 있는 노드에 있는 수열에서 해당 수의 upper_Bound를 찾으면된다.
* upper_bound를 하는 이유는 초과된 위치, 즉 작거나 같은 경우의 숫자가 해당 숫자의 index 이므로
* 각 노드의 upper_bound를 더하면 해당 수의 위치가 나오게 된다. 
* 따라서 모든 노드의 확인하는 수를 upper_bound로 index를 찾아서 더해주면, 위치가 나오게 된다.
* 
* 만들어진 노드들로 이루어진 트리를 이분탐색을 이용해 가능한 숫자의 범위로
* 해당 범위에서 각 번호가 몇번째인지 확인한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[400000];

void update(int node, int start, int end, int index, int value) {
	if (index < start || end < index) return;
	tree[node].push_back(value);
	if (start == end) return;
	update(node * 2, start, (start + end) / 2, index, value);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
}


int query(int node, int start, int end, int i, int j, int mid) {
	if (j < start || end < i) return 0;
	if (i <= start && end <= j) return upper_bound(tree[node].begin(), tree[node].end(), mid) - tree[node].begin();
	int m1 = query(node * 2, start, (start + end) / 2, i, j, mid);
	int m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j, mid);

	return m1 + m2;
}

int main(void) {

	int N, M;
	cin >> N >> M;

	vector<int> arr(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(1, 1, N, i, arr[i]);
	}

	for (int i = 0; i < 400000; i++) sort(tree[i].begin(), tree[i].end());

	while (M--) {
		int i, j, k;
		cin >> i >> j >> k;
		int left = -1e9, right = 1e9;
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;
			if (query(1, 1, N, i, j, mid) < k) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << left << "\n";
	}

	return 0;
}