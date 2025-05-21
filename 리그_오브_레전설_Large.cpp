#include <iostream>
#define endl '\n'

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

#define DIV 1'000'000'007

using namespace std;
using ll = unsigned long long;
class LOL
{
public:
    LOL(int n, int m) : N(n), M(m) {}

    ll recur(int len)
    {
        if (len < 2 * M)
            return len >= M ? len - M + 2 : 1;

        ll ret = 0;
        bool is_len_odd = false;
        if (len % 2 == 1)
        {
            is_len_odd = true;
            len--;
        }

        ll DaQ = recur(len / 2) % DIV;
        ret += (DaQ * DaQ) % DIV;

        // 경계에 B 스킬을 배치하는 경우
        for (ll splited_b = 1; splited_b <= (M + 1) / 2; splited_b++)
        {
            ll DaQ1 = recur(len / 2 - splited_b) % DIV;
            ll DaQ2 = recur(len / 2 - (M - splited_b)) % DIV;
            if (splited_b != (M - splited_b))
                ret = (ret + 2 * DaQ1 * DaQ2 % DIV) % DIV;
            else
                ret = (ret + DaQ1 * DaQ2 % DIV) % DIV;
        }

        if (is_len_odd)
            ret *= 2;
        return ret;
    }

private:
    ll N;
    ll M;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    LOL lol(N, M);
    cout << lol.recur(N) << endl;

    return 0;
}