/*
* 간단한 코드지만 알고리즘을 떠올리는게 어려웠던 문제다.
* 우선 처음 떠오른 방범이 해결방법이였다. 하지만 이것이 맞는지 몰라서 다른방법을 찾아보다 처음 생각했던 방법이 맞다는걸 알게됬다.
* 방법은 오름차순 정렬한 후 하나씩 더해가면서 더한 총 값의 다음수가 불가능한 수 라는 것이다.
* 이유는 뒤늦게 알게 됬는데, 만약1,1,2,3,5,6,7,30 이 있다면 첫번째 수 1로 불가능 한 수는 2다. 두번째 수 까지 포함한다면
* 불가능 한 가장 작은 수는 3이다. 계속해서 세번째까지 포함하면 불가능한 가장 작은 수는 5다. 그 다음은 8이다.
* 각 나온 결과를 되돌아보면 이전 수는 모두 만들 수 있다는 것을 알 수 있다.
* 어째서 이런 결과가 나오냐면 이전 수들의 더한 값은 다시말해서 어떤 조합을 해서 그 수까지는 반드시 만들 수 있다는 뜻이다.
* 1,1,1 3개의 조합으로는 1, 2, 3을 만들 수 있고 1,2,3,4,5 의 조합으로는 1부터 5까지의 단독숫자와 6부터 15까지 모든 수를 합친값 까지 가능하다.
* 따라서 해당 숫자가 여태까지 더한 값 + 1 과 같거나 작다면 최소값은 기존에 더해온값 + 1 + 해당 값 이라는 뜻이다.
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
//	int sum = 1;
//
//	cin >> N;
//
//	vector<int> v(N);
//
//	for (auto& i : v) {
//		cin >> i;
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < N; i++) {
//		if (sum < v[i])
//			break;
//		sum += v[i];
//	}
//
//	cout << sum;
//
//	return 0;
//}
//2023-02-17 복습
/*
* 1.아이디어
* 해당 추를 크기 순서로 먼저 정렬한다.
* sum을 만들어 가장 작은 추 부터 비교한다. 만약 sum이 확인하고 있는 추보다 크다면,
* sum-1과 해당 추 사이에 있는 수는 만들수 없다는 뜻이다.
* 따라서 sum이 만들수 있는 가장 작은 수이다.
* 2.시간복잡도
* 정렬을 사용했으므로 O(NlogN), N<=1000 따라서 가능
* 3.변수형
* int :
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

	int sum = 1;
	for (int i = 0; i < N; i++) {
		if (sum < v[i])
			break;
		sum += v[i];
	}
	cout << sum;

	return 0;
}