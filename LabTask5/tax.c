#include <stdio.h> 
#include <stdlib.h>

char get_tax_group(float i);
float get_tax(float i,char g);
int width(int x);

int main(void) {
   
    float income=0,deductions=0,taxable,tax,current;
    char group;
    int w; 
    do {
        printf("Enter next amount : ");
        scanf("%f",&current);
        if (current > 0) { income += current; }
        else             { deductions -= current; }
    } while (current != 0);
    if (income < deductions) {
        taxable = 0;
        w = width((int)deductions) + 3; // 3 accounts for decimal point and 2 decimal places
        // assumes that income or deductions will be the largest output number because taxable is the difference and tax is multiplied by a factor less than 1
    }
    else {
        taxable = income - deductions;
        w = width((int)income) + 3; // 3 accounts for decimal point and 2 decimal places
    }
    printf("Income         = $%*.2f\n",w,(float)income);
    printf("Deductions     = $%*.2f\n",w,(float)deductions);
    taxable = income < deductions ? 0 : income - deductions;
    printf("Taxable Income = $%*.2f\n",w,taxable);
    group = get_tax_group(taxable);
    printf("Tax group      = %c\n",group);
    tax = get_tax(taxable,group);
    printf("Tax owed       = $%*.2f\n",w,tax);
   
    return(EXIT_SUCCESS);

}
char get_tax_group(float i){ 
    char g;
    if (i >= 500000)      { g = 'S'; }
    else if (i >= 200000) { g = 'Q'; }
    else if (i >= 100000) { g = 'M'; }
    else if (i >= 50000)  { g = 'A'; }
    else if (i >= 20000)  { g = 'R'; }
    else                  { g = 'P'; }
    return g;
}

float get_tax(float i,char g){ 
    float t = 0;
    if      (g == 'S' || g == 'Q') { t = i * 0.25; }
    else if (g == 'M')             { t = i * 0.10; }
    else if (g == 'A' || g == 'R') { t = i * 0.03; }
    // The assignment says that if group is nonexistent then throw an error, but since the groups are defined by get_tax_group ONLY, there will never be other undefined groups. 
    // If the project is expanded in the future and more groups are added, they must be accompanied by a percentage of income which determines their tax(es).
    // Therefore, the concern of code expansion leading to unexpected results is not a valid excuse.  
    // However, just because the assignment says to do so, I have included a line below with this functionality.
    else if (g != 'P') { printf("Group %c not defined.\n",g); exit(EXIT_FAILURE); }
    if (t > 50000) {t = 50000; }
    return t;
}

int width(int x) { // binary, faster than log and faster than linear lookup
    if (x >= 10000) { 
        if (x >= 10000000) { 
            if (x >= 100000000) { 
                if (x >= 1000000000) { return 10; } 
                else                 { return 9;  } 
            }
            else {
                return 8;
            }
        }
        else {
            if (x >= 100000) {
                if (x >= 1000000) { return 7; }
                else              { return 6; }
            }
            else {
                return 5; 
            }
        }
    }
    else {
        if (x >= 100) { 
            if (x >= 1000) { return 4; }
            else           { return 3; }
        }
        else { 
            if (x >= 10) { return 2; } 
            else         { return 1; }
        }
    }
}
