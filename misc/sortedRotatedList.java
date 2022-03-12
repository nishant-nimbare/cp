import java.util.*;

public class sortedRotatedList {

    public static void main(String[] args){

        // int arr[] = {6, 7 , 8, 9 ,10 ,11 , 1, 2, 3, 4, 5 };
        int arr[] = {3, 4, 5, 1, 2};
        int n = arr.length;
        System.out.println();

        // divide in 2 half
        // discard sorted half each time

        int l=0, r=arr.length;
        while(l<r){
            if(l+1==r){
                System.out.println("\n"+r);
                break;
            }

            int m = l + (r-l)/2;
            System.out.print("-"+m+" ");
            if(arr[l] < arr[m] ){
                //left half is correct go right
                l = m;
            }else{
                r = m;
            }
        }

    }

}