class Solution
{
    
    public int is_bleak(int n)
    {
        for(int x= n-1;x>=n-32;x--){
            if(x+countSetBits(x) == n) 
                    return 0;
            }     
        return 1;
    }
    
    private int countSetBits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

}