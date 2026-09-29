#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee
{
protected:
    int id;
    string empName;
    string dept;

public:
    Employee(int i, string n, string d)
    {
        id = i;
        empName = n;
        dept = d;
    }

    void showInfo() const
    {
        cout << "ID: " << id
             << " | Name: " << empName
             << " | Department: " << dept;
    }

    virtual double calculateSalary() const = 0;

    virtual ~Employee()
    {
    }
};

// Full-Time Employee
class FullTimeEmployee : public Employee
{
private:
    double monthlySalary;

public:
    FullTimeEmployee(int i, string n, string d, double salary)
        : Employee(i, n, d)
    {
        monthlySalary = salary;
    }

    double calculateSalary() const
    {
        return monthlySalary;
    }

    void display() const
    {
        showInfo();

        cout << " | Type: Full-Time"
             << " | Salary: Rs. "
             << calculateSalary() << endl;
    }
};

// Part-Time Employee
class PartTimeEmployee : public Employee
{
private:
    double ratePerHour;
    int totalHours;

public:
    PartTimeEmployee(int i, string n, string d, double rate, int hours)
        : Employee(i, n, d)
    {
        ratePerHour = rate;
        totalHours = hours;
    }

    double calculateSalary() const
    {
        return ratePerHour * totalHours;
    }

    void display() const
    {
        showInfo();

        cout << " | Type: Part-Time"
             << " | Salary: Rs. "
             << calculateSalary() << endl;
    }
};

// Intern
class Intern : public Employee
{
private:
    double monthlyStipend;

public:
    Intern(int i, string n, string d, double stipend)
        : Employee(i, n, d)
    {
        monthlyStipend = stipend;
    }

    double calculateSalary() const
    {
        return monthlyStipend;
    }

    void display() const
    {
        showInfo();

        cout << " | Type: Intern"
             << " | Stipend: Rs. "
             << calculateSalary() << endl;
    }
};

// Main Function
int main()
{
    FullTimeEmployee emp1(501, "Ayodhya", "Marketing", 72000);

    PartTimeEmployee emp2(502, "Avanii", "Software Developer", 250000, 1);

    Intern emp3(503, "Arjun", "Design", 9000);

    cout << "===== Employee Salary Details =====" << endl;

    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}