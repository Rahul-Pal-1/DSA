// Given an array you have to find the longest subarray which is palindrome

#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(int num)
{
    int temp = 0;
    int number = num;
    while (number)
    {
        temp = temp * 10 + number % 10;
        number /= 10;
    }
    if (num == temp)
    {
        return true;
    }
    return false;
}

int palindromeSub(vector<int> a, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {

        num = num * 10 + a[i];
    }

    if (ispalindrome(num))
    {
        return 0;
    }

    for (int j = k; j < a.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + a[j];
        if (ispalindrome(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}

int main()
{
    int k = 4;
    vector<int> a = {2, 3, 5, 1, 1, 5};
    int v = palindromeSub(a, k);
    if (v == -1)
    {
        cout << "ans is not find here";
    }
    else
    {
        for (int i = v; i < v + k; i++)
        {
            cout << a[i];
        }
    }
}
