#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long;

class CandyBag
{
public:
    CandyBag(ll N, ll M) : N(N), M(M) {}

    void inputCandy()
    {
        max_candy = 0;
        for (int loop = 0; loop < N; loop++)
        {
            ll in;
            cin >> in;
            max_candy = max(max_candy,in);
            A.push_back(in);
        }
    }

    ll getMaxBags()
    {
        ll ret =  0;
        ll lo = 1, hi = max_candy;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (canMakeBags(mid))
            {
                ret = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        return ret;
    }

private:
    ll N, M;
    ll max_candy;
    vector<ll> A;
    bool canMakeBags(ll mid)
    {
        ll bag_size = 0;
        for (ll a : A)
            bag_size += a / mid;
        return bag_size >= M;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        ll N, M;
        cin >> N >> M;
        CandyBag candy_bag(N, M);
        candy_bag.inputCandy();

        ll answer = candy_bag.getMaxBags();
        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}
