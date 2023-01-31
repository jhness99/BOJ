/*
* 문제풀이
* 상당히 어려웠던 문제. Disjoint Set 개념이 없어서 더욱 어려웠다. 
* union-find 알고리즘을 사용하면 간단한 문제였지만 아에 몰라서 못풀었다.
* union-find 알고리즘, disjoint set 알고리즘이 숙달해야할 필요가 있다.
*/
#include <iostream>

using namespace std;

//각 노드의 부모를 가지는 배열
int parent[100001] = { 0, };

//해당 노드의 루트노드를 반환하는 함수
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

//u와 v를 받아 u의 부모노드를 v로 바꿔주는 함수
void Union(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}

int main(void) {

	int G, P;
	int cnt = 0;
	cin >> G >> P;
	
	//자기자신을 부모노드(루트노드)로 가지도록 초기화
	for (int i = 1; i <= G; i++) parent[i] = i;

	int g;

	//비행기의 수만큼 반복하며 진행
	while (P--) {
		cin >> g;
		//find를 사용해 만약 부모가 0, 다시말해서 1~g게이트로 비행기가 들어갈 수 없을때, 
		if (find(g) == 0) break;

		//1~g까지의 게이트에 아직 들어갈 곳이 있다면 비행기 수를 1 올리고 해당 게이트를 막아준다.
		else {
			cnt++;
			Union(find(g), find(g)-1);
		}
	}
	cout << cnt;

	return 0;
}