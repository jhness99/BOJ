/*
* 1.아이디어
* 입력이 주어진건 값이 오름차순으로만 올 것 같지만 그건아니다.
* 
* 입력받은 값을 순서대로 모든 연산을 해 보고 그 값을 min, max값으로 갱신해준다.
* 
* 갱신인 이렇게 한다.
* 우선 각 연산이 나오는 위치를 표시해준다. op[N+1]에 각각의 연산을 넣고
* 만약 마지막 숫자 까지의 연산을 모두 넣었다면,  op를 가지고 연산을 시작한다.
* 이때 나오는 연산값으로 min 값이나 max값을 갱신해준다.
*/
#include <iostream>

using namespace std;

int op[11];
int A[11];
int B[4];

int N, Max, Min;

void Cal() {
	int total = A[0];
	for (int i = 1; i < N; i++) {
		switch (op[i])
		{
		case 0:
			total += A[i];
			break;
		case 1:
			total -= A[i];
			break;
		case 2:
			total *= A[i];
			break;
		case 3:
			total /= A[i];
			break;
		}
	}
	Max = max(Max, total);
	Min = min(Min, total);
}

void DFS(int index) {
	if (N == index) {
		Cal();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (B[i] == 0) continue;
		B[i]--;
		op[index] = i;
		DFS(index+1);
		B[i]++;
		op[index] = 0;
	}
}

int main(void) {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> B[i];
	}
	Max = -1000000000;
	Min = 1000000000;
	
	DFS(1);

	cout << Max << "\n" << Min;

	return 0;
}