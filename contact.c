//
// Created by march on 11/14/2023.
//

#include "contact.h"
#include <ctype.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX_BUFFER_SIZE 1000

void toLowerCase(char *string){
    if (string == NULL) {
        return;
    }

    for (int i = 0; string[i] != '\0'; ++i) {
        string[i] = tolower(string[i]);
    }
}

void insertStringInSortedFile(const char *myString) {
    FILE *file = fopen("../data/contacts.txt", "r+");

    if (file != NULL) {
        char lines[100][100];
        int nbLines = 0;

        while (fgets(lines[nbLines], sizeof(lines[0]), file) != NULL) {
            nbLines++;
        }

        int insertIndex = 0;
        while (insertIndex < nbLines && strcmp(myString, lines[insertIndex]) > 0) {
            insertIndex++;
        }

        for (int i = nbLines; i > insertIndex; i--) {
            strcpy(lines[i], lines[i - 1]);
        }

        strcpy(lines[insertIndex], myString);
        nbLines++;

        rewind(file);

        for (int i = 0; i < nbLines; i++) {
            fprintf(file, "%s", lines[i]);
            if (i == insertIndex) {
                fprintf(file, "\n");
            }
        }

        fclose(file);
    } else {
        printf("We could not open the file contacts.txt\n");
    }
}

contact *createContact(char *firstName, char *lastName){
    toLowerCase(firstName);
    toLowerCase(lastName);

    size_t totalLength = strlen(firstName) + strlen("_") + strlen(lastName) + 1;
    char fullName[totalLength];
    strcpy(fullName, lastName);
    strcat(fullName, "_");
    strcat(fullName, firstName);
    printf("New contact %s created", fullName);
    insertStringInSortedFile(fullName);

    contact *newContact = (contact*)malloc(sizeof (contact));
    newContact->name = fullName;
    newContact->myAppointments = NULL;
    newContact->nb_levels = 5;
    newContact->next = NULL;

    return newContact;
}

void displayContacts(){
    FILE *file = fopen("../data/contacts.txt", "r+");

    if(file != NULL){
        char line[100];
        printf("Display the first 100 contacts :");
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }

        fclose(file);
    } else {
        printf("There is no contact.");
    }
    printf("\n---------------------------------");
}