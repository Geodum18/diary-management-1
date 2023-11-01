//
// Created by march on 10/24/2023.
//
#include "cell.h"

#ifndef DIARY_MANAGEMENT_LIST_H
#define DIARY_MANAGEMENT_LIST_H

typedef struct s_d_list
{
    int max_levels;
    t_d_cell **heads;
} t_d_list;

t_d_list *createList(int max_levels);
void insertCell(t_d_list *myList, t_d_cell *myCell);
void displayLevel(t_d_list *myList, int level);
void displayAllLevels(t_d_list *myList);
void insertSorted(t_d_list *myList, t_d_cell *myCell);
#endif //DIARY_MANAGEMENT_LIST_H
