#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"

int parser_EmployeeFromText(char* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(char* pFile , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
