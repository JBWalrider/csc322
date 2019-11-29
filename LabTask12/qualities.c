#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 1024
typedef char String[STRING_LENGTH];

int main(void) {

    FILE *f_qualities;
    String sentence;
    String qualities_list = "";
    String quality;
    
    f_qualities = fopen("MyQualities.txt", "w");
    if (f_qualities == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    printf("Please enter entences, . to end.\n");
    
    while (1>0) {
    
        if (fgets(sentence, STRING_LENGTH, stdin) == NULL) {
            printf("Error reading sentence\n");
            exit(EXIT_FAILURE);
        }
        
        if (!strcmp(sentence, ".\n")) {
            qualities_list[strlen(qualities_list)-2] = '.';
            break;
        }

        if (strstr(sentence, "I am ") != NULL) {
            strncpy(quality, sentence+5, strlen(sentence)-1);
            strncat(qualities_list, quality, strlen(quality)-1);
            strncat(qualities_list, ", ", 2);
            fputs(quality, f_qualities);
        }
        
    }
    if (fclose(f_qualities) == EOF) {
        printf("Error closing file\n");
        exit(EXIT_FAILURE);
    }

    printf("The qualities are %s\n\n", qualities_list);
    
    f_qualities = fopen("MyQualities.txt", "r");
    
    printf("Confirming the saved qualities ...\n");
    while (fgets(quality, STRING_LENGTH, f_qualities) != NULL) {
        printf("%s", quality);
    }
    
    if (remove("MyQualities.txt")) {
        printf("Error deleting file\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;

}

