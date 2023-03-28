//
// Created by Rafael on 3/26/2023.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#endif //ARRAY_ARRAY_H
typedef struct array array;
struct array {
    int size;
    int content_size;
    void* (*access)(array* array, int position);
    void (*insert)(array* array, void* element, int position); //position value optional
    int (*search)(array* array, void* element);
    void (*delete)(array* array, void* element, int position); //position value optional
    void (*sort)(array* array);
    void** contents;
};

array* Array(int size);
void quicksort(array* array, int low, int high);
int partition(array* array, int low, int high);