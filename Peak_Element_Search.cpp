// It will return an index of a peak(which is greater than both it's adjecent ) element. If ascending first and for descending last element will be the peak element.

#include <bits/stdc++.h>
using namespace std;
int SearchpeakElement(int a[], int n)
{
    int low = 0, high = n - 1;
        if(a[low]>a[low+1]){
            return low;
        }
        if(a[high]>a[high-1]){
            return high;
        }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        if (a[mid] >= a[mid - 1] && a[mid] >= a[mid + 1]){
            return mid;
            break;
        }
        else {
            if(a[mid]<a[mid+1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
}
int main()
{
    int a[] = {10, 20, 5, 15, 25, 12};
    int n = sizeof(a) / sizeof(a[0]);
   cout<< SearchpeakElement(a, n);
    return 0;
}
