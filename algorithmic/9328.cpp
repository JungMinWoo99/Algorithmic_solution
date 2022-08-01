#include <iostream>
#include<queue>
#include<map>

using namespace std;

class Board {
private:
	int h, w;
	char** grid;
	map<char, bool> key;
	queue<pair<int, int>> next_move;
	int doc = 0;

public:

	void input_grid() {
		for (int n = 0; n < h; n++)
			for (int m = 0; m < w; m++)
				cin >> grid[n][m];
	}

	void search_edge() {

		for (int n = 0; n < h; n++) {

			if (grid[n][0] != '*')
				add_next_move(n, 0);

			if (grid[n][w - 1] != '*')
				add_next_move(n, w - 1);
		}

		for (int m = 0; m < w; m++) {

			if (grid[0][m] != '*')
				add_next_move(0, m);

			if (grid[h-1][m] != '*')
				add_next_move(h-1, m);
		}

	}

	void add_next_move(int n, int m) {
		next_move.push(make_pair(n, m));
	}

	void visit_cell(int n, int m) {
		grid[n][m] = '_';
	}

	void add_adj_cell(int n, int m) {
		add_next_move(n - 1, m);
		add_next_move(n + 1, m);
		add_next_move(n , m - 1);
		add_next_move(n , m + 1);
	}

	void add_key(char k) {
		key[k] = true;
	}

	void input_given_key() {
		string str;
		cin >> str;
		if (str.compare("0") == 0)
			return;
		else {
			for (string::iterator it = str.begin(); it != str.end(); it++)
				add_key(*it);
		}
	}

	Board(int h, int w) :h(h), w(w) {
		
		grid = new char* [h];
		for (int i = 0; i < h; i++)
			grid[i] = new char[w];
		
		input_grid();

		input_given_key();

		search_edge();
	}

	~Board() {

		for (int i = 0; i < h; i++)
			delete[] grid[i];

		delete[] grid;
	}

	bool out_of_boundary(int n, int m) {
		return !((-1 < n && n < h) && (-1 < m && m < w));
	}

	bool imp_cell(int n, int m) {
		
		if (out_of_boundary(n, m))
			return false;//방문하지 못하면 false 반환
		else if (grid[n][m] == '_' || grid[n][m] == '*')
			return false;
		else if (grid[n][m] == '.') {
			visit_cell(n, m);
			return true;//방문했다면 true 반환
		}
		else if (grid[n][m] == '$') {
			doc++;
			visit_cell(n, m);
			return true;
		}
		else if ('a' <= grid[n][m] && grid[n][m] <= 'z') {
			add_key(grid[n][m]);
			visit_cell(n, m);
			return true;
		}
		else if ('A' <= grid[n][m] && grid[n][m] <= 'Z') {
			if (key[grid[n][m] - ('A' - 'a')]) {
				visit_cell(n, m);
				return true;
			}
			else {
				add_next_move(n, m);
				return false;
			}
		}
		else
			return false;
	}

	void travel() {
		int loop_break=0;
		while (loop_break != next_move.size()) {//탈출 조건 추가해야함
			int n = next_move.front().first;
			int m = next_move.front().second;
			int size = next_move.size();
			next_move.pop();

			if (imp_cell(n, m)) {
				add_adj_cell(n, m);
				loop_break = 0;
			}
			else if(size== next_move.size())
				loop_break++;
		}
	}

	int answer() {
		return doc;
	}

};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int h, w;
		cin >> h >> w;
		Board test(h, w);
		test.travel();
		cout<<test.answer()<<'\n';
	}

	return 0;
}