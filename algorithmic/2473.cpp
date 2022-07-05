#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/*
* ��� �˰���
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<double> val_arr;//�� ����� Ư����

	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		val_arr.push_back(input);
	}

	sort(val_arr.begin(), val_arr.end());

	double answer=3000000001;
	int answer_arr[3];
	for (int k = 0; k < N - 2; k++) {
		int l = k + 1;
		int r = N - 1;

		//�� ��� �ַ��
		while (l < r) {
			//���� k,l,r ����� Ư������ ���� �ּ� Ư�������� �����Ǿ��� ���
			double val_sum = val_arr[k] + val_arr[l] + val_arr[r];
			if (answer > fabs(val_sum)) {
				answer = fabs(val_sum);
				answer_arr[0] = val_arr[k];
				answer_arr[1] = val_arr[l];
				answer_arr[2] = val_arr[r];
			}
			if (val_arr[k] + val_arr[l] + val_arr[r] > 0)
				r--;
			else
				l++;
		}
	}

	//���� ���
	for (int i = 0; i < 3; i++)
		cout << answer_arr[i] << '\n';

	return 0;
}