/*
* 1.아이디어
* 두 용액-2470 과 똑같은 문제이다.
* 차이점은 입력받는 데이터가 정렬 되어있는지, 아닌지의 차이이다
* 따라서 해당 문제를 푼 알고리즘인 투 포인터를 사용하면 된다.
* 이번문제는 정렬이 되어있으므로 정렬을 따로 해줄 필요가 없다.
* 
* 입력받은 처음값을 left, 마지막값을 right에 넣는다.
* 각 left와 right의 위치의 숫자를 rightNum, leftNum에 저장한다.
* 해당 수 2개를 index로 넣은 값을 더한 값을 value에 저장한다.
* 
* left와 right를 기준으로 해당 위치의 용액을 가져와서 더한다.
* 더한 값과 기존 value의 절대값을 비교해서 기존value가 절대값이 더 크다면,
* rightNum, leftNum를 left, right로 갱신해준다. 그리고 value도 갱신해준다.
* 갱신한 value가 양수이면 0과 가까워지기 위해 감소해야하므로, right--;
* 갱신한 value가 음수라면 0과 가까워지기 위해 증가해야하므로, left++;
* left >= right 가 될때까지 반복한다.
* 2.시간복잡도
* O(N), N<=100,000, 따라서 가능
* 3.변수형
* 
*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//	
//	int N;
//	cin >> N;
//
//	vector<int> v(N);
//
//	for (auto& i : v)
//		cin >> i;
//
//	int left = 0;
//	int right = N - 1;
//
//	int leftNum = v[left];
//	int rightNum = v[right];
//
//	int value = leftNum + rightNum;
//
//	while (left < right) {
//		int newValue = v[left] + v[right];
//		if (abs(value) >= abs(newValue)) {
//			value = newValue;
//			leftNum = v[left];
//			rightNum = v[right];
//		}
//		
//		if (newValue > 0)	//최악의 경우 value는 바뀌지 않을 수 있으므로 매번 right left를 사용해서 값을 바꿔주는 newValue를 기준으로 이동
//			right--;
//		else
//			left++;
//	}
//
//	cout << leftNum << " " << rightNum;
//
//	return 0;
//}
//2023-03-20 복습
/*
* 1.아이디어
* 두 용액-2470과 같은 문제이다. 차이는 이 문제는 이미 오름차순으로 정렬되어있다는 점 정도이다.
* 그 외에는 두 용액과 같은 방법인 투 포인터로 풀면된다.
* left = 0, right = N-1로 설정한다.
* input[left] + input[right]의 절대값을 기준으로 해당 값이 최소가 된다면, leftNum rightNum을 갱신해주고
* 0과 비교해서 크다면, right-- 0과 비교해서 작다면, left ++ 를 해준다.
* left와 right가 만나게 된다면 종료한다.
*
* 2.시간복잡도
* N개를 모두 확인하므로 O(N), N<=100000, 따라서 가능
* 3.변수형
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<int> input(N);
	for (auto& i : input)
		cin >> i;

	int left = 0;
	int right = N - 1;
	int leftNum = input[left];
	int rightNum = input[right];
	int value = abs(rightNum + leftNum);

	while (left < right) {
		int newValue = input[left] + input[right];
		if (value > abs(newValue)) {
			value = abs(newValue);
			leftNum = input[left];
			rightNum = input[right];
		}
		if (0 < newValue)
			right--;
		else
			left++;
	}

	cout << leftNum << " " << rightNum;

	return 0;
}