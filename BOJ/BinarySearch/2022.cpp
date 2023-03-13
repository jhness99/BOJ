/*
* 1.아이디어
* 수학적인 풀이법이 필요한 문제이다.
* 삼각비를 이용해 풀 수있다.
* 자세한건 https://sw-ko.tistory.com/145 를 봐보자
* 
* 쨋든 mid(두 빌딩 사이의 거리)를 넣었을 때 C의 높이가 나오게 되는 공식을 세운 후
* 이분탐색으로 탐색하면 되는 문제이다.
* 간단한 이분탐색 문제이지만 공식을 도출해내는과정이 어려웠다.
*/
#include <iostream>

using namespace std;

int main(void) {

	double x, y, c, answer = 0;
	
	cin >> x >> y >> c;

	double left = 0;
	double right = min(x,y); // 두 값 다 사이거리보다 길고, 그중 작은 것으로 해야 연산횟수가 줄어드므로 min사용
	double result = 0;

	//수가 소숫점 6자리까지 주어지므로, 오차를 없애기 위해 이렇게 표현
	while (right - left > 0.000001) {
		double mid = (left + right) / 2.0;

		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);

		double h3 = (h1 * h2) / (h1 + h2);
		if (h3 >= c) {
			answer = mid;
			left = mid;
		}
		else
			right = mid;
	}
	cout << fixed;
	cout.precision(3);
	cout << answer;

	return 0;
}