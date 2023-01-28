/*
* 문제풀이
* 처음엔 비슷한 문제인 회의실배정 문제처럼 푸는 줄 알았지만 다른 문제였다.
* 회의실 배정은 끝나는 시간을 기준으로 해당 회의실에 최대로 사용할 수 있는 회의의 수를 찾아내는 거지만
* 강의실 배정 문제는 강의실의 개수를 찾는 문제였다.
* 따라서 모든 강의를 듣도록 하고, 그렇게 됬을때 얼마나 많은 강의실을 사용하게 되는지 알아봐야 했다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

	int N, cnt = 0;
	cin >> N;
	vector<pair<int, int>> schedule;
	priority_queue<int, vector<int>, greater<>> pq;		//가장 작은 수가 top이 되는 우선순위 큐


	for (int i = 0; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		schedule.push_back({ num1, num2 });
	}
	sort(schedule.begin(), schedule.end());				//스케쥴의 시작을 기준으로 오름차순 정렬

	pq.push(schedule[0].second);						//가장 시작이 빠른 스케쥴의 종료시간을 넣는다.
	for (int i = 1; i < N; i++) {

		//만약 현재 가장 빠른 순서의 스케쥴(top)의 종료시간보다 더 나중에 시작하는 스케쥴이 있을경우
		//top을 빼준다. 이렇게 되면 비교한 스케쥴만 들어가게 되고 강의실의 갯수는 늘어나지 않는다.
		if (pq.top() <= schedule[i].first) {
			pq.pop();
		}
		//만약 top의 종료시간보다 새로 확인한 스케쥴의 시작시간이 작을경우, 
		//top의 강의실은 사용할 수 없으므로 새로운 강의실을 사용, pq의 크기(강의실의 수)가 늘어나게 된다.
		pq.push(schedule[i].second);
	}

	cout << pq.size();

	return 0;
}