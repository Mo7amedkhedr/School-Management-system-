
#include"school_private.h"

typedef struct{
  int id ;
  char name[MAX_NAME_LENGTH];
  int age;
  char subjects[MAX_SUBJECTS][50];
  int numSubjects;
  int active;
}Student;

void addStudent(Student students[], int *count);

void editStudent(Student students[],int *count,int id);

void deleteStudent(Student students[],int count,int id);

void printStudent(Student student);

void printAllStudents(Student students[],int count);

void saveStudentsToFile(Student students[], int count);

int loadStudentsFromFile(Student students[]);

