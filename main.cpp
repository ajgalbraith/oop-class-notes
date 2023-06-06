#include <iostream>
using namespace std;

void f1() {
  int a = 0;        // local variable
  static int x = 0; // static/global variable
  x++;
  a++;
  cout << "a = " << a << "; x = " << x << ";" << endl;
}

void f2(int *p) {
  (*(p))++;
  // cout << "p = " << *p << ";" << endl;
}

int main() {
  cout<<"Starting program, fam!"<<endl;
  // static variables vs local
  f1(); // call function thrice
  f1();
  f1();
  // takeaway static/global outlive functions,
  // whereas local variables vanish

  // heap variables
  int *p = new int;
  *p = 0;
  f2(p);
  f2(p);
  f2(p);
  cout << "p = " << *p << ";" << endl;
  return 0;
}