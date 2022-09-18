#include <bits/stdc++.h>
using namespace std;

bool isPossible(int *a, int n, int m, int maxpossible)
{
    int studentRequired = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxpossible < a[i])
        {
            return false;
        }

        if (a[i] + sum > maxpossible)  // if on adding we need one more student
        {
            studentRequired++;
            sum = a[i];               // we will simply put its value to sum just to add it with next one to check above property
            if (studentRequired > m)
            {
                return false;
            }
        }
        else
        {
            sum += a[i];
        }
    }
    return true;
}

int minAllocationPage(int *a, int n, int m)
{
    int ans = INT_MAX;
    int sum = 0;
    if (n < m)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int low = 0, high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(a, m, n, mid))
        {
            high = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int a[] = {12, 34, 67, 90};
    int m = 2;
    int n = 4;

    cout<<minAllocationPage(a, m, n);
    return 0;
}
