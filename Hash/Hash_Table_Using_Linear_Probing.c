#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tablesize = 0, student = 0;

struct node
{
    int age, key, state;
    char name[100];
}*hashTable;

void insert(int key, char *name, int age)
{
    int index = key % tablesize;
    if(tablesize == student)
    {
        printf("Hash Table is full can't perform insertion\n");
        return;
    }
    while(hashTable[index].state == 1)
        index = (index+1) % tablesize;
    
    hashTable[index].key = key;
    hashTable[index].age = age;
    strcpy(hashTable[index].name,name);
    hashTable[index].state = 1;

    student++;

    return;
}

void display()
{
    int i;
    if(student == 0)
    {
        printf("Hash Table is Empty!!\n");
        return;
    }
    printf("\n\n");
    printf("  Rollno          Name          Age         Index \n");
    printf("________________________________________________________\n");
    for(i=0;i<tablesize;i++)
    {
        if(hashTable[i].state == 1)
        {
            printf("|   %d      |     %s     |     %d     |      %d     |\n",hashTable[i].key,hashTable[i].name,hashTable[i].age,i);
        }
    }
    printf("\n");
    return;
}

int main()
{
    int age, key;
    char name[100];

    hashTable = (struct node *)calloc(tablesize,sizeof(struct node));
    printf("Enter the size of the hash table: ");
    scanf("%d",&tablesize);

    printf("\nEnter the key value: ");
    scanf("%d",&key);
    printf("Enter Name: ");
    scanf("%s",name);
    name[strlen(name)] = '\0';
    printf("Enter Age: ");
    scanf("%d",&age);

    insert(key,name,age);

    display();

    return 0;
}