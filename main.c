#include <stdio.h>
#include "contact.h"
#include "file.h"

#include "colours.h" //provide perameter to change coloure of the string or character

int main()
{
    int i=0;
    int choice;
    AddressBook addressBook;
    //initialize(&addressBook); // Initialize the address book

    {
        printf(CYAN); // start appllying CYAN Color
        printf("\n");
        printf("╔═════════════════════════════════════════════════╗\n");
        printf("║        ADDRESS BOOK MANAGEMENT SYSTEM           ║\n");
        printf("║               BY JITENDRA SHARMA                ║\n");
        printf("╚═════════════════════════════════════════════════╝\n");
        printf(RESET); // Stop Applying CYAN color
    }

    do
    {
        // ➕🔍..... Symbole will be showing only in UTF-8 console
        printf(YELLOW "\n═══════════════════Address Book Menu:═══════════════════\n");
        printf(GREEN "1. ➕ Create contact\n");
        printf(BLUE "2. 🔍 Search contact\n");
        printf(MAGENTA "3. ✏️  Edit contact\n");
        printf(RED "4. ❌ Delete contact\n");
        printf(CYAN "5. 📋 List all contacts\n");
        printf(GREEN"6. 💾 Save Contacts To File\n");
         printf(GREEN"7. 📂 Load Contacts From File\n");
        printf(RED "8. 🚪 Exit\n");
        printf(GREEN "═════════════════════════════════════════════════════════\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf(RESET);

        switch (choice)
        {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            searchContact(&addressBook);
            break;
        case 3:
            printf(YELLOW "\n═════════════════════Edit Contact═════════════════════\n" RESET);
            editContact(&addressBook);
            break;
        case 4:
            deleteContact(&addressBook);
            break;
        case 5:
            // printf("Select sort criteria:\n");
            // printf("1. Sort by name\n");
            // printf("2. Sort by phone\n");
            // printf("3. Sort by email\n");
            // printf("Enter your choice: ");
            // int sortChoice;
            // scanf("%d", &sortChoice);

            listContacts(&addressBook); // listContacts(&addressBook, sortChoice);

            break;
        case 6:
            saveContactsToFile(&addressBook);
            i=0;
            break;
        case 7:
             loadContactsFromFile(&addressBook);
             break;

        case 8:
            printf("Saving and Exiting...\n");
            saveContactsToFile(&addressBook);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
