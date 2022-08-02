#include <iostream>
#include <vector>
#include<deque>
#include<algorithm>

using namespace std;

//typedef pair<int, Node*> Node;//재귀적 자료형이 정의됨
class Node {
public:
	int first;
	Node* second;

	Node(int first,Node* second):first(first),second(second){}
};
typedef vector<Node*> pair_stack;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	deque<int> arr;
	vector<int> p_arr;
	vector<pair_stack*> stack_vector;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	while (!arr.empty()) {
		int element = arr.front();
		arr.pop_front();

		if (stack_vector.size() == 0) {
			stack_vector.push_back(new pair_stack);
			stack_vector.back()->push_back(new Node(element,(Node*)NULL));
		}
		else if (stack_vector.size() == 1) {
			if (stack_vector.back()->back()->first < element) {
				Node* pre_stack_top_pointer = stack_vector.back()->back();
				stack_vector.push_back(new pair_stack);
				stack_vector.back()->push_back(new Node(element, pre_stack_top_pointer));
			}
			else
				stack_vector.back()->push_back(new Node(element, (Node*)NULL));
		}
		else if (stack_vector.size() > 1) {

			//이진 탐색

			int start = 0;
			int end = stack_vector.size() - 1;

			if (element <= stack_vector[start]->back()->first)
				stack_vector[start]->push_back(new Node(element, (Node*)NULL));
			else if (element > stack_vector[end]->back()->first) {
				Node* pre_stack_top_pointer = stack_vector[end]->back();
				stack_vector.push_back(new pair_stack);
				stack_vector[end+1]->push_back(new Node(element, pre_stack_top_pointer));
			}
			else {

				int mid;

				do {
					mid = (start + end) / 2;
					if (stack_vector[mid]->back()->first < element)
						start = mid;
					else
						end = mid;
				} while (end - mid != 1);

				Node* pre_stack_top_pointer = stack_vector[end-1]->back();
				stack_vector[end]->push_back(new Node(element, pre_stack_top_pointer));
			}
		}
	}

	/*
	* 스택 확인 코드
	cout << stack_vector.size()<<'\n';
	for (int i = stack_vector.size()-1; i > -1; i--) {
		while (!stack_vector[i]->empty()) {
			if(stack_vector[i]->back()->second!=(Node*)NULL)
				cout << '(' << stack_vector[i]->back()->first << ',' << stack_vector[i]->back()->second->first << ')';
			else
				cout << '(' << stack_vector[i]->back()->first << ',' << "0" << ')';
			stack_vector[i]->pop();
		}
		cout << '\n';
	}
	*/

	
	for (Node* node = stack_vector.back()->back(); node != (Node*)NULL; node = node->second)
		p_arr.push_back(node->first);

	cout << p_arr.size() << "\n";
	for (int i = p_arr.size()-1; i > -1; i--)
		cout << p_arr[i] << ' ';
	

	return 0;
}