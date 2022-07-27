#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int N, S;
vector<int> p_arr1;
vector<int>	p_arr2;
map<int, int> p_arr1_sum;
long long answer = 0;

void fill_p_arr1_sum(int sum=0, int index=0) {
	if (index == p_arr1.size()) {
		p_arr1_sum[sum]++;
		return;
	}
	fill_p_arr1_sum(sum, index + 1);

	fill_p_arr1_sum(sum+p_arr1[index], index + 1);
}

void fill_answer(int sum = 0, int index = 0) {
	if (index == p_arr2.size()) {
		answer += p_arr1_sum[S-sum];
		return;
	}
	fill_answer(sum, index + 1);

	fill_answer(sum + p_arr2[index], index + 1);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N>>S;
	int half1 = N / 2;
	int half2 = N - half1;

	//ют╥б

	for (int i = 0; i < half1; i++) {
		int input;
		cin >> input;
		p_arr1.push_back(input);
	}

	for (int i = 0; i < half2; i++) {
		int input;
		cin >> input;
		p_arr2.push_back(input);
	}

	fill_p_arr1_sum();
	fill_answer();

	if(S==0)
		answer--;

	cout << answer << '\n';

	return 0;
}