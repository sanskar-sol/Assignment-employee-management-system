
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
        EmployeeIdentity(int emp_id = 0, Date date = {0, 0, 0})
            : employee_id(emp_id), date_of_hire(date)
        {}

        // copy constructor 
        EmployeeIdentity(EmployeeIdentity& emp_id)
        {
            employee_id = emp_id.employee_id;
            date_of_hire = emp_id.date_of_hire;
        }

        // getter methods 
        int get_employee_id() const {return employee_id;}
        Date get_date_of_hire() const {return date_of_hire;}
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
        EmployeeProfile(string dep = "Unknown", long sal = 0, string job = "Unknown")
            : department(dep), salary(sal), job_title(job)
        {
        
        }
        


        // copy function 
        EmployeeProfile(EmployeeProfile& emp_prof)
        {
            department = emp_prof.department;
            salary = emp_prof.salary;
            job_title = emp_prof.job_title;
        }

        // getter methods 
        long get_salary() const {return salary;}
        string get_department() const {return department;}
        string get_job_title() const {return job_title;}

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
        static int count;
        static const int max_size;
        string name;
        int age;
        EmployeeIdentity emp_id;
        EmployeeProfile emp_profile;
    public:
        Employee(string _name = "Unknown", int _age = 0, EmployeeIdentity _emp_id = EmployeeIdentity(), EmployeeProfile _emp_profile = EmployeeProfile())
            : name(_name), age(_age), emp_id(_emp_id), emp_profile(_emp_profile)
        {}


        // getter methods 
        string get_name() const {return name;}
        int get_age() const {return age;}
        int get_employee_id() const {return emp_id.get_employee_id();}
        Date get_date_of_hire() const  {return emp_id.get_date_of_hire();}
        string get_department() const  {return emp_profile.get_department();}
        long get_salary() const {return emp_profile.get_salary();}
        string get_job_title() const{return emp_profile.get_job_title();}
        static int get_count() {return count;}

        // setter methods
        static void add_count() {count++;}
        static void minus_count() {count--;}
        void set_name(string _name)
        {
            name = _name;
        }

        void set_age(int _age)
        {
            age = _age;
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

        // printing information
        void print_info() const
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Salary: " << this->get_salary() << endl;
            cout << "Department: " << this->get_department() << endl;
            cout << "Job_Title: " << this->get_job_title() << endl;
        }
};

int Employee::count = 0;

int main()
{
    int menu_index = 0;
    const int max = 20;
    bool run  = true;
    Employee e[max];

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
        int temp_count = Employee::get_count();
        int temp_index;
        bool found;

        switch(menu_index)
        {
            case 0:
                clear_screen();
                print_title("Employee Management System");
                cout << "1. Add Employee" << endl;
                cout << "2. Salary Management" << endl;
                cout << "3. Print Employee Information" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice(Any other key to quit): ";
                cin >> menu_index;
                break;
            case 1:
            {
                clear_screen();
                print_title("Adding Employee Information");
                cout << "Enter Employee Name(No spaces): ";
                cin >> tname;
                cout << "Enter Employee Age: ";
                cin >> tage;

                // emp id
                cout << "Enter Employee Id: ";
                cin >> tempid;
                cout << "Enter Date of Hire (Format-> dd mm yy): ";
                cin >> d;
                cin >> m;
                cin >> y;
                tempdate = {d, m, y};
                EmployeeIdentity temp_id(tempid, tempdate);

                // emp profile
                cout << "Enter the Department(No spaces): ";
                cin >> tdep;
                cout << "Enter the Job Title(No spaces): ";
                cin >> title;
                cout << "Enter the salary: ";
                cin >> tsalary;
                EmployeeProfile temp_profile(tdep, tsalary, title);
                Employee temp_emp(tname, tage, temp_id, temp_profile);
                
                e[temp_count] = temp_emp;
                Employee::add_count();
                cout << "Employee Information Added" << endl;
                cout << "\nEnter 0 to Main Menu or 4 to exit: " << endl;
                cin >> menu_index;
                break;
            }
            case 2:
                clear_screen();
                print_title("Salary Management");
                cout << "Enter the EmployeeID: ";
                cin >> tempid;
                found = false;
                // searching 
                for (int i = 0, n = Employee::get_count(); i < n; i++)
                {
                    if (e[i].get_employee_id() == tempid)
                    {
                        found = true;
                        cout << "Employee Found!\n" << endl;
                        cout << "Name: " << e[i].get_name() << endl;
                        cout << "Enter the new Salary: " << endl;
                        cin >> tsalary;
                        e[i].set_salary(tsalary);
                        cout << "Salary Updated!" << endl;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Employee Not Found" << endl;
                }

                cout << "\nEnter 0 to Main Menu or 4 to exit: " << endl;
                cin >> menu_index;
                break;
            case 3:
                clear_screen();
                print_title("Print Employee Information");
                cout << "Enter the EmployeeID: ";
                cin >> tempid;
                found = false;
                // searching 
                for (int i = 0, n = Employee::get_count(); i < n; i++)
                {
                    if (e[i].get_employee_id() == tempid)
                    {
                        found = true;
                        cout << "Employee Found!\n" << endl;
                        e[i].print_info();
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Employee Not Found" << endl;
                }

                cout << "\nEnter 0 to Main Menu or 4 to exit: " << endl;
                cin >> menu_index;
                break;

            default:
                run = false;
                menu_index = 0;
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

