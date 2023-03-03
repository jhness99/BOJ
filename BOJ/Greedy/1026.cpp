//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	int N, result = 0;
//	cin >> N;
//
//	vector<int> A(N);
//	vector<int> B(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//	}
//	for (int i = 0; i < N; i++) {
//		cin >> B[i];
//	}
//
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end(), greater<int>());
//
//	for (int i = 0; i < N; i++) {
//		result += A[i] * B[i];
//	}
//
//	cout << result;
//	return 0;
//}
//2023-03-03 복습
/*
* 1.아이디어
* 원래는 배열 B를 정렬해서 풀었지만 이번엔 정렬을 안하고 풀어보려고한다.
* 먼저 B에 나온 원소들을 check배열의 index에 ++해서 개수를 새주고
* A는 정렬해서 작은순서부터 check가 1이상일 때 해당 index와 곱해줘서 계산하는 것이다.
* 2.시간복잡도
* O(NlogN)이므로 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Check[101];

int main(void) {

	int N, answer = 0, Max = -1;;
	cin >> N;

	vector<int> A(N);

	for (auto& i : A)
		cin >> i;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		Max = max(Max, temp);
		Check[temp]++;
	}

	sort(A.begin(), A.end());

	int index = 0;

	int i = Max;

	while (i != 0) {
		if (Check[i] > 0) {
			answer += i * A[index];
			index++;
			Check[i]--;
			continue;
		}
		i--;
	}

	cout << answer;

	return 0;
}