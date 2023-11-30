//
// Created by march on 11/14/2023.
//

#ifndef DIARY_MANAGEMENT_CONTACT_H
#define DIARY_MANAGEMENT_CONTACT_H
#include "appointments.h"


typedef struct s_contact
{
    char *name;
    appointment **myAppointments;
    int nb_levels;
    struct s_contact **next;
} contact;

void toLowerCase(char *string);
void insertStringInSortedFile(const char *myString);
contact *createContact(char *firstName, char *LastName);
void displayContacts();

#endif //DIARY_MANAGEMENT_CONTACT_H
