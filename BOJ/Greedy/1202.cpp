/*
* 첫 시도는 벡터를 사용해서 수를 넣어주고 정렬한 후에 가장 무게가 작으면서 가장 가치가 높은 순으로
* 가방에 넣어주고, 가방을 비활성화 시켜주는 코드를 만들었다.
* 하지만 이렇게 되면 시간복잡도가 O(n*k)이 되고, 시간 초과가 나오게 된다
* 따라서 아래 코드로 로직을 바꿨다. 기본적으로 비슷하다
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 300001

//최대크기의 배열생성
pair<int, int> jewerly[MAX];
int bp[MAX];

int main(void) {
	/*
	int N, K, sum = 0;
	cin >> N >> K;
	vector<pair<int, int>> v;
	vector<pair<int, bool>> bp;
	for (int i = 0; i < N; i++) {
		int M, V;
		cin >> M >> V;
		v.push_back({ M, V });
	}

	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		bp.push_back({ temp, false });
	}

	sort(v.begin(), v.end(), [](const pair<int, int> &p1,const pair<int, int> &p2) {
		if (p1.first < p2.first)
			return true;
		else if (p1.first == p2.first)
			return p1.second > p2.second;
		else
			return false;
		});
	sort(bp.begin(), bp.end());

	for (auto& p : v) {
		for (auto& i : bp) {
			if (i.first >= p.first && !i.second) {
				i.first -= p.first;
				i.second = true;
				sum += p.second;
				break;
			}
		}
	}

	cout << sum;
	*/
	int N, K; 
	long long sum = 0;
	priority_queue<int> pq; //가장 큰 값을 top으로 두는 우선순위 큐

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int M, V;
		cin >> M >> V;
		jewerly[i] = { M, V };
	}

	for (int i = 0; i < K; i++) {
		cin >> bp[i];
	}

	//올림차순 정렬을 해준다. 이때 jewerly는 무게가 작은 순으로 정렬됨.
	sort(jewerly, jewerly + N);
	sort(bp, bp + K);
	int index = 0;

	for (int i = 0; i < K; i++) {
		//해당 배낭과 크기가 같거나 작은 무게를 가진 보석만 pq에 넣어짐, 따라서 pq의 top은 
		//해당 배낭이 가질 수 있는 가장 가치가 높은 보석이다.
		while (index < N && bp[i] >= jewerly[index].first) {
			pq.push(jewerly[index].second);
			index++;
		}
		//현재 가방에 넣을 수 있는 가장 가치있는 보석을 넣는다.
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;

	return 0;
}