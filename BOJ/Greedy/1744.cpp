/*
* 처음 시도한 코드는 우선순위 큐에 값을 다 넣어주고 top부터 2개 빼서 더한것이 큰지 곱한것이 큰지 비교하게 했다
* 하지만 이 코드의 문제는 음수를 고려하지 않았다. 예를 들면 -1,-2,-3,-4,-5를 묶으면
* 내가 쓴 코드는 가장 큰 값을 빼내기에 (-1,-2) (-3,-4) 이렇게 묶게 되는데
* 이러면 -5가 그냥 더해지므로 최대값이 되지 않는다.
* 따라서 우선순위큐가 아니라 각각 양수와 음수를 따로 구분해서 정렬한 후 계산해줬다.
* 0은 음수배열에 포함시켜줬다. 0은 -와 곱하면 0이 되므로 홀수일 때 작아지는 마지막 음수 때문에 작아지는 것을 막아줄 수 있기 때문이다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	/*
	int N;
	long long sum = 0;
	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	while (pq.size() > 1) {
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();

		if (num1 == 0) {
			if (pq.size() % 2 != 0) {
				pq.push(num2);
				continue;
			}
		}

		if (num1 * num2 > num1 + num2) {
			sum += num1 * num2;
		}
		else {
			sum += num1;
			pq.push(num2);
		}
	}
	if (!pq.empty()) {
		int num = pq.top();
		pq.pop();
		sum += num;
	}
	cout << sum;

    return 0;
	*/

	vector<int> pos;		//양수 벡터
	vector<int> neg;		//음수 벡터
	int N;
    int sum = 0;
    cin >> N;
    
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input > 0) 
			pos.push_back(input);
		else
			neg.push_back(input);		//음수 벡터는 0을 포함함
	}
	sort(pos.begin(), pos.end(), greater<>());		//큰 순으로 정렬
	sort(neg.begin(), neg.end());					//작은 순으로 정렬(그래야 곱했을 때 양수가 되면서 최대)

	int posSize = pos.size();
	if (posSize % 2 != 0) sum += pos.back();		//만약 양수의 수가 홀수개라면 가장 마지막에 있는 작은 값을 더해준다.
	for (int i = 0; i < posSize-1; i+= 2) {
		if (pos[i + 1] == 1) sum += pos[i] + pos[i + 1];	//1일경우 곱하면 자기자신이 나와서 최대가 되지 않으므로 더해준다.
		else if (pos[i + 1] > 0) sum += pos[i] * pos[i + 1];
	}

	int negSize = neg.size();
	if (negSize % 2 != 0) sum += neg.back();		//만약 음수의 수가 홀수개라면 가장 마지막에 있는 작은 값을 더해준다.
	for (int i = 0; i < negSize-1; i += 2) 
		sum += neg[i] * neg[i + 1];					//음수는 곱하는 것이 무조건 가장 크므로 조건없이 곱해준다.

	cout << sum;

	return 0;
}