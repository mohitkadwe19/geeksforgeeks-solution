//User function Template for Java

class Solution{
    static long sumOfDivisors(int N){
        long long ans=0;
        for(long long i=1;i<=N;i++){
            long long times=N/i;
            ans+=(i*times);
        }
        return ans;
    }
    public static void main(String[] args){
        int N = 4;
        System.out.println(sumOfDivisors(N));
    }
}