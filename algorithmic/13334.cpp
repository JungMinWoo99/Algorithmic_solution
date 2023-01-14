#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compareToFirstValue(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
        return false;
    else if (a.first == b.first)
    {
        if (a.second < b.second)
            return false;
        else
            return true;
    }
    else
        return true;
}

bool compareToSecondValue(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second < b.second)
        return false;
    else if (a.second == b.second)
    {
        if (a.first > b.first)
            return false;
        else
            return true;
    }
    else
        return true;
}

struct CompareToFirstValue
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return compareToFirstValue(a, b);
    }
};

struct CompareToSecondValue
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return compareToSecondValue(a, b);
    }
};

class RailFinder
{
private:
    int rail_len;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareToSecondValue> *edge_vector;
    vector<int> max_value;

public:
    RailFinder(int rail_len, vector<pair<int, int>> &input) : rail_len(rail_len)
    {
        edge_vector = new priority_queue<pair<int, int>, vector<pair<int, int>>, CompareToSecondValue>(input.begin(), input.end());
    }

    int findMaxValue()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareToFirstValue> edge_included_rail;
        auto isLengthWithinLimit = [&edge_included_rail](int max_rail_len, pair<int, int> top)
        {
            int current_rail_len = top.second - edge_included_rail.top().first;
            if (current_rail_len <= max_rail_len)
                return true;
            else
                return false;
        };

        while (!edge_vector->empty())
        {
            pair<int, int> queue_top = edge_vector->top();
            edge_vector->pop();

            edge_included_rail.push(queue_top);

            while (!isLengthWithinLimit(this->rail_len, queue_top))
            {
                edge_included_rail.pop();
                if (edge_included_rail.empty())
                    break;
            }

            max_value.push_back(edge_included_rail.size());
        }

        return *max_element(max_value.begin(), max_value.end());
    }
};

int main(void)
{
    vector<pair<int, int>> edge_vector;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int h, o;
        cin >> h >> o;
        if (h < o)
            edge_vector.push_back(make_pair(h, o));
        else
            edge_vector.push_back(make_pair(o, h));
    }

    int d;
    cin >> d;

    RailFinder main(d, edge_vector);
    cout << main.findMaxValue();

    return 0;
}