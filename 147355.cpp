<<<<<<< HEAD
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
=======
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
>>>>>>> 7e3cdf22f60d3375536a16d355516c151b7652d7
}