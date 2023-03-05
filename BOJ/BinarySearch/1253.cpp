/*
* 1.아이디어
* 우선 예제를 입력을 정렬한다.
* arr[0]~arr[N-1]까지의 수 탐색
* 
* 왼쪽 오른쪽에서 투포인터로 2수를 합쳤을 때 arr[i]가 나오는지 탐색
* 두 값을 더한 값이 arr[i]보다 더 크면, right--, 더 작으면, left++
* 두 수가 같은 경우가 나온다면 answer++, break;
* 
* 2.시간복잡도
* 투포인터의 시간복잡도 O(N), N번 반복하므로 O(N^2) 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, answer = 0;
	cin >> N;

	
	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	sort(input.begin(), input.end());

	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N - 1;
		while (left < right) {

			//예외처리를 1회만 해줬음 계속 해줘야 되는데
			if (left == i) { 
				left++; 
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			int sum = input[left] + input[right];
			if (sum == input[i]) {
				answer++;
				break;
			}
			else if (sum > input[i])
				right--;
			else
				left++;
		}
	}

	cout << answer;

	return 0;
}