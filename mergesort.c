#include<stdio.h>


    // we will merge subarray while comparing it.
    void merge(int A[], int l, int m, int r){
    
        int i, j, k;

        // we will get size from first to middle in n1.
        int n1 = m - l + 1;

        // we will get size from middle+1 to last in n2.
        int n2 = r - m;

        // we will create two temp array with size of n1 and n2.
        int L[n1], R[n2];
 

        // traverse till n1 and store the value in L array
        for (i = 0; i < n1; i++)
            L[i] = A[l + i];

        // traverse till n2 and store the value in R array
        for (j = 0; j < n2; j++)
            R[j] = A[m + 1 + j];
 
        i = 0;
        j = 0;
        k = l;
    
        // traverse till i< n1 and j<n2
        while (i < n1 && j < n2) {

            // comparing L and R array elements. 
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }
 
        // if L[] have more element than R[] then it should be added at last.
        while (i < n1) {
            A[k] = L[i];
            i++;
            k++;
        }
 
        // if R[] have more element than L[] then it should be added at last.
        while (j < n2) {
            A[k] = R[j];
            j++;
            k++;
        }
    }

    void divide(int A[], int left_index, int right_index){
    
        if (left_index < right_index){
        
            // we will find middle index by this operation.
            int middle_index = (left_index + right_index) / 2;
            
            // it will divide from first to middle index.
            divide(A, left_index, middle_index);
            // it will divide from middle+1 to last index. 
            divide(A, middle_index + 1, right_index);
		
            // after dividing we will merge subarray of array. 
            merge(A, left_index, middle_index, right_index);
        }
    }

    int main(){
	   
       int A[] = {3, 41, 52, 26, 38, 57, 9, 49};
	   
       // to find array size.
       int arr_size = sizeof(A) / sizeof(A[0]);
 
        // print the given unsorted array.
        printf("Question Array :" );
        for (int i = 0; i < arr_size; ++i)
        {
    	   printf("%d ", A[i]); 
        }

        // given array will be divided into smaller arrays. it will be keep on dividing till every element of array is seperated.
        divide(A,0,arr_size-1);

        // print the sorted array.
        printf("Sorted Array :" );
        for (int i = 0; i < arr_size; ++i)
        {
            printf("%d ", A[i]); 
        }

    }