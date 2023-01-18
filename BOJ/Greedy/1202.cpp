/*
* ù �õ��� ���͸� ����ؼ� ���� �־��ְ� ������ �Ŀ� ���� ���԰� �����鼭 ���� ��ġ�� ���� ������
* ���濡 �־��ְ�, ������ ��Ȱ��ȭ �����ִ� �ڵ带 �������.
* ������ �̷��� �Ǹ� �ð����⵵�� O(n*k)�� �ǰ�, �ð� �ʰ��� ������ �ȴ�
* ���� �Ʒ� �ڵ�� ������ �ٲ��. �⺻������ ����ϴ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 300001

//�ִ�ũ���� �迭����
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
	priority_queue<int> pq; //���� ū ���� top���� �δ� �켱���� ť

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int M, V;
		cin >> M >> V;
		jewerly[i] = { M, V };
	}

	for (int i = 0; i < K; i++) {
		cin >> bp[i];
	}

	//�ø����� ������ ���ش�. �̶� jewerly�� ���԰� ���� ������ ���ĵ�.
	sort(jewerly, jewerly + N);
	sort(bp, bp + K);
	int index = 0;

	for (int i = 0; i < K; i++) {
		//�ش� �賶�� ũ�Ⱑ ���ų� ���� ���Ը� ���� ������ pq�� �־���, ���� pq�� top�� 
		//�ش� �賶�� ���� �� �ִ� ���� ��ġ�� ���� �����̴�.
		while (index < N && bp[i] >= jewerly[index].first) {
			pq.push(jewerly[index].second);
			index++;
		}
		//���� ���濡 ���� �� �ִ� ���� ��ġ�ִ� ������ �ִ´�.
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;

	return 0;
}