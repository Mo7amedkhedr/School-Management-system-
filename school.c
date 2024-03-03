#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

void addStudent(Student students[], int *count){

    if(*count < MAX_STUDENTS)
    {
        printf("Enter student ID :  ");
        scanf("%d", &students[*count].id);
         fflush(stdin);
        printf("Enter student name :  ");
        scanf(" %s", students[*count].name);
         fflush(stdin);
        printf("Enter student age :  ");
        scanf("%d", &students[*count].age);
        printf("Enter the number of subjects for the student :   ");
        scanf("%d", &students[*count].numSubjects);
        printf("Enter the subjects for the student : \n");
        for(int i =0 ; i<students[*count].numSubjects; i++)
        {
            scanf("%s", students[*count].subjects[i]);
        }
        students[*count].active = 1 ;
        (*count)++;
        printf("Student added successfully \n");
    }
    else
    {
        printf("Maximum student limit reached \n");
    }
}

void editStudent(Student students[],int *count,int id)
{
    for (int i = 0; i <count; i++)
    {
        if(students[i].id == id && students[i].active)
        {
            printf("Enter new age for student %d: ",id);
            scanf("%d", &students[i].age);
            printf("Enter new name for student %d: ",id);
             fflush(stdin);
            scanf(" %s", students[*count].name);
             fflush(stdin);
            printf("Enter the new number of subjects for the student %d: ",id);
            scanf("%d", &students[*count].numSubjects);
            printf("Enter the new subjects for the student %d: \n",id );
            for(int i =0 ; i<students[*count].numSubjects; i++)
            {
                scanf("%s", students[*count].subjects[i]);
            }
            printf("Student information updated successfully!\n");
            return;
        }
    }
    printf("Students with ID %d not found or this student is deleted before! \n", id);
}

void deleteStudent(Student students[],int count,int id)
{
    for (int i = 0; i <count; i++)
    {
        if(students[i].id == id && students[i].active)
        {
            students[i].active=0; // this student is deleted
            printf("Student with ID deleted successfully!\n",id);
            return;
        }
    }
    printf("Students with ID %d not found or this student is deleted before! \n", id);

}

void printStudent(Student student)
{
    printf("ID : %d \n Name : %s \n Age : %d \n",student.id,student.name,student.age);
    printf("Subjects : ");
    for(int i =0 ; i<student.numSubjects; i++)
    {
        printf("%s , ",student.subjects[i]);
    }
    printf("\n");
}
void printAllStudents(Student students[],int count)
{
    printf("\n list of all students :\n");
    for(int i=0; i<count; i++)
    {
        if(students[i].active)
        {
            printStudent(students[i]);
        }
    }

}

void saveStudentsToFile(Student students[], int count)
{

    FILE *file = fopen("students.txt","w");
    if(file == NULL)
    {
        printf("Error opening file \n");
        return;
    }
    for(int i =0; i<count; i++)
    {
        if(students[i].active)
        {
            fprintf(file, "%d %s %d %d ",students[i].id,students[i].name,students[i].age,students[i].numSubjects);
            for(int j=0; j<students[i].numSubjects; j++)
            {
                fprintf(file, "%s ",students[i].subjects[j]);
            }
            fprintf(file, "\n");
        }
    }
    fclose(file);
    printf("Student records saved to file successfully!\n");
}

int loadStudentsFromFile(Student students[])
{
    FILE *file = fopen("students.txt","r");
    if(file == NULL)
    {
        printf("Error opening file \n");
        return;
    }
    int count = 0;
    while(fscanf(file, "%d %s %d %d", &students[count].id, students[count].name,&students[count].age, &students[count].numSubjects) != EOF)
    {
        for(int i=0; i<students[count].numSubjects; i++)
        {
            fscanf(file, "%s", students[count].subjects[i]);
        }
        students[count].active=1;
        count++;
    }
    fclose(file);
    printf("Students records loaded from file successfully!\n");
    return count;

}
