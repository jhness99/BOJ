/*
* 1.아이디어
* 이 문제의 경우 첫번째 줄을 고른 집합과 아래숫자의 집합이 같아야 한다.
* 즉 위에서 시작한 수가 계속 이동해서 순환이 되어야 한다.
* 그래서 그래프를 만들어 풀어봤다. 
* 1 2 3 4 5
* 5 3 1 2 4 
* 이러한 예제일경우 1->5, 5->4, 4->2, 2->3, 3->1 로 자기자신으로 돌아오는 순환의 형태를 띈다.
* 따라서 순환인경우 해당 수를 집합에 넣어주면 되는 것이다.
* 모든 수를 집합에 넣은 후 출력하면 된다.
* 2.시간복잡도
* 최대 N을 N번 확인하므로 O(N^2), N<=100 따라서 가능하다.
* 3.변수형
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int Graph[101];
bool visited[101];
vector<int> answer;

int N;

void DFS(int start, int node) {
	if (visited[node]) return;
	if (node == start) {
		answer.push_back(node);
		return;
	}
	visited[node] = true;
	DFS(start, Graph[node]);
}

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> Graph[i];
	}

	for (int i = 1; i <= N; i++) {
		DFS(i, Graph[i]);
		memset(visited, false, sizeof(visited));
	}

	cout << answer.size() << "\n";
	for (auto& i : answer)
		cout << i << "\n";

	return 0;
}