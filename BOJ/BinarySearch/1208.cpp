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
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, S;
//int arr[40];
//vector<int> A;
//vector<int> B;
//long long result = 0;
//
//void makeA(int sum, int index) {
//	if (index >= N / 2)
//		return;
//
//	sum += arr[index];
//	if (sum == S) result++;
//
//	A.push_back(sum);
//	makeA(sum - arr[index], index + 1);
//	makeA(sum, index + 1);
//}
//
//void makeB(int sum, int index) {
//	if (index >= N )
//		return;
//
//	sum += arr[index];
//	if (sum == S) result++;
//
//	B.push_back(sum);
//	makeB(sum - arr[index], index + 1);
//	makeB(sum, index + 1);
//}
//
//int main(void) {
//
//	cin >> N >> S;
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	makeA(0, 0);
//	makeB(0, N / 2);
//
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//
//	for (int i = 0; i < A.size(); i++) {
//		int low = lower_bound(B.begin(), B.end(), S - A[i]) - B.begin();
//		int high = upper_bound(B.begin(), B.end(), S - A[i]) - B.begin();
//		result += (high - low);
//	}
//
//	cout << result;
//
//	return 0;
//}
//2023-03-27 복습
/*
* 1.아이디어
* 최대 40개의 수열을 가지고 조합을 만들기 때문에 2^40개의 조합이 나온다. 이렇게 되면 너무 큰 수가 나오므로 시간초과가 걸린다.
* 따라서 반으로 나눠서 2^20 2^20 2개로 나눈다. 이렇게 되면 각각 100만밖에 안되기 때문에 이분탐색을 사용해 해당수들을 탐색해서
* 두 수를 합쳐서 S가 나오는 수를 찾으면 된다.
*
* 수열로 부분수열의 합을 구하는 함수2개를 만들어준다.
* 수열로 부분수열의 합을 만드는 함수는 이렇게 만든다.
* 우선 입력으로 재귀로 보내줄 sum과 부분수열을 만들 가장 끝 위치를 매개변수로 준다.
* index가 한계를 넘었다면 종료해주고, 아니라면
* sum에 해당 index위치의 arr를 더해준다. 만약 더한값이 S라면, 나중에 두 수를 더해서 나오는 수열에선 체크할 수 없으므로 result++해준다.
* 그리고 더한 값을 각 백터에 push_back해준다. 여기서 중요한데 2개의 재귀호출을 한다. 이때 재귀호출하는것은
* 방금 더해준 arr[index]를 뺀것과 아닌것이다. 이유는 수열에 자기자신을 포함하냐 안하냐의 차이다.
* 빼준것은 자기자신을 빼줬으므로 다음수는 포함하지만 자신은 수열에서 뺀 것들의 합을 나타낼 수 있고
* 빼지않은것은 방금 더해준 수까지 수열로 포함하는 수들의 합으로 나타낼 수 있다.
* 이렇게 하면 모든 수를 확인할 수 있고 O(2^N)의 시간복잡도를 가진다.
*
* 해당 로직으로 A와 B로 나눠서 수열의 합을 만들어주고 해당 수열들의 합을 했을 때에 S가 나오는지 이분탐색을 사용해서 개수를 구해주면 된다.
*
* 2.시간복잡도
* O(2^(N/2)log2^(N/2)) + O(2^(N/2+1)) + O(2^(N/2+1)log2^(N/2+1)) N<=40 따라서 가능
* 3.변수형
* long long result : 2^40이 최악의 경우의 수인데 해당 수는 int를 넘으므로 long long
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

void MakeA(int sum, int index) {
	if (index >= N / 2)
		return;

	sum += arr[index];
	if (sum == S)result++;

	A.push_back(sum);
	MakeA(sum - arr[index], index + 1);
	MakeA(sum, index + 1);
}

void MakeB(int sum, int index) {
	if (index >= N)
		return;

	sum += arr[index];
	if (sum == S)result++;

	B.push_back(sum);
	MakeB(sum - arr[index], index + 1);
	MakeB(sum, index + 1);
}

int main(void) {

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	MakeA(0, 0);
	MakeB(0, N / 2);

	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		int low = lower_bound(B.begin(), B.end(), S - A[i]) - B.begin();
		int high = upper_bound(B.begin(), B.end(), S - A[i]) - B.begin();
		result += (high - low);
	}

	cout << result;

	return 0;
}