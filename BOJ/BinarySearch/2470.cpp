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