#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class UnionFind {
   public:
    UnionFind(int size) : p(size + 1), sub_t_size(size + 1, 1) {
        p[1] = 1;
    }

    void getAllP(int a, vector<int>& buf) {
        buf.clear();
        int pa = a;
        while (pa != p[pa]) {
            buf.push_back(pa);
            pa = p[pa];
        }
        buf.push_back(1);
    }

    int getP(int a) {
        int pa = a;
        while (pa != p[pa])
            pa = p[pa];
        return pa;
    }

    void addEdge(int p_node, int c_node) {
        p[c_node] = p_node;
        sub_t_size[p_node] += sub_t_size[c_node];
    }

    int getSubTsize(int node) {
        return sub_t_size[node];
    }

   private:
    vector<int> p;
    vector<int> sub_t_size;
};

class BinTree {
   public:
    BinTree(int size) : c(size + 1) {}

    void addEdge(int p_node, int c_node) {
        c[p_node].push_back(c_node);
    }

    int getCcnt(int t) {
        int ret = 1;
        for (int i : c[t])
            ret += getCcnt(i);
        return ret;
    }

   private:
    vector<vector<int>> c;
};

main(void) {
    int test_case;

    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int V, E, a, b;
        cin >> V >> E >> a >> b;
        cin.ignore();
        UnionFind uf(V);
        BinTree bt(V);
        for (int i = 0; i < E; i++) {
            int p, c;
            cin >> p >> c;
            uf.addEdge(p, c);
            bt.addEdge(p, c);
        }

        vector<int> pa_nodes;
        vector<int> pb_nodes;
        uf.getAllP(a, pa_nodes);
        uf.getAllP(b, pb_nodes);
        reverse(pa_nodes.begin(),pa_nodes.end());
        reverse(pb_nodes.begin(),pb_nodes.end());

        int idx = 0;
        int len = min(pa_nodes.size(), pb_nodes.size());
        while (idx + 1 < len && pa_nodes[idx + 1] == pb_nodes[idx + 1])
            idx++;
        
        cout << '#' << test_case << ' ' << pa_nodes[idx] << ' ' << bt.getCcnt(pa_nodes[idx]) << endl;
    }
    return 0;
}