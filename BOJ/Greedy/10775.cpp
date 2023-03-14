/*
* 문제풀이
* 상당히 어려웠던 문제. Disjoint Set 개념이 없어서 더욱 어려웠다. 
* union-find 알고리즘을 사용하면 간단한 문제였지만 아에 몰라서 못풀었다.
* union-find 알고리즘, disjoint set 알고리즘이 숙달해야할 필요가 있다.
*/
//#include <iostream>
//
//using namespace std;
//
////각 노드의 부모를 가지는 배열
//int parent[100001] = { 0, };
//
////해당 노드의 루트노드를 반환하는 함수
//int find(int u) {
//	if (parent[u] == u) return u;
//	return parent[u] = find(parent[u]);
//}
//
////u와 v를 받아 u의 부모노드를 v로 바꿔주는 함수
//void Union(int u, int v) {
//	u = find(u);
//	v = find(v);
//	parent[u] = v;
//}
//
//int main(void) {
//
//	int G, P;
//	int cnt = 0;
//	cin >> G >> P;
//	
//	//자기자신을 부모노드(루트노드)로 가지도록 초기화
//	for (int i = 1; i <= G; i++) parent[i] = i;
//
//	int g;
//
//	//비행기의 수만큼 반복하며 진행
//	while (P--) {
//		cin >> g;
//		//find를 사용해 만약 부모가 0, 다시말해서 1~g게이트로 비행기가 들어갈 수 없을때, 
//		if (find(g) == 0) break;
//
//		//1~g까지의 게이트에 아직 들어갈 곳이 있다면 비행기 수를 1 올리고 해당 게이트를 막아준다.
//		else {
//			cnt++;
//			Union(find(g), find(g)-1);
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}
/*
* 1.아이디어
* 유니온 파운드를 사용해야한다.
* 유니온 파운드의 개념을 재정의하고 문제를 풀어보자
*
* 유니온파운드는 그래프 알고리즘으로 두 노드가 같은 그래프에 속하는지 판별하는 알고리즘이다.
* 서로소 집합, 상호베타적집합(Disjoint-Set)이라고도 불린다.
* 노드를 합치는 Union연산과 루트노드를 찾는 find연산으로 나뉜다.
* union(A,B)는 B를 A의 부모로 만들어주는 연산이다.
* find(A)는 A의 루트노드(가장 위에 있는 부모노드)를 찾는 연산이다.
* 따라서 union(A, B)를 하고 find(A)를 하게되면 B가 나오게 된다.
*
* 이것을 위 문제에 어떻게 연동할수있냐면
* 비행기 번호가 4일때, 1~4까지의 게이트에 들어갈 수 있다.
* 따라서 큰 게이트부터 차곡차곡 넣어주는데, 만약 같은 게이트에 들어가려고 하면 해당게이트-1 에 넣어주는것이다.
* 즉, 게이트에 들어가면 해당 게이트-1을 그 게이트의 부모로 만들어주고 다음에 그 게이트를 들어가려고 하면
* 해당 게이트의 루트 게이트에 넣어주는 것이다.
* 예를 들어 게이트가 4개이고 들어오는 비행기가 3 3 4 4 1 이라고 가정해보자
* 3번게이트에 첫번째 비행기가 들어가고 해당 게이트의 부모를 2번 게이트로 지정한다.
* 두번째 비행기는 3번 게이트가 차 있으므로 2번게이트에 들어간다. 그리고 2번게이트의 부모를 1번게이트로 해준다.
* 세번째 비행기는 4번 게이트에 들어가고 4번게이트의 부모를 3번게이트로 해준다.
* 네번째 비행기는 4번 게이트가 차 있으므로 그 부모인 3번으로 가는데 3번또한 차있으므로 그 부모인 2번게이트로 간다.
* 하지만 2번게이트도 차있으므로 1번게이트로 가는데 이것은 결국 루트 게이트로 가는 것이다.
* 결국 루트 게이트 1번에 들어가고 0번 게이트를 부모로 가진다. 이때 0번 게이트가 루트라는 뜻은
* 해당 그래프의 게이트 어디로든지 들어오려고 해도 불가능하다, 꽉 찼다는 뜻이다.
* 따라서 다섯번째 비행기는 들어갈 수 없으므로 최대 들어올 수 있는 비행기는 4대라고 할 수 있다.
* 2.시간복잡도
* O(P) p<=100000, 따라서 가능
* 3.변수형
*
*/
//#include <iostream>
//
//using namespace std;
//
////각 게이트의 루트
//int parents[100001];
//
//int G;
//
////해당 노드의 루트노드를 반환하는 함수, 루트노드가 아닐경우 parents를 루트노드로 갱신해준다.
//int Find(int g) {
//	if (parents[g] == g) return g;
//	return parents[g] = Find(parents[g]);
//}
//
////c와 p를 받아 c의 부모노드를 p로 바꿔주는 함수
//void Union(int c, int p) {
//	c = Find(c);
//	p = Find(p);
//
//	parents[c] = p;
//}
//
//int main(void) {
//
//	int P, cnt = 0;
//	cin >> G >> P;
//
//	for (int i = 1; i <= G; i++)
//		parents[i] = i;
//
//	while (P--) {
//		int G;
//		cin >> G;
//		if (Find(G) == 0)
//			break;
//		else {
//			cnt++;
//			Union(Find(G), Find(G) - 1);
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}
//2023-03-14 복습
/*
* 1.아이디어
* 유니온 파운드를 사용해야한다.
* 유니온 파운드의 개념을 재정의하고 문제를 풀어보자
*
* 유니온파운드는 그래프 알고리즘으로 두 노드가 같은 그래프에 속하는지 판별하는 알고리즘이다.
* 서로소 집합, 상호베타적집합(Disjoint-Set)이라고도 불린다.
* 노드를 합치는 Union연산과 루트노드를 찾는 find연산으로 나뉜다.
* union(A,B)는 B를 A의 부모로 만들어주는 연산이다.
* find(A)는 A의 루트노드(가장 위에 있는 부모노드)를 찾는 연산이다.
* 따라서 union(A, B)를 하고 find(A)를 하게되면 B가 나오게 된다.
*
* G만큼의 게이트를 초기화한다. 초기에는 자기자신을 가리키게 한다.
* P만큼 게이트위치를 입력 받는다.
* 입력받은 값이 0과 연결, 즉 더이상 넣을 수 없을경우 반복문을 나간다./
* 만약 0이 아니라면, 해당 게이트의 루트 게이트를 알아내고 해당 루트게이트의 다음 게이트를 해당 게이트의 부모로 지정해서
* 결국 Union(A, B)라 가정했을 때, B -> A 가 되도록 B를 A의 부모로 설정해 주는것이다.
* 이 연산이 끝나면 answer++해주고 다시 반복한다.
* 2.시간복잡도
*
*/
#include <iostream>

using namespace std;

int gate[100001];

int Find(int u) {
	if (gate[u] == u) return u;
	return gate[u] = Find(gate[u]);
}

void Union(int u, int v) {
	u = Find(u);
	v = Find(v);

	gate[u] = v;
}

int main(void) {

	int G, P, answer = 0;
	cin >> G >> P;

	for (int i = 0; i <= G; i++)
		gate[i] = i;

	while (P--) {
		int g;
		cin >> g;
		if (Find(g) == 0)
			break;
		else {
			answer++;
			Union(Find(g), Find(g) - 1);
		}
	}
	cout << answer;

	return 0;
}