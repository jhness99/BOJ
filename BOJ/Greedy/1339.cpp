/*
* �� ������ �ּ�ó���� �κ��� ���� �� �κ��ε�, map�� ����� �� ���ĺ����� ���ڸ� �����ؼ� Ǯ����.
* ������ ������ Ʋ���� �ǰ� ������ ã�ƺôµ�, ó���� �׸��� �˰��� map�� ����ؼ� Ʋ���� �˾Ҵ�.
* ������ �˰��� ��ü�� ������ �־��µ� �ݷʸ� ���� ��ڴ�
* ABC�� BCD�� �ϸ� ���� �� �ڵ忡���� 
* A�� ���� �������Ƿ� A�� 9�� ������, �׷��� ���� ū ���� �� �� ����.
* B�� 100�� �ڸ��� 10�� �ڸ����� 1���� �������� A�� 100�� �ڸ����� 1�� ���Ա� ������
* ���� ���� �������� B�� �� ���� ���� �ִ� ���� �� ū ���� �ȴٴ� ���̴�.
* �˻��� �� �� ��� �� ���ĺ��� �������� x(�ش� ���ĺ��� ���� �ڸ������� ��)*���ĺ� �÷� ����
* �ش� ���� �������� ���� �� �Ŀ� 9���� 1���� ���ʴ�� ���� ���� ���ϸ� ���� ������ ���̿���.
* ������� ABC BCD�� ��� 
* A = 100�ڸ�, ���� 100A 
* B = 100�ڸ�, 10�ڸ�, ���� 110B
* C = 10�ڸ�, 1�ڸ�, ���� 11C
* D = 1�ڸ�, ���� 1D �� �ȴ�.
* �̷��ԵǸ� ���ĺ� �迭���� alpha[] = {100, 110, 11, 1}�� ����ǰ� �ǰ� ���� A, B, C, D�� �����̴�.
* �̰��� �����ϸ� B A C D �� �ǰ� ���� B = 9, A = 8, C = 7, D = 6 �̵ȴ�.
* ���������� alpha[i] * (9 - i)�� ���༭ �ش� ���ĺ��� ���� �˼��ִ�.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

//#include <map>
using namespace std;

int main(void) {

	/*
	int N, maxSize = 0;
	int sum = 0;
	cin >> N;
	
	
	map<char, int> m;
	vector<string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		maxSize = max((int)v[i].length(), maxSize);
	}

	int cnt = 9;
	//�� ���ĺ��� 9~1������ �����Ѵ�.
	for (int i = 0; i < maxSize; i++) {
		for (auto& s : v) {
			int index = i + s.length() - maxSize;
			if (index >= 0) {
				if (m.find(s[index]) == m.end()) {
					m.insert({ s[index], cnt });
					cnt--;
				}
			}
		}
	}
	
	������ ���� ����� string�� ���ڷ� ��ȯ�ؼ� ���ϱ�
	for (auto& s : v) {
		string temp = "";
		for (int i = 0; i < s.length(); i++) {
			temp += to_string(m[s[i]]);
		}
		sum += stoi(temp);
	}

	cout << sum;
	*/

	int N, maxSize = 0;
	int sum = 0;
	cin >> N;

	//�� ���ĺ��� ���ڷ� ��ȯ�ɶ� ���ؾ� �ϴ� ���� �迭
	vector<int> alpha(26, 0);
	vector<string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		maxSize = max((int)v[i].length(), maxSize);
	}

	for (auto& s : v) 
		for (int i = 0; i < s.length(); i++) 
			alpha[s[i] - 'A'] += pow(10, s.length() - i - 1);
	
	//�������� ���ķ� 9���� 1���� ������� ���Եǰ� ��
	sort(alpha.begin(), alpha.end(), greater<>());

	int i = 0;
	while (alpha[i] > 0) {
		sum += alpha[i] * (9 - i);
		i++;
	}

	cout << sum;
	return 0;
}