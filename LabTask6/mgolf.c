#include <stdio.h>
#include <stdlib.h>

void M(int*num,int i,int j,int k){int l=k,m=i,n=j+1,temp[k];for(;l>=i;)temp[l--]=0;l=i;while(m<=j&&n<=k){if(num[m]>num[n])temp[l++]=num[n++];else temp[l++]=num[m++];if(m>j)for(;n<=k;)temp[l++]=num[n++];else if(n>k)for(;m<=j;)temp[l++]=num[m++];}for(;k>=i;)num[k]=temp[k],k--;}
void MergeSort(int*num,int i,int k){if(i<k){int j=(i+k)/2;MergeSort(num,i,j);MergeSort(num,j+1,k);M(num,i,j,k);}}

int main(void) {
    int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
    const int NUMBERS_SIZE = 8;
    int i;
    
    printf("UNSORTED: ");
    for (i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%i ", numbers[i]);
    }
    printf("\n");
    
    MergeSort(numbers, 0, NUMBERS_SIZE - 1);
    
    printf("SORTED: ");
    for (i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%i ", numbers[i]);
    }
    printf("\n");
    
    return(EXIT_SUCCESS);
}
