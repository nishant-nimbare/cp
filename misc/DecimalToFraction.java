import java.util.*;

public class DecimalToFraction {



    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String n[] = str.split("\\.",2);

        int dplace = n[1].length();
        System.out.println(" dplace " + dplace);

        int multiplier = pow(10, dplace);
        System.out.println(" multiplier " + multiplier);

        // int num = Integer.parseInt(n[0] + n[1]);
        int num = Integer.parseInt(n[0])*multiplier + Integer.parseInt(n[1]);
        int den = multiplier;

        System.out.println(num);
        System.out.println(den);

        int g = gcd(num, den);
        System.out.println(" gcd " + g);

        num = num/g;
        den =den/g;

        System.out.println(num + " / " + den);

    }

    public static int gcd(int a, int b){
        if(b==0) return a;
        if(a<b) return gcd(b,a);
        return gcd(b, a%b);
    }

    public static int pow(int x, int e){
        if(x==0) return 0;
        if(e==0) return 1;

        if(e==1) return x;

        if(e%2==1){
            return x*pow(x*x, e/2);
        }else{
            return pow(x*x, e/2);
        }

    }
}