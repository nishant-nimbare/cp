import java.util.*;

public class invertBinary {

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
        new invertBinary().start();
    }

    public void start(){
   
        Node root =new Node(10, new Node(1,new Node(0),new Node(5)), new Node(20,new Node(15, null, new Node(16)),new Node(100)));
     
        System.out.println(root.toString(""));

        go(root);
        System.out.println("after inverting");
        System.out.println(root.toString(""));

     
    }


    public void go(Node cur){

        if(cur==null) return;

        go(cur.left);
        go(cur.right);

        Node t = cur.left;
        cur.left = cur.right;
        cur.right = t;
    }
}