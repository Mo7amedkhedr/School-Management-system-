#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

int main(void)
{
    Student students[MAX_STUDENTS];
    int studentCount=0;
    int choice,id;
    studentCount=loadStudentsFromFile(students);//load existing student record from file
    do
    {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Edit Student Information\n");
        printf("3. Delete Student\n");
        printf("4. Print Student Information\n");
        printf("5. Print All Students\n");
        printf("6. Save Students to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1 :
            addStudent(students,&studentCount);
            break;
        case 2 :
            printf("Enter the ID of the student to edit: ");
            scanf("%d", &id);
            editStudent(students, &studentCount, id);
            break;
        case 3 :
            printf("Enter the ID of the student to delete: ");
            scanf("%d", &id);
            deleteStudent(students, studentCount, id);
            break;
        case 4:
            printf("Enter the ID of the student to print: ");
            scanf("%d", &id);
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].id == id && students[i].active)
                {
                    printStudent(students[i]);
                    break;
                }
            }
            break;
        case 5:
            printAllStudents(students, studentCount);
            break;
        case 6:
            saveStudentsToFile(students, studentCount);
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");


        }
    }while(1);

    return 0 ;
}
