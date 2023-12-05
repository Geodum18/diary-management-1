//
// Created by march on 10/24/2023.
//

#include "cell.h"
#include "list.h"
#include "stdio.h"
#include "timer.h"
#include "contact.h"
#include <string.h>
#include "list_contact.h"

int main(){

    int choice, menu=1;

    t_d_listcontact *myContacts = createListContact(5);

    char *actualContactName = strdup("None");
    contact *actualContactPtr = NULL;

    initializeContacts(myContacts);

    while(menu){
        printf("-------------------\n");
        printf("Actual Contact : %s\n", actualContactName);
        printf("-------------------\n");
        printf("1 - Select a contact\n");
        printf("2 - View a contact's appointment\n");
        printf("3 - Create a contact\n");
        printf("4 - Display contacts\n");
        printf("5 - Create an appointment\n");
        printf("6 - Delete an appointment\n");
        printf("7 - See previous appointments (load file)\n");
        printf("8 - Calculation time example\n");
        printf("9 - Quit & Save\n");
        printf("-------------------\n");
        printf("Enter your choice :\n");
        printf("-------------------\n");
        scanf("%d", &choice);

        if (choice == 1){
            displayContacts(myContacts);
            char contactName[100];
            printf("-------------------\n");
            printf("Which contact would you like to select ?\n");
            printf("-------------------\n");
            scanf(" %s", contactName);

            actualContactPtr = setContactSelected(myContacts, contactName);

            if (actualContactPtr != NULL) {
                actualContactName = actualContactPtr->name;
                printf("Contact selected !\n");
            } else {
                printf("Contact not found.\n");
                actualContactName = strdup("None");
            }

        } else if (choice == 2){
            if (actualContactPtr!=NULL){
                displayAppointments(actualContactPtr);
            } else {
                printf("No contact selected\n");
            }


        } else if (choice == 3){

            char firstName[50], lastName[50];
            printf("Enter the first name of your contact\n");
            scanf(" %s", firstName);
            printf("Enter the last name of your contact\n");
            scanf(" %s", lastName);

            contact *newContact = createContact(firstName, lastName, 5);
            insertContact(myContacts, newContact);

        } else if (choice == 4){

            displayContacts(myContacts);

        } else if (choice == 5){

            int day, month, year, time, length;
            char purpose[200];

            if (strcmp(actualContactName, "None") == 1) {
                printf("Create an appointment:\n");
                printf("Step 1 - On which day dd/mm/yyyy format ?\n");
                scanf("%d/%d/%d", &day, &month, &year);
                printf("Step 2 - At which hour ?\n");
                scanf("%d", &time);
                printf("Step 3 - How long would it be ? In minutes\n");
                scanf("%d", &length);
                printf("Final Step - What is the purpose of the appointment ?\n");
                scanf(" %[^\n]", purpose);
                appointment *myAppointment = createAppointment(day, month, year, time, length, purpose, actualContactName);
                displayAppointment(myAppointment);
                addAppointmentToContact(actualContactPtr, myAppointment);
            } else {
                printf("No contact selected\n");
            }

        } else if (choice == 6){

        } else if (choice == 7){

            if (actualContactPtr!=NULL){
                displayFileAppointments(actualContactName);
            } else {
                printf("No contact selected\n");
            }

        } else if (choice == 8){
            printf("You will now test the complexity of a standard search algorithm VS a level based algorithm.\n\n");
            complexityTest();
        } else if (choice == 9){
            printf("See you!");
            break;
        } else {
            printf("Wrong choice!\n");
        }

    }

    return 0;
}


