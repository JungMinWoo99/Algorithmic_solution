#include <iostream>
#define endl '\n'

#include <vector>
#include <limits>
#include <algorithm>
#include <bitset>
#include <cmath>

#define MAX_BITSET_LEN 65
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned int X;
    unsigned int K;
    cin >> X >> K;

    bitset<MAX_BITSET_LEN> X_bits(X);

    bitset<MAX_BITSET_LEN> K_bits(K);

    bitset<MAX_BITSET_LEN> answer;
    answer.reset();
    int cur_x_idx = 0;
    for(int idx = 0;idx<MAX_BITSET_LEN;idx++)
    {
        while(X_bits[cur_x_idx] == 1 && cur_x_idx<MAX_BITSET_LEN) cur_x_idx++;
        answer[cur_x_idx] = K_bits[idx];
        cur_x_idx++;
    }
    cout<<answer.to_ullong()<<endl;

    return 0;
}