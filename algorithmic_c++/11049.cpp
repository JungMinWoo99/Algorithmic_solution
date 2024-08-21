#include <iostream>

using namespace std;

int arr[501];
int dp[501][501] = { 0, };

int main() {

	ios::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i] >> arr[i + 1];

	for (int n = 2; n <= N; n++) {
		for (int m = n; m <= N; m++) {
			for (int i = m - n + 1; i < m; i++) {

				int comp = dp[m - n][i] + dp[i][m] + arr[m - n] * arr[i] * arr[m];
				if (dp[m - n][m] == 0)
					dp[m - n][m] = comp;

				dp[m - n][m] = dp[m - n][m] < comp ? dp[m - n][m] : comp;
			}
		}
	}
	cout << dp[0][N] << '\n';
	return 0;
}