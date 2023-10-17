class Solution{
   static ArrayList<ArrayList<Integer>> transitiveClosure(int N, int graph[][])
    {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<N; i++) {
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(graph[i][j] == 1) {
                    adj.get(i).add(j);
                }
            }
        }
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for(int i=0; i<N; i++) {
            boolean[] visited = new boolean[N];
            int[] neighbours = new int[N];
            dfs(i , adj , neighbours , visited);
            ArrayList<Integer> list = new ArrayList<>();
            for(int j=0; j<N; j++) {
                if(i == j) {
                    list.add(1);
                    continue;
                }
                list.add(neighbours[j]);
            }
            ans.add(list);
        }
        return ans;
    }
    static void dfs(int node , ArrayList<ArrayList<Integer>> adj , int[] neighbours , boolean[] visited) {
        visited[node] = true;
        for(int ele:adj.get(node)) {
            neighbours[ele] = 1;
            if(!visited[ele]) {
                dfs(ele , adj , neighbours , visited);
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int graph[][] = new int[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                graph[i][j] = sc.nextInt();
            }
        }
        ArrayList<ArrayList<Integer>> ans = transitiveClosure(N, graph);
        System.out.println(ans);   
    }
}