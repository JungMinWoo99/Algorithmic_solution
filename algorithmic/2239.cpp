#include <iostream>
#include <vector>

using namespace std;

/*
* ��� �˰���
*/

int arr[9][9];

vector<pair<int, int>> track;//������ �迭��ġ�� ������� �����ϴ� ����Ʈ(���� �߰��� �� ���� ��� �������� �ö󰡸� �ٽ� ���� �ٲ�)

bool col_check(int col) {
	bool table[10] = {false};//�ѹ� Ȯ�ε� ���� ������ ����
	for (int i = 0; i < 9; i++) {
		if (table[arr[col][i]])//�̹� Ȯ�ε� ���� �� Ȯ�εȰ��
			return false;
		else//ó�� Ȯ�ε� ���� ���
			table[arr[col][i]] = true;
		table[0] = false;//0�� ���� ������ ���� �ƴ϶�� ���̱� ������ �ߺ����� Ȯ�εǵ� ��
	}
	return true;//�ߺ��� ���� �ϳ��� ���� ���
}

bool row_check(int row) {
	bool table[10] = { false };//�ѹ� Ȯ�ε� ���� ������ ����
	for (int i = 0; i < 9; i++) {
		if (table[arr[i][row]])//�̹� Ȯ�ε� ���� �� Ȯ�εȰ��
			return false;
		else//ó�� Ȯ�ε� ���� ���
			table[arr[i][row]] = true;
		table[0] = false;//0�� ���� ������ ���� �ƴ϶�� ���̱� ������ �ߺ����� Ȯ�εǵ� ��
	}
	return true;//�ߺ��� ���� �ϳ��� ���� ���
}

bool cell_check(int col, int row) {//col�� row���� ���� ���� �ߺ��� �˻�
	bool table[10] = { false };//�ѹ� Ȯ�ε� ���� ������ ����
	for (int n = col*3; n < (col+1)*3; n++) {
		for (int m = row*3; m < (row + 1) * 3; m++) {
			if (table[arr[n][m]])//�̹� Ȯ�ε� ���� �� Ȯ�εȰ��
				return false;
			else//ó�� Ȯ�ε� ���� ���
				table[arr[n][m]] = true;
			table[0] = false;//0�� ���� ������ ���� �ƴ϶�� ���̱� ������ �ߺ����� Ȯ�εǵ� ��
		}
	}
	return true;//�ߺ��� ���� �ϳ��� ���� ���
}

bool all_check(int col, int row) {
	if (!col_check(col))
		return false;
	if (!row_check(row))
		return false;
	if (!cell_check(col / 3, row / 3))
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int n = 0; n < 9; n++) {
		for (int m = 0; m < 9; m++) {
			int input;
			scanf_s("%1d", &input);
			arr[n][m] = input;
			if (input == 0)
				track.push_back(make_pair(n, m));//���� ä������ ĭ�� ��ġ�� ����
		}
	}

	int iter = 0;//track�� ����� �ݺ���ó�� �� ����
	while (iter!=track.size()) {//��ĭ�� ��� ä��� ��
		++arr[track[iter].first][track[iter].second]%=10;
		if (!(arr[track[iter].first][track[iter].second] == 0)) {//0�� ���Ե��� ���� ���
			if (all_check(track[iter].first, track[iter].second))//���Ե� ���� �ߺ��� �ƴҰ��
				iter++;
			else
				continue;//�ߺ��� ��� ������ ����
		}
		else //0�� ���Ե� ���(1~9���� ���� ������ ���� ���ٴ� ��)
			iter--;
	}

	cout << endl;
	for (int n = 0; n < 9; n++) {
		for (int m = 0; m < 9; m++) {
			cout<<arr[n][m];
		}
		cout << endl;
	}
	
	return 0;
}