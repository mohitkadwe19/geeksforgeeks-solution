class Solution
{
    //Function to find the nodes that are common in both BST.
    public static boolean search(Node root, int key){
        if(root==null)return false;
        
        if(root.data==key){
            return true;
        }
        if(root.data>key){
            return search(root.left,key);
        }else{
            return search(root.right,key);
        }
    }  
	public static ArrayList<Integer> findCommon(Node root1,Node root2)
    {
          Queue<Node> q = new LinkedList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        q.add(root1);
        
        while(!q.isEmpty()){
            Node curr = q.poll();
            if(search(root2,curr.data)){
                ans.add(curr.data);
            }
            if(curr.left!=null){
                q.add(curr.left);
            }
            if(curr.right!=null){
                q.add(curr.right);
            }
        }
        Collections.sort(ans);
        return ans;

    }
  public static void main(String[] args){
    Node solution = new Node(1);
    Node.solution.next = new Node(2);
    Node.solution.next.next = new Node(3);
    Node.solution.next.next.next = new Node(4);
    Node.solution.next.next.next.next = new Node(5);
    Node solution1 = new Node(1);
    Node.solution1.next = new Node(2);
    Node.solution1.next.next = new Node(3);
    Node.solution1.next.next.next = new Node(4);
    Node.solution1.next.next.next.next = new Node(5);
    ArrayList<Integer> ans = findCommon(solution,solution1);
    System.out.println(ans);
  }
}