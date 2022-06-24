#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
* 1,모두 양수 또는 모두 음수 일 경우
*	가장 작은 두 값이 정답
* 
* 2,양수와 음수와 모두 존재하는 경우
* 
* 
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> n_value;//음수 값 저장 벡터
	vector<int> p_value;//양수 값 저장 벡터
	
	int i;
	cin >> i;

	for (double n = 0; n < i; n++) {
		int x;
		cin >> x;
		if (x >= 0)
			p_value.push_back(x);
		else
			n_value.push_back(x);
	}

	//정답은 오름차순으로
	int answer1;
	int answer2;
	int min_sum;

	//초기 값 세팅
	if (p_value.size() > 0 && n_value.size() > 0) {// 양수와 음수가 모두 있는 경우
		if (p_value.size() > 1 && n_value.size() > 1) {//양수와 음수 모두 2개 이상 있는 경우
			//가장 작은 두 양수의 합의 크기와 가장 큰 두 음수의 합의 크기를 비교하여 초기 비교값 설정
			if (p_value[0] + p_value[1] < -n_value[n_value.size() - 1] - n_value[n_value.size() - 2]) {
				answer1 = p_value[0];
				answer2 = p_value[1];
				min_sum = p_value[0] + p_value[1];
			}
			else {
				answer1 = n_value[n_value.size() - 2];
				answer2 = n_value[n_value.size() - 1];
				min_sum = -n_value[n_value.size() - 1] - n_value[n_value.size() - 2];
			}
		}
		else if(n_value.size() == 1&& p_value.size() == 1) {//원소가 양수 음수 각각 1개인 경우
			answer1 = n_value[0];
			answer2 = p_value[0];
			min_sum = p_value[0] - n_value[0];
		}
		else if (n_value.size() == 1) {//음수가 1개만 있는 경우
			answer1 = p_value[0];
			answer2 = p_value[1];
			min_sum = p_value[0] + p_value[1];
		}
		else if(p_value.size() == 1) {//양수가 1개만 있는 경우
			answer1 = n_value[n_value.size() - 2];
			answer2 = n_value[n_value.size() - 1];
			min_sum = -n_value[n_value.size() - 1] - n_value[n_value.size() - 2];
		}
	}
	else if (n_value.size()==0) {//양수만 존재하는 경우
		answer1 = p_value[0];
		answer2 = p_value[1];
		min_sum = p_value[0] + p_value[1];
	}
	else if (p_value.size() == 0) {//음수만 존재하는 경우
		answer1 = n_value[n_value.size() - 2];
		answer2 = n_value[n_value.size() - 1];
		min_sum = -n_value[n_value.size() - 1] - n_value[n_value.size() - 2];
	}

	//부호가 다른 두 값에 대해 특성값을 계산하여 최소값 구하기
	//n번째 수와 n-1번째 수의 중앙값을 기준으로 더하는 값의 절대값이 중앙값을 넘어가면 n-1번째수로 넘어가게 하기
	if (p_value.size() > 0 && n_value.size() > 0) {//최소한 각 벡터에 1개 이상의 원소가 있어야됨
		int n = 0;
		int p = p_value.size() - 1;
		while (1) {

			int mid;
			if (p != 0&&p_value.size()!=1)//-1에 접근하면 안됨
				mid = (p_value[p] + p_value[p - 1]) / 2;
			else
				mid = 0;//아래 반복문이 음수를 끝까지 접근해야 끝나도록 함

			while (mid < -n_value[n]) {
				if (abs(p_value[p] + n_value[n]) < min_sum) {
					answer1 = n_value[n];
					answer2 = p_value[p];
					min_sum = abs(p_value[p] + n_value[n]);
				}
				if (n != n_value.size() - 1)//n이 벡터 끝까지 간 것이 아니라면 다음 원소에 접근
					n++;
				else
					break;
			}
			if (p != 0)//p가 벡터 끝까지 간 것이 아니라면 다음 원소에 접근
				p--;
			else
				break;
		}
	}
		

	cout << answer1 << ' ' << answer2;
	return 0;
}