#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#define STRING_LENGTH 1024
typedef char String[STRING_LENGTH];

int main(void) {
    String str;
    char* sentence;
    String rx;
    char* p_split_sentence;
    char* p_split_word;
    const String DELIM_SENTENCE = ".!?";
    const String DELIM_WORD = " ";
    char* word;
    int word_count;
    printf("Please enter the string to analyse\n");
    fgets(str, STRING_LENGTH, stdin);
    printf("Please enter the regular expression : ");
    scanf("%s", rx);
    regex_t r_rx;
    if (regcomp(&r_rx, rx, 0)) {
        printf("Error compiling regex\n");
        exit(EXIT_FAILURE);
    } /* if doesn't compile */
    sentence = strtok_r(str, DELIM_SENTENCE, &p_split_sentence);
    while (1>0) {
        printf("%s\n", sentence);
        if (regexec(&r_rx, sentence, 0, NULL, 0)) {
            printf("No\t");
        } /* if doesn't match */
        else {
            printf("Yes\t");
        } /* if does match */
        word_count = 0;
        word = strtok_r(sentence, DELIM_WORD, &p_split_word);
        while (word != NULL) {
            word_count++;
            word = strtok_r(NULL, DELIM_WORD, &p_split_word);
        } /* while word != NULL */
        printf("%d words\n", word_count);
        sentence = strtok_r(NULL, DELIM_SENTENCE, &p_split_sentence);
        if (!strcmp(sentence, "\n")) {
            break;
        }
        sentence++; /* snip leading space for subsequent sentences */
    } /* while true */
    return EXIT_SUCCESS;
}
