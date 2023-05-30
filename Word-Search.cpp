#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

  bool cal(int i, int j, vector<vector<char>> &board, string word, int k, vector<vector<int>> &vis)
  {

    if (k == word.length())
      return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j])
      return false;

    vis[i][j] = 1;

    bool ans = false;

    for (int l = 0; l < 4; l++)
    {

      if (board[i][j] == word[k])
        ans = ans | cal(i + dx[l], j + dy[l], board, word, k + 1, vis);
    }

    return ans;
  }

  bool isWordExist(vector<vector<char>> &board, string word)
  {
    // Code here
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && board[i][j] == word[0])
        {
          bool ans = cal(i, j, board, word, 0, vis);
          if (ans)
            return true;
        }
      }
    }

    return false;
  }
};

int main()
{
  vector<vector<char>> board = {{'g', 'i', 'z'},
                                {'u', 'e', 'k'},
                                {'q', 's', 'e'}};
  string word = "geeks";
  Solution obj;
  cout << obj.isWordExist(board, word) << endl;
}