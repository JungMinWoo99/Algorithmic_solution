#include <iostream>
#define endl '\n'

#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>

using namespace std;

class CardGame
{
public:
    void InputTestCase(int N)
    {
        input_size = N;
        for(int i = 0;i<N;i++)
        {
            int a;
            cin >> a;
            input.push_back(a);
        }
    }
private:
    int input_size;
    vector<int> input;
    vector<int> suffix_sum;
    vector<vector<int>> DP;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}