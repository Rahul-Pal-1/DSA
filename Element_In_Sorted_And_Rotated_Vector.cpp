#include <bits/stdc++.h>
using namespace std;

int Search(vector<int> vec, int target) {
     int n = vec.size();
    
    int low = 0, high = n-1, ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(target == vec[mid]){
                ans = mid;
                break;
            }

            if(vec[low] <= vec[mid]){
                if(vec[low] <= target && target <= vec[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(vec[mid] < vec[high]){
                    if(vec[mid] <= target && target <= vec[high]){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
            }
        }
        return ans;
}
int main()
{
    vector<int> a= {5, 6, 7, 8, 9, 10, 1, 2, 3};
   
    int k = 10;
    cout <<Search(a, k);
    return 0;
}
