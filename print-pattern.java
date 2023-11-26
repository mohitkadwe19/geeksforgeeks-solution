import java.util.*;

class Solution {
  public List<Integer> pattern(int N) {
    ArrayList <Integer> a = new ArrayList<>();
        int q=N;
        while(q>0){
            a.add(q);
            q=q-5;
        }
        int p=q;
        while( p<=N){
            a.add(p);
            p=p+5;
            
        }
        return a;
  }
}