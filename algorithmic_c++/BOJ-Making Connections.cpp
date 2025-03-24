#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 100001

using namespace std;

using PR = pair<int, int>;

long long tree_size[MAX_N];
int tree_depth[MAX_N];
int p[MAX_N];
int N, M;
long long tree_cnt;
long long connectivity_size;

int getParent(int a) {
    int pa = a;
    while (pa != p[pa])
        pa = p[pa];
    return pa;
}

void merge_deprecated(int a, int b) {
    int a_p = getParent(a);
    int b_p = getParent(b);
    if (a_p == b_p)
        return;

    int deep_tree = tree_depth[a_p] > tree_depth[b_p] ? a_p : b_p;
    int shallow_tree = a_p == deep_tree ? b_p : a_p;

    connectivity_size -= tree_size[deep_tree] * tree_size[deep_tree];
    connectivity_size -= tree_size[shallow_tree] * tree_size[shallow_tree];

    p[shallow_tree] = deep_tree;
    tree_size[deep_tree] += tree_size[shallow_tree];
    tree_size[shallow_tree] = 0;

    connectivity_size += tree_size[deep_tree] * tree_size[deep_tree];
    tree_depth[deep_tree] = max(tree_depth[deep_tree],tree_depth[shallow_tree]+1);
    tree_cnt--;
}

//깊이가 2이하에 있는 자식 노드를 바로 부모노드로 옮길 수 있음음
int getParentAndUpChild(int a) {
    if (a != p[a])
        p[a] = getParentAndUpChild(p[a]);
    else
        return a;
    return p[a];
}

void mergeTree(int a, int b) {
    int a_p = getParentAndUpChild(a);
    int b_p = getParentAndUpChild(b);
    if (a_p == b_p)
        return;
    
    //(a+b)^2 - (a^2 + b^2) 만큼 증가
    connectivity_size += 2 * tree_size[a_p] * tree_size[b_p];

    p[b_p] = a_p;
    tree_size[a_p] += tree_size[b_p];
    tree_size[b_p] = 0;

    
    tree_cnt--;
}

void calConnectivity() {
    // 유클리드 호제법
    long long gcd1 = connectivity_size;
    long long gcd2 = tree_cnt;
    while (gcd2 != 0) {
        long long tem = gcd1 % gcd2;
        gcd1 = gcd2;
        gcd2 = tem;
    }
    cout << connectivity_size / gcd1 << '/' << tree_cnt / gcd1 << endl;
}

int main(void) {
    cin >> N >> M;

    // init
    tree_cnt = N;
    connectivity_size = N;

    for (int i = 1; i <= N; i++) {
        tree_size[i] = 1;
        p[i] = i;
    }

    // query
    for (int i = 0; i < M; i++) {
        int command;
        cin >> command;

        if (command == 1) {
            int a, b;
            cin >> a >> b;
            mergeTree(a, b);
            // for(int i = 1;i<=N;i++)
            //     cout<<p[i]<<' ';
            // cout << endl;
        } else if (command == 2) {
            calConnectivity();
        }
    }

    return 0;
}