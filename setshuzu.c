#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[100][100];
    int size;
} ArraySet;

void initSet(ArraySet *set) {
    set->size = 0;
}   

int contains(ArraySet *set, const char *element) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->data[i], element) == 0) {
            return 1; // Element found
        }
    }
    return 0; // Element not found
} 

