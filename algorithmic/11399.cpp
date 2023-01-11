#include <iostream>
#include<cstring>
#include<vector>
#include<deque>
#include<utility>
#include <algorithm>
#include <cmath>

using namespace std;

class ArrayBasedMinHip {
private:
	int node_number;
    int* node_array;
public:
	ArrayBasedMinHip(int heap_size) {
        node_array=new int[heap_size];
        node_number=0;
    }

	void clear() {
		node_number = 0;
	}

	int getNodeNumber() {
		return node_number;
	}

	int getLeftChildIndex(int idx) {//범위를 벗어나면 -1
		if (idx * 2 > node_number)
			return -1;
		return idx * 2;
	}

	int getRightChildIndex(int idx) {//범위를 벗어나면 -1
		if (idx * 2 + 1 > getNodeNumber())
			return -1;
		return idx * 2 + 1;
	}

	int getParentIndex(int idx) {
		return idx / 2;
	}

	int getSmallestChildIndex(int idx) {
		if (getRightChildIndex(idx) < 0) {
			if (getLeftChildIndex(idx) < 0)
				return -1;//자식노드가 없는 경우
			else
				return getLeftChildIndex(idx);
		}
		return node_array[getRightChildIndex(idx)] < node_array[getLeftChildIndex(idx)] ? getRightChildIndex(idx) : getLeftChildIndex(idx);
	}

	void Push(int i) {
		node_array[++node_number] = i;
		int start = node_number;
		while (getParentIndex(start) != 0) {
			if (node_array[start] < node_array[getParentIndex(start)]) {//부모노드 보다 작은수인경우(우선순위가 더 큰경우)
				int tem = node_array[start];
				node_array[start] = node_array[getParentIndex(start)];
				node_array[getParentIndex(start)] = tem;
				start = getParentIndex(start);
			}
			else//부모노드보다 큰 수 또는 같은 수일경우
				break;
		}
	}

	int Pop() {

		int popnum = node_array[1];
		node_array[1] = node_array[node_number--];
		int start = 1;
		while (getLeftChildIndex(start) != -1) {
			if (node_array[start] > node_array[getSmallestChildIndex(start)]) {
				int tem = node_array[start];
				int tem2 = getSmallestChildIndex(start);
				node_array[start] = node_array[getSmallestChildIndex(start)];
				node_array[getSmallestChildIndex(start)] = tem;
				start = tem2;
			}
			else
				break;
		}
		return popnum;
	}
};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node_number;
	cin >> node_number;

    ArrayBasedMinHip main(node_number);

	for (int i = 0; i < node_number; i++) {
		int input;
		cin >> input;
		main.Push(input);
	}

    int answer = 0;
	for (int i = 0; i < node_number; i++) {
		answer += main.Pop() * (node_number - i);
	}

	cout << answer;

	return 0;
}