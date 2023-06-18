#include <iostream>
using namespace std;

class Person {
  public: 
    Person(){
      name="james";
      age = 20;
    };
    string name;
    int age;
    void intro(){
      cout << "i am a person and name is " << name << endl;
    }
};

class Student : public Person {
  public:
    void intro(){
      cout << "i am a student and my name is " << name << " and my age is " << age << endl;
    }
};

int main()
{
  Person p1;
  p1.intro();

  Student s1;
  s1.intro();

  cout << "******************************"<<endl;

  Person *p2 = new Person();
  p2->intro();

  Student* s2 = new Student();
  s2->intro();

  cout << "******************************"<<endl;

  Person *p3;
  p3=&p1;
  p3->intro();

  cout << "******************************"<<endl;

  p3 = &s1;
  p3->intro();

  // cannot defined student pointer to person object
  // because student is type person, but parent is not type student 
  Student *s3;
  // s3=&p1; // NOT ALLOWED
  s3->intro();

  return 0;
};