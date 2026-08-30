#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

class Employee
{
    private:
        // static
        static int max_size;
        static int count;
        string name;
        int age;

        // imp
        int employee_id;
        Date date_of_hire;
        long salary;
        string department;
        string job_title;

    public:
        // constructor
    
        Employee(string _name = "Unknown", int _age = 0, int _employee_id = 0, Date _date_of_hire = {0, 0, 0}, 
                 long _salary = 0, string _department = "Unknown", string _job_title = "Unknown")
                 : name(_name), age(_age), employee_id(_employee_id), date_of_hire(_date_of_hire),
                   salary(_salary), department(_department), job_title(_job_title)
        {};

        // getters 
        string get_name() {return name;}
        int get_age() {return age;}
        int get_employee_id() {return employee_id;}
        Date get_date_of_hire() {return date_of_hire;}
        long get_salary() {return salary;}
        string get_department() {return department;}
        string get_job_title() {return job_title;}

        //setters
        void set_name(string _name) {name = _name;}
        void set_age(int _age)
        {
            if (age > 0) {age = _age;}
            else {cout << "Invalid Age." << endl;}
        } 
        void set_employee_id() {}
        
};