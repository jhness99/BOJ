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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, L, cnt = 0;
	cin >> N >> L;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	int prev = v[0];
	for (int i = 1; i < N; i++) {
		if (v[i] - prev > L - 1) {
			prev = v[i];
			cnt++;
		}
	}

	cout << cnt + 1;

	return 0;
}