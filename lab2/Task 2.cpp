#include <iostream>
using namespace std;

class Employee
{
public:
    virtual float calculateSalary() = 0; 
};

class FullTimeEmployee : public Employee
{
private:
    float salary;

public:
    FullTimeEmployee(float s)
    {
        salary = s;
    }

    float calculateSalary() override
    {
        return salary;
    }
};


class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(int h, float r)
    {
        hoursWorked = h;
        hourlyRate = r;
    }

    float calculateSalary()override
    {
        return hoursWorked * hourlyRate;
    }
};

int main()
{
    FullTimeEmployee f(50000);     
    PartTimeEmployee p(20, 500); 

    int a,b;

    a = f.calculateSalary();
    b = p.calculateSalary();

    cout << "Full Time Employee Salary: " <<a<< endl;
    cout << "Part Time Employee Salary: " <<b<< endl;
}