#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void add(int product, int pos, int arr[], int size)
  {
    if (product == 0 || pos >= size)
      return;
    int carry = 0;
    if (product >= 10)
    {
      carry = product / 10;
      product %= 10;
    }
    arr[pos] += product;
    if (arr[pos] >= 10)
    {
      carry += arr[pos] / 10;
      arr[pos] %= 10;
    }
    add(carry, pos + 1, arr, size);
  }

  string multiplyStrings(string str1, string str2)
  {
    int start1, start2;
    start1 = 0;
    start2 = 0;
    string ans = "";
    bool neg = false;
    if (str1[start1] == '-')
    {
      if (str2[start2] == '-')
      {
        start1++;
        start2++;
      }
      else
      {
        neg = true;
        start1++;
      }
    }
    else if (str2[start2] == '-')
    {
      neg = true;
      start2++;
    }
    while (str1[start1] == '0')
      start1++;
    while (str2[start2] == '0')
      start2++;

    int n1 = str1.size();
    int n2 = str2.size();

    int arr[n1 + n2];
    for (int i = 0; i < n1 + n2; i++)
      arr[i] = 0;

    for (int i = n1 - 1; i >= start1; i--)
    {
      int x = str1[i] - '0';
      for (int j = n2 - 1; j >= start2; j--)
      {
        int y = str2[j] - '0';
        int pos = (n1 + n2 - 2) - i - j;
        int p = x * y;
        add(p, pos, arr, n1 + n2);
      }
    }

    int j = n1 + n2 - 1;
    while (arr[j] == 0)
      j--;

    if (neg == true)
      ans += '-';
    for (int i = j; i >= 0; i--)
    {
      ans += (char)(arr[i] + '0');
    }

    return ans;
  }
};

int main()
{
  string s1 = "0033";
  string s2 = "2";
  Solution obj;
  cout << obj.multiplyStrings(s1, s2) << endl;
  return 0;
}