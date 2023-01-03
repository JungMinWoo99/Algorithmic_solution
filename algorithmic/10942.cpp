#include <iostream>

using namespace std;

/*
* 사용 알고리즘
* 다이나믹 프로그래밍
*/

int arr[2001];//수열
bool table[2001][2001] = { false, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	cin >> N;

	for (int i = 1; i <= N; i++) {//수열 입력 받기
		cin >> arr[i];
	}
	//테이블 채우기
	table[1][1] = true;
	for (int i = 2; i <= N; i++) {
		table[i][i] = true;
		if (arr[i] == arr[i - 1])
			table[i][i - 1] = true;
	}
	for (int i = 2; i <= N-1; i++) {
		for (int n = 1; n+i <= N; n++) {
			if (arr[i+n] == arr[n])
				table[n+i][n] = table[n+i-1][n+1];//s+1,e-1의 팰린드롬 여부
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << table[E][S] <<'\n';
	}

	return 0;
}