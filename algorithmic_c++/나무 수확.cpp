#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Cell
{
    long long int max_val_w_s=0;
    long long int max_val_wo_s=0;
};

class Grid
{
public:
    Grid(int n):input(n),DP(n),size(n)
    {
        for(auto& i:input)
            i.resize(n);
        
        for(auto& i:DP)
            i.resize(n);

        for(int i = 0;i<n;i++)
            for(int l = 0;l<n;l++)
                cin >> input[i][l];
    }

    void setMax(pair<int,int> pos)
    {
        auto bound_check = [=](pair<int,int> pos)
        {
            int y = pos.first;
            int x = pos.second;

            return -1 < x && x < size && -1 < y && y < size;
        };
        pair<int, int> p1 = make_pair(pos.first - 1, pos.second);
        pair<int, int> p2 = make_pair(pos.first, pos.second - 1);

        Cell c1;
        Cell c2;
        if(bound_check(p1))
            c1 = DP[p1.first][p1.second];

        if(bound_check(p2))
            c2 = DP[p2.first][p2.second];
        
        Cell large_w_s_cell;
        Cell large_wo_s_cell;
        if(c1.max_val_w_s > c2.max_val_w_s)
            large_w_s_cell = c1;
        else
            large_w_s_cell = c2;
        
        if(c1.max_val_wo_s > c2.max_val_wo_s)
            large_wo_s_cell = c1;
        else
            large_wo_s_cell = c2;
        
        
        DP[pos.first][pos.second].max_val_wo_s = large_wo_s_cell.max_val_wo_s + input[pos.first][pos.second];
        DP[pos.first][pos.second].max_val_w_s = max(large_w_s_cell.max_val_w_s + input[pos.first][pos.second], DP[pos.first][pos.second].max_val_wo_s + input[pos.first][pos.second]);
    }

    void findAnswer()
    {        
        for(int i = 0;i<size;i++)
            for(int l = 0;l<size;l++)
            {
                setMax(make_pair(i,l));
            }
        auto last_cell = DP[size-1][size-1];
        int answer = last_cell.max_val_w_s;
        printf("%d\n",answer);
    }

private:
    int size;
    vector<vector<long long int>> input;
    vector<vector<Cell>> DP;
    
};

int main(void)
{
    int n;
    cin>> n;
    Grid obj(n);
    obj.findAnswer();
    return 0;
}