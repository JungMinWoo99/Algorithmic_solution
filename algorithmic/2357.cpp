#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int min;
    int max;
    int start_idx;
    int mid_idx; //(start_idx+end_idx+1)/2
    int end_idx;
    Node *parent;
    Node *left_child;
    Node *right_child;

    void setRange(int start_idx, int end_idx)
    {
        this->start_idx = start_idx;
        this->end_idx = end_idx;
        this->mid_idx = (start_idx + end_idx + 1) / 2;
    }

    void setParent(Node *parent)
    {
        this->parent = parent;
    }

    void setChild(Node *left, Node *right)
    {
        left_child = left;
        right_child = right;
    }

    bool isLeaf()
    {
        if (end_idx - start_idx == 1)
            return true;
        else
            return false;
    }
};

class SegmentTree
{
private:
    Node *root;
    vector<int> input_vector;

public:
    SegmentTree(int input_num)
    {
        for (int i = 0; i < input_num; i++)
        {
            int input;
            cin >> input;
            input_vector.push_back(input);
        }
        initTree();
    }

    void initTree()
    {
        root = new Node;
        root->parent = NULL;
        root->setRange(0, input_vector.size());
        generateAllChild(root);
    }

    void generateAllChild(Node *parent)
    {
        if (parent->isLeaf())
        {
            parent->min = input_vector[parent->start_idx];
            parent->max = input_vector[parent->start_idx];
            return;
        }

        parent->setChild(new Node, new Node);

        parent->left_child->setRange(parent->start_idx, parent->mid_idx);
        generateAllChild(parent->left_child);

        parent->right_child->setRange(parent->mid_idx, parent->end_idx);
        generateAllChild(parent->right_child);

        parent->min = parent->left_child->min < parent->right_child->min ? parent->left_child->min : parent->right_child->min;
        parent->max = parent->left_child->max > parent->right_child->max ? parent->left_child->max : parent->right_child->max;

        return;
    }

    void printRangeMinAndMax(int start, int end)
    {
        pair<int,int> sum=findMinAndMax(start, end, root);
        cout<<sum.first<<" "<<sum.second<<endl;//제출시에는 '\n'으로
    }

    pair<int, int> findMinAndMax(int start, int end, Node *current_node)
    {
        if (current_node->start_idx == start && current_node->end_idx == end) 
            return make_pair(current_node->min, current_node->max);
        
        if (end <= current_node->mid_idx)
            return findMinAndMax(start, end, current_node->left_child);
        else if (start >= current_node->mid_idx)
            return findMinAndMax(start, end, current_node->right_child);
        else
        {
            pair<int, int> compare_pair1 = findMinAndMax(start, current_node->mid_idx, current_node->left_child);
            pair<int, int> compare_pair2 = findMinAndMax(current_node->mid_idx, end, current_node->right_child);

            int min = compare_pair1.first < compare_pair2.first ? compare_pair1.first : compare_pair2.first;
            int max = compare_pair1.second > compare_pair2.second ? compare_pair1.second : compare_pair2.second;
            return make_pair(min, max);
        }
    }
};

int main(void){
    int N,M;
    cin>>N>>M;
    SegmentTree main(N);
    for(int i=0;i<M;i++){
        int start,end;
        cin>>start>>end;
        main.printRangeMinAndMax(start-1,end);
    }
    
    return 0;
}