#include <iostream>
#include <cstring>
using namespace std;

class person 
{
    char name[50]; 
    int id;        
public:
    person() 
    {
        name[0] = '\0';
        id = 0; 
        cout << "Hello from default constructor in person class" << endl;        
    }

    person(const char* n, int i) 
    {
        strncpy(name, n, 49); 
        name[49] = '\0';      
        id = i;
        cout << "Hello from parameterized constructor in person class" << endl;

    }

    void SetName(const char* n) 
    {
        strncpy(name, n, 49); 
        name[49] = '\0';      
    }

    void SetId(int i) 
    {
        id = i;
    }

    const char* GetName() 
    {
        return name;
    }

    int GetId() 
    {
        return id;
    }

    void Display() 
    {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Employee: public person
{
    int salary;
    int id;
    char name [50];
public:
    Employee() : person()
    {
        cout << "Hello from default constructor in Employee class" << endl;        
        salary = 0;
    }

    Employee(const char* n, int id, int sal) : person(n, id)
    {
        salary = sal;
        cout << "Hello from parameterized constructor in Employee class" << endl;
    }

    void SetSalary(int sal) 
    {
        salary = sal;
    }

    int GetSalary() 
    {
        return salary;
    }

    void Print() 
    {
        cout << "Name: " << GetName() << ", ID: " << GetId() << ", Salary: " << salary << endl;
    }
};

class Customer: public person
{
    float accountNumber;
public:
    Customer():person()
    {
        cout << "Hello from default constructor in Customer class" << endl;        
        accountNumber = 0;
    }

    Customer(const char* n, int id , int accountNum):person(n , id)
    {
        accountNumber = accountNum;
        cout << "Hello from parameterized  constructor in Customer class" << endl;        
    }

    void setAccountNumber(int accountNum)
    {
        accountNumber = accountNum;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }
    void Print() 
    {
        cout << "Name: " << GetName() << ", ID: " << GetId() << ", accountNumber: " << getAccountNumber() << endl;
    }

};

int main()
{
    person p1; 
    p1.SetName("Omar"); 
    p1.Display(); 

    p1.SetId(1); 
    p1.Display(); 
    person p2;

    person p3("Shaban", 2);
    p3.Display();

    cout << "\n" << endl;
    Employee e1;
    e1.SetName("Jeson Statom");
    e1.Display();
    e1.SetId(100);
    e1.Display();

    Employee e2("Mohamed", 3, 50000);
    e2.Print();

    cout << "\n" << endl;
    Customer c1("messi" , 10 ,1990);
    c1.Print();

    return 0;
}



//  Task Two
// Virtual Inheritance: Ensures a single shared instance of base across the hierarchy.
class base
{
protected:
    int Z;
public:
    base()
    {
        Z = 0;
        cout << "Base default constructor called." << endl;
    }
    base(int z)
    {
        Z = z;
        cout << "Base parameterized constructor called." << endl;
    }

    void setz(int z)
    {
        Z = z;
    }

    int getz()
    {
        return Z;
    }
};

class base1: virtual public base
{
    protected:
    int X;
    public:
    base1()
    {
        cout << "base1 default constructor called." << endl;
        X = 0;
    }
    base1(int x)
    {
        cout << "base1 parameterized constructor called." << endl;
         X = x;
    }

    void setx(int x)
    {
        X = x;
    }

    int getx()
    {
        return X;
    }
};

class base2 : virtual public base
{
    protected:
    int Y;
    public:
    base2()
    {
        cout << "base2 default constructor called." << endl;
        Y = 0;
    }
    base2(int y)
    {
        cout << "base2 parameterized constructor called." << endl;
        Y = y;
    }

    void sety(int y)
    {
        Y = y;
    }
    int gety(){
        return Y;
    }
};

class child : public base1 , public base2
{
    public:
    child()
    {
        cout << "Child default constructor called." << endl;
    }
    child(int m, int n, int z) : base(z), base1(m), base2(n)
    //child(int m , int n , int z ): base1(m) ,base2(n) 
    {
        cout << "Child parameterized constructor called." << endl;

    }
    int sum()
    {
        return getx() + gety() + getz() ;
    }
    int product()
    {
        return getx() * gety() * getz() ; 
    }
    void print()
    {
        cout<< "Sum: " << sum() << "  product: " << product() << endl; 
    }
};

int main()
{
  child ch(3, 8 , 9);
  ch.sum();
  ch.product();
  ch.print();

    return 0;
}
