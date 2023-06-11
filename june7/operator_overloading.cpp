#include <iostream>
using namespace std;

/* class Person;
int f1(Person *p1);
int f1(Person *p1) {
  return  p1->age;
};
class Person {
  private:
    string name;
    int age;
  friend int f1(Person *p1);
};
int main() {
  Person *p1 = new Person();
  p1->name = "John";
  p1->age = 20;
  cout << p1->name << endl;
  cout << p1->age << endl;
  return 0;
}; */

class Circle {
  // private:
  public:
    int* radius;
    string color;
    Circle() {
      radius = new int(0);
      color = "";
    };
    Circle(int r, string c) {
      radius = new int(r);
      color = c;
    };
    ~Circle() {
      delete radius;
      radius=NULL;
    }
    Circle(Circle& c) {
      radius = new int(*(c.radius));
      color = c.color;
    }
/*     int getArea() {
      return 3.14 * radius * radius;
    };
    int getRadius() {
      return radius;
    };
    void setRadius(int r) {
      radius = r;
    }; */
  
    Circle operator+(Circle c) {
      Circle temp(0, "");
      temp.radius = this->radius + *(c.radius);
      temp.color = this->color + " and " + c.color;
      return temp;
    };

    // assignment operator
    Circle operator=(Circle c){
      *(this->radius) = *(c.radius);
      this->color = c.color;
      return *this;
    };


    friend ostream& operator<<(ostream& os, Circle& c);
    friend istream& operator>>(istream& is, Circle& c);
};

ostream& operator<<(ostream& out, Circle& c) {
  return out << "Radius: " << *(c.radius) << ", color: " << c.color << endl;
}
istream& operator>>(istream& is, Circle& c) {
  return is >> *(c.radius) >> c.color;
}


int main() {
/*
  // operator overloading "+""
  Circle c1(10, "blue");
  Circle c2(5, "red");
  Circle c3(0, "green");
  c3 = c1+c2; // c3 = c1.operator+(c2);
  cout << c1.radius << ", " << c1.color << endl;
  cout << c2.radius << ", " << c2.color << endl;
  cout << c3.radius << ", " << c3.color << endl;
 */
  
  /* // PART 1 
  // input, output

  // operator overloading ">>"
  Circle c3(2, "green");
  cout << c3;

  // operator overloading "<<"
  Circle c1;
  cin >> c1;
  cout << c1; */

  // PART 2: copy constructor vs. assignment operator

  // test copy constructor
  Circle c1(1, "red");
  Circle c2 = c1; // Circle c2 = Circle(c1); NOTE: this is different from the assignment operator
  c2.color = "blue";
  cout << "c1: " << c1;
  cout << "c2: " << c2;

  // test assignment operator
  Circle c3;
  c3 = c1; // this is NOT the copy constructor. This is c3.operator(c1)
  *(c3.radius) = 99;
  cout << "c1: " << c1;
  cout << "c3: " << c3;

  return 0;
};