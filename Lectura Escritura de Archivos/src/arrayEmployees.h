#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

Employee* new_Empleado();
Employee* addEmployee(int id, char* name, char* lastName,float salary,int sector);
int searchEmpty(Employee arrayEmployees[], int len, int *pUbicacionEmpty);
int printEmployees(Employee arrayEmployees[], int length);
int findEmployeeById(Employee arrayEmployees[], int len,int id);
int sortEmployeeByName(Employee arrayEmployees[], int len, int order);
int reportTotalSalary(Employee arrayEmployees[], int len, float *pTotalSalary);


#endif /* ARRAYEMPLOYEES_H_ */
