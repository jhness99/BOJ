#include <iostream>

using namespace std;

int main(void) {

	int n;
	int cnt = 0;

	cin >> n;

	while (n > 1) {
		if (n >= 5 && (n-5 >= 5 || (n - 5)%2 == 0)) {
			n -= 5;
			cnt++;
		}
		else if(n >= 2){
			n -= 2;
			cnt++;
		}
	}

	if (n == 1)
		cnt = -1;

	cout << cnt;
	return 0;
}