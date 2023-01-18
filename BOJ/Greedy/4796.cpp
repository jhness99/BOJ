#include <iostream>

using namespace std;

int main(void) {
	int L, P, V;

	int i = 1;
	while(1) {
		cin >> L;
		cin >> P;
		cin >> V;

		if (!L&& !P&& !V)
			break;

		int temp = 0;
		temp = (V / P)*L + min(V%P, L);
		cout << "Case " << i << ": " << temp << "\n";
		i++;
	};
	
	return 0;
}