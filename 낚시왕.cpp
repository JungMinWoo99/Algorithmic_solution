#include <iostream>
#define endl '\n'

#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <queue>

using namespace std;
enum Dir{
    None,
    Up,
    Down,
    Right,
    Left
};

Dir FlipDir(Dir d)
{
    if(d == Up || d==Right)
        return Dir(d+1);
    else
        return Dir(d-1);
}

pair<int,int> dir[] = {
    {0,-1},
    {0,1},
    {1,0},
    {-1,0},
};

struct Shark
{
    int r,c,s,d,z;
    bool operator<(const Shark& b)
    {
        return this->z<b.z;
    }
};

class FishingKing
{
public:
    FishingKing(int r,int c,int m): R(r),C(c),M(m),shark_buf(r,vector<vector<Shark>>(c))
    {
        for(int loop = 0;loop<M;loop++)
        {
            int r, c, s, d, z;
            cin >> r >> c >> s >> d >> z;
            shark_que.push({r-1,c-1,s,d,z});
        }
    }
private:
    int R,C,M;
    queue<Shark> shark_que;
    vector<vector<vector<Shark>>> shark_buf;

    void MoveShark(Shark& shark)
    {
        pair<int,int> cur_pos = {shark.r, shark.c};
        pair<int,int> next_pos_not_bounded = {
            shark.r + dir[shark.d].first * shark.s, 
            shark.c + dir[shark.d].second * shark.s
        };

        int flip_cnt=0;
        flip_cnt += abs(next_pos_not_bounded.first / (R-1) +(next_pos_not_bounded.first > 0 ? 0:-1));
        flip_cnt += abs(next_pos_not_bounded.second / (C-1) +(next_pos_not_bounded.second > 0 ? 0:-1));

        if(flip_cnt % 2 == 1)
            shark.d = FlipDir((Dir)shark.d);

        if (next_pos_not_bounded.first/R % 2 == 1)
            shark.r = (R - 1) - next_pos_not_bounded.first % (R-1);
        else
            shark.r = next_pos_not_bounded.first % (R-1);
        
        if (next_pos_not_bounded.first/R % 2 == 1)
            shark.c = (R - 1) - next_pos_not_bounded.first % (R-1);
        else
            shark.c = next_pos_not_bounded.first % (R-1);
    }

    

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}