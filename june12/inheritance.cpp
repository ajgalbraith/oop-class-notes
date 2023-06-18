#include <iostream>
using namespace std;

class person
{
private:
  int age;

public:
  string name;
  person(string name)
  {
    this->name = name;
    this->age = 0;
  }
  person(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
  ~person()
  {
    cout << "person " << name << " is destroyed" << endl;
  }

  friend ostream &operator<<(ostream &os, const person &p);
};

ostream &operator<<(ostream &os, const person &p)
{
  os << "name = " << p.name << ", age = " << p.age << endl;
  return os;
}

class student : public person // private would block student from accessing person's details
{
public:
  int rollno;
  student(string name, int rollno) : person(name)
  {
    this->rollno = rollno;
  }
  student(string name, int age, int rollno) : person(name, age)
  {
    this->rollno = rollno;
  }
  ~student()
  {
    cout << "student " << name << " is destroyed" << endl;
  }
    friend ostream &operator<<(ostream &os, const student &s);
};

ostream &operator<<(ostream &os, const student &s)
{
  os << "name = " << s.name << ", rollNo= " << s.rollno << endl;
  return os;
}


int main()
{
  // myfunc(10);
  // myfunc(10.5);
  // myfunc('a');
  // myfunc("hello");
  student s1 = student("Ravi", 10);
  student s2 = student("James", 10, 20);
  s1.name = "Jake"; // can only access if= student: public person
  // s2.age = 20; // error: cannot access if student is not a friend of person
  cout << "s1: " << s1;
  cout << "s2: " << s2;
  return 0;
}