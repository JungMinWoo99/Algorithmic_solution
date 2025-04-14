#include <iostream>
#include <fstream>
#define endl '\n'

#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>

#include <type_traits>

using namespace std;

template <int s, int k, int i>
struct CalVal;

template <int n>
struct Answer;

template <int s, int n>
struct LoopS;

template <int s, int k, int n>
struct LoopK;

template <int s, int k, int i>
struct LoopI;

template <int n>
struct Answer
{
    static const int val = LoopS<n, n>::val;
};

template <int s, int n>
struct LoopS
{
    static const int val = (LoopS<s - 1, n>::val + LoopK<s, n, n>::val) % 2010;
};

template<int n>
struct LoopS<1,n>
{
    static const int val = LoopK<1, n, n>::val % 2010;
};


template <int s, int k, int n>
struct LoopK
{
    static const int val = (LoopK<s, k - 1, n>::val + LoopI<s, k, n>::val) % 2010;
};

template<int s, int n>
struct LoopK<s,s,n>
{
    static const int val = LoopI<s, s, n>::val;
};

template <int s, int k, int i>
struct LoopI
{
    static const int val = (LoopI<s, k, i - 1>::val + CalVal<s, k, i>::val) % 2010;
};

template <int s, int k>
struct LoopI<s,k,k>
{
    static const int val = CalVal<s,k,k>::val;
};

template <int s, int k, int i>
struct CalVal
{
    static const int val = (s * k / i) % 2010;
};

constexpr int calc(int n) {
    int ret = 0;
    for (int s = 1; s <= n; ++s)
        for (int k = s; k <= n; ++k)
            for (int i = k; i <= n; ++i)
                ret = (ret + s * k / i) % 2010;
    return ret;
}


int answer_arr[] = {
    0,
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    cout<<answer_arr[n]<<endl;

    return 0;
}