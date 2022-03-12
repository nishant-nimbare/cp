import java.util.*;

class QuickSort{
    public static void main(String ...args){
        int[] arr = {2,34,17,19,63,37,10,51,26,3,11,36,5,3,72};

        System.out.println(Arrays.toString(arr));

        new QuickSort().quickSort(arr, 0, arr.length-1);

        System.out.println(" ---------- ");
        System.out.println(Arrays.toString(arr));

    }

    void quickSort(int[] arr, int l, int r){

        if(l >= r){ return; }

        int m = sort(arr, l, r);

        quickSort(arr, l, m-1);
        quickSort(arr, m+1, r);
    }

    int sort(int[] arr, int l, int r){
        int p = r;
        int i=l, j=r-1;

        while(i<=j){

            while(arr[i] < arr[p] && i<=j) i++;

            while(arr[j] >= arr[p] && i<=j) j--;

            if(i>j) break;

            if(arr[i] >= arr[p] ) {
                // int temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;

                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];

                i++;
            }
            System.out.println("-> i:"+i+" j:"+j);
        }

        int pivot = arr[p];
        arr[p] = arr[i];
        arr[i] = pivot;
        // arr[p] = arr[p] ^ arr[i];
        // arr[i] = arr[p] ^ arr[i];
        // arr[p] = arr[p] ^ arr[i];

        System.out.println("l:"+l+" r:"+r+" p:"+p+" arr:"+Arrays.toString(arr));
        return i;
    }

}