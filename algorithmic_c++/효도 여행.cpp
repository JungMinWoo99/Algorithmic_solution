#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    Node(int m) : link(0), DP(m + 1)
    {
        DP[0] = 0;
    }
    vector<pair<char, int>> link;
    vector<int> DP;
};

class Tree
{
public:
    Tree(int N, int M) : node_num(N), arr(N + 1, M)
    {
        for (auto &i : arr)
            i.DP.resize(M);

        for (auto &i : arr[1].DP)
            i = 0;
    }

    int DFS()
    {
        vector<bool> visited(arr.size() + 1);
        vector<pair<int, int>> node_stack;
        vector<char> route_stack;

        int answer = 0;

        auto print_route = [&](int node_idx)
        {
            if (arr[node_idx].link.size() == 1)
            {
                for (auto i : node_stack)
                    cout << i.first << ' ';
                cout << endl;
            }
        };

        node_stack.push_back(make_pair(1, -1));
        visited[1] = true;
        route_stack.push_back(' ');
        while (!node_stack.empty())
        {
            auto &top = node_stack.back();

            auto node_idx = top.first;
            top.second += 1;
            auto next_route = top.second;

            if (next_route < arr[node_idx].link.size())
            {
                auto next_link = arr[node_idx].link[next_route];
                int next_node = next_link.second;
                char next_route = next_link.first;
                if (!visited[next_node])
                {
                    node_stack.push_back(make_pair(next_node, -1));
                    route_stack.push_back(next_route);
                    visited[next_node] = true;

                    DP(node_idx, next_node, next_route);
                }
            }
            else
            {
                int top_node = node_stack.back().first;

                if (arr[top_node].link.size() == 1)
                    answer = max(answer, arr[top_node].DP[input_str.length()]);

                node_stack.pop_back();
                route_stack.pop_back();
                visited[top_node] = false;
            }
        }

        return answer;
    }

    void DP(int p_node, int c_node, char route)
    {
        auto& dp_arr_c= arr[c_node].DP;
        auto& dp_arr_p= arr[p_node].DP;
        dp_arr_c[0]=0;
        for(int i = 0;i<input_str.length();i++)
        {
            if(input_str[i] == route) 
                dp_arr_c[i+1] = max((dp_arr_p[i] + 1), dp_arr_p[i]);
            else
                dp_arr_c[i+1] = max(dp_arr_p[i+1], dp_arr_c[i]);
        }
    }

    void enterInput()
    {
        cin >> input_str;
        for (int i = 0; i < node_num - 1; i++)
        {
            int n1, n2;
            char ch;
            cin >> n1 >> n2 >> ch;
            arr[n1].link.push_back(make_pair(ch, n2));
            arr[n2].link.push_back(make_pair(ch, n1));
        }
    }

private:
    int node_num;
    vector<Node> arr;
    string input_str;
};

int main(void)
{
    int N, M;
    cin >> N >> M;

    Tree tree(N, M);

    tree.enterInput();
    cout<<tree.DFS();

    return 0;
}