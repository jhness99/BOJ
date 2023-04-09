/*
* 1.아이디어
* 예전에 했던 M과 N문제와 비슷하다.
* 입력값을 정렬하고 이전에 사용했던 숫자를 기억해서 해당 숫자가 또 나올경우, 넘어가주면 된다.
* 
* prev를 사용해서 중복숫자 사용을 막으려고 했지만 조합에 따라 다른 수가 가능한 경우도 있었다.
* 따라서 모든 수의 중복을 확인하려고 해야 했다. 99가 최대 4개 까지 들어갈 수 있으므로 99999999이 최대가 되고, 따라서 100000000의 배열을 만들어서
* 방문처리를 하고 방문을 이미 했다면 answer를 더해주지 않으면 된다. 이 방법도 가능하지만 다른풀이를 보고 같은 로직의 더 좋은 코드로 작성했다.
* 
* 바로 set을 사용해서 중복을 막아주는 것이다. set에 전부 넣어주고 로직이 끝난 후 set의 크기만 알아내면 된다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int N, K;
int input[10];
int answer;
bool check[10];
set<int> setNum;

void DFS(int cnt, string str) {
	if (cnt == K) {
		setNum.insert(stoi(str));
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i])continue;
		check[i] = true;
		DFS(cnt + 1, str + to_string(input[i]));
		check[i] = false;
	}
}

int main(void) {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	DFS(0, "");

	cout << setNum.size();

	return 0;
}