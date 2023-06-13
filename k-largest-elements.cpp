#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> kLargest(int arr[], int n, int k)
  {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
      minHeap.push(arr[i]);
      if (minHeap.size() > k)
      {
        minHeap.pop();
      }
    }
    vector<int> result;
    while (!minHeap.empty())
    {
      result.push_back(minHeap.top());
      minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main()
{
  int N = 5, K = 2;
  int arr[] = {12, 5, 787, 1, 23};
  Solution obj;
  vector<int> result = obj.kLargest(arr, N, K);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}