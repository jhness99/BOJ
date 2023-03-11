/*
* 1.아이디어
* 먼저 양수끼리의 합과 음수끼리의 합을 생각해봐야한다.
* 음수의 경우, 작은수 끼리 곱해야 더 큰 수가 된다.
* 따라서 양수는 큰 수 순서, 즉 내림차순으로,
* 음수는 작은 수 순서, 즉 오름차순으로 정렬해서
* 처음부터 끝가지 정렬해주면된다.
* 여기서 변수는 0을 생각해볼수있다.
* 0이 1개일경우,음수중 1개를 0으로 만들어 더 큰 수를 만들 수 있고,
* 음수는 작은수부터 곱하므로 음수의 갯수가 홀수였을경우 남는 수는 음수들 중에서 가장 큰 수가 남는다.
* 따라서 해당 수를 0과 곱하면 더 큰 수가 만들어 지므로 음수가 홀수개고 0이 있을경우 해당 수를 제거해주고
* 만약 음수가 짝수개라면 0이 있어도 제거해주지 않는다.
* 2.시간복잡도
* O(N) N<=50 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, answer = 0;
	cin >> N;

	vector<int> Plus;
	vector<int> Minus;


	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (temp > 1)
			Plus.push_back(temp);
		else if (temp == 1)
			answer++;
		else
			Minus.push_back(temp);
	}

	sort(Plus.begin(), Plus.end(), greater<>());
	sort(Minus.begin(), Minus.end());

	int PlusSize = Plus.size();
	if (PlusSize % 2 != 0) {
		PlusSize--;
		answer += Plus.back(); \
	}
	for (int i = 0; i < PlusSize; i += 2)
		answer += Plus[i] * Plus[i + 1];

	int MinusSize = Minus.size();
	if (MinusSize % 2 != 0) {
		MinusSize--;
		answer += Minus.back();
	}
	for (int i = 0; i < MinusSize; i += 2)
		answer += Minus[i] * Minus[i + 1];

	cout << answer;

	return 0;
}