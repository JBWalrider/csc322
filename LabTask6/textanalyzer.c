#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 128

typedef char String[STRING_LENGTH];

int GetNumOfCharacters(String UserString) {
    int num;
    for (num = 0; num < STRING_LENGTH; num++) {if (UserString[num] == '\0') { break; } }
    return num;
}
void OutputWithoutWhitespace(String UserString) {
    printf("String with no whitespace: ");
    int num;
    for (num = 0; num < STRING_LENGTH; num++) {
        if (UserString[num] == '\0') { break; } 
        if (UserString[num] != ' ' && UserString[num] != '\n' && UserString[num] != '\t') { printf("%c", UserString[num]); }
    }
    printf("\n");
}

int main(void) {

    String UserString;
    int NumCharacters;

    printf("Enter a sentence or phrase:\n");
    fgets(UserString,STRING_LENGTH,stdin);
    UserString[strlen(UserString)-1] = '\0';

    printf("You entered: %s\n", UserString);

    NumCharacters = GetNumOfCharacters(UserString);
    printf("Number of characters: %d\n", NumCharacters);

    OutputWithoutWhitespace(UserString);
    return(EXIT_SUCCESS);

  }
//-----------------------------------------------------------------------------
