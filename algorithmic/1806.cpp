#include <iostream>

using namespace std;

/*
* ��� �˰���
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

	//���� N �̻��� ���� �Ǹ� �ȵǴ� ����
	int start = 0;//�κ����� ����(������ �Ǵ�)
	int end = 0;// �κ����� ��(������ �ȵǴ�)

	//�κ����� ���� ������ ����
	int sum=0;

	//0���� �����ϴ� �κ����� ã�� �κ�
	for (end = 0; sum < S; end++) {
		if (end == N) {//�־��� ���� ��� ���� ���
			if (sum < S)//�� ���ص� S�� �� �Ѵ� ���
				answer = 0;
			else//�� ���ؼ� S�� �Ѵ� ���
				answer = N;
			cout << answer;
			return 0;//���α׷� ����
		}
		sum += arr[end];
	}
	answer = end - start;

	//�κ��� ã�� �κ�
	while (end != N + 1) {//start�� �ִ밪�� �Ǽ� end�� �����ؾߵɶ� ���̻� ������ �� ���ٸ� Ž���� ���� ��Ȳ��
		if (sum - arr[start] >= S) {//�κ����� ��ĭ �ٿ��� S���� ū ���
			sum -= arr[start];
			start++;
			answer--;//�κ����� ���̴� ���� �þ�� �ȵ�
		}
		else {//�κ����� ��ĭ���̸� S���� �۾����� ���
			sum -= arr[start];
			start++;
			end++;
			sum += arr[end - 1];
		}
	}

	cout << answer;
	return 0;
}