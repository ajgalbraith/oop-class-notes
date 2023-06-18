#include <iostream>
using namespace std;

template <class T, class U>

class A
{
  T x;
  U y;

public:
  A()
  {
    cout << "Constructor Called" << endl;
  }
};

int main()
{
  A<char, char> a;
  A<int, double> b;
  return 0; 
}

// int main()
// {
//   myfunc(10);
//   myfunc(10.5);
//   myfunc('a');
//   myfunc("hello");
//   return 0; 
// }
// void myfunc(V x)
// {
//   cout << "x = " << x << endl;
// }
