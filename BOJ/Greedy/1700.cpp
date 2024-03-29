/*
* 문제풀이
* 이 문제는 고려할 부분이 총 3가지가 있다. 
* 첫째, 현재 사용하려는 전기용품이 이미 멀티탭에 꽃여있는가
* 둘째, 현재 멀티텝에 비어있는 부분이 있는가
* 셋째, 새로운 전기용품을 사용하기 위해 하나의 멀티텝을 빼야하는가
* 이 3가지 조건을 모두 적용시켜 for문으로 스케쥴을 확인시켜주면된다.
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N;
//	int K;
//	int cnt = 0;
//
//	cin >> N >> K;
//
//	vector<int> multiTap(N,0);
//	vector<int> schedule(K);
//
//	for (auto& i : schedule) {
//		cin >> i;
//	}
//
//	for (int i = 0; i < K; i++) {
//		bool flag = false;
//		//만약 확인하고있는 전기용품이 이미 꽃여있는가
//		for (int j = 0; j < N; j++) {
//			if (schedule[i] == multiTap[j]) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag)
//			continue;
//		//만약 현재 멀티텝에 빈 곳이 있는가
//		for (int j = 0; j < N; j++)
//		{
//			if (multiTap[j] == 0)
//			{
//				multiTap[j] = schedule[i];
//				flag = true;
//				break;
//			}
//		}
//		if (flag == true)
//			continue;
//
//		//만약 멀티텝에 꽃인 전기용품을 빼고 새로운 전기용품을 꽃아야 하는가
//		int changeLoc = -1;		//멀티탭에서 뺄 전기용품의 위치
//		int num = -1;			//멀티탭에서 뺄 전기용품이 다음에 사용 되는 거리(이때 다시 사용하지 않을경우 -1)
//		for (int j = 0; j < N; j++) {
//
//			//temp는 꽃여있는 전기용품이 다음에 언제 다시 사용하는지를 저장하는 변수
//			int temp = 0;
//			for (int k = i + 1; k < K; k++) {
//
//				//해당 멀티탭에 꽃인 전기용품이 다시 사용 되는 때까지의 거리를 측정
//				if (schedule[k] == multiTap[j])
//					break;
//				temp++;
//			}
//			
//			//해당 거리가 이전에 체크한 다른 멀티탭의 전기용품의 거리와 비교해서 더 클 경우
//			//해당 전기용품을 멀티탭에서 뺄 전기용품으로 저장
//			//이후 더 멀거나 더이상 사용하지 않는 전기용품(끝까지 가게되서 temp의 값이 가장 크게 나오게 됨)을 발견하면 그 위치로 갱신
//			if (temp > num) {
//				num = temp;
//				changeLoc = j;
//			}
//		}
//		//모든 멀티탭을 확인하고 가장 멀거나 사용하지 않는 전기용품을 다음 스케쥴의 전기용품으로 바꿔준다.
//		multiTap[changeLoc] = schedule[i];
//		cnt++;
//	}
//
//	cout << cnt;
//
//	return 0;
//}
//2023-02-18
/*
* 1.알고리즘
* 고려해아할 것 3개
* 1)현재 멀티탭이 비어있는지
* 2)이미 꽂여있는 전기제품인지
* 3)어떤 콘센트를 빼고 끼워야 하는 경우
* 2.시간복잡도
* O(NK^2), N,K <= 100, 따라서 가능
* 3.변수형
* vector<int> schedule(K) : 스케쥴을 저장해주는 벡터
* vector<int> multiTap(N, 0) : 멀티탭에 어떤 전기제품이 끼워져있는지
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, K, answer = 0;
//	cin >> N >> K;
//
//	vector<int> schedule(K);
//	vector<int> multiTap(N, 0);
//
//	for (auto& i : schedule)
//		cin >> i;
//
//	for (int i = 0; i < K; i++) {
//		bool flag = false;
//		for (int j = 0; j < N; j++) {
//			if (multiTap[j] == schedule[i]) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag)
//			continue;
//
//		for (int j = 0; j < N; j++) {
//			if (multiTap[j] == 0) {
//				flag = true;
//				multiTap[j] = schedule[i];
//				break;
//			}
//		}
//		if (flag)
//			continue;
//
//		int changeNum = -1;
//		int num = -1;
//
//		for (int j = 0; j < N; j++) {
//			int temp = 0;
//			for (int k = i + 1; k < K; k++) {
//				if (schedule[k] == multiTap[j])
//					break;
//				temp++;
//			}
//			if (num < temp) {
//				num = temp;
//				changeNum = j;
//			}
//		}
//		multiTap[changeNum] = schedule[i];
//		answer++;
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-12 복습
/*
* 1.아이디어
* 먼저 플레그에 최대한 콘센트를 꼽는다.
*
* 우리는 만약 플레그를 뽑아야 할 경우를 확인하고
* 만약 뽑아야 한다면 가장 마지막에 나오는 전기용품이 있는 콘센트를 뽑고 새로운 콘센트를 끼워주기만 하면 된다.
* 그리고 해당 연산을 했다면 cnt를 해주면 된다.
*
* (틀린이유)
* 먼저 중복되는 곳이 있는지 확인해야 한다. 빈 곳부터 확인하면 빈곳이 없지만 중복되어 들어갈 수 있으므로
* 중복되는 부분을 체크 안 할수 있기 때문이다.
*
* 2.시간복잡도
*
* 3.변수형
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M, answer = 0;
//	cin >> N >> M;
//
//	vector<int> multiTap(N, 0);
//	vector<int> schedule(M);
//
//	for (auto& i : schedule)
//		cin >> i;
//
//	for (int i = 0; i < M; i++) {
//
//		bool flag = false;
//
//		for (int j = 0; j < N; j++) {
//			if (multiTap[j] == schedule[i]) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag)
//			continue;
//
//		for (int j = 0; j < N; j++) {
//			if (multiTap[j] == 0) {
//				flag = true;
//				multiTap[j] = schedule[i];
//				break;
//			}
//		}
//		if (flag)
//			continue;
//
//		int ChangeLoc = -1;
//		int num = -1;
//
//		for (int j = 0; j < N; j++) {
//			int temp = 0;
//			for (int k = i + 1; k < M; k++) {
//				if (multiTap[j] == schedule[k])
//					break;
//				temp++;
//			}
//			if (temp > num) {
//				num = temp;
//				ChangeLoc = j;
//			}
//		}
//		multiTap[ChangeLoc] = schedule[i];
//		answer++;
//	}
//	cout << answer;
//
//	return 0;
//}
//2023-04-09 복습
/*
* 1.아이디어
* 이 문제는 3가지 경우를 고려해주면 된다.
* 첫번째는 멀티탭이 비어있는지
* 두번째는 멀티탭에 꽂으려고 하는 전기용품이 이미 꽂여있는지
* 세번째는 멀티탭에 꽂을 공간이 없는경우
*
* 이 3가지 경우를 모두 고려해서 횟수를 고려해주면 된다.
*
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, K, answer = 0;
	cin >> N >> K;

	vector<int> multiTap(N, 0);
	vector<int> schedule(K);
	for (auto& i : schedule)
		cin >> i;

	for (int i = 0; i < K; i++) {
		bool flag = false;

		for (int j = 0; j < N; j++) {
			if (multiTap[j] == schedule[i]) {
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		for (int j = 0; j < N; j++) {
			if (multiTap[j] == 0) {
				flag = true;
				multiTap[j] = schedule[i];
				break;
			}
		}

		if (flag)
			continue;

		int ChangeLoc = -1;
		int Num = -1;

		for (int j = 0; j < N; j++) {
			int temp = 0;
			for (int k = i + 1; k < K; k++) {
				if (multiTap[j] == schedule[k])
					break;
				temp++;
			}
			if (temp > Num) {
				Num = temp;
				ChangeLoc = j;
			}
		}
		multiTap[ChangeLoc] = schedule[i];
		answer++;
	}
	cout << answer;

	return 0;
}