/*
* 1.아이디어
* 단순반복으로 하면 시간복잡도가 O(NM)이 되는데 N,M <= 500000이므로 이분탐색(O(logN)을 사용한다.
* 
* 입력값을 정렬한다.
* 
* start와 end를 구한다.
* 확인할 숫자가 입력되면 해당 숫자를 기준으로 이분탐색을 해준다.
* 존재할경우 1 없을경우 0을 출력한다.
* 
* 2.시간복잡도
* O(NlogM), N,M <= 500000, 따라서 가능
* 3.변수형
* int
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int N, M;
//	cin >> N;
//
//	vector<int> v(N);
//	for (auto& i : v)
//		cin >> i;
//
//	sort(v.begin(), v.end());
//
//	cin >> M;
//	while (M--) {
//		int target;
//		cin >> target;
//
//		int start = 0;
//		int end = N - 1;
//		int mid;
//		while (start <= end) {
//			mid = (start + end) / 2;
//			if (v[mid] == target) {
//				cout << "1 ";
//				break;
//			}
//			else if (v[mid] > target){
//				end = mid - 1;
//			}
//			else {
//				start = mid + 1;
//			}
//		}
//		if (start > end)
//			cout << "0 ";
//	}
//
//	return 0;
//}
//2023-03-16 복습
/*
* 1.아이디어
* 숫자 카드2-10816과 비슷한 문제이다.
* 차이점은 숫자의 유무만 판단하면 되므로, upper_bound - lower_bound 가 0보다 크다면 해당 수가 존재하는 것이다.
* 2.시간복잡도
* N개의 크기의 배열을 정렬하므로 O(NlogN), N크기의 배열을 이분탐색하는것을 총 M번 반복하므로 O(MlogN)
* 따라서 O(MlogN) + O(NlogN), M, N<=500000, 따라서 가능
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

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	cin >> M;
	while (M--) {
		int Num;
		cin >> Num;

		int right = upper_bound(input.begin(), input.end(), Num) - input.begin();
		int left = lower_bound(input.begin(), input.end(), Num) - input.begin();
		if (right - left > 0)
			cout << 1 << " ";
		else
			cout << 0 << " ";

	}

	return 0;
}