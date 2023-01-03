#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the smallest positive number missing from the array.
  int missingNumber(int arr[], int n)
  {
    sort(arr, arr + n);
    int missing = 1;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == missing)
        missing++;
    }
    return missing;
  }
};

int main()
{

  int N = 5, arr[] = {1, 2, 3, 4, 5};

  Solution ob;
  cout << ob.missingNumber(arr, N) << endl;

  return 0;
}