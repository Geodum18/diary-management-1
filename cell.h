//
// Created by march on 10/24/2023.
//

#ifndef DIARY_MANAGEMENT_CELL_H
#define DIARY_MANAGEMENT_CELL_H

typedef struct s_d_cell
{
    int value;
    int nb_levels;
    struct s_d_cell **next;
} t_d_cell;

t_d_cell* createCell(int value, int nb_levels);

#endif //DIARY_MANAGEMENT_CELL_H
