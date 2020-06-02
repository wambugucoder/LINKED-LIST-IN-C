#include <stdio.h>
#include <stdlib.h>

struct Node {
    char *name;
    int age;
    struct Node *next;
};

struct Node * customerRecord;
struct Node * newRecord;

void printCustomerRecord()
{
    struct Node * iterator = customerRecord;
    while(iterator != NULL)
    {
        printf("Name of Customer: %s\n", iterator->name);
        printf("Age of Customer: %d\n", iterator->age);
        iterator=iterator->next;
    }
}

void writeToFile()
{
    FILE * fptr;
    fptr = fopen("Customerdetails.txt", "w");
    struct Node * iterator = customerRecord;

    if(fptr==NULL)
    {
        printf("Error\n");
    }

    else
    {
        while(iterator!= NULL)
        {
            fprintf(fptr, "\nCustomer Name: %s\nAge: %d\n", iterator->name, iterator->age);
            iterator= iterator->next;
        }
    }

    fclose(fptr);
    }

int main()
{
    int count, i;
    printf("How many customers do you have? ");
    scanf("%d", &count);

    for(i=0; i<count; i++)
    {
        if(i==0)
        {
            customerRecord = malloc(sizeof(struct Node));
            newRecord = customerRecord;
        }
        else
        {
            newRecord->next = malloc(sizeof(struct Node));
            newRecord = newRecord->next;
        }
        newRecord->name = malloc(50*sizeof(char));
        printf("Name of Customer: ");
        scanf("%s", newRecord->name);
        printf("Age of Customer: ");
        scanf("%d", &newRecord->age);
    }
    newRecord->next = NULL;
    printf("\n\n");
    printCustomerRecord();
    writeToFile();
}
