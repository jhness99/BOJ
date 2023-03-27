/*
* 1.아이디어
* 모든 알파벳의 조합을 사용해 탐색한다. 일단 시간초과가 걸릴 것 같지만 모든 알파벳을 확인해보자
* 알파벳을 모두 확인한 조합의 길이가 K개가 된다면 모든 입력받은 string을 확인해서 만약 조합의 알파벳중에 문자열의 알파벳이 없다면 
* return, 만약 모든 알파벳이 조합의 알파벳중에 있다면 cnt++, 마지막에 answer 와 cnt중 비교해서 더 큰 것으로 갱신
* 
* 2.시간복잡도
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

vector<string> str;
bool check[26];
int answer;

int N, K;

void DFS(int cnt, int index) {
	if (cnt == K) {
		int cnt = 0;
		bool read;
		for (int i = 0; i < str.size(); i++) {
			read = true;
			for (int j = 0; j < str[i].size(); j++) {
				if (!check[str[i][j] - 'a']) {
					read = false;
					break;
				}
			}
			if(read == true)
				cnt++;
		}
		answer = max(answer, cnt);
		return;
	}
	for (int i = index; i < 26; i++) {
		if (check[i]) continue;
		check[i] = true;
		DFS(cnt + 1, i);
		check[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		str.push_back(temp);
	}

	if (K < 5)
	{
		cout << 0 << endl;
		return 0;
	}

	check['a' - 'a'] = true;
	check['n' - 'a'] = true;
	check['t' - 'a'] = true;
	check['i' - 'a'] = true;
	check['c' - 'a'] = true;

	K = K - 5;

	DFS(0 , 0);

	cout << answer;

	return 0;
}