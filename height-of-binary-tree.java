class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class Solution {
    //Function to find the height of a binary tree.
    int height(Node node) 
    {
        if(node == null)
            return 0;
        return 1 + Math.max(height(node.left), height(node.right)); 
    }
    public static void main(String[] args){
        Node solution = new Node(1);
        Node.solution.next = new Node(2);
        Node.solution.next.next = new Node(3);
        Node.solution.next.next.next = new Node(4);
        Node.solution.next.next.next.next = new Node(5);

        System.out.println(height(solution));
    }
}