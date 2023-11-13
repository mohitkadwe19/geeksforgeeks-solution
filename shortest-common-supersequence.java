class Solution {
  // Function to find length of shortest common supersequence of two strings.
  public static int shortestCommonSupersequence(String X, String Y, int m, int n) {
    
    // code here
    int[][] dp = new int[m + 1][n + 1];
    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(X.charAt(i - 1) == Y.charAt(j - 1)){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int lcs = dp[m][n];
    return m + n - lcs;
    
  }
}