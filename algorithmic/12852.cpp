#include <iostream>
#include <list>

using namespace std;

class Node {
public:
	int get_cul_num() {
		return this->cul_num;
	}

	int get_val() {
		return this->val;
	}

	Node* get_pre_node() {
		return this->pre_node;
	}

	void set_cul_num(int i) {
		this->cul_num = i;
	}

	void set_pre_node(Node* i) {
		this->pre_node = i;
	}

	void set_val(int i) {
		this->val = i;
	}

private:
	int val=-1;//�ش� ����� ��
	int cul_num = 0;//����Ƚ��
	Node* pre_node = nullptr;//���������� �ִ� ���
};

Node arr[1000001];

void link_all_node(int start) {//���� ���α׷����� ���� ������ �ذ��ϴ� �Լ�
	list<Node*> n_buffer;//������ ó���� ��带 ������ ��⿭ ����
	n_buffer.push_back(&arr[start]);

	for (Node* node = n_buffer.front(); node != &arr[1]; node = n_buffer.front()) {
		n_buffer.pop_front();//���� ���� ���� ����
		int val = node->get_val();

		if (val % 3 == 0) {//3�� ����� ���
			if (arr[val / 3].get_pre_node() == nullptr) {//���� ����� ��尡 ���� ��츸 ���ᰡ��(�̹� ������ִٸ� �ּ� ��Ʈ�� �ƴѰ���)
				arr[val / 3].set_pre_node(node);//��� ����
				arr[val / 3].set_cul_num(node->get_cul_num() + 1);//�ּҰ� ����
				n_buffer.push_back(&arr[val / 3]);//Ž���� ��� ���ۿ� ����
			}
		}

		if (val % 2 == 0) {//3�� ����� ���
			if (arr[val / 2].get_pre_node() == nullptr) {//���� ����� ��尡 ���� ��츸 ���ᰡ��(�̹� ������ִٸ� �ּ� ��Ʈ�� �ƴѰ���)
				arr[val / 2].set_pre_node(node);//��� ����
				arr[val / 2].set_cul_num(node->get_cul_num() + 1);//�ּҰ� ����
				n_buffer.push_back(&arr[val / 2]);//Ž���� ��� ���ۿ� ����
			}
		}

		if (1) {// -1���� ���
			if (arr[val - 1].get_pre_node() == nullptr) {//���� ����� ��尡 ���� ��츸 ���ᰡ��(�̹� ������ִٸ� �ּ� ��Ʈ�� �ƴѰ���)
				arr[val - 1].set_pre_node(node);//��� ����
				arr[val - 1].set_cul_num(node->get_cul_num() + 1);//�ּҰ� ����
				n_buffer.push_back(&arr[val - 1]);//Ž���� ��� ���ۿ� ����
			}
		}
	}
}

void print_answer(int i) {//�׳� ���Ŀ� �°� ���� ����ϴ� �Լ�
	list<int> answer;
	answer.push_back(arr[1].get_cul_num());
	for (Node* node = &arr[1]; node->get_cul_num() != 0; node = node->get_pre_node())
		answer.push_front(node->get_val());
	cout << answer.back() << endl;
	answer.pop_back();
	cout << i << ' ';
	while (!answer.empty()) {
		cout << answer.front() << ' ';
		answer.pop_front();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	cin >> i;
	for (int n = 1; n <= i; n++) {
		arr[n].set_val(n);
	}
	link_all_node(i);
	print_answer(i);

	return 0;
}