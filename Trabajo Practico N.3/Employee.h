#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

int employee_setId(Employee* pEmp,int id);
int employee_getId(Employee* pEmp,int* id);

int employee_setNombre(Employee* pEmp,char* nombre);
int employee_getNombre(Employee* pEmp,char* nombre);

int employee_setHorasTrabajadas(Employee* pEmp,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* pEmp,int* horasTrabajadas);

int employee_setSueldo(Employee* pEmp,int sueldo);
int employee_getSueldo(Employee* pEmp,int* sueldo);

void employee_showInfo(Employee* pEmp);
int employee_sort(void* pEmp, void* auxEmp);

int employee_modifyMenu(int idEmployee, char nameEmployee[], int hoursEmployee, int salaryEmployee);

#endif // employee_H_INCLUDED
