#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    int id;
    char *name;

public:

    Employee(int id = 0 , char name [] = "Default Constructor")
    {
        this->id = id ;
        int lengthName = strlen(name)+1;
        this->name = new char[lengthName];
        strcpy(this->name , name);
    }

    Employee(const Employee& emp)
    {
        this->id = emp.id; // Copy ID
        int lengthName = strlen(emp.name) + 1;
        this->name = new char[lengthName]; // Allocate memory for name
        strcpy(this->name, emp.name); // Copy the string content
    }
   
    ~Employee()
    {
        delete [] name;
    }

    void setname(char name []) 
    { 
        delete[] this->name;    
        int lenName = strlen(name)+1;      
        this->name = new char [lenName];      
        strcpy(this->name , name);       
    }

    char* getname ()
    {    
        return this->name;      
    }

    void setId(int id) 
    {
        this->id = id; 
    }

    int getId() 
    { 
        return id ;
    }

   Employee operator+(Employee &emp);
   Employee operator+(int d);
   friend Employee operator+(int d ,const Employee &emp);
   friend Employee operator+(char name [] ,const Employee &emp);
   Employee operator+(char name []);
   Employee operator++();
   Employee operator++(int d);
   Employee& operator=(Employee &emp);
   int operator==(const Employee emp);

    void Display()
    {
                cout << "ID: " << id << ", Name: " << name << endl;
    }
};
void fillData(Employee &emp , int id , char name[])
{
        emp.setId(id);
        emp.setname(name);
}
    
void display(Employee &emp) 
    {
        cout << "ID: " << emp.getId() << ", Name: " << emp.getname() << endl;
    }

Employee Employee ::operator+(Employee &emp)
{
    Employee temp;
    temp.id = id + emp.id;
    int lenName = strlen(name) +  strlen(emp.name) +  1;
    temp.name = new char [lenName];
    strcpy(temp.name , name);
    strcat(temp.name , emp.name);
    return temp;
}

Employee Employee ::operator+(int id)
{
    Employee temp ;
    temp.id =  this->id + id; 
    return temp;
}

Employee operator+(int id, const Employee &emp)
{
    Employee temp ;
    temp.id =  emp.id + id;
    return temp;
}

Employee Employee ::operator++()
{
    id ++;  // 8 increase into >>  9
    return *this;  // the value of this = 9
}

Employee Employee ::operator+(char name [])
{
    Employee temp;
    int lenName = strlen(name) + strlen(this->name) + 1;
    temp.name = new char[lenName];
    strcpy( temp.name , this->name);
    strcat(temp.name , name);
    return temp;
}

Employee operator+(char name [], const Employee &emp)
{
    Employee temp;
    int lenName = strlen(name) + strlen(emp.name) + 1;
    temp.name = new char[lenName];
    strcpy(temp.name , name);
    strcat(temp.name , emp.name);
    return temp;
}

Employee Employee ::operator++(int d)
{
    Employee temp = *this; // create new obj and set the value of this in the new obj (temp)  
    ++ id;
    return temp;
}

Employee& Employee::operator=(Employee &emp) 
{ 
    if (this == &emp) 
    return *this; 
    delete[] name; 
    id = emp.id; 
    if (emp.name) 
    { 
        name = new char[strlen(emp.name) + 1]; 
        strcpy(name, emp.name); 
    } else 
    {
         name = nullptr; 
    }
    return *this; 
}

int Employee::operator==(const Employee emp)
{
    // Compare both ID and name for equality
    if (this->id == emp.id && strcmp(this->name, emp.name) == 0)
        return 1; // Equal
    else
        return 0; // Not equal
}


int main()
{
   Employee emp1(1, "Shaban"); 
   Employee emp2(1, "hassan"); 
   Employee emp3 = emp1 + emp2; 
   emp3.Display(); 

   Employee emp4 = 3 + emp1; 
   Employee emp5 = 3 + emp2; 
   emp4.Display(); //4
   emp5.Display(); // 5

   ++emp1; 
   emp1.Display(); 
   emp2++; 
   emp2.Display();

   Employee emp6; 
   emp6 = emp1; 
   emp6.Display();

   Employee emp7 = "Mr. " + emp1; 
   emp7.Display();

   Employee emp8 =  emp2 + " Oky "; 
   emp8.Display();

   int isEqual = (emp1 == emp2);
    if (isEqual == 1)
        cout << "Equal" << endl;
    else
    cout << "Not Equal" << endl;
   
    return 0;
}