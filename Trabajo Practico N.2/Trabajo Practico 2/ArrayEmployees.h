// SECTOR BIBLIOTECA
typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}Employee;

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
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL vector] - (0) if Ok
*
*/
int initEmployees(Employee employees[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee[]
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL vector or without
free space] - (0) if Ok
 */
int addEmployee(Employee employees[], int len, int id, char name[],char lastName[],float salary,int sector);

int searchEmpty(Employee employees[], int len);
int newEmployee(Employee employees[], int len);
