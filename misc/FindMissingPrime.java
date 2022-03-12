import java.util.*;

class FindMissingPrime {
    static int MAX = 100000;
    static boolean sieve[] = new boolean[MAX];
    //sieve 
    // false => prime
    // true => not prime

    public static void main(String ...args){

        int primes[] =  { 41, 53, 31, 59, 13, 43, 17, 19, 23, 31, 37 , 47};



        // init sieve
        for(int i=2; i<MAX; i++){
            //if i prime 
            // mark all it's multiples not prime

            if(!sieve[i]){
                for(int j=2*i; j<MAX; j += i){
                    sieve[j]=true;
                }
            }
        }



        // // display all prime
        // for(int i=1; i<MAX; i++){
        //     if(!sieve[i]) System.out.print(i+" ");
        // }


        //sort
        Arrays.sort(primes);

        for(int k:primes) System.out.print(k+" ");
        System.out.print("\n");

        // int ;

        for(int i=0, si=primes[0]; i<primes.length; i++, si++){

            //find next prime in order

            while(sieve[si]){
                si++;
            }

            System.out.print(" si:"+ si);


            if(sieve[primes[i]]){
                //not prime
                System.out.println(primes[i]+ " is not prime");
                break;
            }

            if( si != primes[i] ){
                // si missing
                System.out.println(si+ " is missing");
                break;
            }

        }

    }
}