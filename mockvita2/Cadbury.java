import java.util.*;


public class Cadbury {


    static int count(int l, int w){

        if(l<w){
            // swap l and w
            int t=l;
            l=w;
            w=t;
        }

        if(l<=0 || w<=0 ) return 0;

        return (l/w) + count(l%w, w); 
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
 
        int minLen = sc.nextInt() , maxLen = sc.nextInt(), minWidth = sc.nextInt(), maxWidth = sc.nextInt();

        sc.close();

        int ans =0;
        for(int l=minLen; l<=maxLen; l++){
            for(int w=minWidth; w<=maxWidth; w++){
                ans += count(l,w);
            }
        }

        System.out.println(ans);
    }
}