//ũ�Ⱑ ���� �κ� ���ڿ�
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i < t.length() - p.length() + 1; i++) {
        //�񱳴���� ���̸�ŭ �߶� ����
        string temp = t.substr(i, p.length());
        
        //�ڸ� ���ڿ��� ���ڷ� ��
        //ó���� stoi�� ��������� core dump ������ �� ū long long int ���� stoll���
        if (stoll(temp) <= stoll(p))
            answer++;
    }
    return answer;
}