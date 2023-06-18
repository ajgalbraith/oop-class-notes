#include <iostream>
using namespace std;
// generics
// template <typename T1, typename T2>


class Person {
  public: 
    Person(){
      name="james";
      age = 20;
    };
    string name;
    int age;
    void intro(){
      cout << "my name is " << name << endl;
    }
};

class Student : Person {
  public:
    string name="alma";
    // using Person::age;
    void intro(){
      cout << "my full name is " << name << " and my age is " << age << endl;
    }
    void parentIntro(){
      Person::intro();
    }
};

int main()
{
  Person p1;
  p1.intro();
  cout << p1.name << endl; 
  Student s1;
  s1.intro();
  s1.parentIntro();
  return 0;
};