class Node
{
	int data;
	Node left,right;
	
	Node(int d)
	{
		data = d;
		left = right = null;		
	}
} 

class Tree
{

  boolean isBalance=true;
  public int findHeight(Node root)
    {
        if(root==null)
        {
            return 0;
        }
        
        int leftHeight=findHeight(root.left);
        int rightHeight=findHeight(root.right);
        
        int height=leftHeight>rightHeight?leftHeight+1:rightHeight+1;
        
        int diff=Math.abs(leftHeight-rightHeight);
        if(diff>1)
        {
            isBalance=false;
        }
        
        return height;
    }
    //Function to check whether a binary tree is balanced or not.
    boolean isBalanced(Node root)
    {
	            int leftHeight=findHeight(root.left);
        int rightHeight=findHeight(root.right);
        int diff=Math.abs(leftHeight-rightHeight);
        if(diff<=1 && isBalance)
        {
            return true;
        }else{
            return false;
        }

    }
}
