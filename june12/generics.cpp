#include <iostream>
using namespace std;

template <typename T>

void myfunc(T x) {
  cout << "x = " << x << endl;
}

int main()
{
  myfunc(10);
  myfunc(10.5);
  myfunc('a');
  myfunc("hello");
  return 0;
}