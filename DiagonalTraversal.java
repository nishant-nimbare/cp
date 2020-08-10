import java.util.*;

class DiagonalTraversal {

    class Node{
        int val;
        Node left, right;
        Node(int v){
            this.val = v;
            this.left = null;
            this.right = null;
        }

        Node(int v, Node l, Node r){
            this.val = v;
            this.left = l;
            this.right = r;
        }

        public String toString(){
            return Integer.toString(this.val);
        }
    }

    Map<Integer, ArrayList<Node> > mmap = new TreeMap<Integer, ArrayList<Node> >();


    public static void main(String[] args){

        DiagonalTraversal mainObj = new DiagonalTraversal();       
        // mainObj.start();
        mainObj.startIter();

    }

    void start(){

        mmap.clear();

        Node root = new Node(8, new Node(3,new Node(1), null ), new Node(10, new Node(6, new Node(4), new Node(7) ), new Node(14, new Node(13), null )));

        Recur(root,0);

        for(Map.Entry mapEle : mmap.entrySet()){

            System.out.println(mapEle.getValue());
        
        }

    }

    void startIter(){
        Node root = new Node(8, new Node(3,new Node(1), null ), new Node(10, new Node(6, new Node(4), new Node(7) ), new Node(14, new Node(13), null )));

        iterative(root);
    }

    void Recur(Node root, int slope){

        // System.out.println(" - recuring for slope "+slope);
        
        if( root == null ) return;

        ArrayList<Node> cur;
        if( mmap.containsKey(slope) ){
            cur = mmap.get(slope);
        }else{
            cur = new ArrayList<Node>();
        }

        cur.add(root);
        mmap.put(slope, cur);

        Recur(root.left, slope+1);
        Recur(root.right, slope);

    }


    void iterative(Node root){

        Queue<Node> q = new LinkedList<Node>();

        q.add(root);

        while(q.size()>0){
            Node cur = q.remove();

            while(cur != null){

                if(cur.left != null) q.add(cur.left);

                System.out.print(cur.val + " ");
                cur = cur.right;
            }

        }
    }

}