/*
* Ʋ������
* 1. while�� ���ǹ����� �޼��ؾ��� S�� totalNum+i(���� ���ؿ� �� + ������)�� ���� ���� ������� ����
* 2. �ڷ����� long long ���ε� int�� ���
*/
#include <iostream>

using namespace std;

int main(void) {

	long long S = 0;		//int ����ؼ� ������

	cin >> S;
	long long i = 1;		//int ����ؼ� ������
	int N = 0;
	long long totalNum = 0;
	while (totalNum + i <= S) {		//���� ��� ������� �ʾ� ������
		N++;
		totalNum += i;
		i++;
	}

	cout << N;

	return 0;
}