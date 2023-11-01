//
// Created by march on 10/24/2023.
//

#include "cell.h"
#include "list.h"

int main(){

    t_d_list *myList = createList(5);

    t_d_cell *Cell1 = createCell(5, 3);
    t_d_cell *Cell2 = createCell(8, 2);
    t_d_cell *Cell3 = createCell(2, 4);
    t_d_cell *Cell4 = createCell(8, 3);

    insertSorted(myList, Cell1);
    insertSorted(myList, Cell2);
    insertSorted(myList, Cell3);
    insertSorted(myList, Cell4);

    displayAllLevels(myList);

    return 0;
}

