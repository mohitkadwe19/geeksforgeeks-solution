#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define MAX 1000
  vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
  {
    // Your code here
    vector<vector<int>> result;
    unordered_set<string> s;
    for (int i = 0; i < row; i++)
    {
      string str = "";
      for (int j = 0; j < col; j++)
      {
        str += to_string(M[i][j]);
      }
      if (s.find(str) == s.end())
      {
        s.insert(str);
        vector<int> v;
        for (int j = 0; j < col; j++)
        {
          v.push_back(M[i][j]);
        }
        result.push_back(v);
      }
    }
    return result;
  }
};

int main()
{
  int rows = 3, cols = 3;
  int arr[][MAX] = {{1, 1, 0}, {1, 0, 0}, {1, 1, 0}};
  Solution obj;
  vector<vector<int>> result = obj.uniqueRow(arr, rows, cols);
  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}