#include <iostream>
#include <list>

using namespace std;

/*
* ��� �˰���
* ���� ����
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	int* in_degree = new int[N + 1]{0,};//�������� ����
	list<int>* adj_list = new list<int>[N + 1];//���� ��� ����Ʈ
	list<int> sort_arr;//���� ���� ����Ʈ

	for (int i = 0; i < M; i++) {
		int i1, i2;
		cin >> i1 >> i2;
		adj_list[i1].push_back(i2);
		in_degree[i2]++;
	}

	//���� ����
	list<int> queue;//���� ��⿭
	for (int i = 1; i <= N; i++)
		if (in_degree[i] == 0)
			queue.push_back(i);
	while (!queue.empty()) {
		int node = queue.front();//������ ���
		queue.pop_front();
		for (list<int>::iterator iter = adj_list[node].begin(); iter != adj_list[node].end(); iter++) {
			int adj_node = *iter;//������ ���� ������ ���
			if (--in_degree[adj_node] == 0)
				queue.push_back(adj_node);//�� �̻� ���Գ�尡 ���� ��带 ���� ��⿭�� �߰�
		}
		sort_arr.push_back(node);
	}

	//���� ���
	for (list<int>::iterator iter = sort_arr.begin(); iter != sort_arr.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}

