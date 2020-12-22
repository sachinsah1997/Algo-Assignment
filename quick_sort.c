#include<stdio.h>

void quicksort(int number[13],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      //if left pointer is before the right pointer
      while(i<j){
         // move right till left pointer to meet the higher value than pivot value.
         while(number[i]<=number[pivot]&&i<last)
            i++;
         // move left till right pointer meet the smaller value than pivot value.
         while(number[j]>number[pivot])
            j--;
         //if left and right pointer overlap each other then swap.
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      // set pivot value as right pointer.
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      // divide the array from into two from right pointer.
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int count, number[13];
   char cArray[13] = "RANDOMIZATION";
   int sLength = 13;

   printf("Given elements: ");
   for(int i=0;i<sLength;i++){
      printf(" %c",cArray[i]);
   }
   printf("\n");


   //here all character are converted into asci number and stored in number array.
   for(int i=0; i<sLength; i++){
      number[i] = (int)cArray[i];
   }

   // this method will sort the array.
   quicksort(number,0,sLength-1);

   printf("Sorted elements: ");
   for(int i=0;i<sLength;i++){
      printf(" %c",number[i]);
   }

   return 0;
}
