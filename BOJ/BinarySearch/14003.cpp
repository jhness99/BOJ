#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);;
	int N, cnt = 0;
	cin >> N;

	vector<int> input(N), LIS;
	vector<pair<int, int>> check;
	for (auto& i : input) {
		cin >> i;
		check.push_back({ i, 0 });
	}

	LIS.push_back(input[0]);
	check[0].second = cnt;

	for (int i = 1; i < N; i++) {
		if (LIS.back() < input[i]) {
			LIS.push_back(input[i]);
			cnt++;
			check[i].second = cnt;
		}
		else {
			int start = 0;
			int end = LIS.size() - 1;
			int mid = end;
			while (start < end) {
				mid = (start + end) / 2;
				if (LIS[mid] < input[i])
					start = mid + 1;
				else
					end = mid;
			}
			LIS[end] = input[i];
			check[i].second = end;
		}
	}

	cout << cnt + 1<< "\n";

	vector<int> answer;
	for (int i = N - 1; i >= 0; i--) {
		if (cnt == check[i].second) {
			answer.push_back(check[i].first);
			cnt--;
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}
//2023-03-21 복습
/*
* 1.아이디어
* 길이가 최대 100만이다. dp를 사용하면 O(N^2)의 시간복잡도를 가지게 되서 시간초과가 일어나므로  이분탐색으로 접근한다.
* 이분탐색을 사용한 LIS문제에서 추가로 해당하는 LIS수열을 출력해야한다.
*
* 우선 이분탐색으로 LIS를 만드는것은 다음과 같다.
* 1.맨 처음 가장 앞에있는 수를 LIS에 push_back한다.
* 2.i, 1->N까지 반복시작
* 3.input[i]가 LIS의 back보다 크다면, 해당 수를 push_back
* 4.만약 같거나 작다면, LIS의 범위를 기준으로 이분탐색 시작, left = 0, right = LIS.size()-1;
* 5.이분탐색을 해서 input[i]와 같거나 초과하는 가장 첫번째 수를 찾아서 해당수 위치에 input[i]를 넣어준다.
* 6.이분탐색이 끝나면, LIS.size()가 LIS의 길이가 된다.
*
* 여기서 LIS를 출력해야 하는데, 이때 만든 LIS를 그대로 출력해선 안된다.
* 왜냐하면 해당 수는 길이만 맞춰주기 때문에 뒤죽박죽이기 때문이다.
* 그러면 어떻게 해야하느냐 하면 input에 있는 모든 수를 LIS에 어디위치에 넣었는지를 저장하는것이다.
* 그 후, LIS의 사이즈를 기준으로 해당 사이즈에 갱신된 수를 저장해서 거꾸로 출력하는 것이다.
*
* 그렇게 되면 LIS가 성립하게 된다. 어디위치에 넣은지 갱신하는 것은 처음 push_back할때랑 이분탐색이 끝났을 때 갱신해준다.
*
* (틀린부분)
* cnt 가 0으로 시작해야 되는 이유를 몰랐다.
* 이유는 이분탐색이 끝나고 check[i].second = index; 에서 index는 0~LIS.size()-1까지 될 수 있다.
* 이때 cnt의 시작을 1로 했는데 0이 된다면, 가장 처음 들어간 cnt보다 작아지기 때문에 안되는 것이다.
* 이를 해결하기위해 해당 수의 second를 가져오거나 아니면 cnt를 0으로 시작해야 한다.
* 하지만 LIS백터에서는 해당수의 값만 알고 값에따른 위치, second를 가져올 수 없다.
* 해시맵이라면 모르겠지만 불가능하다고 할 수 있다.
* 따라서 cnt 를 0으로 해야한다.
* 2.시간복잡도
* 최악의 경우 이분탐색을 N번반복하므로O(NlogN) N<=1000000 따라서 가능
* 3.변수형
*
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0;
	cin >> N;

	vector<int> answer;
	vector<int> LIS;
	vector<pair<int, int>> check;

	vector<int> input(N);
	for (auto& i : input) {
		cin >> i;
		check.push_back({ i, 0 });
	}

	LIS.push_back(input[0]);
	check[0].second = cnt;

	for (int i = 1; i < N; i++) {
		if (LIS.back() < input[i]) {
			LIS.push_back(input[i]);
			cnt++;
			check[i].second = cnt;
		}
		else {
			int left = 0;
			int right = LIS.size() - 1;
			int index = 0;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (LIS[mid] < input[i]) {
					left = mid + 1;
				}
				else {
					index = mid;
					right = mid - 1;
				}
			}
			LIS[index] = input[i];
			check[i].second = index;
		}
	}
	cout << cnt + 1 << "\n";

	for (int i = N - 1; i >= 0; i--) {
		if (cnt == check[i].second) {
			answer.push_back(check[i].first);
			cnt--;
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i] << " ";

	return 0;
}