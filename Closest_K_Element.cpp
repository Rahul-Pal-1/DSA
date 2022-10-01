#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get_dist(int a, int b)
    {
        if (a > b)
            return a - b;        
        else
            return b - a;
    }
    
    //find index of closest integer to x
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = 0;
        int sz = arr.size();
        vector<int> res;
        
        if (x < arr[0])
            idx = 0;
        else if (x > arr[sz-1])
            idx = sz - 1;
        else
        {
            for (int i=1; i<sz; i++)
            {
                if (arr[i] == x)
                {
                    idx = i;
                    break;
                }
                else if (arr[i] > x && arr[i-1] < x)        //x isn't in the array
                {
                    int left_dist = get_dist(arr[i-1], x);
                    int right_dist = get_dist(arr[i], x);
                    if (left_dist <= right_dist)
                        idx = i-1;
                    else
                        idx = i;
                    break;
                }
            }
        }
                
        int left = idx, right = idx;
        while(--k)  //arr[idx] is one of the integers
        {
            int left_dist = left-1 >= 0 ? get_dist(arr[left-1], x) : INT_MAX;
            int right_dist = right+1 < sz ? get_dist(arr[right+1], x) : INT_MAX;
            if (left_dist <= right_dist)
                left--;
            else
                right++;
        }
        
        for (int i=left; i<=right; i++)
            res.push_back(arr[i]);
        
        return res;
    }
};

int main(){
    vector<int> a = {1,2,3,4,5};
    int k =4;
    int x=3;
    Solution obj;
    vector<int> v =  obj.findClosestElements(a,k,x);
    for(auto i: v){
        cout<<i;
    }
    return 0;
}
