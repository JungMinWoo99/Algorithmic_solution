#include <iostream>
#define endl '\n'

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>

using namespace std;

struct Schedule{
    int s;
    int e;

    bool operator<(const Schedule& b) const{
        if(this->e == b.e)
            return this->s < b.s;
        return this->e < b.e;
    }

    bool IsContinuous(const Schedule& b) const{
        return this->e >= b.s || this->s <= b.e;
    }
};

class UnionFind{
public:
    UnionFind(int n):N(n),parent_list(n){
        for(int idx = 0;idx<N;idx++)
            parent_list[idx] = idx;
    }

    void FillPList(const vector<Schedule>& list, vector<vector<Schedule>>& buf){
        for(int idx = 0;idx< N;idx++){
            auto cur_sch = list[idx];
            for(int idx2 = 0;idx2<idx;idx2++){
                if(cur_sch.IsContinuous(list[idx2])){
                    MergeSet(idx, idx2);
                }
            }
        }

        
    }
private:
    int N;
    vector<int> parent_list;
    
    int GetParent(int child){
        if(child != parent_list[child])
            parent_list[child] = GetParent(parent_list[child]);
        return parent_list[child];
    }

    int MergeSet(int p, int c){
        parent_list[GetParent(c)] = parent_list[GetParent(p)];
    }
};

class MakeCalender{
public:
    int InputScheduleList(int N){
        for(int loop = 0;loop<N;loop++){
            int s, e;
            cin >> s >> e;
            input_arr.push_back({s,e});
        }
    }

    int UnionFind(){
        vector<

    }

private:
    vector<Schedule> input_arr;
    vector<Schedule> disjoint_set;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}