#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DFS
{
public:
    DFS(int r) : r(r), power(r)
    {
        for (int i = 0; i < r; i++)
            cin >> power[i];
        match_cnt = r * (r - 1) / 2;
    }

    void find_max(int depth = 0)
    {
        if (depth == match_cnt)
        {
            vector<int> score(r);
            int cnt = 0;
            for (int i = 0; i < r; i++)
            {
                for (int l = i + 1; l < r; l++)
                {
                    int res = res_stack[cnt++];
                    switch (res)
                    {
                    case 0:
                    {
                        score[l] += 3;
                        break;
                    }
                    case 1:
                        score[i] += 1;
                        score[l] += 1;
                        break;
                    case 2:
                    {
                        score[i] += 3;
                        break;
                    }
                    default:
                        break;
                    }
                }
            }

            int win_num = 0;
            for (int i = 1; i < r; i++)
                if (score[0] >= score[i])
                    win_num++;

            if (win_num >= 2)
            {

                cnt = 0;
                double prob = 100.0;
                for (int i = 0; i < r; i++)
                {
                    for (int l = i+1; l < r; l++)
                    {
                        int res = res_stack[cnt++];
                        switch (res)
                        {
                        case 0:
                            prob *= lose(i, l);
                            break;
                        case 1:
                            prob *= draw(i, l);
                            break;
                        case 2:
                            prob *= win(i, l);
                            break;
                        default:
                            break;
                        }
                    }
                }
                answer += prob;
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                res_stack.push_back(i);
                find_max(depth + 1);
                res_stack.pop_back();
            }
        }
    }

    double print_answer()
    {
        printf("%.3f",answer);
    }

private:
    vector<int> power;
    vector<int> res_stack;

    int match_cnt;
    int r;
    double answer = 0;

    double win(int my_idx, int op_idx)
    {
        double f_i = power[my_idx];
        double f_l = power[op_idx];

        return f_i * 4.0 / (5.0 * f_i + 5.0 * f_l);
    }

    double draw(int my_idx, int op_idx)
    {
        double f_i = power[my_idx];
        double f_l = power[op_idx];

        return (f_i + f_l) / (5.0 * f_i + 5.0 * f_l);
    }

    double lose(int my_idx, int op_idx)
    {
        double f_i = power[my_idx];
        double f_l = power[op_idx];

        return f_l * 4.0 / (5.0 * f_i + 5.0 * f_l);
    }
};

int main(int argc, char **argv)
{
    DFS obj(4);
    obj.find_max();
    obj.print_answer();
    return 0;
}