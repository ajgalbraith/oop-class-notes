#include <iostream>
using namespace std;
// generics
// template <typename T1, typename T2>


class Person {
  public: 
    Person(){
      name="james";
    };
    string name;
    virtual void vIntro(){
      cout << "my virtual person name is " << name << endl;
    }
    void intro(){
      cout << "my person name is " << name << endl;
    }
};

class Student : public Person {
  public:
    string name="alma";
    void vIntro(){
      cout << "my virtual student name is " << name << endl;
    }
    void intro(){
      cout << "my student name is " << name << endl;
    }
};

int main()
{
  Person p1;
  // p1.intro();
  Student s1;
  // s1.intro();

  Person* p3;
  cout << "&p1 intro() vIntro()" << endl;
  p3 = &p1;
  p3->intro();
  p3->vIntro();
  cout << "&s1 intro() vIntro()" << endl;
  p3 = &s1;
  p3->intro();
  p3->vIntro();
  // Person *p2 = new Person();
  // Student *s2 = new Student();
  // s2->intro();

  return 0;
};