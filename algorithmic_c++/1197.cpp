#include <iostream>
#include <list>

using namespace std;

/*
* 사용 알고리즘
* 크루스칼 알고리즘
* 사이클 검출-서로수집합(Disjoint Set)에서 합집합 찾기(union-find)
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
	list<pair<pair<int, int>, int>> edge;//두 노드, 간선의 가중치를 저장하는 벡터
	int* c_check_table;//사이클 체크 테이블(루트 노드위치를 저장)
	int n_num,e_num;
	cin >> n_num >>e_num;

	c_check_table = new int[n_num+1];//노드 갯수 만큼 할당
	for (int i = 0; i < n_num+1; i++) {//테이블 기본값 세팅
		c_check_table[i] = i;//셀프 루프하는 트리가 초기 세팅
	}

	for (int i = 0; i < e_num; i++) {//엣지 벡터 채우기
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
		} while (c_check_table[root1] != root1);//셀프 루프가 되는 루트 노드에 도달 할때까지 반복
		c_check_table[n1] = root1;//루트 노드 갱신
		do {
			root2 = c_check_table[root2];
		} while (c_check_table[root2] != root2);//셀프 루프가 되는 루트 노드에 도달 할때까지 반복
		c_check_table[n2] = root2;//루트 노드 갱신
		if (root1 != root2) {//사이클이 형성되지 않는경우
			answer += e_val;
			c_check_table[root1] = root2;//독립된 두 트리를 연결
			e_count++;
		}
		edge.pop_front();
	}

	cout << answer;

	return 0;
}