#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void Rearrange(int arr[], int n)
  {
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] < 0)
      {
        v1.push_back(arr[i]);
      }
      else
      {
        v2.push_back(arr[i]);
      }
    }
    v1.insert(v1.end(), v2.begin(), v2.end());

    for (int i = 0; i < n; i++)
    {
      arr[i] = v1[i];
    }
  }
};

int main()
{
  int N = 4;
  int arr[] = {-3, 3, -2, 2};
  Solution ob;
  ob.Rearrange(arr, N);
  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}