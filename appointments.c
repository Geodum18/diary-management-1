//
// Created by jules on 14/11/2023.
//

#include "appointments.h"
#include <stdlib.h>
#include <stdio.h>
#include "contact.h"
#include "string.h"

void insertAppointmentAtBeginning(appointment *myAppointment, char *owner) {
    char filename[100];
    sprintf(filename, "../data/%s.txt", owner);
    FILE *file = fopen(filename, "a+");

    if (file != NULL) {
        char lines[500][500];
        int nbLines = 0;
        while (fgets(lines[nbLines], sizeof(lines[0]), file) != NULL) {
            nbLines++;
        }

        fclose(file);
        file = fopen(filename, "w");

        if (file != NULL) {
            char myString[500];
            sprintf(myString, "%s %d/%d/%d %d %d %s", owner,myAppointment->DateDay, myAppointment->DateMonth, myAppointment->DateYear, myAppointment->TimeHour, myAppointment->LengthMinute, myAppointment->Purpose);

            fprintf(file, "%s\n", myString);

            for (int i = 0; i < nbLines; i++) {
                fprintf(file, "%s", lines[i]);
            }

            fclose(file);
        } else {
            printf("Nous n'avons pas pu réouvrir le fichier en mode 'w' pour l'écraser\n");
        }
    } else {
        printf("Nous n'avons pas pu ouvrir ou créer le fichier %s\n", filename);
    }
}


appointment *createAppointment(int day, int month, int year, int hour, int lengthMinute, char *purpose, char *owner){
    appointment *myAppointment = (appointment*)malloc(sizeof(appointment));
    myAppointment->DateDay = day;
    myAppointment->DateMonth = month;
    myAppointment->DateYear = year;
    myAppointment->TimeHour = hour;
    myAppointment->LengthMinute = lengthMinute;
    myAppointment->Purpose = purpose;

    insertAppointmentAtBeginning(myAppointment, owner);
    return myAppointment;
}

void addAppointmentToContact(struct s_contact *myContact, appointment *newAppointment) {
    myContact->nb_appointments++;
    myContact->myAppointments = (appointment**)realloc(myContact->myAppointments, myContact->nb_appointments * sizeof(appointment*));
    myContact->myAppointments[myContact->nb_appointments - 1] = newAppointment;
}

void displayAppointment(appointment *myAppointment){
    printf("-> %d/%d/%d - %dh for %d min: %s\n", myAppointment->DateDay, myAppointment->DateMonth, myAppointment->DateYear, myAppointment->TimeHour, myAppointment->LengthMinute, myAppointment->Purpose);
}

void displayAppointments(struct s_contact *myContact){
    printf("Appointments of %s:\n", myContact->name);
    if (myContact->nb_appointments >= 1){
        for (int i=0; i<myContact->nb_appointments; i++){
            displayAppointment(myContact->myAppointments[i]);
        }
    } else {
        printf("None\n");
    }
}

void displayFileAppointments(char* fullname){
    char filename[100];
    sprintf(filename, "../data/%s.txt", fullname);
    FILE *file = fopen(filename, "r");

    if (file != NULL){
        int i=1;
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            size_t newlineIndex = strcspn(line, "\n");
            line[newlineIndex] = '\0';
            printf("%d - %s\n", i, line);
            i++;
        }
        fclose(file);
    } else {
        printf("You have no appointments saved.\n");
    }
}