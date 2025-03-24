#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> input(n);
    for (auto &i : input)
        i.resize(n);

    for (int i = 0; i < n; i++)
        for (int l = 0; l < n; l++)
            cin >> input[i][l];

    vector<pair<pair<int, int>, pair<int, int>>> case_arr;
    for (int i = 0; i < n - 1; i++)
        for (int l = 0; l < n; l++)
            case_arr.push_back(make_pair(make_pair(i, l), make_pair(i + 1, l)));

    for (int i = 0; i < n; i++)
        for (int l = 0; l < n - 1; l++)
            case_arr.push_back(make_pair(make_pair(i, l), make_pair(i, l + 1)));


    int max_pair = min(4, n * n / 2);
    vector<pair<pair<int, int>, pair<int, int>>> pick_case;

    auto is_not_overlap = [](pair<pair<int, int>, pair<int, int>> p1, pair<pair<int, int>, pair<int, int>> p2)
    {
        return p1.first != p2.first && p1.first != p2.second &&  p1.second != p2.first && p1.second != p2.second;
    };

    int answer=0;
    std::function<void(int)> pick_pair = [&](int last_pick)
    {
        if(pick_case.size() == max_pair)
        {
            int sum = 0;
            for(auto i: pick_case)
                {
                    sum += input[i.first.first][i.first.second];
                    sum += input[i.second.first][i.second.second];
                }
            answer = max(answer, sum);
        }
        else
        {
            for (int i = last_pick + 1; i < case_arr.size(); i++)
            {
                bool is_overlap = false;
                for (auto c : pick_case)
                    if (!is_not_overlap(c, case_arr[i]))
                        is_overlap = true;
                if(is_overlap)
                    continue;
                pick_case.push_back(case_arr[i]);
                pick_pair(i);
                pick_case.pop_back();
            }
        }
    };
    pick_pair(-1);
    cout<<answer<<endl;

    return 0;
}