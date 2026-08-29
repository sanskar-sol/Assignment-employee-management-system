// for employee logic and helper function

#include <iostream>
#include <string>

using namespace std;

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
        int employee_id;
        int government_id;
        Date date_of_hire;

    public:
        EmployeeIdentity(int emp_id, int gov_id, Date date)
            : employee_id(emp_id), government_id(gov_id), date_of_hire(date)
        {
            
        }

        // getter metnods 
        int get_employee_id() const
        {
            return employee_id;
        }

        int get_government_id() const 
        {
            return government_id;
        }

        Date get_date_of_hire() const
        {
            return date_of_hire;
        }
};  

class EmployeeProfile
{
    private:
        mutable string department;
        mutable long salary;
        mutable string job_title;

    public:
        EmployeeProfile(string dep, long sal, string job)
            : department(dep), salary(sal), job_title(job)
        {
        
        }

        // getter methods 
        long get_salary() const
        {
            return salary;
        }

        string get_department() const
        {
            return department;
        }

        string get_job_title() const
        {
            return job_title;
        }

        // setter methods
        void set_salary(int sal)
        {
            salary = sal;
        }

        void set_department(string dep)
        {
            department = dep;
        }

        void set_job_title(string job)
        {
            job_title = job;
        }
};
// helper function to print a date 

void print_date(Date date)
{
    cout << date.day << "/" << date.month << "/" << date.year << std::endl;
}


int main()
{
    return 0;
}