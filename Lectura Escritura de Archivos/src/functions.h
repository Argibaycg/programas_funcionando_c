
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int getEmployeesData(char pName[],char pLastName[],float* pSalary,int* pSector, char* pMesaggeError);
int menuModifyEmployee(Employee arrayEmployees[], int lentgh);
int getIdToRemoveEmployee(Employee arrayEmployees[], int lentgh, int* pIdParaRemover);
int removeEmployee(Employee arrayEmployees[], int len, int id);

#endif /* FUNCTIONS_H_ */
