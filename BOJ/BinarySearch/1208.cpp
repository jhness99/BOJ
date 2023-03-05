/*
* 1.아이디어
* 최대 주어지는 정수는 40개인데 40개의 정수로 만들어지는 수열의 최대 개수는 
* 2^40이므로 이 모든 수열의 합을 확인하면 시간초과가 걸린다.
* 다라서 수열을 절반으로 나눠서 2^20개로 만들고 만드는 도중에 확인해주고,
* 2개의 수열들의 합을 저장한 vector끼리 또 합해서 지정한 숫자가 나올경우 도 체크해주면,
* 시간복잡도가 O(NlogN) + O(N^20)이므로 가능하다.
* 
* 2.시간복잡도
* 3.변수형
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int arr[40];
vector<int> A;
vector<int> B;
long long result = 0;

void makeA(int sum, int index) {
	if (index >= N / 2)
		return;

	sum += arr[index];
	if (sum == S) result++;

	A.push_back(sum);
	makeA(sum - arr[index], index + 1);
	makeA(sum, index + 1);
}

void makeB(int sum, int index) {
	if (index >= N )
		return;

	sum += arr[index];
	if (sum == S) result++;

	B.push_back(sum);
	makeB(sum - arr[index], index + 1);
	makeB(sum, index + 1);
}

int main(void) {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	makeA(0, 0);
	makeB(0, N / 2);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++) {
		int low = lower_bound(B.begin(), B.end(), S - A[i]) - B.begin();
		int high = upper_bound(B.begin(), B.end(), S - A[i]) - B.begin();
		result += (high - low);
	}

	cout << result;

	return 0;
}