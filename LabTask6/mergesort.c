#include <stdio.h>
#include <stdlib.h>

void Merge(int *num, int i, int j, int k) {
    int l=k, m=i, n=j+1, temp[k]; // use j and j+1 instead of j-1 and j because (i+k)/2 rounds down 
    for (;l>=i;) { temp[l--]=0; } // initialize only what we need to 0
    l=i; // reset l, trying to land l on i at the end of the loop and implicitly using the result does not save bytes and is terribly unreadable
    while (m<=j && n<=k) {
        if (num[m] > num[n]) {           temp[l++] = num[n++]; } // add lowest number
        else {                           temp[l++] = num[m++]; } // using ++ saves space and is more readable
        if (m>j) {      for (;n<=k;) { temp[l++] = num[n++]; } } // if one of the two subarrays is exhausted then fill in the rest in one motion, faster than checking
        else if (n>k) { for (;m<=j;) { temp[l++] = num[m++]; } } // these go after the first set of conditions with the same principle as do-while, first check will always be false, saves time from checking the first time and faster than starting another iteration of while loop to check
    }
    for (;k>=i;) { num[k] = temp[k]; k--; } // transfer back to original array
    // i tried "num[k] = temp[k--]" but got a warning, so i can't use it for this assignment
}

void MergeSort(int *num, int i, int k) {
    if (i<k) {
        int j = (i+k)/2;
        MergeSort(num,i,j);
        MergeSort(num,j+1,k);
        Merge(num,i,j,k);
    }
}

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
