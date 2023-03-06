/*
* 1.아이디어
* 도저히 생각해도 모르겠어서 검색을 해봤다.
* 처음에 생각한 것은 1~1000000까지의 맛을 저장할 배열을 만들고 해당 배열을 이용해
* 상자에 있는 사탕중 몇번째를 빼는지 계산하려 했다.
* 하지만 숫자가 너무 커서 하나하나 계산하다가는 100000*1000000이 되서 시간초과가 일어나게 된다.
* 
* 그래서 검색을 통해 세그먼트 트리를 사용해야 된다는 것을 알게 되었다.
* 세그먼트 트리란 구간을 저장하기 위한 트리이다.
* 예를 들어 1 2 3 4 5가 있다면 2부터 4까지의 합, 1부터 5까지의 합 등등을 구간으로 정해서 저장하는 것이다.
* 
* 이 문제에서 사용하는 세그먼트 트리 tree[i]는 i노드에서의 사탕 개수를 의미한다.
* 이때 i노드는 k의 맛 정도이다. 즉, k맛 정도를 가지는 i노드에 해당 맛 정도의 사탕개수가 저장되는 것이다.
* 
* 2가지 연산이 필요한대 새로운 값이 들어왔을 때 각 노드를 갱신해주는 연산과
* k번째로 맛있는 사탕의 맛을 가져와주는 연산이다.
* 
* 각 연산의 구현방법
* 갱신해주는 연산의 경우, 자신이 들어가야 하는 노드의 위치를 재귀함수로 탐색한다.
* 탐색한 위치 노드의 구간이 내가 갱신하고자 하는 값(K맛 정도)이라면 (이분탐색으로 인한 start, end)
* 해당 노드를 k맛 정도 사탕의 개수로 갱신해준다.
* 그리고 재귀이기 때문에 돌아가면서 해당 노드의 부모노드 또한 바뀐 값(갱신한 노드의 k맛정도 사탕 개수)으로
* 갱신된 값을 저장해준다.
* 
* k번째로 맛있는 사탕의 맛을 가져와주는 연산의 경우 이분탐색을 사용해서
* 탐색중인 노드의 왼쪽 자식을 기준으로 왼쪽 자식이 K보다 같거나 크다면, 해당 자식 노드 그룹중에서
* k번째로 맛있는 사탕이 있다는 뜻이므로 해당 노드를 기준으로 다시 탐색 시작
* 만약 왼쪽 자식이 k보다 작다면, 
* 오른쪽 자식의 그룹에서 k번째의 맛있는 사탕이 있다는 뜻이므로 해당 노드를 기준으로 다시 탐색 시작
* 만약 start와 end가 같아저서 탐색이 종료되야 한다면, 해당 end(start도 가능)가 k번째 사탕의 맛 정도를 의미한다.
* 2.시간복잡도
* 세그먼트 트리의 시간복잡도가 O(logMAX)이고 N번 반복하므로 O(NlogMAX) N<=100000, M<=1000000 따라서 가능
* 3.변수형
* 
*/
#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX];
int tree[MAX*4];

int query(int node, int start, int end, int k) {
	if (start == end)
		return end;

	int mid = (start + end) / 2;
	if (tree[node * 2] >= k)
		return query(node * 2, start, mid, k);
	else
		return query(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

void update(int node, int start, int end, int idx, int value) {
	if (idx < start || end < idx) return;
	if (start == end) {
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, value);
	update(node * 2 + 1, mid + 1, end, idx, value);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			int k = query(1, 1, MAX, B);
			cout << k << "\n";
			arr[k]--;
			update(1, 1, MAX, k, arr[k]);
		}
		else {
			cin >> B >> C;
			arr[B] += C;
			update(1, 1, MAX, B, arr[B]);
		}
	}

	return 0;
}