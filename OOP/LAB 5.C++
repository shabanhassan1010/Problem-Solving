#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    static char *schoolName;
    static int counter;
    int id;
    char *name;

public:
    Employee(int id = 0, const char name[] = "Default Constructor")
    {
        counter++;
        this->id = id;
        int lengthName = strlen(name) + 1;
        this->name = new char[lengthName];
        strcpy(this->name, name);
    }

    Employee(const Employee &copyConstructor)
    {
        counter++;
        this->id = copyConstructor.id;
        int lengthName = strlen(copyConstructor.name) + 1;
        this->name = new char[lengthName];
        strcpy(this->name, copyConstructor.name);
    }

    ~Employee()
    {
        delete[] name;
        counter--;
    }

    void setname(const char name[])
    {
        delete[] this->name;
        int lenName = strlen(name) + 1;
        this->name = new char[lenName];
        strcpy(this->name, name);
    }

    char* getname()
    {
        return this->name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void Display()
    {
        cout << "ID: " << id << ", Name: " << name << ", School Name: " << schoolName << endl;
    }

    static int getCounter()
    {
        return counter;
    }

    static void setSchoolName(const char* school)
    {
        if (schoolName != NULL)
        {
            delete[] schoolName;
        }
        int lenSchool = strlen(school) + 1;
        schoolName = new char[lenSchool];
        strcpy(schoolName, school);
    }

    static char* getSchoolName()
    {
        return schoolName;
    }
};

char* Employee::schoolName = "School One"; 
int Employee::counter = 0;

int main()
{
    Employee::setSchoolName("School One");

    Employee emp1(1, "Shaban");
    Employee emp2(2, "Hassan");

    emp1.Display();
    cout << "Number of Employees: " << Employee::getCounter() << endl;
    emp2.Display();
    cout << "Number of Employees: " << Employee::getCounter() << endl;

    Employee::setSchoolName("Sunrise Academy");
    cout << "Updated School Name: " << Employee::getSchoolName() << endl;

    return 0;
}