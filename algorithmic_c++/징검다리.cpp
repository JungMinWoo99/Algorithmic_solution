#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int max = 0;
    vector<int> DP(N+1);
    for(auto& i : DP)
        i = INT_MAX;
    DP[0] = 0;
    
    vector<int> input(N);
    for(int i = 0; i<N;i++)
        cin>>input[i];
    
    for(int i = 0; i < N; i++)
    {
        for(int l = i + 1; l > 0; l--)
        {
            if(DP[l-1] < input[i] && input[i] < DP[l])
                DP[l] = input[i];
        }
    }

    int answer = 0;
    while (answer + 1 < DP.size() && DP[answer + 1] != INT_MAX)
        answer++;

    cout<< answer<<endl;

    // for(int i = 0;i<DP.size();i++)
    //     cout<<DP[i]<<' ';

    return 0;
}