#include <iostream>
#include <list>

using namespace std;

/*
* 사용 알고리즘
* 위상 정렬
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	int* in_degree = new int[N + 1]{0,};//진입차수 저장
	list<int>* adj_list = new list<int>[N + 1];//인접 노드 리스트
	list<int> sort_arr;//위상 정렬 리스트

	for (int i = 0; i < M; i++) {
		int i1, i2;
		cin >> i1 >> i2;
		adj_list[i1].push_back(i2);
		in_degree[i2]++;
	}

	//위상 정렬
	list<int> queue;//정렬 대기열
	for (int i = 1; i <= N; i++)
		if (in_degree[i] == 0)
			queue.push_back(i);
	while (!queue.empty()) {
		int node = queue.front();//정렬할 노드
		queue.pop_front();
		for (list<int>::iterator iter = adj_list[node].begin(); iter != adj_list[node].end(); iter++) {
			int adj_node = *iter;//정렬할 노드와 인접한 노드
			if (--in_degree[adj_node] == 0)
				queue.push_back(adj_node);//더 이상 진입노드가 없는 노드를 정렬 대기열에 추가
		}
		sort_arr.push_back(node);
	}

	//정답 출력
	for (list<int>::iterator iter = sort_arr.begin(); iter != sort_arr.end(); iter++)
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}

