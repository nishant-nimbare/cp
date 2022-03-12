import java.util.*;

class MergeSort {
    public static void main(String ...args){
        int[] arr = {2,34,17,19,63,37,10,51,26,3,11,36,5,3,72};

        System.out.println(Arrays.toString(arr));

        new MergeSort().mergeSort(arr, 0, arr.length-1);

        System.out.println(" ---------- ");
        System.out.println(Arrays.toString(arr));

    }

    void mergeSort(int[] arr, int l, int r){
        if(l >= r ){
            return ;
        }
        int m = (r-l)/2 + l;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, r);
    }

    void merge(int[] arr, int l, int r){
        int m = (r-l)/2 + l;
        int i=l, j=m+1, k=0;
        
        System.out.print("\nl:"+l+" r:"+r+" temp:"+(r-l+1));

        int temp[] = new int[r-l+1];

        while(i<=m && j<=r){
            if(arr[i]<arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }

        while(i<=m){
            temp[k++] = arr[i++];
        }

        while(j<=r){
            temp[k++] = arr[j++];
        }

        System.out.print("{ ");
        for(i=l, k=0; k<temp.length; i++, k++){
            arr[i] = temp[k];
            System.out.print(temp[k]+", ");
        }
        System.out.print(" }\n");
    }
    
}