#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TreeNode
{
private:
    string str;
    vector<TreeNode *> child_set;

public:
    static bool compareNode(TreeNode *compared_node1, TreeNode *compared_node2)
    {
        int compare_res=compared_node1->str.compare(compared_node2->str);
        if(compare_res<0)
            return true;
        else
            return false;
    }

    int compareString(string compared_str)
    {
        return this->str.compare(compared_str);
    }
    TreeNode(string input)
    {
        str = input;
    }

    void addChild(TreeNode *child)
    {
        child_set.push_back(child);
    }

    TreeNode *getChild(string input)
    {
        for (int i = 0; i < child_set.size(); i++)
        {
            if (child_set[i]->compareString(input) == 0)
                return child_set[i];
        }
        return NULL;
    }

    string &getString()
    {
        return this->str;
    }

    vector<TreeNode *> &getChildSet()
    {
        return this->child_set;
    }

    void sortChild()
    {
        sort(child_set.begin(), child_set.end(),compareNode);
    }
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree(vector<vector<string>> &input)
    {
        root = new TreeNode("");
        for (int i = 0; i < input.size(); i++)
        {
            TreeNode *current_node = root;
            for (int n = 0; n < input[i].size(); n++)
            {
                TreeNode *next_node = current_node->getChild(input[i][n]);
                if (next_node == NULL)
                {
                    next_node = new TreeNode(input[i][n]);
                    current_node->addChild(next_node);
                }
                current_node = next_node;
            }
        }
    }

    void sortTree(TreeNode *target)
    {
        target->sortChild();
        for (int i = 0; i < target->getChildSet().size(); i++)
            sortTree(target->getChildSet()[i]);
    }

    void sortTree()
    {
        sortTree(this->root);
    }

    void printTree(TreeNode *target, int depth = 0)
    {
        if (target != root)
        {
            for (int i = 1; i < depth; i++)
                cout << "--";
            cout << target->getString() << endl;
        }

        for (int i = 0; i < target->getChildSet().size(); i++)
            printTree(target->getChildSet()[i], depth + 1);
    }

    void printTree(){
        printTree(root);
    }
};

int main(void){
    vector<vector<string>> input;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int K;
        cin>>K;
        vector<string>* input_vector=new vector<string>;
        for(int n=0;n<K;n++){
            string input;
            cin>>input;
            input_vector->push_back(input);
        }
        input.push_back(*input_vector);
    }

    Tree main(input);
    main.sortTree();
    main.printTree();

    return 0;
}