//���� ����� ���� ����
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    //�Էµ� ���ڿ��� ��ġ�� �ϳ��ϳ� ������ �� �� ����
    map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        //�ʿ� �ش� ���ĺ��� �ִ��� Ž��
        auto index = m.find(s[i]);

        //���ĺ��� �������
        if (index == m.end()) {
            m.insert({ s[i], i });
            answer.push_back(-1);
        }
        //���ĺ��� �������
        else {
            answer.push_back(i - (index->second));
            index->second = i;  //�ش� ���ĺ��� �ٽ� �⿬�� ��ġ�� ����
        }
    }

    return answer;
}