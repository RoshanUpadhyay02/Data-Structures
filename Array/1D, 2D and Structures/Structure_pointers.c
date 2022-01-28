#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[100];
    int reg_no;
    char course[100];
};

int main()
{
    int n,i;
    printf("Enter the no. of Students: ");
    scanf("%d",&n);

    struct Student c[n];

    printf("\nPlease use (_) when you want to leave space eg. Ramesh_Sharma\n")
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the Details of Student %d: ",i+1);
        printf("\nEnter Name: ");
        scanf("%s",(c+i)->name);
        printf("Enter Registration Number: ");
        scanf("%d",&(c+i)->reg_no);
        printf("Enter the course details: ");
        scanf("%s",(c+i)->course);
    }

    printf("\n Printing Details Of the Students\n");
    for(i=0;i<n;i++)
    {
        printf("\nDetails of Student %d: ",i+1);
        printf("\nName : %s",(c+i)->name);
        printf("\nRegister Number : %d",(c+i)->reg_no);
        printf("\nCourse : %s",(c+i)->course);
        printf("\n");
    }

    return 0;
}