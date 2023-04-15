/*
* 1.아이디어
* 우선 시작위치가 정해져있다. 왼쪽 끝 부분에서 무조건 시작하게 되고 
* 달라지는건 그 이후에 부딛칠 계란을 고를때이다. 따라서 자기자신을 제외한 모든 경우를 확인해보아야 한다.
* 
* (맞은풀이)
* DFS풀던것처럼 확인하는데 이때 확인하는건 내가 몇번째 계란을 들고있는지였다.
* 내가 들고있는 계란을 기준으로 모든 계란을 쳐서 부수는 것이다.
* 이때 내가 들고있는 계란이 이미 깨져있을 경우도 있으므로 그럴경우 다음으로 넘어가도록 한다.
* 만약 더 이상 계란을 깰 수 없을떄(마지막까지 안가도 전부 깨져있거나, 아직 깰 수 있는 계란이 남아있지만 마지막 계란으로 전부 시도 했을경우) 현재 깬 계란의 개수를 확인해주어야 한다.
* 확인됬다면 answer와 비교해 더 큰 값으로 갱신해준다.
*/
#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector<pair<int, int>> eggs;
int arr[8];

void DFS(int index) {
	if (index == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (eggs[i].first <= 0)
				cnt++;
		}
		answer = max(answer, cnt);
		return;
	}
	if (eggs[index].first <= 0) DFS(index + 1);
	else {
		bool CheckCrushEgg = false;
		for (int i = 0; i < N; i++) {
			if (eggs[i].first <= 0 || i == index) continue;

			eggs[i].first -= eggs[index].second;
			eggs[index].first -= eggs[i].second;
			
			CheckCrushEgg = true;
			DFS(index + 1);

			eggs[i].first += eggs[index].second;
			eggs[index].first += eggs[i].second;
		}
		if (!CheckCrushEgg) DFS(N);
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		eggs.push_back({ a,b });
	}

	DFS(0);

	cout << answer;

	return 0;
}