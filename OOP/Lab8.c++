#include <iostream>
#include <cstring> // For strlen, strncpy, etc.
using namespace std;

class Employee
{
    int id;
    char *name;
    public:
    Employee()
    {
        id = 0;
        name = NULL;
    }

    Employee(int d , char *n)
    {
        id = d;
        int lenName = strlen(n)+1;
        name = new char[lenName];
        strcpy(name , n);
    }

    Employee(const Employee &copyConst)
    {
        id = copyConst.id;
        int lenNameForCopyConstructor = strlen(copyConst.name) +1;
        name = new char[lenNameForCopyConstructor];
        strcpy(name , copyConst.name);
    }

    void setName(char *n)
    {
        if( name != NULL)
        {
            delete [] name;
        }
        int lenName = strlen(n)+1;
        name = new char[lenName];
        strcpy(name , n);
    }

    char * getName()
    {
        return name;
    }

    void setId(int d)
    {
        id = d;
    }

    int getId()
    {
        return id;
    }

    void print ()
    {
        cout<< "ID:  " << id << " " << "Name:   " << name << endl;
    }

   Employee operator+(Employee &emp);  // 1
   Employee operator+(int d);    // 2
   friend Employee operator+(int d ,const Employee &emp);
   friend Employee operator+(char name [] ,const Employee &emp);
   Employee operator+(char name []);
   Employee operator++();
   Employee operator++(int d);
   Employee& operator=(Employee &emp);
   int operator==(const Employee emp);
};
    void fillData(Employee &emp , int id , char name[])
    {
            emp.setId(id);
            emp.setName(name);
    }
    
    void display(Employee &emp) 
    {
        cout << "ID: " << emp.getId() << ", Name: " << emp.getName() << endl;
    }

   Employee Employee:: operator+(Employee &emp)
   {
    Employee temp;
    temp.id = id + emp.id;
    int lenName = strlen(name) + strlen(emp.name) + 1;
    temp.name = new char [lenName];
    strcpy(temp.name , name);
    strcat(temp.name , emp.name);
    return temp;
   }

   Employee Employee ::operator+(int d)
   {
        Employee temp = *this; // create new obj and set the value of this in the new obj (temp)  
        ++ id;
        return temp;
   }




int main()
{
    Employee e1(1 , "shaban");
    e1.print();
    Employee e2(2 , "hassan");
    e2.print();
    Employee e3 = e1 + e2;
    e3.print();

}