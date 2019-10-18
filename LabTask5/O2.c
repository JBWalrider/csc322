#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


float pressure_ambient(int d);
float pressure_oxygen(float a,int p);
char group_oxygen(float o);
bool exceeds_max(float o);
bool exceeds_cont(float o);

int main(void) {
   
    int depth,percent;
    float pressure_a,pressure_o;
    char group;
    bool m,c;

    printf("Enter depth and percentage O2   : ");
    scanf("%d %d",&depth,&percent);
    pressure_a = pressure_ambient(depth);
    printf("Ambient pressure                : %.1f\n",pressure_a);
    pressure_o = pressure_oxygen(pressure_a,percent);
    printf("O2 pressure                     : %.2f\n",pressure_o);
    group = group_oxygen(pressure_o);
    printf("O2 group                        : %c\n",group);
    m = exceeds_max(pressure_o);
    c = exceeds_cont(pressure_o);
    printf("Exceeds maximal O2 pressure     : %s\n",m?"true":"false");
    printf("Exceeds contingency O2 pressure : %s\n",c?"true":"false");
    
    return(EXIT_SUCCESS);

}

float pressure_ambient(int d) { return d/33+1; }

float pressure_oxygen(float a,int p) { return .01*a*p; }

char group_oxygen(float o) { return (char)((int)(o*10)+65); }

bool exceeds_max(float o) { return o > 1.4; }

bool exceeds_cont(float o) { return o > 1.6; }

