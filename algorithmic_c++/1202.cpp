#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare_dia(pair<int, int> comp1, pair<int, int> comp2) {
	return comp1.first > comp2.first;//???? ???? ???????? ????
}

bool compare_sack(int comp1, int comp2) {
	return comp1 > comp2;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long answer=0;
	int N, K;
	cin >> N >> K;
	vector<unsigned int> sack;
	vector<pair<unsigned int,unsigned int>> dia;//first: m, second: v
	priority_queue<int, vector<int>, less<int>> v_queue;

	for (int n = 0; n < N; n++) {
		unsigned int m, v;
		cin >> m >> v;
		dia.push_back(make_pair(m, v));
	}
	
	for (int k = 0; k < K; k++) {
		unsigned int c;
		cin >> c;
		sack.push_back(c);
	}

	sort(sack.begin(), sack.end(),compare_sack);

	sort(dia.begin(), dia.end(), compare_dia);

	while (!(sack.empty())) {//?????? ?? ????????????
		while (sack.back() >= dia.back().first) {
			if (dia.empty())
				break;
			unsigned int cur_dia_v = dia.back().second;
			v_queue.push(cur_dia_v);
			dia.pop_back();
		}
		if (!v_queue.empty()) {
			answer += (long long)v_queue.top();
			v_queue.pop();
		}
		sack.pop_back();
	}
	
	cout << answer<<'\n';
	return 0;
}