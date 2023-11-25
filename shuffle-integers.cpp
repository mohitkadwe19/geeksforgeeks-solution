#include<bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void shuffleArray(int arr[], int n)
    {
        if (n == 1 || n == 2)
        {    
            return;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(arr[i]);
        }
        int even = 0, odd = 1;

        for (int i = 0; i < n / 2; i++)
        {
            arr[even] = ans[i];
            even = even + 2;
        }
        int k = (n / 2);
        for (; k < n; k++)
        {
            arr[odd] = ans[k];
            odd = odd + 2;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    ob.shuffleArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}