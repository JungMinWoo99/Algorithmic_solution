#include <iostream>
#include<algorithm>
#include<string>
#include <list>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;

	cin >> a;
	cin >> b;
	int size1 = a.size();
	int size2 = b.size();
	int** grid = new int* [size2];//LSC ���� ���� �迭
	for (int i = 0; i < size2; i++)
		grid[i] = new int[size1] {0, };
	bool** grid2 = new bool* [size2];//�� ���ڿ����� ���� ������ ��ġ�� �����ϴ� �迭
	for (int i = 0; i < size2; i++)
		grid2[i] = new bool[size1] {false, };
	for (int i = 0, input = 0; i < size2; i++) {//������ 1�� ���,input�� ���ڿ� ���� ��
		if (a[0] == b[i]) {
			input = 1;//���� ���ڳ����� �����ķ� 1����
			grid2[i][0] = true;
		}
		grid[i][0] = input;
	}
	for (int i = 0, input = 0; i < size1; i++) {//������ 1�� ���,input�� ���ڿ� ���� ��
		if (a[i] == b[0]) {
			input = 1;//���� ���ڳ����� �����ķ� 1����
			grid2[0][i] = true;
		}
		grid[0][i] = input;
	}
	for (int i = 1; i < size1; i++) {//������ i�� ���
		int input = grid[0][i];//���ڸ� �ٿ��� ���ϱ��� ������ LCS���� �ʱ� ���԰����� ����
		for (int n = 1; n < size2; n++) {
			if (a[i] == b[n]) {//���κ��� ���� �ΰ��� ��ġ�Ұ��
				input = grid[n - 1][i - 1] + 1;//���� ���ڿ� �ΰ��� LCS�� + 1�� ���԰����� ����
				grid[n][i] = input;
				grid2[n][i] = true;
			}
			else {
				input = grid[n - 1][i] > grid[n][i - 1] ? grid[n - 1][i] : grid[n][i - 1];//a[i]�� ���ΰ���� LCS���� a[i]�� �Ⱥ��� LCS���� ���ؼ� �� ū���� ����
				grid[n][i] = input;
			}
		}
	}
	cout << grid[size2 - 1][size1 - 1] << endl;

	int count = grid[size2 - 1][size1 - 1];

	if (count == 0)
		return 0;

	for (int n = 0; n < size2; n++) {
		for (int m = 0; m < size1; m++) {
			cout << grid[n][m]<<' ';
		}
		cout << '\n';
	}
	int n = size2 - 1;
	int m = size1 - 1;
	string output;
	
	do{
		if (m != 0) {
			while (grid[n][m - 1] == count) {
				m--;
				if (m == 0)
					break;
			}
		}

		if (n != 0) {
			while (grid[n - 1][m] == count) {
				n--;
				if (n == 0)
					break;
			}
		}

		output.push_back(b[n]);
		n--;
		m--;
		count--;

	} while (count > 0);
	
	reverse(output.begin(), output.end());
	cout << output<<'\n';

	return 0;
}