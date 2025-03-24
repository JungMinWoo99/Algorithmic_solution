#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

struct Node
{
    int a_max;//지금만들고 있는 요리의 최고점
    int b_max;//지금까지 완성된 최고의 요리
};


int main(void)
{
    int n;
    cin>> n;
    vector<int> input_arr;
    for(int i = 0;i<n;i++)
    {
        int l;
        cin>>l;
        input_arr.push_back(l);
    }

    vector<Node> forward_dp(n);
    vector<Node> backward_dp(n);

    forward_dp[0].a_max = input_arr[0];
    forward_dp[0].b_max = input_arr[0];
    for(int i = 1; i<n;i++)
    {
        int next=input_arr[i];
        Node dp=forward_dp[i-1];

        //만들던 요리에 재료를 추가하는 것과 요리를 새로 만드는 것 중 더 좋은 경우를 채택
        int next_a = max(dp.a_max + next, next);
        //지금까지 만들었던 최고의 요리와 현재 요리를 비교
        int next_b = max(dp.b_max, next_a);

        forward_dp[i].a_max = next_a;
        forward_dp[i].b_max = next_b;
    }


    backward_dp[n-1].a_max = input_arr[n-1];
    backward_dp[n-1].b_max = input_arr[n-1];
    for(int i = n-2; i>-1;i--)
    {
        int next=input_arr[i];
        Node dp=backward_dp[i+1];

        //만들던 요리에 재료를 추가하는 것과 요리를 새로 만드는 것 중 더 좋은 경우를 채택
        int next_a = max(dp.a_max + next, next);
        //지금까지 만들었던 최고의 요리와 현재 요리를 비교
        int next_b = max(dp.b_max, next_a);

        backward_dp[i].a_max = next_a;
        backward_dp[i].b_max = next_b;
    }
    
    int answer = INT_MIN;
    for(int i = 1;i<n-1;i++)
        answer = max(forward_dp[i-1].b_max + backward_dp[i+1].b_max, answer);
    cout<< answer<<endl;;

    // for(Node i: forward_dp)
    //     cout<< i.b_max<<' ';
    //     cout<<endl;
    // for(Node i: backward_dp)
    //     cout<< i.b_max<<' ';
    return 0;
}