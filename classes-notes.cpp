#include <iostream>
using namespace std;

// define class
class Circle {
  // access modifiers: public, private, protected, etc.
private: // only acessible within class
  double radius = 0;
  static int count; // static variables are shared by a class
public:
  Circle() {
    cout << "a new circle was created" << endl;
    Circle::count++;
  }
  // method overloading (polymorphism)
  Circle(double r) {
    this->radius = r;
    cout << "a new circle with radius=" << r << " was created" << endl;
    Circle::count++;
  }

  // copy constructor
  Circle(Circle &c) {
    this->radius = c.radius;
    cout << "a new circle with radius=" << radius << " was created" << endl;
    Circle::count++;
  }

  // getter/setter methods
  double getRadius() { return radius; }
  /*
    in reality, the compiler adds an implicit reference to  the object, like so:
    double getRadius(Circle* this) {
      return radius; // returm this.radius;
    }
  */
  void setRadius(double r) { radius = r; }
  // static getter/setter
  static double getCount() { return Circle::count; }
  static void setCount(int r) { Circle::count = r; }
  // method
  void say(string txt) { cout << txt << endl; }
};

// setting static variables
int Circle ::count = 0;

int main() {
  std::cout << "Starting program!\n";

  Circle c1; // define and create object using "none-parameter" construction
  Circle c2(3.4); // define and create object using "parameter" construction

  // setter
  cout<<"setting c1 radius to 5.0"<<endl; 
  c1.setRadius(5.0); // setRadius ()

  // example of method calling
  c1.say("I'm a circle called c1!");
  c2.say("I'm a circle called c2!");

  // access static variables
  cout << "Current count=" << Circle::getCount() << endl;

  // from copy constructor
  Circle c3(c1);

}