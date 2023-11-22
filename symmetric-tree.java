class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

// complete this function
// return true/false if the is Symmetric or not
class GfG
{
   public static boolean isSymmetric(Node root)
    {
        // add your code here;
        if(root==null) return true;
        return mImage(root.left,root.right);
    }
    
    static boolean mImage(Node a, Node b){
        if(a==null && b==null) return true;
        if(a==null || b==null || a.data!=b.data) return false;
        return mImage(a.left,b.right) && mImage(a.right,b.left);
    }

}