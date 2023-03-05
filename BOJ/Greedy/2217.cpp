/*
* 실버문제지만 하나 생각못했던것
* 내려가면서 예전의 가장 큰 무게와 비교해야됬던것
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(void) {
//
//	int N, weight = 0;
//	cin >> N;
//	
//	vector<int> v(N);
//
//	for (int i = 0; i < N; i++) 
//		cin >> v[i];
//
//	//가장 큰 무게를 견딜 수 있는 로프부터 확인하기위해 내림차순 정렬
//	sort(v.begin(), v.end(), greater<int>());
//
//	for (int i = 0; i < v.size(); i++) {
//		int temp = 0;
//		//가장 작은 로프를 기준으로 한 무게와 이전까지의 로프를 기준으로 한 무게와 비교
//		//더 큰 것을 채택
//		temp = v[i] * (i+1);
//		weight = max(weight, temp);
//	}
//
//	cout << weight;
//
//	return 0;
//}

//2023-02-01 복습
/*
* 이번에도 햇갈렸다. 간단한 문제인데...
* 내림차순으로 정렬하고 큰 값부터 확인하는건 생각했지만, 그 다음이 생각이 잘 안났음
* 이전에 확인했던 로프들의 합의 최대와 이번에 확인하는 로프의 무게x이 로프보다 같거나 큰 로프의 개수 를 비교해서
* 더 큰 값을 고르면 되는 문제였다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, weight = 0;;
	cin >> N;

	vector<int> v(N);

	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < N; i++) {
		int temp = v[i] * (i + 1);
		weight = max(weight, temp);
	}

	cout << weight;

	return 0;
}
//2023-03-04 복습
/*
* 1.아이디어
* 내림차순으로 정렬
* index를 기준으로 v[index] * (index+1)이 기존 값보다 큰지 확인하고 큰 값으로 갱신
*
* 2.시간복잡도
* O(NlogN) N<=100000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, answer = 0;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < N; i++) {
		answer = max(answer, v[i] * (i + 1));
	}
	cout << answer;

	return 0;
}