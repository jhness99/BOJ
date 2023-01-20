#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M, sum = 0;

	cin >> N >> M;
	int minSet = 10000;
	int minPrice = 10000;
	for (int i = 0; i < M; i++) {
		int price;
		int setPrice;

		cin >> setPrice >> price;
		minPrice = min(minPrice, price);
		minSet = min(minSet, setPrice);
	}

	sum = min((N / 6 + 1) * minSet, min((N * minPrice), ((N / 6) * minSet)+((N%6)* minPrice)));

	cout << sum;

	return 0;
}