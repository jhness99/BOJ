#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string numStr;
	cin >> numStr;

	sort(numStr.begin(), numStr.end() , greater<>());
	if (numStr.size() == 1 || numStr.back() != '0'){
		cout << -1;
	}
	else {
		long long sum = 0;
		for (auto& c : numStr) {
			sum += c - '0';
		}
		if (sum % 3 == 0)
			cout << numStr;
		else
			cout << -1;
	}
		
	

	return 0;
}