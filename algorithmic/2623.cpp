#include <iostream>
#include <deque>

using namespace std;

/*
* 사용 알고리즘
* 위상 정렬 응용
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	deque<int>* order_deque = new deque<int>[N + 1];//각 가수의 바로 다음 우선순위의 가수 리스트
	int* in_deg = new int[N + 1]{ 0, };//in_degree 저장
	bool* is_sort = new bool[N + 1]{ false, };//정렬 여부를 저장
	deque<int> search_queue;//탐색 대기열
	deque<int> answer;

	//각 변수들의 초기값 설정
	for (int m = 0; m < M; m++) {
		int singer;//입력받는 가수의 수
		cin >> singer;
		int* order = new int[singer];//순서를 입력받을 배열
		for (int i = 0; i < singer; i++)
			cin >> order[i];
		for (int i = 1; i < singer; i++)//in_degree 카운팅
			in_deg[order[i]]++;
		for (int i = 0; i < singer - 1; i++)//order_deque 작성
			order_deque[order[i]].push_back(order[i + 1]);
		delete[] order;
	}

	//정답 찾기
	for (int i = 1; i <= N; i++)
		if (in_deg[i] == 0)
			search_queue.push_back(i);//진입차수가 0인 노드 부터 탐색 및 정렬
	while (!search_queue.empty()) {//모든 가수들이 정렬될 때까지
		int node = search_queue.front();
		search_queue.pop_front();
		answer.push_back(node);//node 가수 정렬
		is_sort[node] = true;//정렬됨을 체크
		//정렬된 가수의 다음 바로 다음 우선순위 가수들의 in_degree감소
		for (int n = 0; n < order_deque[node].size(); n++) {
			if (is_sort[order_deque[node][n]] == true) {//이미 정렬된 가수가 후순위인경우->순서 정하기 불가능
				cout << '0' << '\n';
				return 0;
			}
			in_deg[order_deque[node][n]]--;
			if (in_deg[order_deque[node][n]] == 0)//더 이상 진입 노드가 없는 경우
				search_queue.push_back(order_deque[node][n]);//탐색 대기열에 추가
		}
	}

	//정답 출력
	if (answer.size() != N) {//정상적으로 정렬되었다면 모든 노드가 정렬되있어야함
		cout << '0' << '\n';
		return 0;
	}
	for (int n = 0; n < answer.size(); n++)
		cout << answer[n] << '\n';
	return 0;
}