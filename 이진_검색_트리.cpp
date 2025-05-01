#include <iostream>
#define endl '\n'

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

struct Node
{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BSF{
public:
    BSF():cur_idx(0){
        int in;
        while(cin>>in)
            input.push_back(in);
    }

    void MakeLeftTree(Node* p_node = nullptr, int p_p_val = 1e6){
        if(p_node == nullptr)
            p_node = &this->root;
        
        p_node->val = input[cur_idx++];

        if( cur_idx < input.size() &&p_node->val > input[cur_idx])
        {
            p_node->left = new Node;
            MakeLeftTree(p_node->left, p_node->val);
        }

        if (cur_idx < input.size() &&p_p_val > input[cur_idx])
        {
            p_node->right = new Node;
            MakeRightTree(p_node->right, p_node->val);
        }
    }

    void MakeRightTree(Node* p_node, int p_p_val){
        if(p_node == nullptr)
            p_node = &this->root;
        
        p_node->val = input[cur_idx++];

        if (cur_idx < input.size() &&p_node->val < input[cur_idx])
        {
            p_node->right = new Node;
            MakeRightTree(p_node->right, p_node->val);
        }

        if( cur_idx < input.size() &&p_p_val < input[cur_idx])
        {
            p_node->left = new Node;
            MakeLeftTree(p_node->left, p_node->val);
        }
    }

    void PrintTree(Node* p_node = nullptr){
        if(p_node == nullptr)
            p_node = &this->root;

        if(p_node -> left != nullptr)
            PrintTree(p_node -> left);
        
        if(p_node -> right != nullptr)
            PrintTree(p_node -> right);
        
        cout<<p_node->val<<endl;
    }
private:
    vector<int> input;
    int cur_idx;
    Node root;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    BSF bsf;
    bsf.MakeLeftTree();
    bsf.PrintTree();

    return 0;
}