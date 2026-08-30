
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// structs
struct Date
{
    int day;
    int month;
    int year;
};

// helper function
void clear_screen();
void print_date(Date);
void print_title(string);

// classes
class EmployeeIdentity
{
    private:
        int employee_id;
        Date date_of_hire;

    public:
        EmployeeIdentity(int emp_id, Date date)
            : employee_id(emp_id), date_of_hire(date)
        {
            
        }

        // default constructor 
        EmployeeIdentity(){};

        // copy constructor 
        EmployeeIdentity(EmployeeIdentity& emp_id)
        {
            employee_id = emp_id.employee_id;
            date_of_hire = emp_id.date_of_hire;
        }

        // getter methods 
        int get_employee_id() const
        {
            return employee_id;
        }

        Date get_date_of_hire() const
        {
            return date_of_hire;
        }
};  

class EmployeeProfile
{   
    private:
        string department;
        long salary;
        string job_title;

        // valid amount function
        bool is_valid_amount(int amount)
        {
            if(amount > 0)
            {
                return true;
            }
            else
            {
                cout << "Entered an invalid amount." << endl;
                return false;
            }
        }

    public:
        EmployeeProfile(string dep, long sal, string job)
            : department(dep), salary(sal), job_title(job)
        {
        
        }
        
        // default constructor 
        EmployeeProfile(){};

        // copy function 
        EmployeeProfile(EmployeeProfile& emp_prof)
        {
            department = emp_prof.department;
            salary = emp_prof.salary;
            job_title = emp_prof.job_title;
        }

        // getter methods 
        long get_salary() 
        {
            return salary;
        }

        string get_department() 
        {
            return department;
        }

        string get_job_title() 
        {
            return job_title;
        }

        // setter methods
        void set_salary(long sal)
        {
            if (is_valid_amount(sal))
            {
                salary = sal;
            }
        }

        void add_salary(long amount)
        {
            if (is_valid_amount(amount))
            {
                salary += amount;
            }
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

class Employee
{
    private:
        static int employee_count;
        static int max_size;
        string name;
        int age;
        EmployeeIdentity emp_id;
        EmployeeProfile emp_profile;
    public:
        Employee(string _name, int _age, EmployeeIdentity _emp_id, EmployeeProfile _emp_profile)
            : name(_name), age(_age), emp_id(_emp_id), emp_profile(_emp_profile)
        {
            
        }

        // default constructor
        Employee(){};
        // getter methods 
        string get_name()
        {
            return name;
        }

        int get_age()
        {
            return age;
        }

        int get_employee_id()
        {
            return emp_id.get_employee_id();
        }

        Date get_date_of_hire()
        {
            return emp_id.get_date_of_hire();
        }

        string get_department()
        {
            return emp_profile.get_department();
        }

        long get_salary() 
        {
            return emp_profile.get_salary();
        }

        string get_job_title()
        {
            return emp_profile.get_job_title();
        }

        // setter methods
        void set_name(string _name)
        {
            name = _name;
        }

        void set_age(int _age)
        {
            age = _age;
        }

        void give_raise(long amount)
        {
            emp_profile.add_salary(amount);
        }

        void set_salary(long sal)
        {
            emp_profile.set_salary(sal);
        }

        void set_department(string dep)
        {
            emp_profile.set_department(dep);
        }

        void set_job_title(string job)
        {
            emp_profile.set_job_title(job);
        }
};

int Employee::employee_count = 0;
int Employee::max_size = 20;


int main()
{
    int menu_index = 0;
    bool run  = true;

    while (run)
    {
        string tname;
        int tage;
        int tempid;
        int d, m, y;
        Date tempdate;
        string tdep;
        long tsalary;
        string title;

        switch(menu_index)
        {
            case 0:
                clear_screen();
                print_title("Employee Management System");
                cout << "1. Add Employee" << endl;
                cout << "2. Update Employee Information" << endl;
                cout << "3. Find Employee Information" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice(Any other key to quit): ";
                cin >> menu_index;
                break;
            case 1:

                clear_screen();
                print_title("Adding Employee Information");
                cout << "Enter Employee Name: ";
                cin >> tname;
                cout << "Enter Employee Age: ";
                cin >> tage;
                cout << "Enter Employee Id: ";
                cin >> tempid;
                cout << "Enter Date of Hire (Format-> dd mm yy): ";
                cin >> d;
                cin >> m;
                cin >> y;
                tempdate = {d, m, y};
                cout << "Enter the Department: ";
                cin >> tdep;
                cout << "Enter the Job Title: ";
                cin >> title;
                cout << "Enter the salary: ";
                cin >> tsalary;
                break;
            default:
                run = false;
                cout << "\n\nExiting the program..." << endl;
                break;
        }
    }
    return 0;
}

// ACTUAL DEFINITIONS
// clearing terminal 
void clear_screen()
{
    system("cls");
}

// helper function to print a date 
void print_date(Date date)
{
    cout << date.day << "/" << date.month << "/" << date.year << std::endl;
}

// title printing
void print_title(string title)
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        cout << "-";
    }
    cout << title;

    for (int i = 0; i < n; i++)
    {
        cout << "-";
    }
    cout << endl;
}

