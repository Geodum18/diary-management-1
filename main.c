//
// Created by march on 10/24/2023.
//

#include "cell.h"
#include "list.h"
#include "stdio.h"
#include "timer.h"

int main(){

    t_d_list *myList = createList(5);

    insertLevelCells(myList, 100);

    int result = searchLevelValue(myList, 52);

    if (result == 1){
        printf("Value founded!\n");
    } else {
        printf("Value not found!\n");
    }

    //algo 2 without levels.

    int result2 = searchValue(myList, 52);


    if (result2 == 1){
        printf("Value founded!\n");
    } else {
        printf("Value not found!\n");
    }

    return 0;
}

