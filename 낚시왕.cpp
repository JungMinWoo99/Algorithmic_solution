#include <iostream>
#define endl '\n'

#include <algorithm>
#include <cctype>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
enum Dir
{
    None,
    Up,
    Down,
    Right,
    Left
};

Dir FlipDir(Dir d)
{
    if (d == Up || d == Right)
        return Dir(d + 1);
    else
        return Dir(d - 1);
}

pair<int, int> dir[] = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0},
};

struct Shark
{
    static int center;
    int r, c, s, d, z;
    bool operator<(const Shark& b)
    {
        if (abs(b.c - center) == abs(this->c - center))
        {
            if (b.r == this->r)
                return b.z > this->z;
            else
                return b.r < this->r;
        }
        return abs(this->c - center) < abs(b.c - center);
    }

    bool operator==(const Shark& b)  // comp pos
    {
        return this->c == b.c && this->r == b.r;
    }
};

int Shark::center;

class FishingKing
{
   public:
    FishingKing(int r, int c, int m) : R(r), C(c), M(m), cur_angler(0)
    {
        for (int loop = 0; loop < M; loop++)
        {
            int r, c, s, d, z;
            cin >> r >> c >> s >> d >> z;
            shark_que.push_back({r - 1, c - 1, s, d, z});
        }
    }

    int FishingAll()
    {
        int answer = 0;
        while (cur_angler < C)
        {
            Shark::center = cur_angler;
            sort(shark_que.begin(), shark_que.end());
            PrintShark();
            answer += Fishing();
            cout << answer << endl;
            cout << endl;
            MoveAllShark();

            sort(shark_que.begin(), shark_que.end());

            MergeShark();
            cur_angler++;
        }
        return answer;
    }

    void PrintShark()
    {
        for (auto& shark : shark_que) cout << shark.r << shark.c << shark.z << endl;
        cout << endl;
    }

   private:
    int cur_angler;
    int R, C, M;
    deque<Shark> shark_que;

    int Fishing()
    {
        if (shark_que.empty()) return 0;
        int ret = shark_que.front().z;
        shark_que.pop_front();
        return ret;
    }

    void MoveShark(Shark& shark)
    {
        pair<int, int> cur_pos = {shark.r, shark.c};
    }

    void MoveAllShark()
    {
        for (auto& shark : shark_que) MoveShark(shark);
    }

    void MergeShark()
    {
        int loop_cnt = shark_que.size();
        for (int loop = 0; loop < loop_cnt; loop++)
        {
            auto front_shark = shark_que.front();
            shark_que.pop_front();

            if (!(front_shark == shark_que.back())) shark_que.push_back(front_shark);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C, M;
    cin >> R >> C >> M;
    FishingKing fishing_king(R, C, M);
    int answer = fishing_king.FishingAll();
    cout << answer << endl;

    return 0;
}