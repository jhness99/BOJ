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
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, H;
//	cin >> N >> H;
//
//	vector<int> Top(N / 2);
//	vector<int> Bottom(N / 2);
//
//	for (int i = 0; i < N / 2; i++) {
//		cin >> Bottom[i] >> Top[i];
//	}
//
//	sort(Top.begin(), Top.end());
//	sort(Bottom.begin(), Bottom.end());
//
//	int answer = 200001;
//	int num = 0;
//	for (int hight = 1; hight <= H; hight++) {
//		int cnt = 0;
//
//		int index = lower_bound(Bottom.begin(), Bottom.end(), hight) - Bottom.begin();
//		cnt += N / 2 - index;
//
//		index = upper_bound(Top.begin(), Top.end(), H - hight) - Top.begin();
//		cnt += N / 2 - index;
//
//		
//		if (answer > cnt) {
//			answer = cnt;
//			num = 1;
//		}else if (answer == cnt) num++;
//	}
//
//	cout << answer << " " << num;
//
//	return 0;
//}
//2023-03-24 복습
/*
* 1.아이디어
* 이 문제는 석순과 종유석을 각각 해당 높이에서 몇개나 부셔야 하는지 따로 계산해주면된다.
* 계산한 갯수가 가장 적어진 경우의 높이와 갯수를 출력하면 되는 문제이다.
*
* 이제 각 석순과 종유석을 기준으로 몇개나 부셔야 하는지를 구해야 한다.
* 구하기 위해서 우선 정렬한다.
* 우선 석순의 경우 정렬했을 때 해당 높이를 기준으로 같거나 큰 석순의 갯수를 구해야 한다.
* 따라서 lowe_bound를 사용해 해당 높이보다 긴 석순을 구한다. 석순의 총 개수 - index
* 이렇게 되면 index는 같거나 큰 즉 관통해야하는 석순의 첫번째 index를 가져오므로
* 해당 높이일 때 부셔야 하는 석순의 개수를 알 수 있다
*
* 다음 종유석의 경우는 일단 종유석은 천장에 붙어있으므로 높이를 반대로 생각해줘야 한다.
* 만약 높이가 1이라면, 부술수 없는 종유석의 위치는 1~천장이 높이 - 1이 된다.
* 그말은 즉 (천장의 높이-확인하는 높이)의 upper_bound가 첫번째로 부수기 시작하는 위치이고,
* 해당 값을 종유석의 개수에 빼주면 부셔야 하는 종유석의 갯수가 나오게 된다.
*
* 해당 방법으로 모든 관통하는 종유석, 석순의 합을 구하고 해당 합이 전에 구한 합보다 작다면,
* 갱신해주고 해당 개수와 같은 높이가 있다면 cnt해준다.
*
* 2.시간복잡도
* 최대 N/2개의 종유석과 석순이 있으므로 정렬로 인해 각각 O(2*(N/2)log(N/2)),
* 이분탐색으로 하는 부분은 O(HlogN/2) 이다. 따라서 O(HlogN)이라고 할 수 있고, N<=200000, H<=500000
* 따라서 가능
*
* 3.변수형
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, H;
	cin >> N >> H;

	vector<int> Buttom(N / 2);
	vector<int> Top(N / 2);

	for (int i = 0; i < N / 2; i++) {
		cin >> Buttom[i] >> Top[i];
	}

	sort(Buttom.begin(), Buttom.end());
	sort(Top.begin(), Top.end());

	int answer = 200001;
	int cnt = 0;
	for (int Height = 1; Height <= H; Height++) {
		int total = 0;
		int index = lower_bound(Buttom.begin(), Buttom.end(), Height) - Buttom.begin();
		total += N / 2 - index;

		index = upper_bound(Top.begin(), Top.end(), H - Height) - Top.begin();
		total += N / 2 - index;

		if (answer > total) {
			answer = total;
			cnt = 1;
		}
		else if (answer == total) cnt++;
	}

	cout << answer << " " << cnt;

	return 0;
}