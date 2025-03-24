#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> input(n);
    for(auto& i: input)
        i.resize(m);

    pair<int,int> N,D;
    vector<pair<int,int>> G_arr;

    for(int i = 0;i<n;i++)
        for(int l = 0;l<m;l++)
        {
            cin>> input[i][l];
            if(input[i][l] == 'G')
                G_arr.push_back(make_pair(i,l));
            if(input[i][l] == 'N')
                N = make_pair(i,l);
            if(input[i][l] == 'D')
                D = make_pair(i,l);
        }
    
    vector<vector<int>> route_len_arr(n);
    for(auto& i: route_len_arr)
        i.resize(m);

    auto can_go = [&](pair<int, int> pos)
    {
        bool bound_check = -1 < pos.first && pos.first < n && -1 < pos.second && pos.second < m;
        if (bound_check)
        {
            bool not_visited = route_len_arr[pos.first][pos.second] == 0;
            bool not_wall = input[pos.first][pos.second] != '#';
            return not_visited && not_wall;
        }
        else
            return false;
    };

    pair<int, int> (*move_set[4])(pair<int, int>);

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
    queue<pair<pair<int, int>, int>> next_queue;
    next_queue.push(make_pair(N,1));
    route_len_arr[N.first][N.second] = 1;
    while(!next_queue.empty())
    {
        auto front = next_queue.front();
        next_queue.pop();
        auto cur_pos = front.first;
        auto next_cnt = front.second + 1;
        //cout<<cur_pos.first<<' '<<cur_pos.second<<' '<<next_cnt<<endl;
        for(int i = 0;i<4;i++)
        {
            auto next_pos = move_set[i](cur_pos);
            if(can_go(next_pos))
            {
                route_len_arr[next_pos.first][next_pos.second] = next_cnt;
                next_queue.push(make_pair(next_pos, next_cnt));
            }
        }
    }
    int fast_G_route_len = INT_MAX;
    for(auto g:G_arr)
    {
        int fast_route_len = abs(g.first - D.first) + abs(g.second - D.second);
        if(fast_route_len < fast_G_route_len)
            fast_G_route_len = fast_route_len;
    }

    int fast_route_len = route_len_arr[D.first][D.second] - 1;

    if(fast_route_len == -1 || fast_route_len >= fast_G_route_len)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    

    return 0;
}