/*
* 1.아이디어
* LIS문제이다. 이때 길이가 최대 100000이기 때문에 DP로는 불가능, 즉 이분탐색을 사용해야 한다.
* 
* 이분탐색 LIS풀이법
* 첫 문자를 LIS백터에 넣고, 다음 숫자가 LIS백터의 가장 마지막 숫자보다 클 경우, push_back
* 만약 같거나 작을경우, 이분탐색을 사용해 자신과 같거나 큰 수 위치에 해당 수를 넣는다.
* 
* 2.시간복잡도
* 이분탐색을 N번 반복하므로 N*O(logN) O(NlogN), N<=100000 따라서 가능
* 3.변수형
* 
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int N;
//	while (cin>>N) {
//		vector<int> LIS;
//		vector<int> input(N);
//		for (auto& i : input)
//			cin >> i;
//
//		LIS.push_back(input[0]);
//		for (int i = 1; i < N; i++) {
//			if (LIS.back() < input[i])
//				LIS.push_back(input[i]);
//			else {
//				int start = 0;
//				int end = LIS.size() - 1;
//
//				while (start < end) {
//					int mid = (start + end) / 2;
//					if (LIS[mid] >= input[i])
//						end = mid;
//					else
//						start = mid + 1;
//				}
//				LIS[end] = input[i];
//			}
//		}
//
//		cout << LIS.size() << "\n";
//	}
//
//	return 0;
//}
//2023-04-12 복습
/*
* 1.아이디어
* 이번 문제는 정렬하고 투포인터를 사용하면 되는 문제이다.
*
* sort로 정렬한 후 양쪽을 left rifht로 지정한다.
* 두 수의 합이 x와 비교했을 때 작다면, 더 키워줘야 하므로 left++. 더 크다면 right--
* 만약 같다면 현재 상태를 갱신할 것인지 확인하고 갱신해준다.
* 만약 같은 상태가 안 나온다면 danger출력
*
* 2.시간복잡도
* 3.변수형
*
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int X, N;
	while (cin >> X) {
		cin >> N;

		X *= 10000000;
		vector<int> Lego(N);
		for (auto& i : Lego)
			cin >> i;

		sort(Lego.begin(), Lego.end());

		int left = 0;
		int right = Lego.size() - 1;
		bool flag = false;

		while (left < right) {
			int sum = Lego[left] + Lego[right];
			if (X > sum)
				left++;
			else if (X < sum)
				right--;
			else {
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "yes " << Lego[left] << " " << Lego[right];
		else
			cout << "danger";
		cout << "\n";
	}
	return 0;
}