/*
에드 혹
B_i-1 != B_i 인 경우 A_i는 반드시 B_i-1이여야함
    => 그리고 나머지 수는 임의로 넣어도 됨
*/
#include <iostream>
#define endl '\n';

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> inputs(N);
    for(auto& input:inputs)
        cin>>input;
    
    vector<int> answer(N);
    vector<int> inputed(N+1,false);//입력한 숫자 기록
    vector<int> visited(N,false);//입력한 칸 기록

    int before = 1;
    for(int idx = 0;idx<N;idx++)
    {
        if(inputs[idx] != before)
        {
            answer[idx] = before;
            inputed[before] = true;
            visited[idx]= true;
            before = inputs[idx];
        }
    }

    int next_num = 1;
    int next_idx = 0;
    while(true)
    {
        while(visited[next_idx]&&next_idx < N) next_idx++;
        while(inputed[next_num]&&next_num <= N) next_num++;

        if(!(next_num <= N && next_num <= N))
            break;
        
        answer[next_idx] = next_num;
        visited[next_idx] = true;
        inputed[next_num] = true;
    }

    vector<int> answer_b_arr;
    vector<int> b_visited(N+2, false);
    int cur_b = 1;
    for(int ele: answer)
    {
        b_visited[ele] = true;
        while(b_visited[cur_b]&&cur_b<b_visited.size()) cur_b++;
        answer_b_arr.push_back(cur_b);
    }

    bool is_answer_b_and_inputs_same = true;
    for(int idx=0;idx<inputs.size();idx++)
        if(answer_b_arr[idx] != inputs[idx])
            is_answer_b_and_inputs_same = false;
    if(is_answer_b_and_inputs_same)
    {
        cout<<"Yes"<<endl;
        for(int ele: answer)
            cout<<ele<<' ';
    }
    else
        cout<<"No"<<endl;


    return 0;
}