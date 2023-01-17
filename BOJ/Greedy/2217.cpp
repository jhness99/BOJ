/*
* �ǹ��������� �ϳ� �������ߴ���
* �������鼭 ������ ���� ū ���Կ� ���ؾ߉����
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int N, weight = 0;
	cin >> N;
	
	vector<int> v(N);

	for (int i = 0; i < N; i++) 
		cin >> v[i];

	//���� ū ���Ը� �ߵ� �� �ִ� �������� Ȯ���ϱ����� �������� ����
	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++) {
		int temp = 0;
		//���� ���� ������ �������� �� ���Կ� ���������� ������ �������� �� ���Կ� ��
		//�� ū ���� ä��
		temp = v[i] * (i+1);
		weight = max(weight, temp);
	}

	cout << weight;

	return 0;
}