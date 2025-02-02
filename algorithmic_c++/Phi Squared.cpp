#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int idx;
    long long int size;
    Node *next = nullptr;
    Node *prev = nullptr;
};

class LL
{
public:
    LL()
    {
        start = nullptr;
        end = nullptr;
    }

    void add_node(int idx, long long int size)
    {
        Node* new_node = new Node();
        new_node->idx = idx;
        new_node->size = size;
        if(start == nullptr)
        {
            start = new_node;
            end = new_node;
        }
        else if (end == nullptr)
        {
            end = new_node;
            start->next = end;
            end->prev = start;
        }
        else
        {
            end->next = new_node;
            new_node->prev = end;
            end = new_node;
        }
    }

    void merge(Node * n1, bool with_next)
    {
        if(with_next)
        {
            auto n2 = n1->next;
            n1->size = n1->size + n2->size;
            n1->next = n2->next;
            if(n2 != end)
                n2->next->prev = n2->prev;
            else
            {
                end = n1;
                n1 -> next = nullptr;
            }
            delete n2;
        }
        else
        {
            auto n2 = n1->prev;
            n1->size = n1->size + n2->size;
            n1->prev = n2->prev;
            if(n2 != start)
                n2->prev->next = n2->next;
            else
            {
                start = n1;
                n1->prev = nullptr;
            }
            delete n2;
        }
    }

    void print_list()
    {
        Node *n = start;
        while (n != nullptr)
        {
            cout << n->idx << ':' << n->size << ' ';
            n = n->next;
        }
        cout << endl;

        n = end;
        while (n != nullptr)
        {
            cout << n->idx << ':' << n->size << ' ';
            n = n->prev;
        }
        cout << endl;
    }

    void mergeAll()
    {
        Node* node = start;
        while(start != end)
        {
            bool merge_with_next = node->next != nullptr && node->size >= node->next->size;
            bool merge_with_prev = node->prev != nullptr && node->size >= node->prev->size;
            
            if(merge_with_next)
                merge(node, true);
            
            if(merge_with_prev)
                merge(node, false);

            if(node != end)
                node = node->next; 
            else
                node = start;
        }
    }

    void print_res()
    {
        cout<<end->size<<endl;
        cout<<end->idx<<endl;
    }
private:
    Node *start;
    Node *end;
};

int main(void)
{
    LL ll;

    int N;
    cin>> N;

    for(int i = 0;i<N;i++)
    {
        int size;
        cin>>size;

        ll.add_node(i+1,size);
    }

    ll.mergeAll();
    ll.print_res();
    return 0;
}