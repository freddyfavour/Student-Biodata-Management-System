#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    char matricNumber[20];
    char program[20];
    float CGPA;
    int level;
    char department[50];
    char gender[10];
    char phoneNumber[15];
    char email[50];
    char address[100];
    char stateOfOrigin[30];
    char guardianPhone[15];
    char guardianEmail[50];
    char NIN[15];
};

void selectProgram(char program[])
{
    int choice;
    do
    {
        printf("Select Program:\n");
        printf("1. Undergraduate\n");
        printf("2. Postgraduate\n");
        printf("3. Part-Time\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1)
            strcpy(program, "Undergraduate");
        else if (choice == 2)
            strcpy(program, "Postgraduate");
        else if (choice == 3)
            strcpy(program, "Part-Time");
        else
            printf("Invalid choice! Try again.\n");
    } while (choice < 1 || choice > 3);
}

void addStudent(struct Student students[], int count)
{
    printf("Enter student's name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter matriculation number: ");
    scanf("%s", students[count].matricNumber);
    selectProgram(students[count].program);
    printf("Enter CGPA: ");
    scanf("%f", &students[count].CGPA);
    printf("Enter level: ");
    scanf("%d", &students[count].level);
    printf("Enter department: ");
    scanf(" %[^\n]", students[count].department);
    printf("Enter gender: ");
    scanf("%s", students[count].gender);
    printf("Enter phone number: ");
    scanf("%s", students[count].phoneNumber);
    printf("Enter email: ");
    scanf("%s", students[count].email);
    printf("Enter address: ");
    scanf(" %[^\n]", students[count].address);
    printf("Enter state of origin: ");
    scanf("%s", students[count].stateOfOrigin);
    printf("Enter guardian's phone number: ");
    scanf("%s", students[count].guardianPhone);
    printf("Enter guardian's email: ");
    scanf("%s", students[count].guardianEmail);
    printf("Enter NIN: ");
    scanf("%s", students[count].NIN);

    printf("Student added to the database.\n\n");
}

void viewStudents(struct Student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s,\n Program: %s,\n Matric Number: %s,\n CGPA: %.2f,\n Level: %d,\n Department: %s,\n Gender: %s,\n Phone: %s,\n Email: %s,\n Address: %s,\n State of Origin: %s,\n Guardian's Phone: %s,\n Guardian's Email: %s,\n NIN: %s,\n\n\n",
               students[i].name, students[i].program, students[i].matricNumber, students[i].CGPA,
               students[i].level, students[i].department, students[i].gender, students[i].phoneNumber,
               students[i].email, students[i].address, students[i].stateOfOrigin, students[i].guardianPhone,
               students[i].guardianEmail, students[i].NIN);
    }
}

void countStudents(struct Student students[], int count)
{
    int undergrad = 0, postgrad = 0, partTime = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].program, "Undergraduate") == 0)
            undergrad++;
        else if (strcmp(students[i].program, "Postgraduate") == 0)
            postgrad++;
        else if (strcmp(students[i].program, "Part-Time") == 0)
            partTime++;
    }

    printf("Total Undergraduate students: %d\n", undergrad);
    printf("Total Postgraduate students: %d\n", postgrad);
    printf("Total Part-Time students: %d\n\n", partTime);
}

void deleteStudent(struct Student students[], int *count)
{
    char matricNumber[20];
    int found = 0;

    printf("Enter matriculation number of the student to delete: ");
    scanf("%s", matricNumber);

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(students[i].matricNumber, matricNumber) == 0)
        {
            found = 1;
            for (int j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with matriculation number %s has been deleted.\n", matricNumber);
            break;
        }
    }

    if (!found)
        printf("Student with matriculation number %s not found.\n", matricNumber);
}

int main()
{
    struct Student students[1000];
    int count = 0;
    int choice;

    do
    {
        printf("1. Add Student\n2. View Students\n3. Count Students by Program\n4. Delete Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addStudent(students, count++);
        else if (choice == 2)
            viewStudents(students, count);
        else if (choice == 3)
            countStudents(students, count);
        else if (choice == 4)
            deleteStudent(students, &count);
        else if (choice != 5)
            printf("Invalid choice, try again.\n");
    } while (choice != 5);

    return 0;
}
