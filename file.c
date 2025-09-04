#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  //  sort(addressBook);
    FILE *fptr;
    fptr=fopen("contact.csv","w");
    if(fptr==NULL)
    {
        addressBook->contactCount=0;
        printf("File not exist\n");
        return;
    }
    fprintf(fptr,"#%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) {
    //addressBook->contactCount = 0;
FILE *fptr;
fptr=fopen("contact.csv","r");
    if(fptr==NULL)
    {
       printf("File not exist\n");
        return; 
    }
    fscanf(fptr,"#%d\n",&addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr, "%49[^,],%49[^,],%49[^\n]\n", 
                  addressBook->contacts[i].name,
                  addressBook->contacts[i].phone,
                  addressBook->contacts[i].email);
    }
   // printf("%d",addressBook->contactCount);
   /* while (fscanf(fptr, "%[^,],%[^,],%[^\n]\n", 
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3) 
    {
        addressBook->contactCount++;
    }*/
    fclose(fptr);
}
