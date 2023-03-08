/*
* 첫 시도는 벡터를 사용해서 수를 넣어주고 정렬한 후에 가장 무게가 작으면서 가장 가치가 높은 순으로
* 가방에 넣어주고, 가방을 비활성화 시켜주는 코드를 만들었다.
* 하지만 이렇게 되면 시간복잡도가 O(n*k)이 되고, 시간 초과가 나오게 된다
* 따라서 아래 코드로 로직을 바꿨다. 기본적으로 비슷하다
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//#define MAX 300001
//
////최대크기의 배열생성
//pair<int, int> jewerly[MAX];
//int bp[MAX];
//
//int main(void) {
//	/*
//	int N, K, sum = 0;
//	cin >> N >> K;
//	vector<pair<int, int>> v;
//	vector<pair<int, bool>> bp;
//	for (int i = 0; i < N; i++) {
//		int M, V;
//		cin >> M >> V;
//		v.push_back({ M, V });
//	}
//
//	for (int i = 0; i < K; i++) {
//		int temp;
//		cin >> temp;
//		bp.push_back({ temp, false });
//	}
//
//	sort(v.begin(), v.end(), [](const pair<int, int> &p1,const pair<int, int> &p2) {
//		if (p1.first < p2.first)
//			return true;
//		else if (p1.first == p2.first)
//			return p1.second > p2.second;
//		else
//			return false;
//		});
//	sort(bp.begin(), bp.end());
//
//	for (auto& p : v) {
//		for (auto& i : bp) {
//			if (i.first >= p.first && !i.second) {
//				i.first -= p.first;
//				i.second = true;
//				sum += p.second;
//				break;
//			}
//		}
//	}
//
//	cout << sum;
//	*/
//	int N, K; 
//	long long sum = 0;
//	priority_queue<int> pq; //가장 큰 값을 top으로 두는 우선순위 큐
//
//	cin >> N >> K;
//
//	for (int i = 0; i < N; i++) {
//		int M, V;
//		cin >> M >> V;
//		jewerly[i] = { M, V };
//	}
//
//	for (int i = 0; i < K; i++) {
//		cin >> bp[i];
//	}
//
//	//올림차순 정렬을 해준다. 이때 jewerly는 무게가 작은 순으로 정렬됨.
//	sort(jewerly, jewerly + N);
//	sort(bp, bp + K);
//	int index = 0;
//
//	for (int i = 0; i < K; i++) {
//		//해당 배낭과 크기가 같거나 작은 무게를 가진 보석만 pq에 넣어짐, 따라서 pq의 top은 
//		//해당 배낭이 가질 수 있는 가장 가치가 높은 보석이다.
//		while (index < N && bp[i] >= jewerly[index].first) {
//			pq.push(jewerly[index].second);
//			index++;
//		}
//		//현재 가방에 넣을 수 있는 가장 가치있는 보석을 넣는다.
//		if (!pq.empty()) {
//			sum += pq.top();
//			pq.pop();
//		}
//	}
//	cout << sum;
//
//	return 0;
//}
//2023-02-08 복습
/*
* 1.아이디어
* 가장 작은 배낭부터 그 배낭이 넣을 수 있는 가장 가치있는 보석을 넣어야 한다.
* 배낭의 무게와 보석의 무게를 기준으로 각각 정렬을 해준다.
* 정렬한 후 배낭을 기준으로 해당 배낭에 넣을 수 있는 가장 가치있는 보석을 찾는다
* 이는 우선순위 큐를 사용해 보석의 무게를 넣고, 배낭보다 무거운 보석이 나왔을 경우
* 반복을 종료하고 우선순위 큐의 가장 무거운 보석을 가치에 더해주면된다.
* 2.시간복잡도
* O(N + K) + O(NlogN) + O(KlogK) N, k<=300000 이므로 가능
* 3.변수형
* long long : 보석의 최대가치가 100000000 이므로 long long
*/
//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, K;
//	cin >> N >> K;
//	vector<pair<int, int>> jewelry(N);
//	vector<int> bp(K);
//	priority_queue<int> pq;
//	long long sum = 0;
//
//	for (auto& p : jewelry)
//		cin >> p.first >> p.second;
//
//	for (auto& i : bp)
//		cin >> i;
//
//	sort(jewelry.begin(), jewelry.end());
//	sort(bp.begin(), bp.end());
//
//	int index = 0;
//	for (int i = 0; i < K; i++) {
//		while (index < N && bp[i] >= jewelry[index].first) {
//			pq.push(jewelry[index].second);
//			index++;
//		}
//		if (!pq.empty()) {
//			sum += pq.top();
//			pq.pop();
//		}
//	}
//
//	cout << sum;
//
//	return 0;
//}
//2023-02-24 복습
/*
* 1.아이디어
* 입력을 받아 pair로 저장
* 가방 무게를 받아서 해당 무게보다 가벼운 보석의 가치를 우선순위 큐에 저장
* 더이상 넣을 수 없다면(모든 보석을 확인함, 또는 가방무게가 더이상 안들어옴, 입력받은 가방 무게보다 더 높음) 우선순위 큐의 가장 큰 값을 answer에 저장
* 이를 K번 반복함
* 2.시간복잡도
* sort를 사용했으므로 O(NlogN) N<=300000 따라서 가능
* 3.변수형
* long long : 보석의 값이 최대 100000000 이므로 100000000*300000(가방의 수)는 long long을 사용해야 한다.
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//
//	int N, K;
//	long long answer = 0;
//	priority_queue<int> pq;
//	cin >> N >> K;
//
//	vector<pair<int, int>> v(N);
//	vector<int> bp(K);
//	for (auto& p : v) {
//		cin >> p.first >> p.second;
//	}
//
//	for (auto& i : bp) {
//		cin >> i;
//	}
//
//	sort(v.begin(), v.end());
//	sort(bp.begin(), bp.end());
//
//	int index = 0;
//	for (int i = 0; i < K; i++) {
//
//		while (index < N && v[index].first <= bp[i]) {
//			pq.push(v[index].second);
//			index++;
//		}
//		if (!pq.empty()) {
//			answer += pq.top();
//			pq.pop();
//		}
//	}
//
//	cout << answer;
//
//	return 0;
//}
//2023-03-08복습
/*
* 1.아이디어
* 가방을 오름차순으로 정렬하고 해당 가방에 담을 수 있는 모든 보석의 가치를 넣는다.
* 가장 높은 가치가 top이 되도록 우선순위 큐를 사용하고 해당 보석을 가방에 넣는다.
* 이미 넣은 보석은 넣지 않도록한다.
*
* 2.시간복잡도
* sort로 인해 O(NlogN+KlogK), N, K<=300000 따라서 가능
* 3.변수형
* long long : 넣은 보석의 가치가 가장 클 경우 int형을 넘으므로 long long
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long answer = 0;
	int N, K;
	priority_queue<int> pq;

	cin >> N >> K;
	vector<pair<int, int>> jewelry(N);
	for (auto& p : jewelry)
		cin >> p.first >> p.second;

	vector<int> bp(K);
	for (auto& i : bp)
		cin >> i;

	sort(jewelry.begin(), jewelry.end());
	sort(bp.begin(), bp.end());

	int index = 0;
	for (int i = 0; i < K; i++) {

		while (index < N && jewelry[index].first <= bp[i]) {
			pq.push(jewelry[index].second);
			index++;
		}

		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;

	return 0;
}