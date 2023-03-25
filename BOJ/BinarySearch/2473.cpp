/*
* 1.아이디어
* 두 용액-2470 문제에서 1개의 수가 더 추가된 경우이다.
* 두 용액에서 수 1개를 추가해주는데 원래 투포인터의 시간복잡도가 O(logN)인데 여기서 N개중 1개의 수를 추가하는 경우까지 확인해야하므로
* 시간복잡도는 O(NlogN)으로 늘어난다. 하지만 이미 sort를 사용했으므로 O(NlogN)이므로 시간복잡도는 영향이 없다.
* 
* 입력된 수를 정렬하고 투포인트를 이용해 left right를 나눠 더했을때 절대값이 더 작아질경우, 해당 index들을 저장하는 것은 같지만
* 여기서 3번째 용액까지 고려해야한다. 따라서 해당 투포인터 알고리즘을 for문을 사용해 N번 반복하고 해당하는 index가 left와 right에 겹치지 않도록 하면 된다.
* 
* 2.시간복잡도
* 위에서 언급했다싶이 O(NlogN), N <= 5000, 따라서 가능
* 
* 3.변수형
* long long : 최대 -10억~10억까지 가능하므로 최대 30억까지 가능, 따라서 long long
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
//	vector<long long> input(N);
//	for (auto& i : input)
//		cin >> i;
//
//	int a = 0, b = 0, c = 0;
//	long long min = 1e10;
//
//	sort(input.begin(), input.end());
//
//	for (int i = 0; i < N; i++) {
//		int left = 0;
//		int right = N - 1;
//
//		if (i == 0) left = 1;
//		if (i == N - 1) right = N - 2;
//
//		while (left < right) {
//			long long temp = input[left] + input[right] + input[i];
//			if (min > abs(temp)) {
//				min = abs(temp);
//				a = input[left];
//				b = input[i];
//				c = input[right];
//			}
//			if (temp < 0) {
//				left++;
//				if (left == i) left++;
//			}
//			else {
//				right--;
//				if (right == i) right--;
//			}
//		}
//	}
//	long long arr[3] = { a,b,c };
//	sort(arr, arr + 3);
//	for (auto& ll : arr)
//		cout << ll << " ";
//
//	return 0;
//}
//2023-03-25 복습
/*
* 1.아이디어
* 두 용액과 비슷한 문제지만 여기서는 3개를 골라야 한다.
* 따라서 1개는 고정해두고 양쪽에서 확인하는 것을 N번 해주면 된다.
* O(N^2)되지만 가능하다
*
* 투포인터로 양쪽에서 이동하면서 두 값의 합이 양수일경우, right--, 음수일경우 left++를 해준다.
* 만약 기존값과 비교해서 0과 더 가깝다면,(절대값이 더 작다면) 해당 위치로 갱신해준다.
* 2.시간복잡도
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<long long> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());
	long long  num = 3000000001;
	int leftNum;
	int rightNum;
	int midNum;
	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N - 1;
		if (left == i)
			left++;
		if (right == i)
			right--;

		while (left < right) {
			long long temp = input[right] + input[left] + input[i];
			if (abs(num) > abs(temp)) {
				num = temp;
				leftNum = input[left];
				rightNum = input[right];
				midNum = input[i];
			}
			if (temp < 0) {
				left++;
				if (left == i) left++;
			}
			else {
				right--;
				if (right == i) right--;
			}
		}
	}

	int answer[] = { rightNum, leftNum, midNum };
	sort(answer, answer + 3);
	for (auto& ll : answer)
		cout << ll << " ";

	return 0;
}