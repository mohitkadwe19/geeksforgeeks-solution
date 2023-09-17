
class Solution
{
    //Function to return list containing first n fibonacci numbers.
    public static long[] printFibb(int n) 
    {
      long[] fibo=new long[n];
        long a=1;
        long b=1;
        for(int i=0;i<n;i++) {
          if(i==0) {
                fibo[i]=1;
            }
            else if(i==1) {
                fibo[i]=1;
            }
            else {
                fibo[i]=a+b;
                a=b;
                b=fibo[i];
            }
        }
        return fibo;

    }
    public static void main(String[] args){
        int n=5;
        long[] ans=printFibb(n);
        for(int i=0;i<n;i++){
            System.out.println(ans[i]);
        }
    }
}