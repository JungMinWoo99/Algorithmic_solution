#include <stdio.h>
#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>

#include <queue>

#define MAX_HASH_LEN 5
using namespace std;

class Island
{
public:
    int N;
    vector<vector<int>> land_map;
    vector<int> hash_table;

    Island(int N, int (*input)[20]) : N(N), land_map(N, vector<int>(N)), hash_table(pow(10, MAX_HASH_LEN + 1) + 1, 0)
    {
        for (int i = 0; i < N; i++)
            for (int l = 0; l < N; l++)
                land_map[i][l] = input[i][l];

        countHash();
    }

    int maxArea(int sea_level, vector<int> &st)
    {
        bool can_put = false;
        int max_val = numeric_limits<int>::min();
        int st_hash = getStHash(st);
        can_put |= hash_table[st_hash] > 0;
        if (hash_table[st_hash] > 0)
        {
            for (int i = 0; i < N; i++)
                for (int l = 0; l < N - st.size() + 1; l++)
                {
                    vector<int> map;
                    // 수평 방향
                    for (int n = 0; n < st.size(); n++)
                        map.push_back(land_map[i][l + n]);
                    if (st_hash == getMapHash(map))
                    {
                        for (int n = 0; n < st.size(); n++)
                            land_map[i][l + n] += st[n];
                        max_val = max(max_val, sinkLand(sea_level));
                        for (int n = 0; n < st.size(); n++)
                            land_map[i][l + n] -= st[n];
                    }
                }

            for (int i = 0; i < N - st.size() + 1; i++)
                for (int l = 0; l < N; l++)
                {
                    vector<int> map;
                    // 수직 방향
                    for (int n = 0; n < st.size(); n++)
                        map.push_back(land_map[i + n][l]);
                    if (st_hash == getMapHash(map))
                    {
                        for (int n = 0; n < st.size(); n++)
                            land_map[i + n][l] += st[n];
                        max_val = max(max_val, sinkLand(sea_level));
                        for (int n = 0; n < st.size(); n++)
                            land_map[i + n][l] -= st[n];
                    }
                }
        }

        reverse(st.begin(), st.end());
        int rev_st_hash = getStHash(st);
        can_put |= hash_table[rev_st_hash] > 0;
        if (rev_st_hash != st_hash && hash_table[rev_st_hash] > 0)
        {
            for (int i = 0; i < N; i++)
                for (int l = 0; l < N - st.size() + 1; l++)
                {
                    vector<int> map;
                    // 수평 방향
                    for (int n = 0; n < st.size(); n++)
                        map.push_back(land_map[i][l + n]);
                    if (rev_st_hash == getMapHash(map))
                    {
                        for (int n = 0; n < st.size(); n++)
                            land_map[i][l + n] += st[n];
                        max_val = max(max_val, sinkLand(sea_level));
                        for (int n = 0; n < st.size(); n++)
                            land_map[i][l + n] -= st[n];
                    }
                }

            for (int i = 0; i < N - st.size() + 1; i++)
                for (int l = 0; l < N; l++)
                {
                    vector<int> map;
                    // 수직 방향
                    for (int n = 0; n < st.size(); n++)
                        map.push_back(land_map[i + n][l]);
                    if (rev_st_hash == getMapHash(map))
                    {
                        for (int n = 0; n < st.size(); n++)
                            land_map[i + n][l] += st[n];
                        max_val = max(max_val, sinkLand(sea_level));
                        for (int n = 0; n < st.size(); n++)
                            land_map[i + n][l] -= st[n];
                    }
                }
        }

        if (!can_put)
            return -1;
        else
            return max_val;
    }

    static int getStHash(vector<int> &st)
    {
        if (st.size() == 1)
            return pow(10, MAX_HASH_LEN + 1);
        int st_hash_code = 0;
        for (int i = 1; i < st.size(); i++)
            st_hash_code = st_hash_code * 10 + 5 - (st[i] - st[i - 1]);
        return st_hash_code;
    }

