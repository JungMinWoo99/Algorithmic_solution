#include <iostream>

using namespace std;

int N;
int W[17][17]={0,};
int DP[17][(1<<16)]={0,};

//������ġ, ���¿��� ���� ���ø� �湮�ϰ� ���ư��� ��Ȳ���� �ʿ��� ��� ���
int dfs(int cur_pos, int cur_stat) {

	if (DP[cur_pos][cur_stat] != 0)
		return DP[cur_pos][cur_stat];

	if (cur_stat + 1 == (1<<N)) {//��� ��带 �湮�� ���
		if (W[cur_pos][1] == 0) {
			DP[cur_pos][cur_stat] = -1;
			return -1;
		}
		else {
			DP[cur_pos][cur_stat] = W[cur_pos][1];
			return W[cur_pos][1];
		}
	}
	else {//���� ��� ��带 �湮���� ���� ���

		bool check_block = true;//���̻� ����Ұ����� ��Ȳ���� Ȯ��

		for (int i = 1; i <= N; i++) {

			int n = 1 << (i - 1);
			if (cur_stat & n)//�̹� i ��带 �湮�� ���
				continue;
			else if (W[cur_pos][i] == 0)//i ���� ���� ���� ���°��
				continue;

			int temp = dfs(i, cur_stat | n);
			if (temp == -1)//i���� �� �� ���̻� �����̾ȵǴ� ���
				continue;
			else {
				check_block = false;
				if (temp + W[cur_pos][i] < DP[cur_pos][cur_stat] || DP[cur_pos][cur_stat] == 0)
					DP[cur_pos][cur_stat] = temp + W[cur_pos][i];
			}
		}

		if(check_block)
			DP[cur_pos][cur_stat] = -1;
	}
	return DP[cur_pos][cur_stat];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> W[i][j];


	cout << dfs(1, 1) << '\n';

	return 0;
}