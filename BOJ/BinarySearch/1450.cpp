/*
* 1.아이디어
* 잘 모르겠어서 검색해봄
* 
* 기본적으로 입력된 값이 최대 30, 따라서 모든 경우의 수는 2^30
* 이럴때는 2개의 그룹으로 나눠서 해야한다.
* 
* 2개의 그룹으로 나눈 후 이분탐색할 그룹을 정렬해주고
* 정렬한 그룹을 정렬하지 않은 그룹을 이용해 탐색해주는것이다.
* 
* 해당 로직자체는 익숙한데 2개의 그룹으로 나누는 것이 어려웠다.
* 세그먼트 트리에서도 비슷하게 노드를 만들었으니까 꼭 기억하자
* 
* 2.시간복잡도
* groub1과 groub2의 크기는 2^(N/2) 이고 O(log(2^(N/2)))를 2^(N/2)번 반복하므로 
* O(2^(N/2) log (2^(N/2)))
* 3.변수형
* 
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//long long N, C, W[31];
//
//void dfs(int start, int end, vector<long long>& v, long long sum) {
//	if (start > end) {
//		v.push_back(sum);
//		return;
//	}
//	else {
//		dfs(start + 1, end, v, sum);
//		dfs(start + 1, end, v, sum+W[start]);
//	}
//}
//
//int main(void) {
//
//	long long answer = 0;
//
//	cin >> N >> C;
//	for (int i = 0; i < N; i++) {
//		cin >> W[i];
//	}
//	vector<long long> group1;
//	vector<long long> group2;
//	dfs(0, N / 2, group1, 0);
//	dfs(N / 2 + 1, N - 1, group2, 0);
//	sort(group2.begin(), group2.end());
//
//	for (int i = 0; i < group1.size(); i++) {
//		answer += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-04-11 복습
/*
* 1.아이디어
* 잘 모르겠어서 검색해봄
*
* 기본적으로 입력된 값이 최대 30, 따라서 모든 경우의 수는 2^30
* 이럴때는 2개의 그룹으로 나눠서 해야한다.
*
* 2개의 그룹으로 나눈 후 이분탐색할 그룹을 정렬해주고
* 정렬한 그룹을 정렬하지 않은 그룹을 이용해 탐색해주는것이다.
*
* 해당 로직자체는 익숙한데 2개의 그룹으로 나누는 것이 어려웠다.
* 세그먼트 트리에서도 비슷하게 노드를 만들었으니까 꼭 기억하자
*
* 2.시간복잡도
* groub1과 groub2의 크기는 2^(N/2) 이고 O(log(2^(N/2)))를 2^(N/2)번 반복하므로
* O(2^(N/2) log (2^(N/2)))
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, C, W[31];

void dfs(int start, int end, vector<long long>& v, long long sum) {
	if (start > end) {
		v.push_back(sum);
		return;
	}
	else {
		dfs(start + 1, end, v, sum);
		dfs(start + 1, end, v, sum + W[start]);
	}
}

int main(void) {

	long long answer = 0;

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	vector<long long> group1;
	vector<long long> group2;
	dfs(0, N / 2, group1, 0);
	dfs(N / 2 + 1, N - 1, group2, 0);
	sort(group2.begin(), group2.end());

	for (int i = 0; i < group1.size(); i++) {
		answer += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();
	}

	cout << answer;

	return 0;
}