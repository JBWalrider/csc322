#include <stdio.h> 
#include <stdlib.h>

int main(void) {

    float s,l;
    unsigned int r;

    printf("Enter side of square in km  : ");
    scanf("%f",&s);
    printf("Enter roads length in km    : ");
    scanf("%f",&l);
    printf("Enter number of 'roos       : ");
    scanf("%d",&r);
    printf("Expected number of kills is : %.1f\n",r/(s*s)*l*.01*1.47);

    return(EXIT_SUCCESS);

}
