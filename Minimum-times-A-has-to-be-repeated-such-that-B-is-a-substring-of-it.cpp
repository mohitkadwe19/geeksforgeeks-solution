#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minRepeats(string A, string B)
  {
    string s = A;
    int moves = 1;
    while (A.size() < B.size())
    {
      A += s;
      moves++;
    }
    if (A.find(B) != -1)
    {
      return moves;
    }
    A += s;
    moves++;
    if (A.find(B) != -1)
    {
      return moves;
    }
    return -1;
  }
};

int main()
{
  string A = "abcd", B = "cdabcdab";
  Solution obj;
  cout << obj.minRepeats(A, B) << endl;
  return 0;
}