import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{
    
    ArrayList<Integer> rotate(int N, int D)
    {
       ArrayList<Integer> list = new ArrayList<>();
        
        int m = D%16;
        int l = (N<<m|N>>(16-m))&65535; 
        int r = (N>>m|N<<(16-m))&65535;
        
        list.add(l);
        list.add(r);
        return list;
    }
    public static void main(String[] args){
        Solution s = new Solution();
        int N = 5;
        int D = 3;
        ArrayList<Integer> ans = s.rotate(N, D);
        System.out.println(ans);
    }
}