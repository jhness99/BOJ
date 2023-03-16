/*
* 1.아이디어
* //모든 문자열을 N-1개의 문자열과 비교해서 나온 Hamming Distance를 저장 , 해당 문자열을 결과값에 저장(틀림)
* 문자열의 모음을 행렬로 봤을때 해당 열의 알파벳은 가장 많이 나온 알파벳을 선택하고,
* Hamming Distance의 합은 문자열 개수 - 각 열에서 가장 많이 나온 알파벳 개수 값을 모든 열에서 확인하고 더하면
* 그 값이 각 문자열와 S의 Hamming Distance 들의 합이 된다.
* 2.시간복잡도
* O(n*n-1*m) = 50000000 이므로 가능
* 3. 변수
* vector<string> : 문자열 저장백터
* map<char, int> : 해당 열에서 알파벳별로 몇개나 나왔는지 확인
* int : 가장 작은 Hamming Distence가 최대 50*1000 이므로 int
*/
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M, HD = 0;
//	string answer;
//
//	cin >> N >> M;
//	vector<string> v(N);
//
//	for (auto& s : v)
//		cin >> s;
//
//	for (int i = 0; i < M; i++) {
//		//현재 열에 나오는 알파벳의 개수를 저장해 줄 맵
//		map<char, int> m;
//		for (int j = 0; j < N; j++) 
//			m[v[j][i]]++;
//		char ch = ' ';
//		int max = 0;
//		//맵에 저장된 가장 많이 등장한 알파벳을 알아냄
//		for (auto& p : m) {
//			if (max < p.second) {
//				max = p.second;
//				ch = p.first;
//			}
//		}
//		//가장 많이 등장한 알파벳을 해당 열의 답으로 선택하고, 
//		//해당 알파벳이 나오지 않은 수를 Hamming Distance 에 더해줌
//		answer += ch;
//		HD += N-max;
//	}
//
//	cout << answer << "\n";
//	cout << HD;
//
//	return 0;
//}
//2023-02-23 복습
/*
* 1.아이디어
* 입력받은 string을 vector에 저장한다.
* 저장한 string을 1번째부터 8번째 문자를 탐색
* 탐색하면서 문자의 카운트를 확인하고 가장 큰 카운트를 가진 문자를 answer에 넣는다.
* 그리고 count+= N-chCount 한다.
* 2.시간복잡도
* O(NM), N<=1000, M<=50
* 3.변수형
*
*/
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int main(void) {
//
//	int N, M;
//
//	cin >> N >> M;
//
//	vector<string> v(N);
//	string answer;
//	int Count = 0;
//
//	for (auto& s : v)
//		cin >> s;
//
//	for (int i = 0; i < M; i++) {
//		map<char, int> m;
//		for (int j = 0; j < N; j++)
//			m[v[j][i]]++;
//		char ch = ' ';
//		int Max = -1;
//		for (auto& p : m) {
//			if (Max < p.second) {
//				Max = p.second;
//				ch = p.first;
//			}
//		}
//		answer += ch;
//		Count += N - Max;
//	}
//
//	cout << answer << "\n" << Count;
//
//	return 0;
//}
//2023-03-16 복습
/*
* 1.아이디어
* 해시맵을 사용해서 풀 수 있다.
* 각 행마다가 아니라 열마다 얼마나 많은 알파벳이 나왔는지 계산하고 가장 많이 나온알파벳을 문자열에 추가해주면 된다.
* 그리고 전체개수 - 알파벳 나온 수를 하면 Hamming Distance의 합도 알 수 있다.
*
* 2.시간복잡도
* O(NM) N<=1000, M<= 50, 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {

	int N, M;
	cin >> N >> M;

	string answer;
	int cnt = 0;
	vector<string> v(N);
	for (auto& s : v)
		cin >> s;

	for (int i = 0; i < M; i++) {
		unordered_map<char, int> hm;

		for (int j = 0; j < N; j++)
			hm[v[j][i]]++;

		int Max = -1;
		char ch = ' ';

		sort(hm.begin(), hm.end());

		for (auto& p : hm) {
			if (p.second > Max) {
				ch = p.first;
				Max = p.second;
			}
		}
		answer += ch;
		cnt += N - Max;
	}

	cout << answer << "\n" << cnt;

	return 0;
}