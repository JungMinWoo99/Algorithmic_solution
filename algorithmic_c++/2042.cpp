#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Node
{
public:
    long long value;
    /**
     * @brief
     * 자신의 범위:[start,end)
     * 왼쪽 자식의 범위:[start, mid)
     * 오른쪽 자식의 범위:[mid,end)
     */
    int start_idx;
    int mid_idx; //(start_idx+end_idx+1)/2
    int end_idx;
    Node *parent;
    Node *left_child;
    Node *right_child;

    Node():value(0){}

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
    vector<long long> input_vector;

public:
    SegmentTree(int input_num)
    {
        for (int i = 0; i < input_num; i++)
        {
            long long input;
            cin >> input;
            input_vector.push_back(input);
        }
        initTree();
    }

    void initTree()
    {
        root=new Node;
        root->parent = NULL;
        root->setRange(0, input_vector.size());
        for (int i = root->start_idx; i < root->end_idx; i++)
            root->value += input_vector[i];
        generateAllChild(root);
    }

    void generateAllChild(Node *parent)
    {
        if (parent->isLeaf())
            return;

        parent->setChild(new Node, new Node);

        parent->left_child->setRange(parent->start_idx, parent->mid_idx);
        for (int i = parent->left_child->start_idx; i < parent->left_child->end_idx; i++)
            parent->left_child->value += input_vector[i];
        parent->left_child->setParent(parent);
        generateAllChild(parent->left_child);

        parent->right_child->setRange(parent->mid_idx, parent->end_idx);
        for (int i = parent->right_child->start_idx; i < parent->right_child->end_idx; i++)
            parent->right_child->value += input_vector[i];
        parent->right_child->setParent(parent);
        generateAllChild(parent->right_child);

        return;
    }

    void changeLeafValue(int idx, long long value)
    {
        input_vector[idx] = value;
        Node *leaf = findLeaf(idx);
        long long difference = value - leaf->value;
        leaf->value = value;
        updateParent(leaf, difference);
    }

    Node *findLeaf(int idx)
    {
        Node *current_node = root;
        while (!current_node->isLeaf())
        {
            if (idx < current_node->mid_idx)
                current_node = current_node->left_child;
            else
                current_node = current_node->right_child;
        }
        return current_node;
    }

    void updateParent(Node *leaf, long long &difference)
    {
        for (Node *parent = leaf->parent; parent != NULL; parent = parent->parent)
            parent->value += difference;
    }

    void printRangeSum(int start, int end)
    {
        long long sum;
        sum = calulateRangeSum(start, end, root);
        cout<<sum<<endl;
    }

    long long calulateRangeSum(int start, int end, Node *current_node)
    {
        if (current_node->start_idx == start && current_node->end_idx == end)
            return current_node->value;
        if (end <= current_node->mid_idx)
            return calulateRangeSum(start, end, current_node->left_child);
        else if (start >= current_node->mid_idx)
            return calulateRangeSum(start, end, current_node->right_child);
        else
            return calulateRangeSum(start, current_node->mid_idx, current_node->left_child) + calulateRangeSum(current_node->mid_idx, end, current_node->right_child);
    }
};

int main(void)
{
    int N, M, K;
    cin >> N >> M >> K;
    SegmentTree main(N);
    for(int i=0;i<M+K;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        if(a==1)
            main.changeLeafValue(b-1,c);
        else if(a==2)
            main.printRangeSum(b-1,c);
    }
    return 0;
}
