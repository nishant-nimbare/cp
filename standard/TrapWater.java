import java.util.*;
import java.util.stream.Collectors; 

public class TrapWater {

    int trap(List<Integer> walls){

        /**
        
        for every element in arr, we find the highest wall on its left and right 
        water trapped on this wall will be of height min (leftMax , rightMax);
        
        we take 2 arrs : left[] and right[]

        time : 0(n) space : 0(n) 
         */ 
        int msize = walls.size();
        int left[] = new int[msize];
        int right[] = new int[msize];

        left[0] = walls.get(0);
        right[msize-1] = walls.get(msize-1);

        for(int i=1; i<msize;i++){
            left[i] = Math.max(left[i-1], walls.get(i));
        }

        for(int i=msize-2; i>=0;i--){
            right[i] = Math.max(right[i+1], walls.get(i));
        }


        int total = 0;

        for(int i=1; i<msize;i++){
            System.out.println("adding "+i+" : "+Math.max(0, ( Math.min(left[i],right[i]) - walls.get(i) ) ));
            total += Math.max(0, ( Math.min(left[i],right[i]) - walls.get(i) ) );
        }        

        return total;
    }



    public static void main(String[] args){

        TrapWater mainObj = new TrapWater();       
        mainObj.start();
    }

    public void start(){

        Scanner sc = new Scanner(System.in);
        String ip = sc.nextLine();

        List<Integer> walls  = Arrays.stream(ip.split(" ")).map(s -> Integer.parseInt(s)).collect(Collectors.toList());

        for(int w : walls){
            System.out.print(w);
        }
        System.out.println(' ');

        System.out.println( trap(walls) );    

    }


}
