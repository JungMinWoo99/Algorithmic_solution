#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <array>
#define DIV 1000000007

using namespace std;

long long int POW(long long int x, long long int y)
{
    if(y == 1)
        return x;

    long long int y_half = y / 2;
    long long int y_rest = y % 2;

    long long int sub_pow = POW(x, y_half);
    long long int ret = (sub_pow * sub_pow) % DIV;

    if (y_rest == 1)
        ret = (ret * x) % DIV;

    return ret;
}

int main(void)
{
    long long int K,P, N;
    cin >> K >> P >> N;
    long long int answer = (K * POW(P,10*N))% DIV;
    cout<< answer;
    return 0;
}