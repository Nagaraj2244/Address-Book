#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
int check_name(char name[]);
int check_ph_no(char num[]);
int check_email(char email[]);
int dpl_num(AddressBook *addressBook,char num[]);
int dpl_email(AddressBook *addressBook,char num[]);
void sort(AddressBook *addressBook)
{
for(int i=0;i<=addressBook->contactCount-2;i++)
    {
        Contact temp;
        for(int j=0;j<=addressBook->contactCount-2-i;j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) > 0)
            {
             temp=addressBook->contacts[j];
            addressBook->contacts[j]=addressBook->contacts[j+1];
            addressBook->contacts[j+1]=temp;
            }
            
        }
    }
}

void listContacts(AddressBook *addressBook) 
{ 
    sort(addressBook);
    
    printf("%d\n",addressBook->contactCount);
    //sorting_contacts(addressBook);
    
    
  printf("            List Contacts:-\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
    printf("Name :%s  Number :%s  Email :%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    //printf("\n");
    }  // Sort contacts based on the chosen criteria
    
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
   loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
void createContact(AddressBook *addressBook)
{
    static int x;
    int n,ret;
    //do
    //{
   // printf("Enter the number of contact to add: ");
   // ret=scanf("%d",&n);
   //getchar();
   // if(ret)
   // {
   // while(addressBook->contactCount<(n+x)&&n<=MAX_CONTACTS)
   // {
        int name_valid=0;
        int num_valid=0;
        int email_valid=0;
        int num_duplicate=0;
        int email_duplicate=0;
  while(!name_valid)
  {
	printf("Enter person Name: "); /* Define the logic to create a Contacts */
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    name_valid=check_name(addressBook->contacts[addressBook->contactCount].name);
    if(name_valid==0)
    printf("Try again\n");
  }
  while(!(num_valid&&num_duplicate))
  {
    printf("Enter person Number: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
    num_valid=check_ph_no(addressBook->contacts[addressBook->contactCount].phone);
    num_duplicate=dpl_num(addressBook,addressBook->contacts[addressBook->contactCount].phone);
    if(num_valid==0||num_duplicate==0)
    printf("Try again\n");
      
  }
  while(!(email_valid&&email_duplicate))
  {
    printf("Enter  person email id: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
   email_valid=check_email(addressBook->contacts[addressBook->contactCount].email);
   email_duplicate=dpl_email(addressBook,addressBook->contacts[addressBook->contactCount].email);
   if(email_valid==0||email_duplicate==0)
   printf("Try again\n");
  }
    addressBook->contactCount++;
    printf("\n");
   // }
    //x=addressBook->contactCount;
    if(addressBook->contactCount>MAX_CONTACTS)
    {
         printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
   // }
   // else
   // printf("Enter Number\n");
//}while(ret!=1);
//saveContactsToFile(addressBook);
sort(addressBook);
}
    
   int check_name(char *name)
    {
      for(int i=0;name[i]!='\0';i++)
      {
     if(!((name[i]>=65&&name[i]<=90)||(name[i]>=97&&name[i]<=122)||name[i]==' '))
     {
        printf("Invalid name\n");
     return 0;
     }
      }
      return 1;
    }
    int check_ph_no(char *phone)
    {
       int i=0;
       int len=strlen(phone);
       if(len!=10)
       {
        printf("Error:phone number must be exactly 10 digit\n");
        return 0;
       }
       while (phone[i] != '\0') {
        if (!(phone[i] >= '0' && phone[i] <= '9')) {
            printf("Error: Phone number must contain only digits\n");
            return 0;
        }
        i++;
    }
    return 1;
    }
    int check_email(char *email)
    {
        int flag=0,len=strlen(email);
        if(email[0]=='@')
        return 0;
        for(int i=0;i<len;i++)
        {
            if(email[i]=='@')
            flag=1;
        }
        if(flag!=1||strstr(email,".com")==NULL||strcmp(email+len-4,".com")!=0)
        {
            printf("Invalid email\n");
        return 0;
        }
        return 1;

    }

    int dpl_num(AddressBook *addressBook, char *number)
    {
        for(int i=0;i<addressBook->contactCount;i++)
        {
       if(strcmp(number,addressBook->contacts[i].phone)==0)
      {
        printf("Number is already exist\n");
       return 0;
      }
        }
       return 1;
    }
   int dpl_email(AddressBook *addressBook, char *email)
    {
        for(int i=0;i<addressBook->contactCount;i++)
        {
       if(strcmp(email,addressBook->contacts[i].email)==0)
      {
        printf("Email is already exist\n");
       return 0;
      }
        }
       return 1;
    }
    int FLAG;
 void name_found(AddressBook *addressBook,int *flag)
 {
    char search_name[20];
       printf("Enter name: ");
        scanf(" %[^\n]",search_name);
    for(int i=0;i<addressBook->contactCount;i++)
   {
    if(strcmp(search_name,addressBook->contacts[i].name)==0)
    {
    printf("Name :%s  Number :%s  Email :%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    printf("\n");
    *flag=1;
    }
   }
   if(*flag==0)
   {
   printf("Contact details not found\n");
   FLAG=1;
   }
 }
 void number_found(AddressBook *addressBook,int *flag)
 {
    char search_number[20];
    printf("Enter number: ");
        scanf(" %[^\n]",search_number);
    for(int i=0;i<addressBook->contactCount;i++)
   {
    if(strcmp(search_number,addressBook->contacts[i].phone)==0)
    {
    printf("Name :%s  Number :%s  Email :%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    printf("\n");
    *flag=1;
    }
   }
   if(*flag==0)
   {
   printf("Contact details not found\n");
   FLAG=1;
   }
 }
void email_found(AddressBook *addressBook,int *flag)
{
  char search_email[20];
   printf("Enter email: ");
        scanf(" %[^\n]",search_email);
    for(int i=0;i<addressBook->contactCount;i++)
   {
    if(strcmp(search_email,addressBook->contacts[i].email)==0)
    {
    printf("Name :%s  Number :%s  Email :%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    printf("\n");
    *flag=1;
    }
   }
   if(*flag==0)
   {
   printf("Contact details not found\n");
   FLAG=1;
   }
}
void searchContact(AddressBook *addressBook) 
{
    int choice,flag=0;
    printf("Search the contact by: \n");
   printf("1.Search by name:\n");
   printf("2.Search by number:\n");
   printf("3.Search by email:\n"); /* Define the logic for search */
   printf("Enter your choice: ");
   scanf("%d",&choice);
   getchar();
   switch(choice)
   {
    case 1:name_found(addressBook,&flag);
   break;
   case 2:number_found(addressBook,&flag);
   break;
   case 3:email_found(addressBook,&flag);
   break;
   default:printf("Invalid choice\n");
   } 
}
void editContact(AddressBook *addressBook)
{
    int choice,flag=0,choice1,arr[100],count=0;;
	 searchContact(addressBook);
     if(FLAG==1)
     {
        FLAG=0;
        return;
     }
     char new_name[20]; 
     char old_name[20];
     char old_phone[20];            /* Define the logic for Editcontact */
     char new_phone[20];
     char new_email[20];
     char old_email[20];
     int name_valid=0,name_valid2=0;
     int phone_valid=0,phone_valid2=0;
     int email_valid=0,email_valid2=0;
     printf("Which field you going to edit\n");
     printf("1.Edit name: \n");
     printf("2.Edit phone number: \n");
     printf("3.Edit email:\n");
     printf("Enter your choice: ");
     scanf("%d",&choice);
     getchar();
     switch(choice)
     {
        case 1:
        while(!name_valid)
        {
           int i;
        printf("\nEnter old name: ");
        scanf(" %[^\n]",old_name);
        name_valid=check_name(old_name);
        if(name_valid==1)
        {
        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].name,old_name)==0)
            {
              arr[count++]=i;
            }
        }
        if(count>1)
        {
            printf("which name are you going to edit\n");
            for(int j=0;j<count;j++)
            {
                printf("%d.Name :%s  Number :%s  Email :%s\n",j+1,addressBook->contacts[arr[j]].name,addressBook->contacts[arr[j]].phone,addressBook->contacts[arr[j]].email);
               printf("\n");
            }
            printf("select any one: ");
            scanf("%d",&choice1);
            while(!name_valid2)
            {
            printf("\nEnter new name\n");
          scanf(" %[^\n]",new_name); 
           name_valid2=check_name(new_name);
           if(name_valid2==1)
            strcpy(addressBook->contacts[arr[choice1-1]].name,new_name);
            }
        }
        else
        {
          for(i=0;i<addressBook->contactCount;i++)
          {
            if(strcmp(addressBook->contacts[i].name,old_name)==0)
            break;
          } 
          printf("Enter new name\n");
          scanf(" %[^\n]",new_name);
          while(!name_valid2)
          {
           name_valid2=check_name(new_name);
           if(name_valid==1)
            strcpy(addressBook->contacts[i].name,new_name);
        }   
        }
        }
        break;

        case 2:
        while(!phone_valid)
        {
            int i;
        printf("\nEnter old number: ");
        scanf(" %[^\n]",old_phone);
        phone_valid=check_ph_no(old_phone);
        if(phone_valid==1)
        {
        for(i=0;i<addressBook->contactCount;i++)
           {
            if(strcmp(addressBook->contacts[i].phone,old_phone)==0)
              break;
            }
            printf("Enter new number:");
            scanf(" %[^\n]",new_phone);
            while(!phone_valid2)
            {
            phone_valid2=check_ph_no(new_phone);
            if(phone_valid2==1)
             strcpy(addressBook->contacts[i].phone,new_phone);
            }
        }
        }
        break;
        case 3:
        while(!email_valid)
        {
            int i;
        printf("\nEnter old email: ");
        scanf(" %[^\n]",old_email);
        getchar();
        email_valid=check_email(old_email);
        if(email_valid==1)
        {
        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,old_email)==0)
            break;
        }
         printf("Enter new email:");
            scanf(" %[^\n]",new_email);
            while(!email_valid2)
            {
            email_valid2=check_email(new_email);
            if(email_valid2==1)
            strcpy(addressBook->contacts[i].email,new_email);
            }
         
        }
        }
        break;
        default:printf("Invalid choice\n");

     } 
}
}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice,flag=0;
    while(1)
    {
    printf("Search the contacts by\n");
    printf("1. Name\n");
    printf("2. Mobile Number\n");
    printf("3. Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
         case 1:name_found(addressBook,&flag);
        break;
        case 2:number_found(addressBook,&flag);
        break;
        case 3:email_found(addressBook,&flag);
        break;
        default:printf("Invalid choice....");
        continue;

    }
    if(flag != 0)
    break;
    }
    if(flag==0)
     return;
    int choice1,x=-1,i,count=0,arr[100];
    char del[50];
    printf("Enter deliting name or number or email\n ");
    scanf(" %[^\n]",del);
    for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcasecmp(addressBook->contacts[i].name,del)==0||strcasecmp(addressBook->contacts[i].phone,del)==0||strcasecmp(addressBook->contacts[i].email,del)==0)
            {
                x=i;
                arr[count++]=i;
            }
        }
        if(count>1)
        {
            printf("which name are you going to edit\n");
           for(int j=0;j<count;j++)
            {
                printf("%d.Name :%s  Number :%s  Email :%s\n",j+1,addressBook->contacts[arr[j]].name,addressBook->contacts[arr[j]].phone,addressBook->contacts[arr[j]].email);
            }
            printf("Select any one\n");
            scanf("%d",&choice1);
            getchar();
            for(int k=choice1-1;k<addressBook->contactCount - 1;k++)
            {
            addressBook->contacts[arr[choice1-1]]=addressBook->contacts[k + 1];
            }
            addressBook->contactCount--;
            printf("Contact deleted successfully.\n");

        }
       else if (x != -1) 
        {
        for (int i = x; i < addressBook->contactCount - 1; i++) 
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;
        printf("Contact deleted successfully.\n");
         } 
        else
        {
            printf("Contact not found.\n");
        }
}
