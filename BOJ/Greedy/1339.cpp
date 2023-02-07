/*
* 이 문제는 주석처리한 부분이 내가 한 부분인데, map을 사용해 각 알파벳마다 숫자를 적용해서 풀었다.
* 하지만 문제는 틀리게 되고 이유를 찾아봤는데, 처음엔 그리디 알고리즘에 map을 사용해서 틀린줄 알았다.
* 하지만 알고리즘 자체의 문제가 있었는데 반례를 예로 들겠다
* ABC와 BCD를 하면 내가 한 코드에서는 
* A가 먼저 나왔으므로 A가 9가 되지만, 그러면 가장 큰 수가 될 수 없다.
* B는 100의 자리와 10의 자리에서 1번씩 나왔지만 A는 100의 자리에서 1번 나왔기 때문에
* 같은 수로 비교했을때 B에 더 높은 수를 넣는 것이 더 큰 수가 된다는 것이다.
* 검색을 해 본 결과 각 알파벳을 기준으로 x(해당 알파벳이 나온 자리수들의 합)*알파벳 꼴로 만들어서
* 해당 수를 내림차순 정렬 한 후에 9부터 1까지 차례대로 곱한 값을 더하면 수가 나오는 것이였다.
* 예를들면 ABC BCD일 경우 
* A = 100자리, 따라서 100A 
* B = 100자리, 10자리, 따라서 110B
* C = 10자리, 1자리, 따라서 11C
* D = 1자리, 따라서 1D 가 된다.
* 이렇게되면 알파벳 배열에는 alpha[] = {100, 110, 11, 1}가 저장되게 되고 각각 A, B, C, D의 순서이다.
* 이것을 정렬하면 B A C D 가 되고 각각 B = 9, A = 8, C = 7, D = 6 이된다.
* 순차적으로 alpha[i] * (9 - i)를 해줘서 해당 알파벳의 값을 알수있다.
*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
////#include <map>
//using namespace std;
//
//int main(void) {
//
//	/*
//	int N, maxSize = 0;
//	int sum = 0;
//	cin >> N;
//	
//	
//	map<char, int> m;
//	vector<string> v(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//		maxSize = max((int)v[i].length(), maxSize);
//	}
//
//	int cnt = 9;
//	//각 알파벳을 9~1까지로 매핑한다.
//	for (int i = 0; i < maxSize; i++) {
//		for (auto& s : v) {
//			int index = i + s.length() - maxSize;
//			if (index >= 0) {
//				if (m.find(s[index]) == m.end()) {
//					m.insert({ s[index], cnt });
//					cnt--;
//				}
//			}
//		}
//	}
//	
//	매핑한 값을 사용해 string을 숫자로 변환해서 더하기
//	for (auto& s : v) {
//		string temp = "";
//		for (int i = 0; i < s.length(); i++) {
//			temp += to_string(m[s[i]]);
//		}
//		sum += stoi(temp);
//	}
//
//	cout << sum;
//	*/
//
//	int N, maxSize = 0;
//	int sum = 0;
//	cin >> N;
//
//	//각 알파벳이 숫자로 변환될때 곱해야 하는 수의 배열
//	vector<int> alpha(26, 0);
//	vector<string> v(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//		maxSize = max((int)v[i].length(), maxSize);
//	}
//
//	for (auto& s : v) 
//		for (int i = 0; i < s.length(); i++) 
//			alpha[s[i] - 'A'] += pow(10, s.length() - i - 1);
//	
//	//내림차순 정렬로 9부터 1까지 순서대로 대입되게 함
//	sort(alpha.begin(), alpha.end(), greater<>());
//
//	int i = 0;
//	while (alpha[i] > 0) {
//		sum += alpha[i] * (9 - i);
//		i++;
//	}
//
//	cout << sum;
//	return 0;
//}
//2023-02-07 복습
/*
* 1.아이디어
* 모든 문자열을 각 자리수로 치환한다. 예를들면 GCF는 G는 100, C는 10, F는 1, ACDEB는 A = 10000, C = 1000, D = 100, E = 10, B = 1이다
* 각 치환한 자리수가 몇번나오는지 계산해서 나오는 수가 가장 많은 순으로 정렬한다
* 위의 예제를 더하면 10000, 1010, 100, 100, 10, 10, 1이고 각 순서는 A, C, G, D, E, F, B
* 정렬한 후 각 자리수로 치환한 값을 9부터 곱해준다.
* 이렇게 한 이유는 반례 ABC BCD를 보면 알 수 있다.만약 A가 가장 앞에 있다고 A에 9를 치환하면 B에 9를 치환한 수보다 작게된다.
* 따라서 이렇게 각 자리수의 합까지 모두 고려해야지만 최대값을 구할 수 있다.
* 2.시간복잡도
* 8자리까지 가능한 수를 최대 10개까지 가능하므로 N<=80, O(N) 따라서 가능
* 3.변수형
* int:
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	int answer = 0;
	cin >> N;

	vector<int> alpha(26, 0);
	vector<string> v(N);

	for (auto& s : v)
		cin >> s;

	for (auto& s : v) {
		for (int i = 0; i < s.length(); i++)
			alpha[s[i] - 'A'] += pow(10, s.length() - i - 1);
	}

	sort(alpha.begin(), alpha.end(), greater<>());


	int i = 0;
	while (alpha[i] > 0) {
		answer += alpha[i] * (9 - i);
		i++;
	}
	cout << answer;

	return 0;
}