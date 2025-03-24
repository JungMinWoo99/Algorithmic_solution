#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;


int main(void)
{
    int N, K;
    cin >> N >> K;
    
    vector<double> sum;
    sum.push_back(0);

    for(int i = 1;i<=N;i++)
    {
        double input;
        cin>> input;
        sum.push_back(sum[i-1]+input);
    }

    for(int i = 0;i<K;i++)
    {
        int a,b;
        cin>> a>> b;
        double sub_sum;
        sub_sum = sum[b] - sum[a-1];
        cout<< sub_sum/(b-a+1)<<endl;
    }

    return 0;
}