//
// Created by march on 10/24/2023.
//

#include "cell.h"
#include "list.h"
#include "stdio.h"
#include "timer.h"
#include "contact.h"
#include <string.h>

int main(){

    int choice, menu=1;

    while(menu){
        printf("\n");
        printf("1 - Search a contact\n");
        printf("2 - View a contact's appointment\n");
        printf("3 - Create a contact\n");
        printf("4 - Display contacts\n");
        printf("4 - Create an appointment\n");
        printf("5 - Delete an appointment\n");
        printf("6 - Save appointments\n");
        printf("7 - Load an appointment file\n");
        printf("8 - Calculation time example\n");
        printf("9 - Quit\n");
        printf("Enter your choice :\n");
        scanf("%d", &choice);

        if (choice == 1){

        } else if (choice == 2){

        } else if (choice == 3){
            char firstName[50], lastName[50];
            printf("Enter the first name of your contact\n");
            scanf(" %s", firstName);
            printf("Enter the last name of your contact\n");
            scanf(" %s", lastName);

            contact *newContact = createContact(firstName, lastName);

        } else if (choice == 4){
            displayContacts();
        } else if (choice == 5){

        } else if (choice == 6){

        } else if (choice == 7){

        } else if (choice == 8){

        } else if (choice == 9){

        } else if (choice == 10){
            printf("See you!");
            break;
        } else {
            printf("Wrong choice!\n");
        }

    }

    return 0;
}

