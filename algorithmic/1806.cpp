#include <iostream>

using namespace std;

/*
* 사용 알고리즘
*/



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[100000];
	int answer = 0;
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr[i] = input;
	}

	//절대 N 이상의 값이 되면 안되는 변수
	int start = 0;//부분합의 시작(포함이 되는)
	int end = 0;// 부분합의 끝(포함이 안되는)

	//부분합의 값을 저장할 변수
	int sum=0;

	//0부터 시작하는 부분합을 찾는 부분
	for (end = 0; sum < S; end++) {
		if (end == N) {//주어진 수를 모두 더한 경우
			if (sum < S)//다 더해도 S를 못 넘는 경우
				answer = 0;
			else//다 더해서 S를 넘는 경우
				answer = N;
			cout << answer;
			return 0;//프로그램 종료
		}
		sum += arr[end];
	}
	answer = end - start;

	//부분합 찾는 부분
	while (end != N + 1) {//start가 최대값이 되서 end이 증가해야될때 더이상 증가할 수 없다면 탐색이 끝난 상황임
		if (sum - arr[start] >= S) {//부분합을 한칸 줄여도 S보다 큰 경우
			sum -= arr[start];
			start++;
			answer--;//부분합의 길이는 절대 늘어나면 안됨
		}
		else {//부분합을 한칸줄이면 S보다 작아지는 경우
			sum -= arr[start];
			start++;
			end++;
			sum += arr[end - 1];
		}
	}

	cout << answer;
	return 0;
}