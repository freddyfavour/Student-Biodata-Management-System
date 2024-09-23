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

        switch (choice)
        {
        case 1:
            strcpy(program, "Undergraduate");
            break;
        case 2:
            strcpy(program, "Postgraduate");
            break;
        case 3:
            strcpy(program, "Part-Time");
            break;
        default:
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    } while (choice < 1 || choice > 3); 
}

void addStudent(struct Student students[], int *count)
{
    struct Student s; 

    printf("Enter student's name: ");
    scanf(" %[^\n]", s.name); 

    printf("Enter matriculation number: ");
    scanf("%s", s.matricNumber);

    
    selectProgram(s.program);

    printf("Enter CGPA: ");
    scanf("%f", &s.CGPA);

    printf("Enter level: ");
    scanf("%d", &s.level);

    printf("Enter department: ");
    scanf(" %[^\n]", s.department); 
  
    printf("Enter gender: ");
    scanf("%s", s.gender);

    printf("Enter phone number: ");
    scanf("%s", s.phoneNumber);

    printf("Enter email: ");
    scanf("%s", s.email);

    printf("Enter address: ");
    scanf(" %[^\n]", s.address); 

    printf("Enter state of origin: ");
    scanf("%s", s.stateOfOrigin);

    printf("Enter guardian's phone number: ");
    scanf("%s", s.guardianPhone);

    printf("Enter guardian's email: ");
    scanf("%s", s.guardianEmail);

    printf("Enter NIN number: ");
    scanf("%s", s.NIN);

    students[*count] = s;

    (*count)++;

    printf("Student has been added to the database of Ladoke Akintola University Of Techology\n\n");
}

void sortStudents(struct Student students[], int count)
{
    printf("\n--- Students by Program ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s,\n Program: %s,\n Matric Number: %s,\n CGPA: %.2f,\n Level: %d,\n Department: %s,\n Gender: %s,\n Phone: %s,\n Email: %s,\n Address: %s,\n State of Origin: %s,\n Guardian's Phone: %s,\n Guardian's Email: %s,\n NIN: %s,\n\n\n",
               students[i].name, students[i].program, students[i].matricNumber, students[i].CGPA,
               students[i].level, students[i].department, students[i].gender, students[i].phoneNumber,
               students[i].email, students[i].address, students[i].stateOfOrigin, students[i].guardianPhone,
               students[i].guardianEmail, students[i].NIN);
    }
    printf("\n\n");
}

void countStudents(struct Student students[], int count)
{
    int undergrad = 0, postgrad = 0, partTime = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].program, "Undergraduate") == 0)
        {
            undergrad++;
        }
        else if (strcmp(students[i].program, "Postgraduate") == 0)
        {
            postgrad++;
        }
        else if (strcmp(students[i].program, "Part-Time") == 0)
        {
            partTime++;
        }
    }

    printf("Total Undergraduate students: %d\n", undergrad);
    printf("Total Postgraduate students: %d\n", postgrad);
    printf("Total Part-Time students: %d\n\n", partTime);
}

int main()
{
    struct Student students[10000]; 
    int count = 0;             

    int choice;
    do
    {
        printf("LAUTECH Student Management System\n");
        printf("Is there any action you would love to perform with our database?\n");
        printf("1. Add Student\n2. View Students\n3. Count Students by Program\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &count); 
            break;
        case 2:
            sortStudents(students, count);
            break;
        case 3:
            countStudents(students, count); 
            break;
        case 4:
            printf("Exiting...\n\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}
