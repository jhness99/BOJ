/*
* 1.아이디어
* 부배열과 부배열의 합이 이해가 안되서 찾아봤다.
* 부배열이란, A[1]~A[N]까지 있다면, A[i]~A[j] 이때 1 <= i, j <= N이다.
* 따라서 부배열은 여러개가 생길 수 있고 순차적으로 되어있다
* 만약 i가 1이고 j가 5라면 A[1] A[2] A[3] A[4] A[5]가 부배열이다.
* 그렇다면 부배열의 합은 A[1]+A[2]+A[3]+A[4]+A[5] 이 된다.
* 여기서 중요한건 순차적으로 배열이 나온다는 것이다.
* 
* 그리고 나온 부배열의 합이 각각 v1, v2 백터에 저장됬다고 하자.
* 이때 나온 v1, v2의 원소 1개씩 더해서 나오는 값이 T 이여야 한다.
* 즉, T = v1[i] + v2[j] 이다. 이는 T - v1[i] = v2[j]로 표현할 수도있다.
* 따라서 v1의 모든원소를 순회하면서 v2의 값들과 T - v1[i]를 비교해서 같은 수들의 갯수를 구해주면 된다.
* 
* 따라서 lower_bound와 upper-bound를 사용해 v1[i]일때 v2안의 원소들의 충족하는 수들의 가장 첫번째와 
* 마지막 수를 가져와서 둘의 index를 빼서 갯수를 구한다.
* 2.시간복잡도
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int T, N, M;
//	cin >> T;
//
//	cin >> N;
//	vector<int> A(N);
//
//	for (auto& i : A)
//		cin >> i;
//
//	cin >> M;
//	vector<int> B(M);
//
//	for (auto& i : B)
//		cin >> i;
//
//	vector<int> v1;
//	vector<int> v2;
//
//	for (int i = 0; i < N; i++) {
//		int sum = A[i];
//		v1.push_back(sum);
//		for (int j = i + 1; j < N; j++) {
//			sum += A[j];
//			v1.push_back(sum);
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		int sum = B[i];
//		v2.push_back(sum);
//		for (int j = i + 1; j < M; j++) {
//			sum += B[j];
//			v2.push_back(sum);
//		}
//	}
//
//	sort(v2.begin(), v2.end());
//	long long answer = 0;
//	for (int i = 0; i < v1.size(); i++) {
//		int low = lower_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
//		int high = upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
//
//		answer += high - low;
//	}
//	cout << answer;
//
//	return 0;
//}
//2023-03-23 복습
/*
* 1.아이디어
* 2개의 배열을 받아와서 두 배열의 부 배열의 합을 만들어야 한다.
* 여기서 부 배열의 합이라면 1 <= i <= j <= N 일때 A[i]+...+A[j]을 말한다.
* 따라서 A에서의 부배열의 합, B에서의 부배열의 합을 만들어서
* 서로 더한값중 T인 값이 몇개있는지 확인해주면 된다.
*
* 그 부분은 lower_bound와 uppor_bound를 사용한다. 2개를 사용해서 A의 부배열들의 합중 1개와 B의 부배열들의 합과 비교해서
* 몇개나 있는지 더해주는 것이다. 그렇게 해서 모든 수를 확인한다.
*
* 2.시간복잡도
* 각 부배열의 합 백터를 만드는데 O(N^2), O(M^2) 이고 T가 가능한 조합을 구하는 시간복잡도가
* O(NlogM^2)이다. N, M<=1000 따라서 가능
* 3.변수형
* long long answer : 최대가능한 조합의 갯수가 N^2*M^2 1000*1000*1000*1000 = 1000000000000 따라서 long long
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int T, N, M;
	long long answer = 0;;
	cin >> T;

	cin >> N;
	vector<int> A(N);
	for (auto& i : A)
		cin >> i;

	cin >> M;
	vector<int> B(M);
	for (auto& i : B)
		cin >> i;

	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < N; i++) {
		int sum = A[i];
		v1.push_back(sum);
		for (int j = i + 1; j < N; j++) {
			sum += A[j];
			v1.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		int sum = B[i];
		v2.push_back(sum);
		for (int j = i + 1; j < M; j++) {
			sum += B[j];
			v2.push_back(sum);
		}
	}

	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++) {
		int low = lower_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
		int upper = upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();

		answer += upper - low;
	}

	cout << answer;

	return 0;
}