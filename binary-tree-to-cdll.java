import java.util.*;

class Node{
    int data;
    Node left,right;
    Node(int d){
        data=d;
        left=right=null;
    }
}
class Solution
{ 
    //Function to convert binary tree into circular doubly linked list.
    Node bTreeToClist(Node root)
    {
        ArrayList<Node> al = new ArrayList<>();
        al = inorder(root,al);
        Node head =al.get(0);
        Node last=null;
        for(int i=0;i<al.size()-1;i++){
            Node n1 =  al.get(i);
            Node n2 = al.get(i+1);
            n1.right=n2;
            n2.left=n1;
            last=n2;
        }
        head.left=last;
        last.right=head;
        
        return head;
    }
    ArrayList<Node> inorder(Node root,ArrayList<Node>al){
        if(root==null)return  al;
        
        inorder(root.left,al);
        al.add(root);
        return al= inorder(root.right,al);

    }
    
}
