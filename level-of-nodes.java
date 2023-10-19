class Solution
{
    //Function to find the level of node X.
    int nodeLevel(int V, ArrayList<ArrayList<Integer>> adj, int X)
    {
         boolean visited[] = new boolean [V];
        Queue<Integer> q = new ArrayDeque<>();
        q.add(0);
        visited[0]= true;
        int levels = 0;
        while(q.size()>0){
            int size = q.size();
            while(size-->0){
                int currNode = q.remove();
                if(currNode == X){
                    return levels;
                }
                for(int nbr : adj.get(currNode)){
                    if(!visited[nbr]){
                        visited[nbr] = true;
                        q.add(nbr);
                    }
                }
            }
            levels++;
        }
        return -1;
    }
    public static void main(String[] args){
        Solution obj = new Solution();
        int V = 4;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<V;i++){
            adj.add(new ArrayList<>());4
        }
        adj.get(0).add(1);
        adj.get(0).add(2);
        adj.get(1).add(2);
        adj.get(2).add(0);
        adj.get(2).add(3);
        adj.get(3).add(3);
        int ans = obj.nodeLevel(V, adj, 2);
        System.out.println(ans);
    }
}