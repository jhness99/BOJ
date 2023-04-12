/*
* 1.아이디어
* 구슬을 입력받아서 해당 구슬을 복사해서 해당 위치를 지우고 지운 양 옆의 위치의 구슬의 합을 더해준다.
* 구슬의 개수가 3개일 경우 가운대밖에 지울수 없으므로 가운대를 지웠을때, 즉 v[0] + v[2]를 여태 더해준 합에 더해서
* 최대값으로 갱신해준다.
*/
#include <iostream>
#include <vector>

using namespace std;

int N;
int answer = -1;

void DFS(vector<int>& v, int sum) {
	if (v.size() == 3) {
		sum += (v[0] * v[2]);
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < v.size() - 2; i++) {
		vector<int> copyV = v;
		copyV.erase(copyV.begin() + i + 1);
		DFS(copyV, sum + (v[i] * v[i + 2]));
	}
}

int main(void) {
	
	cin >> N;
	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	DFS(v, 0);

	cout << answer;

	return 0;
}