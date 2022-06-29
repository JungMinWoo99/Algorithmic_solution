#include <iostream>
#include <deque>

using namespace std;

/*
* 사용 알고리즘
* 위상 정렬
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
		int* con_time = new int[N + 1];//건설 시간 저장
		int* dp_time = new int[N + 1];//누적 건설 시간 저장
		deque<int> sort_arr;//위상 정렬 저장
		int* in_deg = new int[N + 1]{ 0, };//진입차수 저장
		bool* in_check= new bool[N + 1]{ false, };//위상정렬수행시 이미 들어간 노드 확인용
		deque<int>* next_n_deque = new deque<int>[N + 1];//각 노드의 다음 노드
		deque<int>* pre_n_deque = new deque<int>[N + 1];//각 노드의 이전 노드
		int K;
		cin >> K;
		for (int i = 1; i <= N; i++)//건설 시간 입력받기
			cin >> con_time[i];
		for (int i = 0; i < K; i++) {
			int i1, i2;
			cin >> i1 >> i2;
			in_deg[i2]++;
			next_n_deque[i1].push_back(i2);//다음 노드 리스트 작성
			pre_n_deque[i2].push_back(i1);//다음 노드 리스트 작성
		}
		

		//위상 정렬
		deque<int> queue;//대기열
		for (int i = 0; i< N; i++) {//위상 정렬 큐에 모든 노드가 들어갈 때 까지
			int node = i + 1;
			if (in_deg[node] == 0 && in_check[node] == false)//진입차수가 0이고 아직 정렬되지 않은 노드인 경우
				queue.push_back(node);
		}
		
		while (!queue.empty()) {
			int node = queue.front();//떨어진 노드
			queue.pop_front();
		
			for (deque<int>::iterator iter = next_n_deque[node].begin(); iter != next_n_deque[node].end(); iter++) {//떨어진 노드와 인접한 노드 탐색
				int next_node = *iter;
				if (--in_deg[next_node] == 0)//다음 노드의 진입차수를 1감소시키고 만약 0이된다면 대기열에 추가
					queue.push_back(next_node);
			}
			
			sort_arr.push_back(node);//node를 정렬
			in_check[node] = true;//node가 정렬됨을 표시
		}
		
		/*
		//정렬 확인 코드
		cout << '\n';
		for (deque<int>::iterator iter = sort_arr.begin(); iter != sort_arr.end(); iter++)
			cout << *iter << ' ';
		cout << '\n';
		*/

		//dp과정
		for (deque<int>::iterator iter = sort_arr.begin(); iter != sort_arr.end(); iter++) {
			int node = *iter;
			int time = con_time[node];
			int max_time = time;//해당 건물 건설까지 걸리는 시간의 최댓값
			
			for (deque<int>::iterator iter = pre_n_deque[node].begin(); iter != pre_n_deque[node].end(); iter++) {
				if (max_time < time + dp_time[*iter])//기존시간보다 더 오랜 시간이 걸리면
					max_time = time + dp_time[*iter];//최댓값 갱신
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