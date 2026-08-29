// for employee logic and helper function

#include <iostream>
#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

class Employee{};

class EmployeeIdentity
{
    private:
        const int employee_id;
        const int government_id;
        const Date date_of_hire;

    public:
        EmployeeIdentity(int emp_id, int gov_id, Date date)
            : employee_id(emp_id), government_id(gov_id), date_of_hire(date)
        {
            
        }

        int get_employee_id()
        {
            return employee_id;
        }

        int get_government_id()
        {
            return government_id;
        }

        Date get_date_of_hire()
        {
            return date_of_hire;
        }
};


// helper function to print a date 

void print_date(Date date)
{
    std::cout << date.day << "/" << date.month << "/" << date.year << std::endl;
}

int main()
{

}