/*
* 1.아이디어
* 모든 위치를 돌면서 만약 이전에 가장 작았던 기름가격보다 비싸다면 이전의 가장 작았던 기름가격으로 비용을 계산해 더해주고
* 더 작은 값이 나왔다면 이제부터 그 값으로 비용을 계산해 더해주도록 하면 된다.
* 2.시간복잡도
* O(N)의 시간복잡도를 가지고 N <= 100000 이므로 가능
* 3.변수형
* 기름의 가격이 최대 1000000000이므로 long long형으로 사용
*/
/*
* 복습이여서 생각보다 쉬웠다. 이번에도 변수를 틀릴 뻔 했지만 다행이 맞췄다.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N;
	long long totalCost = 0;

	cin >> N;
	vector<int> Distance(N - 1);
	vector<long long> Cost(N - 1);		//기름의 가격이 최대 1000000000이기때문에 long long으로 지정

	for (auto& i : Distance)
		cin >> i;

	for (auto& i : Cost)
		cin >> i;

	long long prev = 1e9+1;				//기본값을 할수있는 가장 큰값의 +1로 지정
	for (int i = 0; i < N - 1; i++) {

		//이전의 값과 현재위치의 기름값을 비교해 더 작은 값으로 비용계산
		prev = min(Cost[i], prev);		
		totalCost += prev * Distance[i];
	}
	cout << totalCost;

	return 0;
}