#include <iostream>
#include <string>

using namespace std;

int main(void) {

	int N;
	int CntL = 0;
	string str;
	cin >> N;
	cin >> str;

	

	for (auto& c : str) {
		if (c == 'L')
			CntL++;
	}
	
	if (CntL != 0) {
		N -= CntL/2 -1;
	}
	cout << N;

	return 0;
}