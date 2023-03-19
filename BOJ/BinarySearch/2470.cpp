/*
* 1.아이디어
* 투포인터와 이진탐색을 사용하면 된다.
* 
* 입력받는 값을 오름차순정렬하고 정렬한 값의 첫번째와 마지막을 기준으로 이진탐색을 한다.
* 가장 처음 상황의 첫번째 값과 마지막 값을 더한 값을 저장한다.
* 새로운 값을 저장해서 나온 값의 절대값이 기존 절대값보다 작다면, 해당 값을 저장해주고 각 수를 저장해준다.
* 그 후 두 수를 뺀 값이 양수이면 right --; 음수이면 left ++를 해준다.
* 
* 2.시간복잡도
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

	int left = 0;
	int right = N - 1;

	int leftNum = v[left];
	int rightNum = v[right];

	int value = leftNum + rightNum;

	while (left < right) {
		int newValue = v[left] + v[right];
		if (abs(newValue) < abs(value)) {
			value = newValue;
			leftNum = v[left];
			rightNum = v[right];
		}
		if (newValue > 0)
			right--;
		else
			left++;
	}

	cout << leftNum << " " << rightNum;

	return 0;
}
//2023-03-19 복습
/*
* 1.아이디어
* 용액들을 오름차순 정렬한다.
* 정렬한 용액을 왼쪽 오른쪽, 즉 가장 산성인것과 가장 염기성인 것을 left right로 정한다.
* 그상태에서 투포인터로 연산한다.
* 만약 left와 right위치의용액의 합이 +라면, 0에 가까워야 하므로 right--,
* 만약 합이 -라면 left++
* 해당 연산을 진행하면서 가장 작은 조합의 값을 answer에 저장한다.
* 두 left >= right 일 경우, 종료한다.
*
* 2.시간복잡도
* O(N) N<=100000 따라서 가능
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

	int N, answer = 2000000001;
	cin >> N;

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	int left = 0;
	int right = N - 1;
	int leftNum = input[left];
	int rightNum = input[right];

	while (left < right) {
		int num = input[right] + input[left];
		if (answer > abs(num)) {
			answer = abs(num);
			leftNum = input[left];
			rightNum = input[right];
		}

		if (num > 0)
			right--;
		else
			left++;

	}

	cout << leftNum << " " << rightNum;

	return 0;
}