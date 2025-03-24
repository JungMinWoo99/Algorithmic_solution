#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define MINE -1
using namespace std;
using Coor = pair<int, int>;

class Board {
   public:
    Board(int size) : size(size), board(size, vector<char>(size)), num_board(size, vector<int>(size, 0)), click_board(size, vector<int>(size, 0)) {
        for (auto& i : board)
            for (auto& l : i)
                cin >> l;
        for (int i = 0; i < size; i++)
            for (int l = 0; l < size; l++) {
                num_board[i][l] = getMineCnt(i, l);
                if (board[i][l] == '*')
                    click_board[i][l] = MINE;
            }
    }

    void clickAround(int y, int x, queue<Coor>& next_queue) {
        static int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
        static int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

        if (num_board[y][x] == 0) {
            for (int i = 0; i < 8; i++)
                if (boundCheck(y + dy[i], x + dx[i]) && click_board[y + dy[i]][x + dx[i]] == 0) {
                    click_board[y + dy[i]][x + dx[i]] = answer;
                    next_queue.push(make_pair(y + dy[i], x + dx[i]));
                }
        }
    }

    void click(int y, int x) {
        if (click_board[y][x] != 0)
            return;  // alreay click

        queue<Coor> next_queue;

        click_board[y][x] = answer;
        next_queue.push(make_pair(y, x));
        while (next_queue.size() > 0) {
            auto next = next_queue.front();
            next_queue.pop();
            clickAround(next.first, next.second, next_queue);
        }

        answer++;
    }

    int clickAll() {
        answer = 1;
        for (int i = 0; i < size; i++)
            for (int l = 0; l < size; l++)
                if (num_board[i][l] == 0 && click_board[i][l] == 0)
                    click(i, l);
        for (int i = 0; i < size; i++)
            for (int l = 0; l < size; l++)
                if (click_board[i][l] == 0)
                    click(i, l);
        return answer;
    }

    void printNum()
    {
        for (auto& i : num_board) {
            for (auto l : i)
                cout << l << ' ';
            cout << endl;
        }
    }

    void printClick()
    {
        for (auto& i : click_board) {
            for (auto l : i)
                cout << l << ' ';
            cout << endl;
        }
    }

   private:
    int size;
    int answer;
    vector<vector<char>> board;
    vector<vector<int>> num_board;
    vector<vector<int>> click_board;

    int getMineCnt(int y, int x) {
        static int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
        static int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        if (board[y][x] == '*')
            return -1;

        int ret = 0;
        for (int i = 0; i < 8; i++)
            if (boundCheck(y + dy[i], x + dx[i]))
                if (board[y + dy[i]][x + dx[i]] == '*')
                    ret++;
        return ret;
    }

    bool boundCheck(int y, int x) {
        return -1 < y && y < size && -1 < x && x < size;
    }
};

int main(void) {
    int test_case;
    int T;
    cin>>T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;
        Board m(N);

        int answer = m.clickAll();
        
        
        cout << '#' << test_case << ' ' << answer-1 << endl;
    }
    return 0;
}