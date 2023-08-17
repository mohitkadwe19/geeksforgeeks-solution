#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> generateNextPalindrome(int num[], int n)
  {
    bool isGreater = false;
    vector<int> ans(n, 0);

    int i = 0;
    int j = n - 1;

    if (n % 2 == 0)
    {
      while (i < j)
      {
        if (num[i] > num[j] || (num[i] >= num[j] && isGreater))
        {
          isGreater = true;
        }
        else
        {
          isGreater = false;
        }

        ans[i] = num[i];
        ans[j] = ans[i];

        i++;
        j--;
      }
    }
    else
    {
      while (i <= j)
      {
        if (num[i] > num[j] || (num[i] >= num[j] && isGreater))
        {
          isGreater = true;
        }
        else
        {
          isGreater = false;
        }
        ans[i] = num[i];
        ans[j] = ans[i];

        i++;
        j--;
      }
    }
    if (isGreater == false)
    {
      i--;
      j++;
      if (ans[i] == 9)
      {
        ans[i] = 0;
        ans[j] = 0;

        i--;
        j++;
        while (ans[i] == 9 && i >= 0 && j < n)
        {
          ans[i] = 0;
          ans[j] = 0;
          i--;
          j++;
        }
      }
      if (i >= 0 && j < n)
      {

        ans[i] = ans[i] + 1;
        ans[j] = ans[i];
        isGreater = true;
      }
    }
    if (isGreater == false)
    {
      ans.push_back(1);
      ans[0] = 1;
    }

    return ans;
  }
};

int main()
{
  int numbers[] = {1, 2, 3, 4, 5};
  int n = sizeof(numbers) / sizeof(numbers[0]);
  Solution obj;
  vector<int> ans = obj.generateNextPalindrome(numbers, n);
  for (auto i : ans)
    cout << i << " ";
  return 0;
}