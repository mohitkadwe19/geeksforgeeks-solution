class Node
{
    int data;
    Node right, left;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class GfG
{
    Node buildBalancedTree(Node root) 
    {
        if(root==null) return null;
        ArrayList<Integer>list=new ArrayList<>();
        inorder(root,list);
        return constructTree(list,0,list.size()-1);
    }
    public void inorder(Node root,ArrayList<Integer>list){
        if(root==null) return ;
        inorder(root.left,list);
        list.add(root.data);
        inorder(root.right,list);
    }
    public Node constructTree(ArrayList<Integer>list,int low,int high){
        if(low>high) return null;
        int mid=(low+high)/2;
        Node curr = new Node(list.get(mid));
        curr.left=constructTree(list,low,mid-1);
        curr.right=constructTree(list,mid+1,high);
        return curr;
    }
    public static void main(String args[]){
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root = buildBalancedTree(root);
        System.out.println(root.data);
    }
}