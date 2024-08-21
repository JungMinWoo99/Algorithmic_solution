#include <iostream>

using namespace std;

/*
* 사용 알고리즘
*/

//전역 배열(값이 크기 때문에 double사용)
int app_c[101] = { 0, };
double app_m[101] = {0,};
double dp_arr[101][10001]={0,};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	//앱의 정보 입력
	for (int i = 1; i <= N; i++)
		cin >> app_m[i];
	
	for (int i = 1; i <= N; i++)
		cin >> app_c[i];
	
	//DP 과정
	for (int c = 1; c <= 10000; c++) {
		for (int i = 1; i <= N; i++) {
			if (app_c[i] <= c) {//앱의 비활성 비용이 c보다 큰 경우에는 해당 앱을 비활성화 할 수 없음
				dp_arr[i][c] = (dp_arr[i - 1][c] < dp_arr[i - 1][c - app_c[i]] + app_m[i] ? dp_arr[i - 1][c - app_c[i]] + app_m[i] : dp_arr[i - 1][c]);
				if (dp_arr[i][c] >= M) {
					cout << c;
					return 0;
				}
			}
			else
				dp_arr[i][c] = dp_arr[i - 1][c];
		}
	}

	return 0;
}