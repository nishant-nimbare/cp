import java.util.*;

public class monkeys {

    static int gcd(int a, int b){
        
        if(a<b){
            int temp = a;
            a = b;
            b = temp;
        }

        if(b == 0) return a;

        return gcd(b, a%b);
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int test = sc.nextInt();
        
        while(test>0){
            int n = sc.nextInt();

            if(n<1) {
                System.out.println(0);
                test--;
                continue;    
            }


            int[] monkey = new int[n];
            
            for(int i=0; i<n; i++){
                monkey[i] = sc.nextInt()-1;
            }

            HashSet<Integer> visited = new HashSet<Integer>();

            ArrayList<Integer> loops = new ArrayList<Integer>();

            for(int i=0; i<n; i++){

                if(visited.contains(i)) continue;

                visited.add(i);
                int t = i, count=0;
                do{
                    if(t>=n || t<0) break;
                    t = monkey[t];
                    visited.add(t);
                    count++;
                }while(t!=i);

                if(t==i)loops.add(count);
                // System.out.println("adding loop : "+count);
                
            }


            // find lcm of all loops
            if(loops.size()>0){
                int ans = loops.get(0);

                for(int i=1; i<loops.size(); i++){
                    int cur = loops.get(i);

                    ans = (ans*cur)/( gcd(ans, cur));
                }

                System.out.println(ans);
            }
            test--;
        }
    }
}