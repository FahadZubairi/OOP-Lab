// Create a class called Employee that includes three pieces of information as instance variables—a first name (type
// String), a last name (type String) and a monthly salary (double). If the monthly salary is not positive, set it to 0.0.
// Write a test application named EmployeeTest that demonstrates class Employee’s capabilities. Create two
// Employee objects and display each object’s yearly salary. Then give each Employee a 10% raise and display each
// Employee’s yearly salary again.
#include<iostream>
using namespace std;
class Employee{
    public:
    string firstname;
    string lastname;
    double salary;
    void SetSalary(){
        if (salary<0.0){
            salary = 0.0;
        }
    }
    void Bonus(){
        salary*=1.1;
    }
    void DisplaySalary(){
        cout<<"Employee Name: "<<firstname<<" "<<lastname<<endl;
        cout<<"Yearly Salary: "<<12*salary<<endl;
    }
};
int main(){
    Employee employee1, employee2;
    cout<<"Enter Employee1 name and salary: ";
    cin>>employee1.firstname>>employee1.lastname>>employee1.salary;
    employee1.SetSalary();
    cout<<"Enter Employee2 name and salary: ";
    cin>>employee2.firstname>>employee2.lastname>>employee2.salary;
    employee2.SetSalary();
    employee1.DisplaySalary();
    employee2.DisplaySalary();
    employee1.Bonus();
    employee2.Bonus();
    cout<<"******Salary After Bonus******"<<endl;
    employee1.DisplaySalary();
    employee2.DisplaySalary();
    return 0;
}