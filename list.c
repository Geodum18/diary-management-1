//
// Created by march on 10/24/2023.
//

#include "list.h"
#include "cell.h"
#include "stdlib.h"
#include "stdio.h"

t_d_list *createList(int max_levels){
    t_d_list *myList = (t_d_list*)malloc(sizeof(t_d_list));

    myList->max_levels = max_levels;
    myList->heads = (t_d_cell**)malloc(sizeof (t_d_cell*) * max_levels);

    for(int i=0; i<max_levels; i++){
        myList->heads[i] = NULL;
    }

    return myList;
}

void insertCell(t_d_list *myList, t_d_cell *myCell){
    //need to check if max_level not overcome the size of the list
    for (int i=0; i<myCell->nb_levels; i++){
        t_d_cell *tempCell = myList->heads[i];
        myList->heads[i] = myCell;
        myCell->next[i] = tempCell;
    }
}

void displayLevel(t_d_list *myList, int level){
    t_d_cell *tempCell = myList->heads[level];
    printf("[list head_%d @- ]-->", level);
    while (tempCell != NULL) {
        printf("[ %d|@- ]-->", tempCell->value);
        tempCell = tempCell->next[level];
    }
    printf("NULL\n");
}

void displayAllLevels(t_d_list *myList){
    for (int i=0; i<myList->max_levels; i++) {
        displayLevel(myList, i);
    }
}

void insertSorted(t_d_list *myList, t_d_cell *myCell) {
    for (int i = 0; i < myCell->nb_levels; i++) {
        t_d_cell *current = myList->heads[i];
        t_d_cell *prev = NULL;
        while (current != NULL && current->value < myCell->value) {
            prev = current;
            current = current->next[i];
        }
        if (prev == NULL) {
            myList->heads[i] = myCell;
        } else {
            prev->next[i] = myCell;
        }
        myCell->next[i] = current;
    }
}