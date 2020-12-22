#include <stdio.h>



//this will adjust and arrange the element following max heap property.
    void arrange(int A[],int arr_size, int i){      
        
        int top=i;                           
        int left=2*i+1;                             
        int right= 2*i+2;                       
        
        // this will compare i with its left node 
        if(left<arr_size && A[left]>A[top]){   
            top=left;                           
        }
    
         // this will compare i with its right node
        if(right<arr_size && A[right]>A[top]){ 
            top=right;                         
        }
     
     //this will check if i value is not the largest and again it will rearrange.   
        if(top!=i){                             
            int temp;
            temp=A[i];
            A[i]=A[top];
            A[top]=temp;

            arrange(A,arr_size,top);               
        }
    }

    //Here this function will work as to find max means top-most element of the heap and retrieve it. 
    int heapextractmax(int A[],int arr_size){          
        if(arr_size<1){
            printf("heap empty");}
        else{
            //as the top element is retrieve and the least element means last node of the heap tree will set to top elements.
            int max=A[0];
            A[0]=A[arr_size-1];                       
            arr_size=arr_size-1;
            // again heap will rearrange as least element is set as top as root element.
            arrange(A,arr_size,0);
            return max;
        }
    }



 // this will sort the array in max heap order. 
    void buildmaxheap(int A[],int arr_size){          
        //we will retrieve last element to move forward to create max heap on that element..
        int startindex=(arr_size/2)-1;                   
        for(int i=startindex;i>=0;i--){
            arrange(A,arr_size,i);
        }
    }

    void heapsort(int A[],int arr_size){          

        for (int i=(arr_size/2)-1;i>=0;i--){
            arrange(A,arr_size,i);              
        }
        
        for(int i=arr_size-1;i>=0;i--){
            int temp;
            temp= A[0];
            A[0]= A[i];
            A[i]=temp;
            arrange(A,i,0);
        }
    }

    int main(){
        int A[]={ 8, 13, 9, 5, 12, 15, 7, 4, 0, 6, 2, 1 };
        
        int arr_size = sizeof(A) / sizeof(A[0]);
        
        printf("Question Array is:");
        for(int i=0;i<arr_size;++i){
            printf("%d ",A[i]);
        }
        printf("\n");

        buildmaxheap(A,arr_size);
        heapsort(A,arr_size);
        int a= heapextractmax(A,arr_size);
        int top_element= heapextractmax(A,arr_size);
        
        printf("Extracted Maximum Element is :%d\n",top_element);
        
        printf("Sorted Array is:");
        for(int i=1;i<arr_size;++i){
            printf("%d ",A[i]);
        }  
    }