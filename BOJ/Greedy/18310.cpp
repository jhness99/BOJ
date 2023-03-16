/*
* 1.아이디어
* 주변 집과의 거리들의 합이 가장 작은 집의 위치를 찾는 문제
* 따라서 오름차순으로 정렬하고 그 가운데의 위치하면 모든 집과의 거리가 가장 짧게됨
* 2.시간복잡도
* sort정렬을 사용하므로 O(NlogN) , N <= 200,000 이므로, O(NlogN) 은 약 3500000이다.
* 3.변수형
* vector<int> : N크기의 배열
*/
/*
* 문제풀이
* 모든 위치의 집과의 거리가 가장 짧으려면 중앙에 있어야 하므로 중앙값을 찾으면 되는 문제였다.
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	
//	int N;
//	cin >> N;
//
//	vector<int> v(N);
//
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end());
//
//	cout << v[(v.size() % 2 == 0 ? v.size() / 2 - 1 : v.size() / 2)];
//
//	return 0;
//}
//2023-02-23 복습
/*
* 1.아이디어
* 중앙에서 비교하는것이 가장 효율적이므로 중앙값을 구해서 모든 값들과 거리를 비교한다.
* 2.시간복잡도
* 정렬을 사용하므로 O(NlogN), N<=100000 따라서 가능
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N;
//	cin >> N;
//
//	vector<int> v(N);
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end());
//
//	int mid = v[(N - 1) / 2];
//
//	cout << mid;
//
//	return 0;
//}
//2023-03-16 복습
/*
* 1.아이디어
* 입력받은 값을 정렬하고 중앙값을 찾는다.
* 중앙값이 답인 이유는 모든 위치의 합을 더했을 때 가장 작기 때문이다.
* 또한 여러값이 나올경우, 즉 짝수일경우, 중앙값후보가 2개가 되는대 이때 가장 작은 값을 하라고 했으므로
* 홀수일 땐 N/2, 짝수일 땐 N/2-1 하면 된다.
* 2.시간복잡도
* 정렬을 하므로 O(NlogN), N<=200000 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	cout << v[(N % 2 == 0 ? N / 2 - 1 : N / 2)];

	return 0;
}