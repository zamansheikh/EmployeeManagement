/* Employee Record Management
this project is done by Zaman Sheikh, 
git: https://github.com/zamansheikh
website: https://zamansheikh.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct
{
    char name[40];
    int age;
    char address[20];
    double basic_salary;
} Employee;

#define TOTAL_EMP 100

// global variables
int i = 0, n = 0;
char choice;
int read = 0, record = 0;
FILE *file1, *file2;
Employee emp[TOTAL_EMP];
// function prototypes
void fileload(Employee emp[]);
void add_employee(Employee employees[]);
void list_employee(Employee employees[]);
void modify_employee(Employee employees[]);
void delete_employee(Employee employees[]);
void search_employee(Employee employees[]);

void sort_employee_name(Employee employees[]);
void sort_employee_age(Employee employees[]);
void sort_employee_address(Employee employees[]);
void sort_employee_salary(Employee employees[]);


// UserSnippetBy ZAMAN SHEIKH v0.1
int main()
{

    fileload(emp);

    while (1)
    {
        printf(" \n  ::::::::::::::::::::::::::  |EMPLOYEES RECORD MANAGEMENT|  :::::::::::::::::::::::::: \n");
        printf("1. Add Employee's Records \n");
        printf("2. List Employee's Records \n");
        printf("3. Modify Employee's Records \n");
        printf("4. Delete Employee's Records \n");
        printf("5. Search Employee's Records \n");
        printf("6. Sort Employee's Records \n");
        printf("7. Exit System \n");
        printf(" \n \n Your Choice: ");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
        case '1':
            system("cls");
            add_employee(emp);
            break;
        case '2':
            system("cls");
            list_employee(emp);
            break;
        case '3':
            system("cls");
            modify_employee(emp);
            break;
        case '4':
            system("cls");
            delete_employee(emp);
            break;
        case '5':
            system("cls");
            search_employee(emp);

            break;
        case '6':
            system("cls");
            // Sort Employee's Records
            printf(" \n  ::::::::::::::::::::::::::  |EMPLOYEES RECORD MANAGEMENT|  :::::::::::::::::::::::::: \n");
            printf("1. Sort by Name \n");
            printf("2. Sort by Age \n");
            printf("3. Sort by Address \n");
            printf("4. Sort by Basic Salary \n");
            printf("5. Return Back \n");
            printf(" \n \n Your Choice: ");
            fflush(stdin);
            choice = getchar();
            switch (choice)
            {
            case '1':
                system("cls");
                // Sort by Name
                sort_employee_name(emp);
                break;
            case '2':
                system("cls");
                // Sort by Age
                sort_employee_age(emp);
                break;
            case '3':
                system("cls");
                // Sort by Address
                sort_employee_address(emp);
                break;
            case '4':
                system("cls");
                // Sort by Basic Salary
                sort_employee_salary(emp);
                break;
            case '5':
                system("cls");
                break;
            default:
                system("cls");
                printf("\nInvalid choice & returning back ...\n");
                system ("pause");
            }
            break;
        case '7':
            system("cls");
            exit(0);
            break;
        default:
            system("cls");
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}

void fileload(Employee emp[])
{

    file2 = fopen("CCsvf.csv", "r+");
    if (file2 == NULL)
    {
        printf("Error opening file2\n");
        exit(1);
    }

    do
    {
        read = fscanf(file2, "%39[^,],%d,%19[^,],%lf\n", emp[record].name, &emp[record].age, emp[record].address, &emp[record].basic_salary);
        // printf("Read =  %d\n", read);
        if (read == 4)
            record++;
        if (read != 4 && !feof(file2))
        {
            printf("file format error\n");
            exit(1);
        }
        if (ferror(file2))
        {
            printf("Error reading from file2\n");
            exit(1);
        }

    } while (!feof(file2));
    // printf("\n%d Employee read from file2\n", record);
    fclose(file2);
}

void add_employee(Employee emp[])
{
    file1 = fopen("CCsvf.csv", "w+");
    char another = 'y';
    while (another == 'y')
    {
        printf("\nEmployee %d info:\n", record + 1);
        fflush(stdin);
        printf("Name: ");
        scanf("%[^\n]%*c", emp[record].name);
        fflush(stdin);
        printf("Age: ");
        scanf("%d", &emp[record].age);
        fflush(stdin);
        printf("Address: ");
        scanf("%[^\n]%*c", emp[record].address);
        fflush(stdin);
        printf("Basic Salary: ");
        fflush(stdin);
        scanf("%lf", &emp[record].basic_salary);
        printf("\n");
        printf("Add another Employee? (y/n): ");
        fflush(stdin);
        another = getchar();
        record++;
    }
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("\n%d Employee added to file1\n", record);
}

void list_employee(Employee employees[])
{
    printf("%-7s %-20s %-7s %-20s %-10s\n", "Serial", "Name", "Age", "Address", "Salary");
    for (i = 0; i < record; i++)
    {
        printf("%-7d %-20s %-7d %-20s %-10.2lf\n", i, emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
    }
    system("pause");
}

void modify_employee(Employee emp[]){
    printf("Enter the serial number of the employee you want to modify: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\nEmployee %d info:\n", n);
    fflush(stdin);
    printf("Name: ");
    scanf("%[^\n]%*c", emp[n].name);
    fflush(stdin);
    printf("Age: ");
    scanf("%d", &emp[n].age);
    fflush(stdin);
    printf("Address: ");
    scanf("%[^\n]%*c", emp[n].address);
    fflush(stdin);
    printf("Basic Salary: ");
    fflush(stdin);
    scanf("%lf", &emp[n].basic_salary);
    printf("\n");

    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    printf("Employee %d modified\n", n);
    fclose(file1);
    system("pause");
}

void delete_employee(Employee emp[]){
    printf("Enter the serial number of the employee you want to delete: ");
    fflush(stdin);
    scanf("%d", &n);
    //shift all the elements after the deleted one to the left
    for (i = n; i < record; i++)
    {
        strcpy(emp[i].name, emp[i + 1].name);
        emp[i].age = emp[i + 1].age;
        strcpy(emp[i].address, emp[i + 1].address);
        emp[i].basic_salary = emp[i + 1].basic_salary;
    }
    record--;
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("Employee %d deleted\n", n);
    system("pause");
}

void search_employee(Employee emp[]){
    //search by name
    printf("Enter the name of the employee you want to search: ");
    fflush(stdin);
    char name[40];
    scanf("%[^\n]%*c", name);
    for (i = 0; i < record; i++)
    {
        if (strcmp(emp[i].name, name) == 0)
        {
            printf("%-7s %-20s %-7s %-20s %-10s\n", "Serial", "Name", "Age", "Address", "Salary");
            printf("%-7d %-20s %-7d %-20s %-10.2lf\n", i, emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
            system("pause");
        }
    }
}


void sort_employee_name(Employee emp[]){
    int i, j;
    Employee temp;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (strcmp(emp[j].name, emp[j + 1].name) > 0)
            {
                strcpy(temp.name, emp[j].name);
                temp.age = emp[j].age;
                strcpy(temp.address, emp[j].address);
                temp.basic_salary = emp[j].basic_salary;
                strcpy(emp[j].name, emp[j + 1].name);
                emp[j].age = emp[j + 1].age;
                strcpy(emp[j].address, emp[j + 1].address);
                emp[j].basic_salary = emp[j + 1].basic_salary;
                strcpy(emp[j + 1].name, temp.name);
                emp[j + 1].age = temp.age;
                strcpy(emp[j + 1].address, temp.address);
                emp[j + 1].basic_salary = temp.basic_salary;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("Employee sorted by name\n");
    system("pause");
}

void sort_employee_age(Employee emp[]){
    int i, j;
    Employee temp;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (emp[j].age > emp[j + 1].age)
            {
                strcpy(temp.name, emp[j].name);
                temp.age = emp[j].age;
                strcpy(temp.address, emp[j].address);
                temp.basic_salary = emp[j].basic_salary;
                strcpy(emp[j].name, emp[j + 1].name);
                emp[j].age = emp[j + 1].age;
                strcpy(emp[j].address, emp[j + 1].address);
                emp[j].basic_salary = emp[j + 1].basic_salary;
                strcpy(emp[j + 1].name, temp.name);
                emp[j + 1].age = temp.age;
                strcpy(emp[j + 1].address, temp.address);
                emp[j + 1].basic_salary = temp.basic_salary;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("Employee sorted by age\n");
    system("pause");
}

void sort_employee_address(Employee emp[]){
    int i, j;
    Employee temp;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (strcmp(emp[j].address, emp[j + 1].address) > 0)
            {
                strcpy(temp.name, emp[j].name);
                temp.age = emp[j].age;
                strcpy(temp.address, emp[j].address);
                temp.basic_salary = emp[j].basic_salary;
                strcpy(emp[j].name, emp[j + 1].name);
                emp[j].age = emp[j + 1].age;
                strcpy(emp[j].address, emp[j + 1].address);
                emp[j].basic_salary = emp[j + 1].basic_salary;
                strcpy(emp[j + 1].name, temp.name);
                emp[j + 1].age = temp.age;
                strcpy(emp[j + 1].address, temp.address);
                emp[j + 1].basic_salary = temp.basic_salary;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("Employee sorted by address\n");
    system("pause");
}


void sort_employee_salary(Employee emp[]){
    int i, j;
    Employee temp;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (emp[j].basic_salary > emp[j + 1].basic_salary)
            {
                strcpy(temp.name, emp[j].name);
                temp.age = emp[j].age;
                strcpy(temp.address, emp[j].address);
                temp.basic_salary = emp[j].basic_salary;
                strcpy(emp[j].name, emp[j + 1].name);
                emp[j].age = emp[j + 1].age;
                strcpy(emp[j].address, emp[j + 1].address);
                emp[j].basic_salary = emp[j + 1].basic_salary;
                strcpy(emp[j + 1].name, temp.name);
                emp[j + 1].age = temp.age;
                strcpy(emp[j + 1].address, temp.address);
                emp[j + 1].basic_salary = temp.basic_salary;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", emp[i].name, emp[i].age, emp[i].address, emp[i].basic_salary);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("Employee sorted by salary\n");
    system("pause");
}

