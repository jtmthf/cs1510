#include <iostream>
#include "IntBox.h"

using namespace std;

int main () 
{
  cout << "IntBox Tester" << endl;
  
  cout << "#1" << endl;
  IntBox a(6,2);
  cout << a << endl;

  cout << "#2" << endl;
  IntBox b(4,2);
  cout << b << endl;
  
  cout << "#3" << endl;
  IntBox c(5,5);
  c.set( 1, 77 );
  cout << c << endl;
  
  cout << "#4" << endl;
  IntBox d(8,8);
  d.set( 2, 1 );
  cout << d << endl;

  cout << "#5 : Operator=" << endl;
  c = d;
  cout << d << endl;
  cout << c << endl;
  c.set( 5, 42 );
  cout << d << endl;
  cout << c << endl;
  
  cout << "#6 : Copy Constructor" << endl;
  IntBox e(a);
  cout << a << endl;
  cout << e << endl;
  e.set( 3, 88 );
  cout << a << endl;
  cout << e << endl;
  
  
  return 0;
}