#include <iostream>
#define endl '\n';

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

/*
idx번째 자릿수에서의 자리합을 구해보자
숫자를 Aa_idxB로 보면 idx번째 자릿수에서의 자리합은 다음과 같다
A*10^(B.len)*45 + 10^(B.len)*sum(0~(a_idx-1)) + a_idx*(B-1)
*/

using ll = long long;

ll power10(int y)
{
    ll ret = 1;
    for (int i = 0; i < y; i++)
        ret *= 10LL;
    return ret;
}

ll calSum(int num)
{
    ll sum = 0;
    for (int v = 0; v <= num; v++)
        sum += v;
    return sum;
}

ll CalA(int idx, vector<ll> &digits)
{
    ll A = 0;
    for (int i = digits.size() - 1; i > idx; i--)
    {
        A *= 10LL;
        A += digits[i];
    }
    return A;
}

ll CalB(int idx, vector<ll> &digits)
{
    ll B = 0;
    for (int i = idx - 1; i > -1; i--)
    {
        B *= 10LL;
        B += digits[i];
    }
    return B;
}

ll CalDigitSum(ll num)
{
    vector<ll> digits;
    while (num != 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    ll digits_sum = 0;

    for (int idx = 0; idx < digits.size(); idx++)
    {
        ll A = CalA(idx, digits);
        ll B = CalB(idx, digits);
        ll sum_a_idx = calSum(digits[idx] - 1LL);
        ll B_len = idx;

        digits_sum += A * power10(B_len) * 45LL + power10(B_len) * sum_a_idx + digits[idx] * (B + 1LL);
    }

    return digits_sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 0)
            a = 1LL;
        ll answer = CalDigitSum(b) - CalDigitSum(a - 1LL);
        cout << answer << endl;
    }

    return 0;
}