#include <bits/stdc++.h>
using namespace std;

int isPossible(int *a, int n, int m, long long maxpossible)
{
    
    int painterRequired = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > maxpossible) // if on adding we need one more student
        {
            painterRequired++;

            sum = a[i];
        }
    }
    return painterRequired;
}

long long minTime(int arr[], long n, long m)
{
    long long sum = 0;
    // if (n < m)
    // {
    //     return arr[0];
    // }
    int low = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = max(low, arr[i]);
        sum += arr[i];
    }
    long long high = sum;
    while (low < high) // we are not required to check if they are equal as our low will be the ans
    {
        long long mid = (low + high) / 2;
        long long painters = isPossible(arr, n, m, mid);

        if (painters <= m )
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int a[] = {8, 18, 10, 22, 19, 13, 17};
    int m = 8;
    int n = 7;

    cout << minTime(a, n, m);
    return 0;
}
