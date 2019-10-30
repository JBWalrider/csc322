#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define ARRAY_LENGTH 5

typedef int* IntPointer;
typedef int IntArray[ARRAY_LENGTH];
typedef IntPointer IntPointerArray[ARRAY_LENGTH];

//-----------------------------------------------------------------------------

void init(IntArray ia, IntPointerArray ipa) {
    srand(getpid());
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        ia[i] = rand();
        ipa[i] = &ia[i];
    }
}

void PrintIntArray(IntArray ia) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d :  %d\n",i,ia[i]);
    }
}

void PrintIntPointerArray(IntPointerArray ipa) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%d :  %d\n",i,*ipa[i]); // [] has higher precedence than *
    }
}

void SortIntArray(IntArray ia) {
    IntPointer ptr;
    for (int i = 1; i < ARRAY_LENGTH; i++) {
        ptr = ia;
        for (int j = 0; j < ARRAY_LENGTH-i; j++) {
            if (*ptr > *(ptr+1)) {
               int temp = *ptr;
               *ptr = *(ptr+1);
               *(ptr+1) = temp;
            }
            ptr++;
        }
    }
}

void SortIntPointerArray(IntPointerArray ipa) {
    IntPointer* ptrptr;
    for (int i = 1; i < ARRAY_LENGTH; i++) {
        ptrptr = ipa;
        for (int j = 0; j < ARRAY_LENGTH-i; j++) {
            if (**ptrptr > **(ptrptr+1)) {
                IntPointer temp = *ptrptr;
                *ptrptr = *(ptrptr+1);
                *(ptrptr+1) = temp;
            }
            ptrptr++;
        }
    }
}

int main(void) { 
    IntArray ia;
    IntPointerArray ipa;
    init(ia, ipa);
    printf("---- Initialized array of integers ----\n");
    PrintIntArray(ia);
    SortIntPointerArray(ipa);
    printf("---- Sorted array of pointers ----\n");
    PrintIntPointerArray(ipa);
    SortIntArray(ia);
    printf("---- Sorted array of integers ----\n");
    PrintIntArray(ia);
    printf("---- Array of pointers ----\n");
    PrintIntPointerArray(ipa);
    return(EXIT_SUCCESS);

}

