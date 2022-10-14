#include<bits/stdc++.h>
using namespace std;

void kthSmallest(int *arr, int n, int k){
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if(i>=k){
            pq.pop();
        }
    }
    cout<<pq.top();
}

int main(){
    int arr[] = {12,2,54,6,8,21,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    kthSmallest(arr,n ,3);
    return 0;
}
