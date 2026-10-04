#include <stdio.h>
#include "file.h"

#include <string.h>

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr;
    fptr = fopen("Address_Book.csv", "w");
    if(fptr == NULL)
    {
        printf("Unable to opent file\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
      fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
  fclose(fptr);
  printf("Contacts saved successfully\n");
}

void loadContactsFromFile(AddressBook *addressBook) {
  char name[50];  // Declaration of variabel to store the Name
  char phone[11]; // Declaration of variabel to store the Pnone No.
  char email[50]; // Declaration of variabel to store the Email Id.
 
  addressBook -> contactCount=0;
  
  FILE *fptr = fopen("Address_Book.csv", "r");

  if(fptr == NULL)
  {
    printf("File not Found\n");
    return ;
  }

  while(fscanf(fptr, "%49[^,],%[^,],%[^\n]\n", name, phone, email)==3)
  {
     strcpy(addressBook->contacts[addressBook -> contactCount].name, name);
      strcpy(addressBook->contacts[addressBook -> contactCount].phone, phone);
       strcpy(addressBook->contacts[addressBook -> contactCount].email, email);
      addressBook -> contactCount++;
  }
  fclose(fptr);
  printf("Contacts Loaded Successfully\n");
}
