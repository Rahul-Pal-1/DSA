#include <bits/stdc++.h>
using namespace std;
void subarray(int a[], int n, int k)
{
    int sum = 0;
    pair<int, int> ans;
    int i;
    for ( i = 0; i < k; i++)
    {
        sum += a[i];
    }
    bool flag = 0;

    if (sum % 3 == 0)
    {
        ans = make_pair(0, i - 1);
        flag = 1;
    }

    for (int j = i; j < n; j++)
    {
        if (flag == 1)
        {
            break;
        }
        sum = sum + a[j] - a[j - k];

        if (sum % 3 == 0)
        {
            flag = 1;
            ans = make_pair(j - k + 1, j);
        }
    }
    if (!flag)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "sub array not found";
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << a[i] <<" ";
        }
    }
}
int main()
{
    int a[] = {84, 23, 45,12, 56, 82 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
    subarray(a, n, k);
    return 0;
}
