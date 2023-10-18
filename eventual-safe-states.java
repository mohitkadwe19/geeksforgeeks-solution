class Solution {

    List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {
     //Your code here
        List<Integer> res=new ArrayList<>();
        boolean[] visit=new boolean[V];
        for(int i=0;i<V;i++){
            if(!isCycle(i,adj,visit)){
                res.add(i);
            }
        }
        return res;
    }
    private static boolean isCycle(int source,List<List<Integer>> adj,boolean[] visit){
       
        visit[source]=true;
        
        for(Integer it:adj.get(source)){
            if(!visit[it]){
                if(isCycle(it,adj,visit)) return true;
            }else return true;
    
        }
        visit[source]=false;
        return false;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        List<List<Integer>> adj = new ArrayList<>();
        List<Integer> a = new ArrayList<>();
        a.add(1);
        a.add(2);
        a.add(3);
        adj.add(a);
        System.out.println(s.eventualSafeNodes(4, adj));
    }
}
