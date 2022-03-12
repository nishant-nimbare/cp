import java.util.*;

public class LongestIncSub {

    public static void main(String[] args){

        int arr[] = {50, 3, 10, 7, 40, 80};
        int n = arr.length;
        int lis[] = new int[n];
        lis[0] = 1;

        int globalmax = 1;
        for(int i=1; i<n; i++){
            int maxi =1;
            for(int j=0; j<i;j++){
                if( (arr[j] < arr[i]) && (lis[j]+1 > maxi)){
                    maxi = lis[j]+1;
                }
            }

            lis[i] = maxi;
            if(globalmax < maxi) globalmax = maxi;
        }

        System.out.println("globalmax : "+globalmax);

        for(int k:lis) System.out.print(k + " ");
        System.out.println();
    }
}