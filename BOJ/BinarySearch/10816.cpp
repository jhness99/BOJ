/*
* 1.아이디어
* 해시맵을 사용한다. 입력값이 나온 횟수를 해시맵에 저장한다.
* 해시맵을 입력받은 값으로 출력한다.
* 
* 이분탐색
* 
* 2.시간복잡도
* 해시맵의 시간복잡도는 O(1), N<=500000, M<= 500000
* 3.변수형
*/
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int N, M;
//	int temp;
//	cin >> N;
//
//	vector<int> v(N);
//
//	for (auto& i : v)
//		cin >> i;
//	
//	sort(v.begin(), v.end());
//
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		int temp;
//		cin >> temp;
//
//		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << " ";
//	}
//
//	/*
//	unordered_map<int, int> hm;
//
//	for (int i = 0; i < N; i++) {
//
//		cin >> temp;
//		if (hm.find(temp) != hm.end())
//			hm[temp]++;
//		else
//			hm.insert({ temp, 1 });
//	}
//
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//		cin >> temp;
//		if (hm.find(temp) != hm.end())
//			cout << hm[temp];
//		else
//			cout << 0;
//		cout << " ";
//	}*/
//
//	return 0;
//}
//2023-03-15 복습
/*
* 1.아이디어
* 이 문제는 해시맵으로 풀어도 되지만 이분탐색으로 풀어보자
*
* 아주 쉽다. 첫번째를 정렬하고 uppor_bound - lower_bound 하면 되는것이다.
* 그러면 마지막 위치 + 1 -  처음 숫자를 발견한 위치 하면 해당 갯수가 나온다.
* 예를들어 1 2 3 4 5 5 5 의 경우 7 - 4 = 3으로 5의 개수가 나온다.
*
* 2.시간복잡도
* N개의 수에서 이분탐색을 하므로 O(logN), 이분탐색을 M번 하므로 O(MlogN), M N<=500000
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> A(N);
	for (auto& i : A)
		cin >> i;

	sort(A.begin(), A.end());

	cin >> M;
	while (M--) {
		int target;
		cin >> target;

		cout << (upper_bound(A.begin(), A.end(), target) - A.begin()) - (lower_bound(A.begin(), A.end(), target) - A.begin()) << " ";
	}

	return 0;
}