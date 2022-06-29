#include <iostream>
#include <deque>

using namespace std;

/*
* ��� �˰���
* ���� ����
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t_num = 0; t_num < T; t_num++) {
		int N;
		cin >> N;
		int* con_time = new int[N + 1];//�Ǽ� �ð� ����
		int* dp_time = new int[N + 1];//���� �Ǽ� �ð� ����
		deque<int> sort_arr;//���� ���� ����
		int* in_deg = new int[N + 1]{ 0, };//�������� ����
		bool* in_check= new bool[N + 1]{ false, };//�������ļ���� �̹� �� ��� Ȯ�ο�
		deque<int>* next_n_deque = new deque<int>[N + 1];//�� ����� ���� ���
		deque<int>* pre_n_deque = new deque<int>[N + 1];//�� ����� ���� ���
		int K;
		cin >> K;
		for (int i = 1; i <= N; i++)//�Ǽ� �ð� �Է¹ޱ�
			cin >> con_time[i];
		for (int i = 0; i < K; i++) {
			int i1, i2;
			cin >> i1 >> i2;
			in_deg[i2]++;
			next_n_deque[i1].push_back(i2);//���� ��� ����Ʈ �ۼ�
			pre_n_deque[i2].push_back(i1);//���� ��� ����Ʈ �ۼ�
		}
		

		//���� ����
		deque<int> queue;//��⿭
		for (int i = 0; i< N; i++) {//���� ���� ť�� ��� ��尡 �� �� ����
			int node = i + 1;
			if (in_deg[node] == 0 && in_check[node] == false)//���������� 0�̰� ���� ���ĵ��� ���� ����� ���
				queue.push_back(node);
		}
		
		while (!queue.empty()) {
			int node = queue.front();//������ ���
			queue.pop_front();
		
			for (deque<int>::iterator iter = next_n_deque[node].begin(); iter != next_n_deque[node].end(); iter++) {//������ ���� ������ ��� Ž��
				int next_node = *iter;
				if (--in_deg[next_node] == 0)//���� ����� ���������� 1���ҽ�Ű�� ���� 0�̵ȴٸ� ��⿭�� �߰�
					queue.push_back(next_node);
			}
			
			sort_arr.push_back(node);//node�� ����
			in_check[node] = true;//node�� ���ĵ��� ǥ��
		}
		
		/*
		//���� Ȯ�� �ڵ�
		cout << '\n';
		for (deque<int>::iterator iter = sort_arr.begin(); iter != sort_arr.end(); iter++)
			cout << *iter << ' ';
		cout << '\n';
		*/

		//dp����
		for (deque<int>::iterator iter = sort_arr.begin(); iter != sort_arr.end(); iter++) {
			int node = *iter;
			int time = con_time[node];
			int max_time = time;//�ش� �ǹ� �Ǽ����� �ɸ��� �ð��� �ִ�
			
			for (deque<int>::iterator iter = pre_n_deque[node].begin(); iter != pre_n_deque[node].end(); iter++) {
				if (max_time < time + dp_time[*iter])//�����ð����� �� ���� �ð��� �ɸ���
					max_time = time + dp_time[*iter];//�ִ� ����
			}
			dp_time[node] = max_time;
		}
		
		int W;
		cin >> W;
		cout << dp_time[W]<<'\n';

		delete[] con_time;
		delete[] dp_time;
		delete[] in_deg;
		delete[] in_check;
		delete[] next_n_deque;
		delete[] pre_n_deque;
	}
	return 0;
}