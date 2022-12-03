#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    int n = points.size();
    
    priority_queue<pair<int, vector<int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        for (int j = 0; j < points[i].size(); j++)
        {
            val += points[i][j] * points[i][j];
        }
        pq.push(make_pair(val, points[i]));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<vector<int>> v;
    while (!pq.empty())
    {
        v.push_back(pq.top().second);
        pq.pop();
    }
    return v;
}


int main()
{
    vector<vector<int>> v = {
        {2, 3}, {-2, -2}};
    int k = 1;
    vector<vector<int>> ans;
    ans =  kClosest(v, k);
    for(vector<int> inner : ans){
        for(auto i : inner)
        cout << i << " ";
    }
    return 0;
}
