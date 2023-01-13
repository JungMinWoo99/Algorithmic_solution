#include <iostream>
#include <vector>
#include <stack>
/**
 * @brief
 * 양방향 트리를 기반으로 DP를 통해 문제를 해결
 */

using namespace std;

class EarlyAdaptorFinder
{
private:
    const int NotEA = 0;
    const int EA = 1;
    int process_start_node = 1;
    int friend_num;

    vector<int> *adj_friend_list;
    /*
    다이나믹 프로그램을 위한 배열
        0: 현재 노드가 EA인 경우의 서브트리의 최소 EA수의 총합
        1: 현재 노드가 EA가 아닌 경우의 해당 노드의 서브트리의 최소 EA수 + 1(해당 노드 포함)의 총합
    */
    int *dp_arr[2];

public:
    EarlyAdaptorFinder(int friend_num)
    {
        this->friend_num = friend_num;
        for (int i = 0; i < 2; i++)
            dp_arr[i] = new int[friend_num + 1]; //+1은 인덱스를 1부터 사용하기 위함
        adj_friend_list = new vector<int>[friend_num + 1];
    }

    void inputFriendRelation(pair<int, int> relation)
    {
        adj_friend_list[relation.first].push_back(relation.second);
        adj_friend_list[relation.second].push_back(relation.first);
    }

    bool isLeaf(int friend_idx)
    {
        return adj_friend_list[friend_idx].empty();
    }

    void findMinEarlyAdaptor()
    {
        int current_node = process_start_node;
        bool *processedNodes = new bool[friend_num + 1]{
            0,
        };
        bool *node_in_stack = new bool[friend_num + 1]{
            0,
        };
        stack<int> recursive_stack;
        recursive_stack.push(current_node);
        node_in_stack[current_node] = true;

        while (!recursive_stack.empty())
        {
            current_node = recursive_stack.top();
            if (processedNodes[current_node])
            {
                recursive_stack.pop();
                node_in_stack[current_node] = true;
                continue;
            }
            else if (isLeaf(current_node))
            {
                dp_arr[NotEA][current_node] = 0;
                dp_arr[EA][current_node] = 1;
                processedNodes[current_node] = true;

                recursive_stack.pop();
                node_in_stack[current_node] = false;
            }
            else
            {
                bool has_all_been_processed = true;
                dp_arr[NotEA][current_node] = 0;
                dp_arr[EA][current_node] = 0;

                for (int i = 0; i < adj_friend_list[current_node].size(); i++)
                {
                    int adj_node = adj_friend_list[current_node][i];
                    if (processedNodes[adj_node])
                    {
                        dp_arr[NotEA][current_node] += dp_arr[EA][adj_node];
                        int min_value_for_node = dp_arr[EA][adj_node] < dp_arr[NotEA][adj_node] ? dp_arr[EA][adj_node] : dp_arr[NotEA][adj_node];
                        dp_arr[EA][current_node] += min_value_for_node;
                    }
                    else if (!node_in_stack[adj_node])
                    {
                        recursive_stack.push(adj_node);
                        node_in_stack[adj_node] = true;
                        has_all_been_processed = false;
                    }
                }

                if (has_all_been_processed)
                {
                    dp_arr[EA][current_node]++;
                    processedNodes[current_node] = true;

                    recursive_stack.pop();
                    node_in_stack[current_node] = false;
                }
            }
        }
    }

    int getEarlyAdaptorNumber()
    {
        return dp_arr[EA][process_start_node] < dp_arr[NotEA][process_start_node] ? dp_arr[EA][process_start_node] : dp_arr[NotEA][process_start_node];
    }
};

int main(void)
{
    int friend_num;
    cin >> friend_num;
    EarlyAdaptorFinder main(friend_num);

    for (int i = 0; i < friend_num - 1; i++)
    {
        int friend1, friend2;
        cin >> friend1 >> friend2;
        main.inputFriendRelation(make_pair(friend1, friend2));
    }

    main.findMinEarlyAdaptor();
    cout << main.getEarlyAdaptorNumber();
    return 0;
}