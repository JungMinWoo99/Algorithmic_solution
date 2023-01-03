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
	int val=-1;//해당 노드의 값
	int cul_num = 0;//연산횟수
	Node* pre_node = nullptr;//연산직전에 있던 노드
};

Node arr[1000001];

void link_all_node(int start) {//동적 프로그래밍을 통해 문제를 해결하는 함수
	list<Node*> n_buffer;//다음에 처리할 노드를 저장한 대기열 버퍼
	n_buffer.push_back(&arr[start]);

	for (Node* node = n_buffer.front(); node != &arr[1]; node = n_buffer.front()) {
		n_buffer.pop_front();//가장 앞의 원소 빼기
		int val = node->get_val();

		if (val % 3 == 0) {//3의 배수인 경우
			if (arr[val / 3].get_pre_node() == nullptr) {//아직 연결된 노드가 없는 경우만 연결가능(이미 연결되있다면 최소 루트가 아닌것임)
				arr[val / 3].set_pre_node(node);//노드 연결
				arr[val / 3].set_cul_num(node->get_cul_num() + 1);//최소값 대입
				n_buffer.push_back(&arr[val / 3]);//탐색할 노드 버퍼에 저장
			}
		}

		if (val % 2 == 0) {//3의 배수인 경우
			if (arr[val / 2].get_pre_node() == nullptr) {//아직 연결된 노드가 없는 경우만 연결가능(이미 연결되있다면 최소 루트가 아닌것임)
				arr[val / 2].set_pre_node(node);//노드 연결
				arr[val / 2].set_cul_num(node->get_cul_num() + 1);//최소값 대입
				n_buffer.push_back(&arr[val / 2]);//탐색할 노드 버퍼에 저장
			}
		}

		if (1) {// -1을한 경우
			if (arr[val - 1].get_pre_node() == nullptr) {//아직 연결된 노드가 없는 경우만 연결가능(이미 연결되있다면 최소 루트가 아닌것임)
				arr[val - 1].set_pre_node(node);//노드 연결
				arr[val - 1].set_cul_num(node->get_cul_num() + 1);//최소값 대입
				n_buffer.push_back(&arr[val - 1]);//탐색할 노드 버퍼에 저장
			}
		}
	}
}

void print_answer(int i) {//그냥 형식에 맞게 답을 출력하는 함수
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