    static int getMapHash(vector<int> &map)
    {
        if (map.size() == 1)
            return pow(10, MAX_HASH_LEN + 1);
        int map_hash_code = 0;
        for (int i = 1; i < map.size(); i++)
            map_hash_code = map_hash_code * 10 + (map[i] - map[i - 1] + 5);
        return map_hash_code;
    }

private:
    void countHash()
    {
        hash_table[pow(10, MAX_HASH_LEN + 1)] = N * N;

        for (int i = 0; i < N; i++)
        {
            vector<int> arr;
            for (int l = 1; l < N; l++)
                arr.push_back(land_map[i][l] - land_map[i][l - 1] + 5);
            for (int l = 1; l <= MAX_HASH_LEN; l++)
            {
                for (int n = 0; n < N - l; n++)
                {
                    int hash_val = 0;
                    for (int k = 0; k < l; k++)
                    {
                        hash_val *= 10;
                        hash_val += arr[n + k];
                    }
                    hash_table[hash_val]++;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            vector<int> arr;
            for (int l = 1; l < N; l++)
                arr.push_back(land_map[l][i] - land_map[l - 1][i] + 5);
            for (int l = 1; l <= MAX_HASH_LEN; l++)
            {
                for (int n = 0; n < N - l; n++)
                {
                    int hash_val = 0;
                    for (int k = 0; k < l; k++)
                    {
                        hash_val *= 10;
                        hash_val += arr[n + k];
                    }
                    hash_table[hash_val]++;
                }
            }
        }
    }

    bool checkBound(int y, int x)
    {
        return -1 < y && y < N && -1 < x && x < N;
    }

    int sinkLand(int mSeaLev)
    {
        static int dy[] = {1, 0, -1, 0};
        static int dx[] = {0, 1, 0, -1};

        int ret = N * N;
        queue<pair<int, int>> bfs_que;
        vector<vector<int>> visited(N, vector<int>(N, false));

        for (int i = 0; i < N; i++)
        {
            bfs_que.push(make_pair(0, i));
            bfs_que.push(make_pair(N - 1, i));
            bfs_que.push(make_pair(i, 0));
            bfs_que.push(make_pair(i, N - 1));
        }

        while (!bfs_que.empty())
        {
            auto cur = bfs_que.front();
            bfs_que.pop();

            if (visited[cur.first][cur.second] || land_map[cur.first][cur.second] >= mSeaLev)
                continue;
            else
            {
                visited[cur.first][cur.second] = true;
                ret--;
            }

            for (int i = 0; i < 4; i++)
            {
                auto next = make_pair(cur.first + dy[i], cur.second + dx[i]);
                if (checkBound(next.first, next.second))
                    bfs_que.push(next);
            }
        }

        return ret;
    }
};

Island *island = nullptr;

void init(int N, int mMap[20][20])
{
    if (island == nullptr)
        delete island;
    island = new Island(N, mMap);
}

int numberOfCandidate(int M, int mStructure[5])
{
    vector<int> st;
    for (int i = 0; i < M; i++)
        st.push_back(mStructure[i]);
    int ret = 0;
    int hash_val = Island::getStHash(st);

    ret += island->hash_table[hash_val];
    reverse(st.begin(), st.end());
    int reverse_hash_val = Island::getStHash(st);
    if (reverse_hash_val != hash_val)
        ret += island->hash_table[reverse_hash_val];

    return ret;
}

int maxArea(int M, int mStructure[5], int mSeaLevel)
{
    vector<int> st;
    for (int i = 0; i < M; i++)
        st.push_back(mStructure[i]);
    int ret = island->maxArea(mSeaLevel, st);
    return ret;
}

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define CMD_INIT 1
#define CMD_NUMBER_OF_CANDIDATE 2
#define CMD_MAX_AREA 3

extern void init(int N, int mMap[20][20]);
extern int numberOfCandidate(int M, int mStructure[5]);
extern int maxArea(int M, int mStructure[5], int mSeaLevel);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int mMap[20][20];
static int mStructure[5];

static bool run()
{
    int numQuery;
    int N, M, mSeaLevel;
    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
        case CMD_INIT:
            scanf("%d", &N);
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    scanf("%d", &mMap[j][k]);
            init(N, mMap);
            isCorrect = true;
            break;
        case CMD_NUMBER_OF_CANDIDATE:
            scanf("%d", &M);
            for (int j = 0; j < M; j++)
                scanf("%d", &mStructure[j]);
            userAns = numberOfCandidate(M, mStructure);
            scanf("%d", &ans);
            printf("CAN_ANS_OUT: %d %d\n", ans, userAns);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_MAX_AREA:
            scanf("%d", &M);
            for (int j = 0; j < M; j++)
                scanf("%d", &mStructure[j]);
            scanf("%d", &mSeaLevel);
            userAns = maxArea(M, mStructure, mSeaLevel);
            scanf("%d", &ans);
            printf("AREA_ANS_OUT: %d %d\n", ans, userAns);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }
    return isCorrect;
}

int main()
{
    // setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}