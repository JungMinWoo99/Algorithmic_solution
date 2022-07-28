#include <iostream>

using namespace std;

int N;
int W[17][17]={0,};
int DP[17][(1<<16)]={0,};

//현재위치, 상태에서 남은 도시를 방문하고 돌아가는 상황까지 필요한 비용 계산
int dfs(int cur_pos, int cur_stat) {

	if (DP[cur_pos][cur_stat] != 0)
		return DP[cur_pos][cur_stat];

	if (cur_stat + 1 == (1<<N)) {//모든 노드를 방문한 경우
		if (W[cur_pos][1] == 0) {
			DP[cur_pos][cur_stat] = -1;
			return -1;
		}
		else {
			DP[cur_pos][cur_stat] = W[cur_pos][1];
			return W[cur_pos][1];
		}
	}
	else {//아직 모든 노드를 방문하지 않은 경우

		bool check_block = true;//더이상 진행불가능한 상황임을 확인

		for (int i = 1; i <= N; i++) {

			int n = 1 << (i - 1);
			if (cur_stat & n)//이미 i 노드를 방문한 경우
				continue;
			else if (W[cur_pos][i] == 0)//i 노드로 가는 길이 없는경우
				continue;

			int temp = dfs(i, cur_stat | n);
			if (temp == -1)//i노드로 간 뒤 더이상 진행이안되는 경우
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