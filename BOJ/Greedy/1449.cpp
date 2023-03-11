//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	
//	int N, L, cnt = 0;;
//	cin >> N >> L;
//	int repairLoc[1000] = { 0, };
//
//	for (int i = 0; i < N; i++)
//		cin >> repairLoc[i];
//
//	sort(repairLoc, repairLoc+N);
//	
//	int start = repairLoc[0];
//
//	for (int i = 1; i < N; i++) {
//		if (L <= repairLoc[i] - start) {
//			cnt++;
//			start = repairLoc[i];
//		}
//	}
//	cout << cnt + 1;
//	return 0;
//}
//2023-02-12 복습
/*
* 1.아이디어
* 먼저 입력부분을 정렬
* 앞 뒤로 0.5씩 있으므로 수리위치는 실질적으로 L-1
* 시작 위치를 v[0]로 지정하고 만약 v[i] - prev 가 L-1(커버되는 거리)보다 크다면, 즉 새로운 테이프를 써야한다면
* 시작위치를 v[i]로 갱신해주고 cnt++을 해준다.
* 마지막은 무조건 테이프로 덮어야 하므로 cnt+1을 해준다.
* 2.시간복잡도
* O(nlogn), N<=1000 따라서 가능
* 3.변수형
* int :
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, L, cnt = 0;
//	cin >> N >> L;
//
//	vector<int> v(N);
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end());
//
//	int prev = v[0];
//	for (int i = 1; i < N; i++) {
//		if (v[i] - prev > L - 1) {
//			prev = v[i];
//			cnt++;
//		}
//	}
//
//	cout << cnt + 1;
//
//	return 0;
//}
//2023-03-09 복습
/*
* 1.아이디어
* 시작위치를 기억하고 진행하면서 다음위치와 시작 위치의 거리가 테이프길이보다 더 크면, 테이프사용개수를 1올려준다.
* 마지막은 결국 테이프1개를 써야하므로 테이프사용개수를 기본적으로 1로 초기화한다.
* 이때 입력받은 수리위치는 정렬로 해야 거리를 알 수 있으므로 sort를 사용한다.
* 2.시간복잡도
* O(NlogN) N<=1000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, L, answer = 1;
	cin >> N >> L;

	vector<int> distance(N);
	for (auto& i : distance)
		cin >> i;

	sort(distance.begin(), distance.end());

	int prevLoc = distance[0];

	for (int i = 1; i < N; i++) {
		if (distance[i] - prevLoc >= L) {
			answer++;
			prevLoc = distance[i];
		}
	}
	cout << answer;

	return 0;
}