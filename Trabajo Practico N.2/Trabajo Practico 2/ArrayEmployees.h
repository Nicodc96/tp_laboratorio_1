// SECTOR BIBLIOTECA
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
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
int hardcodearEmpleados(Employee x[], int tam, int cantidad);
/** \brief Option's Menu that the User can choose options "a","b","c","d" or "e".
 *  if other letter was choose, the function return default with the error message.
 *  if the options "a" or "b" was choose before enter any employee
 *  the function return the error message
 * \param void.
 *
 * \return char option.
 */
int menu();

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee[] to array of employees
* \param len TAM
* \return int Return (-1) if Error [Invalid length or NULL vector] - (0) if Ok
*
*/
int initEmployees(Employee employees[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param int id
* \param char name[]
* \param char lastName[]
* \param float salary
* \param int sector
* \return Employee return newEmployee, if isEmpty = 0 in the moment to add values
* the function newEmployee return the error message.
*/
Employee addEmployee(int id, char name[],char lastName[],float salary,int sector);

/** \brief check if possible to add more values in the struct
 *
 * \param Employee employees
 * \param int len
 * \return int return (-1) if is impossible to add more employees, else return
 * indice "i" where the function set the new values
 */
int searchEmpty(Employee employees[], int len);

/** \brief add new employee, asking the correct values with a limit of 5 tries
 * else the function continue with the next question
 * \param Employee employees
 * \param int len
 * \param int id
 * \return int return (1) if the function could add the new employee, else return (0)
 * [error].
 */

int newEmployee(Employee employees[], int len, int id);

/** \brief
*
* \param Employee employees
* \param int len
* \param int id
* \return
*
*/
void findEmployeeById(Employee employees[], int len, int id);

/** \brief show a list of the employees or specific employee
 *
 * \param Employee employeeX
 * \return employees or specific employee
 */

void printEmployees(Employee employeeX);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param Employee employees
* \param int len
* \param int id
* \return int Return (-1) if Error [Invalid length or NULL vector or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee employees[], int len, int id);

/** \brief find a specific employee by ID
 *
 * \param int id
 * \param Employee employees[]
 * \param int len
 * \return int return (0) if the user canceled the function, or (1) if
 * the employee was eliminated.
 */
int searchSpecificEmployee(int id, Employee employees[], int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param Employee employees[]
* \param int len
* \param int order [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL vector] - (0) if Ok
*
*/
int sortEmployees(Employee employees[], int len, int order);

/** \brief Ask for ID and check if exist
 *
 * \param Employee employee[]
 * \param int tam
 * \return int return flag = (0) if ID does not exist, flag = (1) if Ok
 * and call the function findEmployeeById
 */

int searchEmployee(Employee employee[], int tam);

void modifyMenuCases(Employee employess[], int tam, int id);

int modifyMenu();
