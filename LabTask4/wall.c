#include <stdio.h> 
#include <stdlib.h>

int main(void) {

    float h,w,a;

    printf("Enter height of the wall in feet  : ");
    scanf("%f",&h);
    printf("Enter width of the wall in feet   : ");
    scanf("%f",&w);
    a = h*w;
    printf("Wall area    : %.2f square feet\n",a);
    a = a / 350;
    printf("Paint needed : %.2f gallons\n",a);
    printf("Cans needed  : %d can(s)\n",(int)(a+0.5));

    return(EXIT_SUCCESS);

}
