#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

#include "colours.h" //provide perameter to change coloure of the string or character
#include <ctype.h>   //provide function to check data.

int searchstatus = 1; // Do help to check availablity of element in the contact list main use of this coming in editconntact()

// Function to validate name.
int check_name(char name[])
{
  int i;
  if (name[0] == '\0')
    return 0;
  for (i = 0; name[i] != '\0'; i++)
  {
    if (isalpha(name[i]) == 0 && name[i] != ' ') // isalph()--true--return--none-zrro
      return 0;                                  // if name is not alphabatic
  }
  return 1; // when the name is alphabatic
}

// Fuction to validate phone number
int check_phone(char phone[])
{
  int i = 0;
  if (phone[0] == '\0')
    return 0;
  while (phone[i] != '\0')
  {
    if (isdigit(phone[i]) == 0) // isdigit()--true--return--none-zrro
      return 0;                 // when the any character is not digits in phone no.
    i++;
  }
  if (i > 10 || i < 10)
    return 0;
  return 1; // when the all character are digits in phone no.
}

// function to check mail
int check_email(char email[])
{
  int i;
  int count = 0;
  if (email[0] == '\0')
    return 0;
  for (i = 0; email[i] != '\0'; i++)
  {
    if (email[i] == '@' || email[i] == '.')
      count++;
  }
  if (count == 2)
    return 1; // when Email has '@' and '.' symbole
  else
    return 0;
}

// Take The name From user and validate its
void forname(char *name)
{
  do
  {
    printf("Enter The Name: ");
    scanf(" %49[^\n]", name);
    if (check_name(name) == 1)
      break;
    else
      printf(RED "Invalid name! Please enter again.\n" RESET);
  } while (!check_name(name));
}

// Take The Phone No. From user and validate its
void forphone(char *phone)
{
  do
  {
    printf("Enter The Phone: ");
    scanf(" %[^\n]", phone);
    if (check_phone(phone) == 1)
      break;
    else
      printf(RED "Invalid Phone Number! Please enter again.\n" RESET);
  } while (!check_phone(phone));
}

// Take The Email Id From user and validate its
void foremail(char *email)
{

  do
  {
    printf("Enter the email Id: ");
    scanf(" %[^\n]", email);
    if (check_email(email) == 1)
      break;

    else
      printf(RED "Invalid mail! Please enter agail.\n" RESET);

  } while (!check_email(email));
}

void listContacts(AddressBook *addressBook) // void listContacts(AddressBook *addressBook, int sortCriteria)
{
  // print the contacts which is populated     // Sort contacts based on the chosen criteria
  // loop for i : 0 to addressBook -> contactCount
  // printf and decorate the output
  printf("+-------+----------------------+--------------+-------------------------+\n");
  printf("| INDEX | Name                 | Phone        | Email                   |\n");
  printf("+-------+----------------------+--------------+-------------------------+\n");

  for (int i = 0; i < addressBook->contactCount; i++)
  {
    printf("| %-5d | %-20s | %-12s | %-23s |\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
  }
  printf("+-------+----------------------+--------------+-------------------------+\n");
}

void initialize(AddressBook *addressBook)
{
  addressBook->contactCount = 0;
  populateAddressBook(addressBook);

  // Load contacts from file during initialization (After files)
  // loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
  saveContactsToFile(addressBook); // Save contacts to file
  exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)
{
  /* Define the logic to create a Contacts */
  char choice;
  int ret;
  char name[50];  // Declaration of variabel to store the Name
  char phone[11]; // Declaration of variabel to store the Pnone No.
  char email[50]; // Declaration of variabel to store the Email Id.
  printf(YELLOW "\n═════════════════════Create Contact═════════════════════\n" RESET);

  forname(name);   // Read the name and validate its
  forphone(phone); // Read the phone no. and validate its
  foremail(email); // Read the email id and validate its

  /* Store contact */
  strcpy(addressBook->contacts[addressBook->contactCount].name, name);

  strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);

  strcpy(addressBook->contacts[addressBook->contactCount].email, email);

  addressBook->contactCount++; // This increase the contactCount by 1 after Store contac

  printf(GREEN "\nContact created successfully!\n" RESET);
}

