/*
* 1.아이디어
* 입력받은 수를 종유석과 석순으로 나눠서 저장한다.
* 처음은 석순(바닥)이고 그 다음은 종유석(천장)이다
* 
* 2개를 나눠서 저장을 한 후에 오름차순 정렬을 한다.
* 이때 정렬을 한 이유는 정렬한 후의 값의 index는 종유석 or 석순 개수 - index를 할 시 장애물을 부셔야 하는 갯수가 나온다.
* 정렬한 값이 2 3 4 5 일경우, 2의 index는 0이다 만약 높이 1에서 전진한다면, 2 3 4 5 모두 부셔야 한다. 즉, 4
* 만약, 높이 4에서 시작한다면 index는 2이고 4 5 가 부셔진다. 즉 2,
* 때문에 종유석 or 석순 개수 - index를 할 시 장애물이 부셔야 하는 갯수가 나오는것이다.
* 
* index는 이분탐색인 lower_bound와 upper_bound를 사용하면 된다. 석순의 경우 lower_bound를 사용한다.
* 이때 종유석의 경우에는 천장에 있으므로 반대로 봐야한다. 천장을 바닥으로 생각해서 최대높이에서 확인높이를 빼준다.
* 예를들어 최대 7인 높이에서 높이 3을 고려한다면, 4가 되고 1 2 3 5에서 5가 된다 5는 index 가 3 이므로 즉, 1
* 
* 두 값을 더하고 더한값을 최소가 되도록 갱신해주고 만약 같은 값이 나오면 나온 횟수를 증가 시켜준다.
* 2.시간복잡도
* 정렬로 인한 복잡도 O(NlogN), 이분탐색을 H번 반복하므로 O(HlogN) 
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, H;
	cin >> N >> H;

	vector<int> Top(N / 2);
	vector<int> Bottom(N / 2);

	for (int i = 0; i < N / 2; i++) {
		cin >> Bottom[i] >> Top[i];
	}

	sort(Top.begin(), Top.end());
	sort(Bottom.begin(), Bottom.end());

	int answer = 200001;
	int num = 0;
	for (int hight = 1; hight <= H; hight++) {
		int cnt = 0;

		int index = lower_bound(Bottom.begin(), Bottom.end(), hight) - Bottom.begin();
		cnt += N / 2 - index;

		index = upper_bound(Top.begin(), Top.end(), H - hight) - Top.begin();
		cnt += N / 2 - index;

		
		if (answer > cnt) {
			answer = cnt;
			num = 1;
		}else if (answer == cnt) num++;
	}

	cout << answer << " " << num;

	return 0;
}