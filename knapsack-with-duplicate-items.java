class Solution{
    static int knapSack(int N, int W, int val[], int wt[])
    {
        int[] dp = new int[W + 1];
   
        for (int bagcapacity = 1; bagcapacity <= W; bagcapacity++) {
            for (int i = 0; i < N; i++) {
                if (wt[i] <= bagcapacity) {
                    int rembagcapacity=bagcapacity-wt[i];
                    int totbagcap=dp[rembagcapacity]+val[i];
                    dp[bagcapacity] = Math.max(dp[bagcapacity], totbagcap);
                }
            }
        }

        return dp[W];

    }
}