void searchContact(AddressBook *addressBook)
{
  /* Define the logic for search */
  printf(YELLOW "\n═════════════════════Search Contact═════════════════════\n" RESET);
  searchstatus = 1; // Do help to check availablity of element in the contact list main use of this coming in editconntact()
  char choice;
  char str123[50]; // To read name, phone, email id and by its do comarision of availability in contact list
  int flag = 0;    // To check index no. availability in the contact list. if available become 1 else 0
  // printf("\n");
  printf("1. Name \n");
  printf("2. Phone Number \n");
  printf("3. Email \n");
  printf("4. Index\n");
  // printf("4. Go Back\n");
  printf(GREEN "Enter Your Choice 1, 2, 3, 4: ");
  scanf(" %c", &choice);
  printf(RESET);
  switch (choice)
  {

  case '1':
    printf("Enter The Name: ");
    scanf(" %49[^\n]", str123); // Read the name
    printf("+-------+----------------------+--------------+-------------------------+\n");
    printf("| INDEX | Name                 | Phone        | Email                   |\n");
    printf("+-------+----------------------+--------------+-------------------------+\n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      int ret = strcmp(addressBook->contacts[i].name, str123);
      if (ret == 0)
      {
        printf("| %-5d | %-20s | %-12s | %-23s |\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        flag = 1;
      }
    }
    printf("+-------+----------------------+--------------+-------------------------+\n");
    if (flag == 0)
    {
      printf(RED "Name Not Found\n" RESET);
      searchstatus = 0;
    }
    break;

  case '2':
    printf("Enter The Phone Number: ");
    scanf(" %49[^\n]", str123); // Read the phone no.
    printf("+-------+----------------------+--------------+-------------------------+\n");
    printf("| INDEX | Name                 | Phone        | Email                   |\n");
    printf("+-------+----------------------+--------------+-------------------------+\n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      int ret = strcmp(addressBook->contacts[i].phone, str123);
      if (ret == 0)
      {
        printf("| %-5d | %-20s | %-12s | %-23s |\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        flag = 1;
      }
    }
    printf("+-------+----------------------+--------------+-------------------------+\n");
    if (flag == 0)
    {
      printf(RED "Phone Number Not Found\n" RESET);
      searchstatus = 0;
    }
    break;
  case '3':
    printf("Enter The Email: ");
    scanf(" %49[^\n]", str123); // Read the email id
    printf("+-------+----------------------+--------------+-------------------------+\n");
    printf("| INDEX | Name                 | Phone        | Email                   |\n");
    printf("+-------+----------------------+--------------+-------------------------+\n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      int ret = strcmp(addressBook->contacts[i].email, str123);
      if (ret == 0)
      {
        printf("| %-5d | %-20s | %-12s | %-23s |\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        flag = 1;
      }
    }
    printf("+-------+----------------------+--------------+-------------------------+\n");
    if (flag == 0)
    {
      printf(RED "Email Not Found\n" RESET);
      searchstatus = 0;
    }
    break;
  case '4':
    int n = 0; // Declaration of variable to store index number
    printf("Enter The Index No.: ");
    scanf("%d", &n); // Read the index number
    printf("+-------+----------------------+--------------+-------------------------+\n");
    printf("| INDEX | Name                 | Phone        | Email                   |\n");
    printf("+-------+----------------------+--------------+-------------------------+\n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
      // int ret = strcmp(addressBook->contacts[i].email, str123);
      if (i == n - 1)
      {
        printf("| %-5d | %-20s | %-12s | %-23s |\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        flag = 1;
      }
    }
    printf("+-------+----------------------+--------------+-------------------------+\n");
    if (flag == 0)
    {
      printf(RED "Index Not Found\n" RESET);
      searchstatus = 0;
    }
    break;
  default:
    printf(RED "Invalid Choice.\n" RESET);
    searchstatus = 0;
    break;
  }
}

void editContact(AddressBook *addressBook)
{
  /* Define the logic for Editcontact */
  char option;
  char name[50];
  char phone[11];
  char email[50];
  int index;

  searchContact(addressBook);
  if (!searchstatus) // If Searched element in the contact list is vailable  searchstatus=1, else searchstatus=0.
  {
    return;
  }
  printf(GREEN "Enter Index To Edit: ");
  scanf("%d", &index);
  printf(RESET);
  printf("What You Want To Edit.\n");
  printf("1. Name \n");
  printf("2. Phone Number \n");
  printf("3. Email \n");
  printf("4. All\n");

  printf(GREEN "Enter Your Choice 1, 2, 3, 4: ");
  scanf(" %c", &option);
  printf(RESET);
  switch (option)
  {
  case '1':
    forname(name);
    strcpy(addressBook->contacts[index - 1].name, name);
    printf(GREEN "\nName Edit successfully!\n" RESET);
    break;

  case '2':
    forphone(phone);
    strcpy(addressBook->contacts[index - 1].phone, phone);
    printf(GREEN "\nPhone No. Edit successfully!\n" RESET);
    break;

  case '3':
    foremail(email);
    strcpy(addressBook->contacts[index - 1].email, email);
    printf(GREEN "\nEmail Edit successfully!\n" RESET);
    break;
  case '4':
    forname(name);
    forphone(phone);
    foremail(email);
    strcpy(addressBook->contacts[index - 1].name, name);
    strcpy(addressBook->contacts[index - 1].phone, phone);
    strcpy(addressBook->contacts[index - 1].email, email);
    printf(GREEN "\nName, Phone and Email Id Edit successfully!\n" RESET);
    break;
  default:
    printf(RED "Invalid Choice! Please enter agail.\n" RESET);
    break;
  }
}

void deleteContact(AddressBook *addressBook)
{
  /* Define the logic for deletecontact */
  int index;
  printf(RED "\n═════════════════════Delete Contact═════════════════════\n" RESET);
  searchContact(addressBook);
  if (!searchstatus) // If Searched element in the contact list is vailable  searchstatus=1, else searchstatus=0.
  {
    // printf(RED"Not Available!.\n"RESET);
    return;
  }

  printf(RED "Enter Indext To Delete: ");
  scanf("%d", &index);
  printf(RESET);
  // main logic to Delete Contact form list
  if (index <= addressBook->contactCount)
  {
    for (int i = index - 1; i < addressBook->contactCount; i++)
    {
      addressBook->contacts[i] = addressBook->contacts[i + 1]; // shift the elements
    }
    printf(RED "Contact Deleted Successfully.\n" RESET);
    addressBook->contactCount--;
  }
  else
  {
    printf(RED "Contact Not Availabel On Index %d\n", index);
    printf(RESET);
  }
}

/// 26017/C_Module/AddressBook-NewDesign/AddressBook-NewDesign
