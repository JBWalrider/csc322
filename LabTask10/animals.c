#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define STRLEN 128

typedef char String[STRLEN];
typedef enum {mammal, insect, bird, fish, error} animal_type;
typedef struct {String name; double size; animal_type type;} animals;

animal_type str_to_animal_type(void) {
    String animal;
    scanf("%s",animal);
    if (!strcmp(animal, "mammal")) { return mammal; }
    if (!strcmp(animal, "insect")) { return insect; }
    if (!strcmp(animal, "bird")) { return bird; }
    if (!strcmp(animal, "fish")) {return fish; }
    return error;
}

char* animal_type_to_str(animal_type animal) {
    switch(animal) {
        case mammal:
            return "mammal"; 
            break;
        case insect:
            return "insect"; 
            break;
        case bird:
            return "bird"; 
            break;
        case fish:
            return "fish"; 
            break;
        default:
            return "error";
            break;
    }
}

int main(void) {
    animals* a;
    String name = "";
    String trash;
    int arr_size = 1;
    int curr_index = -1;
    if ((a = malloc(arr_size*sizeof(animals))) != NULL) {
        while (1>0) {
            curr_index++;
            if (curr_index == arr_size) {
                arr_size *= 2;
                a = realloc(a, arr_size * sizeof(animals));
            }
            printf("Enter animal information (\"exit\" to exit)\n");
            printf("What is the name : ");
            scanf("%s", name);
            if (!strcmp(name, "exit")) { break; }
            fgets(trash, STRLEN, stdin);
            strcpy(a[curr_index].name, name);
            printf("What is the size : ");
            scanf("%lf", &(a[curr_index].size));
            fgets(trash, STRLEN, stdin);
            printf("What is the type : ");
            a[curr_index].type = str_to_animal_type();
            if (a[curr_index].type == error) {
                printf("Animal type not supported.\n");
                free(a);
                exit(1);
            }
        }
        printf("The following new species were found:\n");
        for (int i = 0; i < curr_index; i++) {
            printf("%-21s has size %6.2f and is a %-s\n", a[i].name, a[i].size, animal_type_to_str(a[i].type));
        }
        free(a);
        return EXIT_SUCCESS;
    }
    else {
        free(a);
        printf("Error allocating memory\n");
        return -1;
    }
}


