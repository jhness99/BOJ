/*
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
*/
/*
* 2023-02-02 복습
* 1.아이디어
* 어떤 수가 30으로 나누어 떨어져야 하는데, 30은 3*10이므로 만약 비교할 수의 만약 1의자리에 수가 있다면 무조건 불가능하다.
* 3으로 나누어 떨어지는 수의 공통점은 모든 수를 더한값이 3으로 나누어떨어진다는 것이다. ex)53241 -> 5+3+2+4+1 = 15, 53241%3 == 0
* 2.시간복잡도
* N은 100000개의 수로 이루어져있으므로 O(N), sort정렬을 사용하므로 O(NlogN), 따라서 가능
* 3.변수형
* string : 입력값은 string 으로 받는다.
* int : 모든 수들을 합쳐도 900000이기때문에 int형
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	string N;
	cin >> N;

	sort(N.begin(), N.end(), greater<char>());	//내림차순 정렬

	int sum = 0;
	for (auto& c : N)
		sum += c - '0';

	if (sum % 3 != 0 || N.back() != '0')		//모두 더한 값이 3으로 나누어 떨어지지않거나 마지막 수가 0이 아닌경우 불가능
		cout << -1;
	else if (sum % 3 == 0)
		cout << N;

	return 0;
}