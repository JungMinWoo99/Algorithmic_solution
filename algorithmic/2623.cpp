#include <iostream>
#include <deque>

using namespace std;

/*
* ��� �˰���
* ���� ���� ����
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	deque<int>* order_deque = new deque<int>[N + 1];//�� ������ �ٷ� ���� �켱������ ���� ����Ʈ
	int* in_deg = new int[N + 1]{ 0, };//in_degree ����
	bool* is_sort = new bool[N + 1]{ false, };//���� ���θ� ����
	deque<int> search_queue;//Ž�� ��⿭
	deque<int> answer;

	//�� �������� �ʱⰪ ����
	for (int m = 0; m < M; m++) {
		int singer;//�Է¹޴� ������ ��
		cin >> singer;
		int* order = new int[singer];//������ �Է¹��� �迭
		for (int i = 0; i < singer; i++)
			cin >> order[i];
		for (int i = 1; i < singer; i++)//in_degree ī����
			in_deg[order[i]]++;
		for (int i = 0; i < singer - 1; i++)//order_deque �ۼ�
			order_deque[order[i]].push_back(order[i + 1]);
		delete[] order;
	}

	//���� ã��
	for (int i = 1; i <= N; i++)
		if (in_deg[i] == 0)
			search_queue.push_back(i);//���������� 0�� ��� ���� Ž�� �� ����
	while (!search_queue.empty()) {//��� �������� ���ĵ� ������
		int node = search_queue.front();
		search_queue.pop_front();
		answer.push_back(node);//node ���� ����
		is_sort[node] = true;//���ĵ��� üũ
		//���ĵ� ������ ���� �ٷ� ���� �켱���� �������� in_degree����
		for (int n = 0; n < order_deque[node].size(); n++) {
			if (is_sort[order_deque[node][n]] == true) {//�̹� ���ĵ� ������ �ļ����ΰ��->���� ���ϱ� �Ұ���
				cout << '0' << '\n';
				return 0;
			}
			in_deg[order_deque[node][n]]--;
			if (in_deg[order_deque[node][n]] == 0)//�� �̻� ���� ��尡 ���� ���
				search_queue.push_back(order_deque[node][n]);//Ž�� ��⿭�� �߰�
		}
	}

	//���� ���
	if (answer.size() != N) {//���������� ���ĵǾ��ٸ� ��� ��尡 ���ĵ��־����
		cout << '0' << '\n';
		return 0;
	}
	for (int n = 0; n < answer.size(); n++)
		cout << answer[n] << '\n';
	return 0;
}