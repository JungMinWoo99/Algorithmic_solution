#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
* 1,��� ��� �Ǵ� ��� ���� �� ���
*	���� ���� �� ���� ����
* 
* 2,����� ������ ��� �����ϴ� ���
* 
* 
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> n_value;//���� �� ���� ����
	vector<int> p_value;//��� �� ���� ����
	
	int i;
	cin >> i;

	for (double n = 0; n < i; n++) {
		int x;
		cin >> x;
		if (x >= 0)
			p_value.push_back(x);
		else
			n_value.push_back(x);
	}

	//������ ������������
	int answer1;
	int answer2;
	int min_sum;

	//�ʱ� �� ����
	if (p_value.size() > 0 && n_value.size() > 0) {// ����� ������ ��� �ִ� ���
		if (p_value.size() > 1 && n_value.size() > 1) {//����� ���� ��� 2�� �̻� �ִ� ���
			//���� ���� �� ����� ���� ũ��� ���� ū �� ������ ���� ũ�⸦ ���Ͽ� �ʱ� �񱳰� ����
			if (p_value[0] + p_value[1] < -n_value[n_value.size() - 1] - n_value[n_value.size() - 2]) {
				answer1 = p_value[0];
				answer2 = p_value[1];
				min_sum = p_value[0] + p_value[1];
			}
			else {
				answer1 = n_value[n_value.size() - 2];
				answer2 = n_value[n_value.size() - 1];
				min_sum = -n_value[n_value.size() - 1] - n_value[n_value.size() - 2];
			}
		}
		else if(n_value.size() == 1&& p_value.size() == 1) {//���Ұ� ��� ���� ���� 1���� ���
			answer1 = n_value[0];
			answer2 = p_value[0];
			min_sum = p_value[0] - n_value[0];
		}
		else if (n_value.size() == 1) {//������ 1���� �ִ� ���
			answer1 = p_value[0];
			answer2 = p_value[1];
			min_sum = p_value[0] + p_value[1];
		}
		else if(p_value.size() == 1) {//����� 1���� �ִ� ���
			answer1 = n_value[n_value.size() - 2];
			answer2 = n_value[n_value.size() - 1];
			min_sum = -n_value[n_value.size() - 1] - n_value[n_value.size() - 2];
		}
	}
	else if (n_value.size()==0) {//����� �����ϴ� ���
		answer1 = p_value[0];
		answer2 = p_value[1];
		min_sum = p_value[0] + p_value[1];
	}
	else if (p_value.size() == 0) {//������ �����ϴ� ���
		answer1 = n_value[n_value.size() - 2];
		answer2 = n_value[n_value.size() - 1];
		min_sum = -n_value[n_value.size() - 1] - n_value[n_value.size() - 2];
	}

	//��ȣ�� �ٸ� �� ���� ���� Ư������ ����Ͽ� �ּҰ� ���ϱ�
	//n��° ���� n-1��° ���� �߾Ӱ��� �������� ���ϴ� ���� ���밪�� �߾Ӱ��� �Ѿ�� n-1��°���� �Ѿ�� �ϱ�
	if (p_value.size() > 0 && n_value.size() > 0) {//�ּ��� �� ���Ϳ� 1�� �̻��� ���Ұ� �־�ߵ�
		int n = 0;
		int p = p_value.size() - 1;
		while (1) {

			int mid;
			if (p != 0&&p_value.size()!=1)//-1�� �����ϸ� �ȵ�
				mid = (p_value[p] + p_value[p - 1]) / 2;
			else
				mid = 0;//�Ʒ� �ݺ����� ������ ������ �����ؾ� �������� ��

			while (mid < -n_value[n]) {
				if (abs(p_value[p] + n_value[n]) < min_sum) {
					answer1 = n_value[n];
					answer2 = p_value[p];
					min_sum = abs(p_value[p] + n_value[n]);
				}
				if (n != n_value.size() - 1)//n�� ���� ������ �� ���� �ƴ϶�� ���� ���ҿ� ����
					n++;
				else
					break;
			}
			if (p != 0)//p�� ���� ������ �� ���� �ƴ϶�� ���� ���ҿ� ����
				p--;
			else
				break;
		}
	}
		

	cout << answer1 << ' ' << answer2;
	return 0;
}