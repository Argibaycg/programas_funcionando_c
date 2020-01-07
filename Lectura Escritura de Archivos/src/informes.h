
#ifndef INFORMES_H_
#define INFORMES_H_

int menuOrderEmployees(Employee arrayEmployees[], int lentgh);
int reportTotalSalary(Employee arrayEmployees[], int len, float *pTotalSalary);
int countEmployeesAndAverageSalary(Employee arrayEmployees[], int len, float totalSalary, float* pAverageSalary);
int employeesWhitSalaryMoreThanAverageSalary(Employee arrayEmployees[], int len, float totalSalary,int* qtyEmployeesWhitSalaryMoreThanAverage);

#endif /* INFORMES_H_ */
