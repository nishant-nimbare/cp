import java.util.*;


public class swayamwar {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());
        
        String brideStr = sc.nextLine();
        String groomStr = sc.nextLine();

        Queue<Character> groom = new LinkedList<Character>();

        for(int c=0; c<groomStr.length(); c++){
            groom.add(groomStr.charAt(c));
        }

        int b=0, g=0, bcount=0;
        while(b<brideStr.length()){
            
            // System.out.println(b+" -> "+groom);

            if(brideStr.charAt(b) == groom.peek()){
            
                b++;
                groom.remove();
                bcount=0;
            }else{

                groom.add(groom.peek());
                groom.remove();
                bcount++;

                if(bcount > groom.size()){
                    break;
                }
            }            
        }

        System.out.println(groom.size());
    }
}