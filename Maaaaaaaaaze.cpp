#include <iostream>
#define endl '\n'

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>

#include <array>
#include <queue>

using namespace std;

constexpr int board_size = 5;

class Maze2D
{
    void RotateRight()
    {
        auto copy = maze;
        for(int r = 0;r<board_size;r++)
        {
            for(int c = 0;c<board_size;c++)
                maze[c][r-4] = maze[r][c];
        }
    }

    array<int,board_size>& operator[](int idx)
    {
        return maze[idx];
    }
public:
    const int size = board_size;
    array<array<int,board_size>,board_size> maze;
}

class Maze3D
{
public:
    Maze3D()
    {
        for(auto& maze_2d:maze)
            maze_2d = new Maze2D;
        sort(maze.begin(),maze.end());
    }

    void RotateRightNthFloor(int idx)
    {
        maze[idx]->RotateRight();
    }

    bool SetNextPermutation()
    {
        return next_permutation();
    }

    ~Maze3D()
    {
        for(auto& maze_2d:maze)
            delete maze_2d;
    }

    Maze2D& operator[](int idx)
    {
        return *maze[idx];
    }

private:
    array<Maze2D*,board_size> maze;
}

int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

class PathFinder
{
public:
    int BFS()
    {
        struct status
        {
            int z, y ,x, val;
        };

        queue<status> bfs_que;
        vector<vector<vector<int>>> visited(board_size,vector<vector<int>>(board_size, vector<int>(board_size,false)));

        bfs_que.push({0,0,0,0});
        int path_len = -1;
        while(!bfs_que.empty())
        {
            auto cur_stat = bfs_que.front();
            bfs_que.pop();

            if(visited[cur_stat.z][cur_stat.y][cur_stat.x])
                continue;
            else
                visited[cur_stat.z][cur_stat.y][cur_stat.x] = false;
            
            for(int dir = 0; dir < 8;dir++)
            {
                int dir 
            }
        }
    }
private:
    Maze3D maze;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}