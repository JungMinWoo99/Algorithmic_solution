#include <iostream>
#include <list>

using namespace std;

/*
* ��� �˰���
* ũ�罺Į �˰���
* ����Ŭ ����-���μ�����(Disjoint Set)���� ������ ã��(union-find)
*/

bool compare(const pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
	if (a.second < b.second)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	list<pair<pair<int, int>, int>> edge;//�� ���, ������ ����ġ�� �����ϴ� ����
	int* c_check_table;//����Ŭ üũ ���̺�(��Ʈ �����ġ�� ����)
	int n_num,e_num;
	cin >> n_num >>e_num;

	c_check_table = new int[n_num+1];//��� ���� ��ŭ �Ҵ�
	for (int i = 0; i < n_num+1; i++) {//���̺� �⺻�� ����
		c_check_table[i] = i;//���� �����ϴ� Ʈ���� �ʱ� ����
	}

	for (int i = 0; i < e_num; i++) {//���� ���� ä���
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_pair(make_pair(a, b), c));
	}
	edge.sort(compare);

	
	for (int e_count = 0; e_count != n_num - 1; ) {
		int n1 = edge.front().first.first;
		int n2 = edge.front().first.second;
		int e_val = edge.front().second;
		int root1 = n1;
		int root2 = n2;
		do {
			root1 = c_check_table[root1];
		} while (c_check_table[root1] != root1);//���� ������ �Ǵ� ��Ʈ ��忡 ���� �Ҷ����� �ݺ�
		c_check_table[n1] = root1;//��Ʈ ��� ����
		do {
			root2 = c_check_table[root2];
		} while (c_check_table[root2] != root2);//���� ������ �Ǵ� ��Ʈ ��忡 ���� �Ҷ����� �ݺ�
		c_check_table[n2] = root2;//��Ʈ ��� ����
		if (root1 != root2) {//����Ŭ�� �������� �ʴ°��
			answer += e_val;
			c_check_table[root1] = root2;//������ �� Ʈ���� ����
			e_count++;
		}
		edge.pop_front();
	}

	cout << answer;

	return 0;
}