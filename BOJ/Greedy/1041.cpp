/*
* 1.아이디어
* 각 주사위 면을 입력받은다.
* (0,5)번째, (1,4)번째, (2,3)번째 면끼리 마주보고있으므로 둘 중 작은 값을 저장하고 정렬한다.
* 정렬하고 3면, 2면, 1면이 보이는 큐브에 값을 넣음
* n=1,일경우 전부더하고 가장 큰 값을 빼주면 된다.
* n>=2, 3면은 무조건 4개, 2면은 (n-1)*4//측면 + (n-2)*4//위에면, 3면은 (n-1)*(n-2)*4//측면 + (n-2)^2//위에면 
* 2.시간복잡도
* 단순for문만 사용하므로 O(N), N이 최대 1000000 이므로 가능
* 3.변수형
* long long:
* 최대 N이 1000000이므로 N+N^2+N^2
* 따라서 1000000000000이 최대 크기이므로 결과값은long long
*/
/*
* 문제풀이
* 진짜 어려웠다. 규칙만 알면 쉬운문제였는데 규칙을 찾는게 너무 어려웠다.
* 규칙은 간단하다. N이 늘어날수록 각 면에 큐브수가 1개식 증가되는데,
* 이때 1면,2면,3면이 보이는 큐브수의 변화만 알면 됬다.
* 3면은 4개 고정이고 2와 1은 n에 따라 변한다.
* 어떤 면을 선택할지는 마주보는 면은 나올 수 없으므로 마주보는 면중 더 작은 면을 선택해 총 3개의 면을 구하고
* 오름차순으로 정렬한 뒤 더해주면 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	long long N;
	int max_num = 0;
	long long answer = 0;
	int d[6];
	cin >> N;

	for (int i = 0; i < 6; i++) {
		cin >> d[i];
		answer += d[i];
		max_num = max(d[i], max_num);
	}
	
	if (N == 1) {
		cout << answer - max_num;
	}
	else {
		answer = 0;
		d[0] = min(d[0], d[5]);
		d[1] = min(d[1], d[4]);
		d[2] = min(d[2], d[3]);

		sort(d, d + 3);
		int sum1 = d[0];
		int sum2 = sum1 + d[1];
		int sum3 = sum2 + d[2];

		answer += sum3 * 4;
		answer += sum2 * ((N - 1) * 4 + (N - 2) * 4);
		answer += sum1 * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));
		
		cout << answer;
	}

	return 0;
}