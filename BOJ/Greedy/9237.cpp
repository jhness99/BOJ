/*
* 1.아이디어
* (틀린아이디어)
* 각 씨앗을 내림차순 정렬한다.
* 가장 오래걸리는 씨앗중 가장 마지막에 심는 index + 해당씨앗 자라는 시간 + 2와
* 가장 빨리자라는 씨앗중 가장 마지막에 심는 index + 해당씨앗 자라는 시간 + 2를 비교해서
* 더 큰 값이 답
*
* (맞은 아이디어)
* 각 씨앗을 내림차순 정렬한다.
* 씨앗을 큰 순서대로 확인하면서 해당 수에서 걸리는 기간을 확인해 더 크다면 그 기간으로 갱신해준다.
* 2.시간복잡도
* 정렬에 의한 O(NlogN), N<=100,000 따라서 가능
* 3.변수형
* int : 100000+100000000+1, 따라서 int
*/
/*
* 문제풀이
* 아무리 생각해도 틀린 아이디어를 기반으로 한 코드도 맞는데 뭐가 잘못된 지 모르겠다.
* 반례도 못찾겠고 그래서 다른 아이디어로 했다.
* 추가: 
* 반례를 찾았다. 반례는 10 9 8 7 6 5 5 5 5 1 이다
* 이 때 내가 처음 생각한 방법으로 하면 10은 10 + 2 + 0 = 12, 1은 1 + 2 + 9 = 12이다
* 하지만 1 뒤의 5는 5 + 8 + 2 = 15 15가 답이된다. 따라서 틀렸다.
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, answer = 0;
//	cin >> N;
//
//	vector<int> v(N);
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end(), greater<>());
//
//	for (int i = 0; i < N; i++) {
//		answer = max(answer, v[i] + i + 1);
//	}
//	cout << answer + 1;
//	return 0;
//}
//2023-03-01 복습
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, answer = 0;
//	cin >> N;
//	vector<int> v(N);
//
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end(), greater<>());
//
//	for (int i = 0; i < N; i++) {
//		answer = max(answer, i + v[i] + 1);
//	}
//
//	cout << answer + 1;
//
//	return 0;
//}
//2023-03-20 아이디어
/*
* 1.아이디어
* 내림차순으로 정렬한다. 왜냐하면 더 오래걸리는 나무를 먼저 심어야 하기 때문이다.
* 정렬한 후 모든 값은 index + arr[index] + 1을 비교해서 가장 큰 값을 구한다.
* 다 자란 후 다음날 이장님을 부르므로 +1
* 2.시간복잡도
* 정렬을 사용하므로 O(NlogN), N<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<int> tree(N);
	for (auto& i : tree)
		cin >> i;

	sort(tree.begin(), tree.end(), greater<>());

	int answer = 0;

	for (int i = 0; i < N; i++)
		answer = max(answer, tree[i] + i + 1);

	cout << answer + 1;

	return 0;
}