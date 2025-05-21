#include <iostream>
#define endl '\n'

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

<<<<<<< HEAD
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
=======
using namespace std;
using ll = long long;

constexpr ll DIV=1'000'000'007;


class Mat
{
public:
    Mat(ll n):mat(n,vector<ll>(n,0)),N(n){}

    vector<ll>& operator[](ll idx)
    {
        return mat[idx];
    }

    const vector<ll>& operator[](ll idx) const
    {
        return mat[idx];
    }

    Mat operator*(const Mat& b)
    {
        Mat ret(N);
        for(ll r = 0;r<N;r++){
            for(ll c = 0; c<N;c++){
                for(ll idx = 0;idx<N;idx++){
                    ret[r][c] += (*this)[r][idx] * b[idx][c];
                    ret[r][c] %= DIV;
                }
            }
        }
>>>>>>> 6d43c0a69f368d3c7250bbc9c8b96674ea09f933
        return ret;
    }

private:
    ll N;
<<<<<<< HEAD
    ll M;
};

=======
    vector<vector<ll>> mat;
};

Mat MatPower(const Mat& x, ll y){
    if(y == 1)
        return x;
    Mat half_pow = MatPower(x, y/2);
    Mat ret = half_pow * half_pow;
    if(y%2==1)
        ret = ret * x;
    return ret;
}

>>>>>>> 6d43c0a69f368d3c7250bbc9c8b96674ea09f933
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

<<<<<<< HEAD
    int N, M;
    cin >> N >> M;
    LOL lol(N, M);
    cout << lol.recur(N) << endl;
=======
    ll N, M;
    cin >> N >> M;

    Mat mat(M);
    mat[0][0] = 1;
    mat[0][M-1] = 1;
    for(int row = 1;row<M;row++)
        mat[row][row-1] = 1;

    Mat ret = MatPower(mat,N);
    ll answer = 0;
    for(int col = 0;col<M;col++)
        answer += ret[M-1][col];

    cout<<answer% DIV<<endl;
>>>>>>> 6d43c0a69f368d3c7250bbc9c8b96674ea09f933

    return 0;
}