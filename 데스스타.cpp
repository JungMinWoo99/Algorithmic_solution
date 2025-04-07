#include <iostream>
#define endl '\n';

#include <vector>
#include <deque>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    vector<vector<unsigned int>> input_mat(N,vector<unsigned int>(N));
    for(auto& row:input_mat)
        for(auto& ele: row)
            cin >> ele;
    
    vector<int> answer(N, numeric_limits<unsigned int>::min());
    for(int idx = 0;idx<N;idx++)
        for(int idx2 = 0;idx2<N;idx2++)
            if(idx != idx2)
                answer[idx] |= input_mat[idx][idx2];

    for(auto val: answer)
        cout<<val<<' ';

    return 0;
}