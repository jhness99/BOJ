//���ڿ� ������
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCount = 0;
    int nonxCount = 0;
    char x;
    for (int i = 0; i < s.length(); i++) {
        //ù �����̸� �ش� ���ڸ� x�� ����
        if (xCount == 0)
            x = s[i];

        if (s[i] == x) xCount++;
        else nonxCount++;

        //x�� ����Ƚ���� x�� �ƴ� ������ ����Ƚ���� ���� ��� ī��Ʈ �ʱ�ȭ �� �ܾ���߰�
        //���� ����Ƚ���� ���� �ʴ��� �������̶�� �ܾ�� �߰�
        if (xCount == nonxCount || i == s.length() - 1) {
            xCount = 0;
            nonxCount = 0;
            answer++;
        }
    }
    return answer;
}