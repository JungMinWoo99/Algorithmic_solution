#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    TreeNode() {}
    TreeNode(int s, int m, int y, int x) : sum(s), next_move(m), last_pos(y, x)
    {
    }
    int sum;
    int next_move;
    pair<int, int> last_pos;
} typedef TreeNode;

class SearchTree
{
public:
    SearchTree(int n, int m) : input(n), friends(m), n(n), grid(n)
    {
        for (auto &i : grid)
            i.resize(n);

        for (auto &i : grid)
            for (auto &l : i)
                l = false;

        for (auto &i : input)
            i.resize(n);

        for (auto &i : input)
            for (auto &l : i)
                cin >> l;

        for (auto &i : friends)
            cin >> i.first >> i.second;

        move_set[0] = [](pair<int, int> cur)
        {
            return make_pair(cur.first - 1, cur.second);
        };

        move_set[1] = [](pair<int, int> cur)
        {
            return make_pair(cur.first + 1, cur.second);
        };

        move_set[2] = [](pair<int, int> cur)
        {
            return make_pair(cur.first, cur.second - 1);
        };
        move_set[3] = [](pair<int, int> cur)
        {
            return make_pair(cur.first, cur.second + 1);
        };
    }

    int find_max()
    {
        pair<int, int> next_friend = friends[s.size() / 4];
        push(next_friend, 0);
        do
        {
            pair<int, int> next_pos;
            do
            {
                if (s.top().next_move == 4)
                    break;
                next_pos = move_set[s.top().next_move++](s.top().last_pos);
            } while (!bound_check(next_pos) || grid[next_pos.first][next_pos.second]);
            
            if (s.top().next_move == 4)
            {
                if (s.size() == friends.size() * 4 || s.size() == n*n)
                    if (s.top().sum > max)
                        max = s.top().sum;
                while (!s.empty() && s.top().next_move == 4)
                    pop();
            }
            else if ((s.size() + 1) % 4 == 0)
            {
                push(next_pos, 4);
                if (s.size() / 4 < friends.size())
                {
                    next_pos = friends[s.size() / 4];
                    if(!grid[next_pos.first][next_pos.second])
                        push(next_pos, 0);
                }
            }
            else
                push(next_pos, 0);

        } while (!s.empty());

        return max;
    }

private:
    vector<vector<int>> input;
    vector<pair<int, int>> friends;
    vector<vector<int>> grid;

    vector<stack<TreeNode>> s;

    int n;
    int max = 0;

    void push(stack<TreeNode>& s, pair<int, int> pos, int move_num)
    {
        int y = pos.first;
        int x = pos.second;
        TreeNode next;

        if (s.empty())
            next.sum = input[y][x];
        else
            next.sum = input[y][x] + s.top().sum;
        next.last_pos = make_pair(y, x);
        next.next_move = move_num;

        grid[y][x] = true;
        s.push(next);
    }

    void pop(stack<TreeNode>& s)
    {
        TreeNode top = s.top();
        grid[top.last_pos.first][top.last_pos.second] = false;
        s.pop();
    }

    bool bound_check(pair<int, int> pos)
    {
        int y = pos.first;
        int x = pos.second;
        return -1 < y && y < n && -1 < x && x < n;
    }

    pair<int, int> (*move_set[4])(pair<int, int>);
};

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;

    SearchTree tree(n, m);

    cout << tree.find_max() << endl;

    return 0;
}