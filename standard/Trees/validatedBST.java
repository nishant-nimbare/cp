import java.util.*;

// left subtree contains strictly less valued nodes
// right subtree contain less than or equal valued node [to parent]

public class validatedBST {

    public class Node{
        Node left, right;
        int val;
        
        public Node(int v){
            this.left = null;
            this.right = null;
            this.val = v;
        }
        
        public Node(int v, Node l, Node r ){
            this.left = l;
            this.right = r;
            this.val = v;
        }

        public String toString(String p){
            String res =  Integer.toString(val)+"\n";
            p += "   ";
            if(left!=null){
                res += p+"|- "+left.toString(p);
            }


            if(right!=null){
                res += p+"|_" + right.toString(p);
            }

            return res;
        }
    }

    public static void main(String[] args){
        new validatedBST().start();
    }

    public void start(){
   
        Node root =new Node(10, new Node(1,new Node(101),new Node(5)), new Node(20,new Node(15, null, new Node(16)),new Node(100)));
        System.out.println(root.toString(""));
     
        if(go(root, -100000, 100000)){
            System.out.println(" Is BST!!");
        }else{
            System.out.println(" Not  BST!!");
        }

    }


    public boolean go(Node cur, int l, int r){

        if(cur == null) return true;

        if( l>cur.val || cur.val>=r) return false;

        if(!go(cur.left, l, cur.val)) return false;

        if(!go(cur.right, cur.val, r)) return false;

        return true;
    }
}