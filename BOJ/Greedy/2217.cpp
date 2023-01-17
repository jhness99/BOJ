/*
* 실버문제지만 하나 생각못했던것
* 내려가면서 예전의 가장 큰 무게와 비교해야됬던것
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int N, weight = 0;
	cin >> N;
	
	vector<int> v(N);

	for (int i = 0; i < N; i++) 
		cin >> v[i];

	//가장 큰 무게를 견딜 수 있는 로프부터 확인하기위해 내림차순 정렬
	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++) {
		int temp = 0;
		//가장 작은 로프를 기준으로 한 무게와 이전까지의 로프를 기준으로 한 무게와 비교
		//더 큰 것을 채택
		temp = v[i] * (i+1);
		weight = max(weight, temp);
	}

	cout << weight;

	return 0;
}