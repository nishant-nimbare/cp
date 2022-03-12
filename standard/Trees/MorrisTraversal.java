// https://www.youtube.com/watch?v=wGXB9OWhPTg
import java.util.*;

public class MorrisTraversal {

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
        new MorrisTraversal().start();
    }


    public void start(){

        Node root =new Node(10, new Node(1,new Node(0),new Node(5)), new Node(20,new Node(15, null, new Node(16)),new Node(100)));

        System.out.println(root.toString(""));

        System.out.println("Inorder...");
        this.inOrder(root);

        System.out.println("################################");
        System.out.println("preorder...");
        this.preOrder(root);
    }


    public void inOrder(Node root){
        Node cur = root;

        while(cur!=null){
            //System.out.print(" -cur"+cur.val+"- ");
            if(cur.left == null){
                System.out.println(cur.val+ " ");
                cur = cur.right;
            }else{
                // find rightmost child in left subtree
                Node temp = cur.left;
                while(temp.right != null && temp.right != cur){
                    //System.out.print(" -temp"+temp.val+"- ");
                    temp = temp.right;
                }
                    //System.out.print(" -temp"+temp.val+"- ");

                if(temp.right == null){
                    // create link between cur and temp
                    //System.out.print(" -link "+temp.val+" -> "+ cur.val);
                    temp.right = cur;
                    cur = cur.left;
                }else{

                    // we have already traversed the left subtree
                    // remove the link and print cur
                    //System.out.print(" -unlink "+temp.val+" -> "+ cur.val);
                    temp.right = null;
                    System.out.println(cur.val+ " ");
                    cur = cur.right;
                }
            }
            // if(cur == null)//System.out.print(" -next null- ");
            // else //System.out.print(" -next"+cur.val+"- ");
        }
    }

    public void preOrder(Node root){
        Node cur = root;

        while(cur!=null){
            //System.out.print(" -cur"+cur.val+"- ");
            if(cur.left == null){
                System.out.println(cur.val+ " ");
                cur = cur.right;
            }else{
                // find rightmost child in left subtree
                Node temp = cur.left;
                while(temp.right != null && temp.right != cur){
                    //System.out.print(" -temp"+temp.val+"- ");
                    temp = temp.right;
                }
                    //System.out.print(" -temp"+temp.val+"- ");

                if(temp.right == null){
                    // create link between cur and temp
                    //System.out.print(" -link "+temp.val+" -> "+ cur.val);
                    System.out.println(cur.val+ " ");
                    temp.right = cur;
                    cur = cur.left;

                }else{

                    // we have already traversed the left subtree
                    // remove the link and print cur
                    //System.out.print(" -unlink "+temp.val+" -> "+ cur.val);
                    temp.right = null;
                    cur = cur.right;
                }
            }
            // if(cur == null)//System.out.print(" -next null- ");
            // else //System.out.print(" -next"+cur.val+"- ");
        }
    }


}