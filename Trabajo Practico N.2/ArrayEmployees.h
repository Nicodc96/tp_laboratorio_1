//------ BIBLIOTECA DE FUNCIONES ------//
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
//------ DEFINICION DE ESTRUCTURA EMPLOYEE ------//
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;
#endif // ARRAYEMPLOYEES_H_INCLUDED

int hardcodearEmpleados(Employee x[], int tam, int cant); // FUNCION DE TESTING

//------ COMIENZO DE DEFINICION DE PROTOTIPOS DE FUNCTIONSEMPLOYEES.C ------//
int menu();
int initEmployees(Employee employeesList[], int len);
Employee addEmployee(int id, char name[],char lastName[],float salary,int sector);
int searchEmpty(Employee employeesList[], int len);
int newEmployee(Employee employeesList[], int len, int id);
int findEmployeeById(Employee employeesList[], int len, int id);
void printEmployee(Employee employeeX);
int printEmployees(Employee employeesList[], int len);
int removeEmployee(Employee employeesList[], int len, int id);
void removingEmployee(Employee employeesList[], int len);
int sortEmployees(Employee employeesList[], int len, int order);
void modifyMenuCases(Employee employeesList[], int len, int id);
void modifyingEmployee(Employee employeesList[], int len);
int modifyMenu(Employee employeesList[], int len, int id);
int checkEmployee(Employee employeesList[], int len);
void sortEmployeesSalary(Employee employeesList[], int len);
void reportEmployees(Employee employeesList[], int len);

//------ FIN DE DEFINICION DE PROTOTIPOS DE FUNCTIONSEMPLOYEES.C ------//
