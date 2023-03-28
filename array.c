#include "array.h"
#include <stdio.h>
#include <stdlib.h>
//
// Created by Rafael on 3/26/2023.
//
void* access(array* array, int position){
    return (void*) &array->contents[position];
}

void insert(array* array, void* element, int position){
    //Inserts an element into the array, specific position is optional
    if (array->content_size ==array->size){ //TODO: Make into dynamic array
        printf("Array is full");
        return;
    }
    if(position){
        if(position >= array->size || array->size<=array->content_size+1){ //TODO: Make into dynamic array
            printf("Invalid position");
            return;
        }
        if(array->contents[position]==NULL) {
            array->contents[position] = element;
            array->content_size++;
            return;
        }
        void* temp1 = array->contents[position];
        void* temp2 = array->contents[position+1];
        array->contents[position] = element;
        position++;

        while(array->contents[position+1]){
            array->contents[position] = temp1;
            temp1 = temp2;
            temp2 = array->contents[position+1];
            position++;
        }
        array->contents[position]=temp1;
        array->content_size++;
        return;
    }
    array->contents[array->content_size] = element;
    array->content_size++;
    return;
}
int search(array* array, void* element){
    //returns the position of the element in the array
    for (int i = 0; i < array->content_size+1; i++){
        if(array->contents[i]==element){
            return i;
        }
    }
}

void delete (array* array, void* element, int position){
    //deletes a value from the array
    if (position){
        array->contents[position] = NULL;
        return;
    }
    for (int i = 0; i < array->content_size+1; i++){
        if(array->contents[i]==element){
            free(&array->contents[i]);
            array->contents[i]=NULL;
        }
    }
}
void sort(array* array){
    //sorts array in place using quicksort
    quicksort(array,0,array->content_size);
}

void quicksort(array* array, int low, int high){
    if(low < high){
        int pivot = partition(array, low, high);
        quicksort(array, low, pivot-1);
        quicksort(array,pivot, high);
    }
}

int partition(array* array, int low, int high){
    int pivotval = (int) array->contents[low];
    int left = low+1;
    int right = high;
    int boolean = 0;
    void* temp;
    while(!boolean){
        while (left <= right && (int) array->contents[left] <= pivotval){
            left = left+1;
        }
        while ((int) array->contents[right] >= pivotval && right>= left){
            right = right -1;
        }
        if (right < left){
            boolean = 1;
        } else {
            temp = array->contents[left];
            array->contents[left] = array->contents[right];
            array->contents[right] = temp;
        };
    temp = array->contents[low];
    array->contents[low] = array->contents[high];
    array->contents[high] = temp;
    }
}

array* Array(int size){
    array* new_array = malloc(sizeof(array));
    new_array->contents = malloc(sizeof(void*) * size );
    new_array->content_size = 0;
    new_array->access = access;
    new_array->insert = insert;
    new_array->search = search;
    new_array->delete = delete;
    new_array->sort = sort;
    return new_array;
}