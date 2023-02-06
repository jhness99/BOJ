/*
* 수를 추가할 때 마다 정렬되서 가장 작은 값을 알려줘야 하므로 
* 우선순위 큐를 역순으로 해 가장 작은 값이 top이 되게 해서
* 해당 값을 2번 빼서 가장 작은수와 그 다음수를 더한 후
* 결과값에 더하고 다시 우선순위 큐에 넣어 확인해준다
* 우선순위큐의 크기가 1이될경우(카드 묶음이 1개가 됬을 경우) 그만둔다.
* 더해줬던 결과값이 답이다.
*/
//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N = 0;
//	int answer = 0;
//	priority_queue<int, vector<int>, greater<>> pq;		//가장 작은 값이 top이 되는 우선순위 큐 생성
//	cin >> N;
//	
//	for (int i = 0; i < N; i++) {
//		int temp;
//		cin >> temp;
//		pq.push(temp);		//자동정렬
//	}
//	while (pq.size() != 1) {	//카드 묶음이 1개가 됬을 경우 반복중지
//		int sum = 0;
//
//		//앞에서 2개의 수를 더해서 새로운 묶음을 만들고
//		//그 묶음만큼 비교횟수 증가시킴
//		sum += pq.top();
//		pq.pop();
//		sum += pq.top();
//		pq.pop();
//		answer += sum;	
//		pq.push(sum);
//	}
//	cout << answer;
//	return 0;
//}
//2023-02-06 복습
/*
* 1.아이디어
* 우선순위큐에 모든 수 삽입
* 작은수 2개를 pop하고 해당 수를 더한값을 answer에 더하고 다시 우선순위 큐에 push
* 2.시간복잡도
* O(N) N <= 100000 이므로 가능
* 3.변수형
* long long
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {

	priority_queue<int, vector<int>, greater<>> pq;
	int N;
	long long answer = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() >= 2) {
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();

		int sum = num1 + num2;
		answer += sum;
		pq.push(sum);
	}

	cout << answer;

	return 0;
}