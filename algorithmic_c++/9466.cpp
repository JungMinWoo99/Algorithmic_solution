#include <iostream>
#include<vector>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int answer = 0;
		int n;
		cin >> n;
		int* n_node = new int[n + 1]{ 0, };
		bool* check_tr = new bool[n + 1]{ 0, };
		for (int i = 1; i <= n; i++)
			cin >> n_node[i];
		for (int i = 1; i <= n; i++) {
			if (check_tr[i] == true)
				continue;
			else {
				int cur_node = i;
				vector<int> tr_list;
				int first_t_node = 0;
				while (first_t_node == 0) {
					if (check_tr[cur_node] == true) {
						first_t_node = cur_node;
						tr_list.push_back(cur_node);
					}
					else {
						check_tr[cur_node] = true;
						tr_list.push_back(cur_node);
						cur_node = n_node[cur_node];
					}
				}
				int FTN_index = 0;
				while (tr_list[FTN_index] != first_t_node)
					FTN_index++;
				answer += FTN_index;
			}
		}
		cout << answer << '\n';
		delete[] n_node;
		delete[] check_tr;
	}
	return 0;
}