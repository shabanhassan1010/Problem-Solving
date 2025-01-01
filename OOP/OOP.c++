#include <iostream>
#include <cstring> 
#include <cmath>   
using namespace std;

class Student 
{
    char name[50]; 
    int id;        
public:
    Student() 
    {
        name[0] = '\0'; // Initialize name to an empty string
        id = 0;         
    }

    Student(const char* n, int i) 
    {
        strncpy(name, n, 49); // Copy the name into the char array
        name[49] = '\0';      
        id = i;              
    }

    void SetName(const char* n) 
    {
        strncpy(name, name, 49); // Copy the name into the char array
        name[49] = '\0';
        // delete[] this->name;    
        // int lenName = strlen(name)+1;      
        // this->name = new char [lenName];      
        // strcpy(this->name , name);    
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

class Rectangle_C  // composition Rs
{
    Student student1, student2;
    int length, width;

public:
    Rectangle_C(const char* name1, int id1, const char* name2, int id2) : student1(name1, id1), student2(name2, id2) 
    {
        length = abs(student2.GetId() - student1.GetId());
        width = abs(strlen(student2.GetName()) - strlen(student1.GetName()));
    }

    void SetStudent1(const char* name, int id) 
    {
        student1.SetName(name);
        student1.SetId(id);
        length = abs(student2.GetId() - student1.GetId());
        width = abs(strlen(student2.GetName()) - strlen(student1.GetName()));
    }

    void SetStudent2(const char* name, int id)
    {
        student2.SetName(name);
        student2.SetId(id);
        length = abs(student2.GetId() - student1.GetId());
        width = abs(strlen(student2.GetName()) - strlen(student1.GetName()));
    }

    Student GetStudent1() 
    {
        return student1;
    }

    Student GetStudent2() 
    {
        return student2;
    }

    int Area() 
    {
        return (length * width);
    }

    void Display() {
        cout << "Student 1: ";
        student1.Display();
        cout << "Student 2: ";
        student2.Display();
        cout << "Length: " << length << " Width: " << width << endl;
        cout << "Area: " << Area() << endl;
    }
};

class Rectangle_A 
{
    Student *student1, *student2;
    int length, width;

public:
    Rectangle_A() 
    {
        student1 = student2 = nullptr;
        length = width = 0;
    }

    Rectangle_A(Student *s1, Student *s2) 
    {
        student1 = s1;
        student2 = s2;
        if (student1 != nullptr && student2 != nullptr) 
        {
            length = abs(student2->GetId() - student1->GetId());
            width = abs(strlen(student2->GetName()) - strlen(student1->GetName()));
        } 
        else 
        {
            length = width = 0;
        }
    }

    void SetStudent1(Student *s1) 
    {
        student1 = s1;
        if (student1 != nullptr && student2 != nullptr) 
        {
            length = abs(student2->GetId() - student1->GetId());
            width = abs(strlen(student2->GetName()) - strlen(student1->GetName()));
        } 
        else 
        {
            length = width = 0;
        }
    }

    void SetStudent2(Student *s2) 
    {
        student2 = s2;
        if (student1 != nullptr && student2 != nullptr) {
            length = abs(student2->GetId() - student1->GetId());
            width = abs(strlen(student2->GetName()) - strlen(student1->GetName()));
        } else {
            length = width = 0;
        }
    }

    // Getter for student1
    Student GetStudent1() {
        return *student1;
    }

    // Getter for student2
    Student GetStudent2() {
        return *student2;
    }

    // Method to calculate area
    int Area() {
        return (length * width);
    }

    // Method to display rectangle details
    void Display() {
        if (student1 != nullptr && student2 != nullptr) {
            cout << "Student 1: ";
            student1->Display();
            cout << "Student 2: ";
            student2->Display();
            cout << "Length: " << length << ", Width: " << width << endl;
            cout << "Area: " << Area() << endl;
        } else {
            cout << "Students are not fully initialized." << endl;
        }
    }
};


int main() 
{
    Rectangle_C rect("Alice", 101, "Bob", 102);

    rect.Display();

    rect.SetStudent1("Charlie", 103);
    rect.SetStudent2("David", 104);

    rect.Display();



    Student s1("Alice", 101);
    Student s2("Bob", 102);
    Student s3("Charlie", 103);

    Rectangle_A rect2;

    rect2.SetStudent1(&s1);
    rect2.SetStudent2(&s2);

    rect2.Display();

    rect2.SetStudent1(&s3);
    rect2.SetStudent2(&s1);

    rect2.Display();

    return 0;
}