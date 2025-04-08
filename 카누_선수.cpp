#include <iostream>
#define endl '\n';

#include <vector>
#include <algorithm>
#include <limits>

#define C4 4

using namespace std;

class Canoe
{
public:
    Canoe(int k, int n) : inputs(C4, vector<int>(n)), K(k), N(n)
    {
        for (int class_num = 1; class_num <= C4; class_num++)
            for (auto &input : inputs[class_num - 1])
                cin >> input;
    }

    int findAnswer()
    {
        int answer = numeric_limits<int>::min();
        MergeClass();
        for (int cl12_idx = 0; cl12_idx < class_1_2.size(); cl12_idx++)
        {
            int cl34_idx = MatchClass12AndClass34(cl12_idx);
            int sum = class_1_2[cl12_idx] + class_3_4[cl34_idx];
            if (abs(answer - K) == abs(sum - K))
                answer = answer < sum ? answer : sum;
            else
                answer = abs(answer - K) < abs(sum - K) ? answer : sum;
        }
        return answer;
    }

private:
    int K, N;
    vector<vector<int>> inputs;
    vector<int> class_1_2;
    vector<int> class_3_4;

    void MergeClass()
    {
        for (int c1 : inputs[0])
            for (int c2 : inputs[1])
                class_1_2.push_back(c1 + c2);
        for (int c3 : inputs[2])
            for (int c4 : inputs[3])
                class_3_4.push_back(c3 + c4);
        sort(class_1_2.begin(), class_1_2.end());
        sort(class_3_4.begin(), class_3_4.end());
    }

    int MatchClass12AndClass34(int cl12_idx)
    {
        int cl34_idx;
        int target = K - class_1_2[cl12_idx];
        int upper_idx = lower_bound(class_3_4.begin(), class_3_4.end(), target) - class_3_4.begin();
        int lower_idx = upper_idx - 1;
        if (lower_idx >= 0)
        {
            int upper_sum = class_1_2[cl12_idx] + class_3_4[upper_idx];
            int lower_sum = class_1_2[cl12_idx] + class_3_4[lower_idx];

            cl34_idx = abs(upper_sum - K) < abs(lower_sum - K) ? upper_idx : lower_idx;
        }
        else
            cl34_idx = upper_idx;
        return cl34_idx;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        int k, n;
        cin >> k >> n;
        Canoe canoe(k, n);
        int answer = canoe.findAnswer();
        cout << answer << endl;
    }

    return 0;
}