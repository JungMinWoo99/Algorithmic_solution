/*
풀이 방법
길이를 기준으로 막대 정보를 정렬하고 첫 막대를 시작으로 막대를 순차적으로 탐색
    => 매 순간 처리할 수 있는 막대를 바로바로 처리
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#include <queue>
#include <deque>
#include <stack>

using namespace std;

struct Stick
{
    int l;
    int w;

    Stick(int l, int w):l(l),w(w){}

    bool operator<(const Stick& b) const{
        if(this->l==b.l)
            return this->w <b.w;
        return this->l<b.l;
    }
};

int main()
{
    int T;
    cin >> T;
    for(int tc = 0;tc<T;tc++)
    {
        int n;
        cin>> n;

        vector<Stick> sticks;
        for(int i = 0;i<n;i++)
        {
            int l, w;
            cin >>l >> w;
            sticks.emplace_back(l,w);
        }
        sort(sticks.begin(), sticks.end());

        queue<int> w_values;
        for(auto stick:sticks)
            w_values.push(stick.w);

        int cnt =0;
        while(!w_values.empty())
        {
            stack<int> processed_sticks;
            int que_size = w_values.size();
            for(int loop = 0;loop<que_size;loop++)
            {
                int front = w_values.front();
                w_values.pop();
                if(processed_sticks.empty() || processed_sticks.top() <= front)
                    processed_sticks.push(front);
                else
                    w_values.push(front);
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}