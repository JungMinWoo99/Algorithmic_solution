#include <iostream>
#define endl '\n';

#include <vector>
#include <limits>
#include <algorithm>

#include <unordered_map>
#include <bitset>
#include <string>

using namespace std;

#define ALPHABET_NUM 26

unordered_map<unsigned long ,unsigned int> counter;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<bitset<ALPHABET_NUM>> inputs;
    
    int N;
    cin>>N;
    for(int in_cnt = 0;in_cnt<N;in_cnt++)
    {
        string input;
        cin >>input;
        bitset<ALPHABET_NUM> input_bits;
        for(char alpa: input)
            input_bits.set(int(alpa-'a'));
        inputs.push_back(input_bits);
    }

    counter[0] = 1;
    for(auto& input: inputs)
    {
        for(auto& pair: counter)
        {
            bitset<ALPHABET_NUM> bits();
            counter[pair.first|input.to_ulong()] += pair.second;
        }
    }

    bitset<ALPHABET_NUM> answer;
    answer.set();
    cout<<counter[answer.to_ulong()]<<endl;

    return 0;
}