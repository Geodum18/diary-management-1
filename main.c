//
// Created by march on 10/24/2023.
//

#include "cell.h"
#include <stdio.h>

int main(){

    //Show Part 1 - Functionalities
    t_d_cell *myCell = createCell(4, 5);
    printf("%d\n", myCell->value);
    printf("%d\n", myCell->nb_levels);

    return 0;
}

