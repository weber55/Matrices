#include "Matrix.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  
  // example usage 1
  Matrix a(2, 2);
  a.at(0, 0) = 1; // [ 1, 2 ]
  a.at(0, 1) = 2; // [ 1, 3 ]
  a.at(1, 0) = 1;
  a.at(1, 1) = 3;
  
  cout << "Matrix a" << endl;
  cout << a << endl;

  Matrix b(2, 2);
  b.at(0, 0) = 3; // [ 3 ]
  b.at(1, 0) = 2; // [ 2 ]
  b.at(0, 1) = 1;
  b.at(1, 1) = 4;

  cout << "Matrix b" << endl;
  cout << b << endl;

  //Matrix c = a.multiply(b);
  //cout << "[ " << c.at(0, 0) << " ]" << endl  // [ 7 ]
  //<< "[ " << c.at(1, 0) << " ]" << endl; // [ 9 ]

  cout << "a + b" << endl;
  Matrix c0 = a + b;
  cout << c0 << endl;
  cout << "a + a" << endl;
  Matrix c1 = a + a;
  cout << c1 << endl;
  cout << "a - 3.5" << endl;
  Matrix c2 = a - 3.5;
  cout << c2 << endl;
  cout << "b - b" << endl;
  Matrix c3 = b - b;
  cout << c3 << endl;
  cout << "a * 2.2" << endl;
  Matrix c4 = a * 2.1;
  cout << c4 << endl;
  cout << "a * b" << endl;
  Matrix c5 = a * b;
  cout << c5 << endl;
  cout << "a / 2" << endl;
  Matrix c6 = a / 2.0;
  cout << c6 << endl;

  //cout << "2 + a" << endl;
  //Matrix c7 = 2.0 + a;
  //cout << c7 << endl;
  
  Matrix d = {{1, 2},  // this will implicitly call the overloaded constructor
	      {3, 4}}; // that takes an initializer list
  cout << d << endl;

  Matrix e(2, 2);
  e = {{4, 3},
       {2, 1}};
  cout << e << endl;

  return EXIT_SUCCESS;
} // main

