#include <iostream>
using namespace std;

class A
{
  int x;
  friend void f(A &a);
};

void f(A &a)
{
  a.x = 10;
  cout << "a.x = " << a.x << endl;
};

void g(A &a)
{
  // this is an error
  // a.x = 10;
  // cout << "a.x = " << a.x << endl;
};

int main()
{
  A a;
  // a.f(a); // error: 'class A' has no member named 'f'
  f(a);
  g(a);

  
  return 0;
}