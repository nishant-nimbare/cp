import java.util.*;

public class Pairs {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.nextLine());

        String[] nums = sc.nextLine().split("\\s+");


        HashMap <Character, Integer> even = new HashMap <Character, Integer> ();
        HashMap <Character, Integer> odd = new HashMap <Character, Integer> ();

        for(int i=0; i<n; i++){
            
            char min=nums[i].charAt(0), max=nums[i].charAt(0);

            for(int c =0; c<nums[i].length(); c++){

                if( min > nums[i].charAt(c) ) min = nums[i].charAt(c);

                if( max < nums[i].charAt(c) ) max = nums[i].charAt(c);
            }

            int temp = Character.getNumericValue(max)*11 + Character.getNumericValue(min)*7;
            
            String tempStr = Integer.toString(temp);

            char cur = tempStr.charAt( tempStr.length()-2);

            if(i%2==0){
                even.put(cur, even.get(cur)+1);
            }else{
                odd.put(cur, odd.get(cur)+1);
            }
        }

        int ans =0;

        for(int val: even.values()){
            int value = val*(val-1)/2;
            ans += (value<=2)?(value):(2);
        }


        for(int val: odd.values()){
            int value = val*(val-1)/2;
            ans += (value<=2)?(value):(2);
        }

        System.out.println(ans);
    }
}