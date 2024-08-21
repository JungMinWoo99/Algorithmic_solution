#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
queue<pair<int,int>> vir;

bool isEmpty(int x, int y, vector<vector<int>> &input)
{
    if (-1 < x && x < N && -1 < y && y < M)
    {
        return input[x][y] == 0;
    }
    else
        return false;
}

int getSafePlace(vector<vector<int>> input)
{
    queue<pair<int,int>> queue = vir;
    while(!queue.empty())
    {
        pair<int,int> virus = queue.front();
        queue.pop();
        int x = virus.first;
        int y = virus.second;
        if(isEmpty(x+1,y,input))
        {
            input[x+1][y]=2;
            queue.push(make_pair(x+1,y));
        }
        if(isEmpty(x-1,y,input))
        {
            input[x-1][y]=2;
            queue.push(make_pair(x-1,y));
        }
        if(isEmpty(x,y+1,input))
        {
            input[x][y+1]=2;
            queue.push(make_pair(x,y+1));
        }
        if(isEmpty(x,y-1,input))
        {
            input[x][y-1]=2;
            queue.push(make_pair(x,y-1));
        }
    }

    int safe = 0;
    for(int n = 0;n<N;n++)
    {
        for(int m = 0;m<M;m++)
        {
            if(input[n][m]==0)
                safe++;
        }
    }

    return safe;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    grid.resize(N);
    for (int i = 0; i < N; i++)
    {
        grid[i].resize(M);
        for (int l = 0; l < M; l++){
            cin >> grid[i][l];
            if(grid[i][l]==2)
                vir.push(make_pair(i,l));
        }
    }

    int cell_num = N * M;
    int max = 0;
    for (int n = 0; n < cell_num; n++)
    {
        for (int m = n + 1; m < cell_num; m++)
        {
            for (int k = m + 1; k < cell_num; k++)
            {
                if (grid[n / M][n % M] == 0 && grid[m / M][m % M] == 0 && grid[k / M][k % M] == 0)
                {
                    grid[n / M][n % M] = 1;
                    grid[m / M][m % M] = 1;
                    grid[k / M][k % M] = 1;
                    int safe = getSafePlace(grid);
                    max = max>safe ? max:safe;
                    grid[n / M][n % M] = 0;
                    grid[m / M][m % M] = 0;
                    grid[k / M][k % M] = 0;
                }
            }
        }
    }

    cout << max << endl;

    return 0;
}