class Solution
{
    public int minOperation(int n)
    {
        if(n == 1){
             return 1;
        }
         
         int count = 0;
         while(n > 0){
             if(n % 2 == 0){
                n = n >> 1;
             }else{
                n -= 1; 
             }
             
             count++;
         }
         
         return count;
    }
}