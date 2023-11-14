//
// Created by march on 11/14/2023.
//

#ifndef DIARY_MANAGEMENT_CONTACT_H
#define DIARY_MANAGEMENT_CONTACT_H

typedef struct s_contact
{
    char *name;
    int nb_levels;
    struct s_contact **next;
} contact;

#endif //DIARY_MANAGEMENT_CONTACT_H
