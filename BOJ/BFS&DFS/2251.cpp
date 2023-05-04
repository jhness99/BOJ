/*
* 1.아이디어
* 물병의 상태를 저장하는 구조체를 하나 만들고 거기에 물의 양을 갱신해준다.
* 
* 어떠한 물병을 다른 물병에 넣는 모든 경우를 push해서 탐색해주고
* visited로 물병의 상태를 방문처리해서 동일한 상태를 탐색하지 않도록 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Bottles {
	int A;
	int B;
	int C;
};

int A, B, C;

bool visited[201][201][201];
vector<int> v;

void BFS() {
	queue<Bottles> q;
	q.push({ 0, 0, C });
	
	while (!q.empty()) {
		int a = q.front().A;
		int b = q.front().B;
		int c = q.front().C;

		q.pop();

		if (visited[a][b][c] == true) continue;
		visited[a][b][c] = true;

		if (a == 0) v.push_back(c);

		if (a + b > B) q.push({ a + b - B, B, c });
		else q.push({ 0,a + b, c });

		if (a + c > C) q.push({ a + c - C, b, C });
		else q.push({ 0,b,a + c });

		if (b + a > A) q.push({ A, b + a - A, c });
		else q.push({ a + b, 0, c });

		if (b + c > C) q.push({ a, b + c - C, C });
		else q.push({a, 0, b + c});

		if (c + a > A) q.push({ A, b, c + a - A });
		else q.push({ c + a, b, 0 });

		if (c + b > B) q.push({ a, B, c + b - B });
		else q.push({ a,c + b, 0 });
	}
}

int main(void) {

	cin >> A >> B >> C;

	BFS();

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}