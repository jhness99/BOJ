//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//	int N, M, sum = 0;
//
//	cin >> N >> M;
//	int minSet = 10000;
//	int minPrice = 10000;
//	for (int i = 0; i < M; i++) {
//		int price;
//		int setPrice;
//
//		cin >> setPrice >> price;
//		minPrice = min(minPrice, price);
//		minSet = min(minSet, setPrice);
//	}
//
//	sum = min((N / 6 + 1) * minSet, min((N * minPrice), ((N / 6) * minSet)+((N%6)* minPrice)));
//
//	cout << sum;
//
//	return 0;
//}
//2023-02-09 복습
/*
* 1.아이디어
* 가장 값싼 세트와 가장 값싼 낱개의 가격을 저장
* 만약 낱개를 6곱한것보다 세트의 가격이 더 비싸다면, 필요한 줄의 개수*낱개의 가격으로 한다.
* 아니라면 필요한 줄 개수를 6으로 나눠서 나온 값을 세트가격을 곱하고, 나머지는 낱개와 곱해서 더해준다.
* 2.시간복잡도
* 가장 값 싼 가격을 M개에서 확인해야하므로 O(M), M<=50 이므로 가능
* 3.변수형
* int :
*/
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M, answer = 0;
//	cin >> N >> M;
//
//	int minSetPrice = 1000;
//	int minPrice = 1000;
//	for (int i = 0; i < M; i++) {
//		int set, single;
//		cin >> set >> single;
//		minSetPrice = min(set, minSetPrice);
//		minPrice = min(single, minPrice);
//	}
//
//	if (minSetPrice > minPrice * 6) {
//		answer = minPrice * N;
//	}
//	else
//		answer = (N / 6) * minSetPrice + min(minPrice * (N % 6), minSetPrice);
//
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-08 복습
/*
* 1.아이디어
* 입력받은 세트와 낱개중 가장 가격이 싼 거 2개를 저장
*
* 만약 낱개*6개보다 세트가 더 비싸다면, answer = 낱개 * N;
* 아닐경우 answer = N/6 * 세트 + min(낱개 * (N%6), 세트)
*
* 2.시간복잡도
* O(M), M<=50 따라서 가능
* 3.변수형
*
*/
#include <iostream>

using namespace std;

int main(void) {

	int N, M, answer = 0;
	cin >> N >> M;

	int minSetPrice = 1001;
	int minPrice = 1001;
	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		minSetPrice = min(minSetPrice, num1);
		minPrice = min(minPrice, num2);
	}
	if (minPrice * 6 < minSetPrice)
		answer = minPrice * N;
	else
		answer = (N / 6) * minSetPrice + min((N % 6) * minPrice, minSetPrice);

	cout << answer;

	return 0;
}