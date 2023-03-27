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
    //sorts array in place

}