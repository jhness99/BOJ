/*
* ����������� ��Ծ��� ������ �����Ѵ�.
* string�� ���� ���ڿ��� �����ϴ� Ÿ���ε�
* char�� �迭���� ����� �� �ִ�.
* �̶� �� �����ؾ��ϴµ� ���ڿ��� ���̱� 4�� string�� ũ��� 5�̰�
* �������� '\0'�� �Ǿ��ִµ� �� �κе� ������ ' '���� ǥ���ǹǷ�
* �Ʒ��� i�� lnput.length()-1���� �����ص� i+1, �� input[input.length()]�� ���� ������ �� �ִ�
* �� ������ �������̶� �ް����� ����ó���� ���ִ� �ٽ� ã�ƺ��� �����Ѵ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	int answer = 0;
	int cnt[2] = { 0, };
	string input = "";
	cin >> input;
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != input[i+1]) {
			cnt[input[i] - '0']++;
			/*
			if (input[i] == '0') {
				cnt[0]++;
			}
			else {
				cnt[1]++;
			}
			*/
		}
	}
	cout << min(cnt[0], cnt[1]);

	return 0;
}