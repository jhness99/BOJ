/*
* 문제풀이
* 간단한 문제였지만 long long 형으로 선언하지 않은게 문제였다. 각 수는 최대 100000까지 되는데 
* 더하는 횟수가 최대 카드의 개수 x 15 이기 때문에 15000번 더할 수 있고, 그렇다면 최대 2^14*1000 * 1000000 이나 되므로
* long long형으로 하는것이 맞다. 그 외에 알고리즘은 우선순위큐를 사용해서 가장 작은수가 top이 되도록 greater<>를 사용해주면 된다.
* 그리고 top과 그 다음 top을 더해서 2번 push해주고 그것을 M번만큼 반복한 후 우선순위큐 안의 수들을 전부 더해주면 된다.
*/
#include <iostream>
#include <queue>

using namespace std;

int main(void) {

	priority_queue<long long, vector<long long>, greater<>> pq;	//작은수가 top이 되는 우선순위큐
	int N, M;
	long long answer = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	while (M--) {
		//1번째와 2번째 작은 수를 더해서 2번 Push
		//가장 작은수 2개를 더했으므로 더했을 때 가장 작은 수
		long long n1 = pq.top();				
		pq.pop();
		long long n2 = pq.top();
		pq.pop();
		long long n3 = n1 + n2;
		pq.push(n3);
		pq.push(n3);
	}

	while (!pq.empty()) {
		answer += pq.top();
		pq.pop();
	}

	cout << answer;

	return 0;
}