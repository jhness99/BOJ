/*
* ���� �߰��� �� ���� ���ĵǼ� ���� ���� ���� �˷���� �ϹǷ� 
* �켱���� ť�� �������� �� ���� ���� ���� top�� �ǰ� �ؼ�
* �ش� ���� 2�� ���� ���� �������� �� �������� ���� ��
* ������� ���ϰ� �ٽ� �켱���� ť�� �־� Ȯ�����ش�
* �켱����ť�� ũ�Ⱑ 1�̵ɰ��(ī�� ������ 1���� ���� ���) �׸��д�.
* ������� ������� ���̴�.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {

	int N = 0;
	int answer = 0;
	priority_queue<int, vector<int>, greater<>> pq;		//���� ���� ���� top�� �Ǵ� �켱���� ť ����
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);		//�ڵ�����
	}
	while (pq.size() != 1) {	//ī�� ������ 1���� ���� ��� �ݺ�����
		int sum = 0;

		//�տ��� 2���� ���� ���ؼ� ���ο� ������ �����
		//�� ������ŭ ��Ƚ�� ������Ŵ
		sum += pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		answer += sum;	
		pq.push(sum);
	}
	cout << answer;
	return 0;
}