#include <iostream>
#include<cstring>

using namespace std;

class student
{
    int Id;
    char *Name;

    public:
//    student()
//    {
//    }
//
//    student(int id)
//    {
//        Id = id;
//        Name = new char[1];
//        Name[0] = '\0';
//    }
//
//
//    student(char name[])
//    {
//        Id = 0;
//        Name = new char[strlen(name) + 1];
//        strcpy(Name, name);
//    }


    student(int id = 0, char name[] = "default")
    {
        Id = id;
        Name = new char[strlen(name) + 1];
        strcpy(Name, name);
    }


    student(student &obj)
    {
        Id = obj.Id;
        Name = new char[strlen(obj.Name) + 1];
        strcpy(Name, obj.Name);
    }


    ~student()
    {
        delete [] Name;
    }


    void SetId(int id)
    {
        Id = id;
    }
    int GetId()
    {
        return Id;
    }
    void SetName(char *name )
    {
      delete[] Name;
      Name = new char[strlen(name) + 1];
      strcpy(Name, name);
    }
    char* GetName()
    {
        return Name;
    }
};

    void FillStudent(student &st , int id , char* name )
    {
        st.SetId(id);
        st.SetName(name);
    }
    void PrintStudent(student &st)
    {
        cout<< st.GetId() << st.GetName() <<endl;
    }

int main()
{
    student st3;
    student st4 (1,"sh3obola");
    FillStudent(st4, 1, "shaban");
    PrintStudent(st4);
    student st1;
    st1.SetId(2);
    st1.SetName("mohamed");
    PrintStudent(st1);


    return 0;
}