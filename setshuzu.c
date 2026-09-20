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

void clearSet(ArraySet *set) {
    set->size = 0;
}

void addElement(ArraySet* set, const char * element){
    if(!contains(set, element)){
        strcpy(set->data[set->size], element);
        set->size++;
    }
}

void remove(ArraySet* set, const char *element){
    int index = -1;
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->data[i], element) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < set->size - 1; i++) {
            strcpy(set->data[i], set->data[i + 1]);
        }
        set->size--;
    }
}

ArraySet* bing(ArraySet *set1, ArraySet *set2){
        ArraySet *result = (ArraySet *)malloc(sizeof(ArraySet));
        initSet(result);
        for(int i = 0; i < set1->size; i++){
            addElement(result, set1->data[i]);
        }
        for (int i = 0; i < set2->size; i++)
        {
            if(!contains(result, set2->data[i])){
                addElement(result, set2->data[i]);
            }
        }
        return result;
}

ArraySet* jiao(ArraySet *set1, ArraySet *set2){
    ArraySet *result = (ArraySet *)malloc(sizeof(ArraySet));
    initSet(result);
   for (int i = 0; i < set1->size; i++)
   {
    addElement(result, set1->data[i]);
   }
    for (int i = 0; i < set1->size; i++)
    {
     if(!contains(set2, set1->data[i])){
          remove(result, set1->data[i]);
     }
    }
    return result;
}

ArraySet* cha(ArraySet *set1, ArraySet *set2){
    ArraySet *result = (ArraySet *)malloc(sizeof(ArraySet));
    initSet(result);
    for (int i = 0; i < set1->size; i++)
    {
        addElement(result, set1->data[i]);
    }
    for (int i = 0; i < set1->size; i++)
    {
        if(contains(set2, set1->data[i])){
            remove(result, set1->data[i]);
        }
    }
    return result;
}

