#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;

// constructor elements initialized to 0
Matrix::Matrix(uint rows, uint cols) {
  this->rows = rows;
  this->cols = cols;
  arr = new double*[rows];
  for (uint i = 0; i < rows; i++) {
    arr[i] = new double[cols];
  }
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      arr[i][j] = 0;
    }
  }
}

// constructor using initializer list
Matrix::Matrix(const i_list & list) {
  rows = list.size();
  cols = (*list.begin()).size();
  arr = new double*[rows];
  for (uint k = 0; k < rows; k++) {
    arr[k] = new double[cols];
  }
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      arr[i][j] = *((list.begin() + i)->begin() + j);
    }
  }
}

// copy constructor
Matrix::Matrix(const Matrix & m) {
  this->rows = m.rows;
  this->cols = m.cols;
  arr = new double*[rows];
  for (uint i = 0; i < rows; i++) {
    arr[i] = new double[cols];
  }
  for (uint i = 0; i < rows; i++) {
    for(uint j = 0; j < cols; j++) {
      arr[i][j] = m.arr[i][j];
    }
  }
}

// destructor
Matrix::~Matrix() {
  for (uint i = 0; i < rows; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

// add scalar to matrix
Matrix Matrix::add(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] + s;
    }
  }
  return m;
}

// add matrix to another matrix
Matrix Matrix::add(const Matrix & m) const {
  Matrix mm(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      mm.arr[i][j] = arr[i][j] + m.arr[i][j];
    }
  }
  return mm;
}

// subtract scalar from matrix
Matrix Matrix::subtract(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] - s;
    }
  }
  return m;
}

// subtract matrix from another matrix
Matrix Matrix::subtract(const Matrix & m) const {
  Matrix mm(rows, cols);
  for (uint i = 0; i < m.rows; i++){
    for (uint j = 0; j < m.cols; j++){
      mm.arr[i][j] = arr[i][j] - m.arr[i][j];
    }
  }
  return mm;
}

// multiply matrix by scalar
Matrix Matrix::multiply(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] * s;
    }
  }
  return m;
}

// multiply matrix by another matrix
Matrix Matrix::multiply(const Matrix & m) const {
  Matrix mm(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < mm.cols; j++) {
      for (uint k = 0; k < mm.cols; k++) {
	mm.arr[i][j] += arr[i][k] * m.arr[k][j];
      }
    }
  }
  return mm;
}

// divide matrix by scalar
Matrix Matrix::divide(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] / s;
    }
  }
  return m;
}

// transpose of matrix
Matrix Matrix::t() const {
  Matrix m(cols, rows);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[j][i];
    }
  }
  return m;
}

// returns number of rows
const uint Matrix::numRows() const {
  return rows;
}

// returns number of columns
const uint Matrix::numCols() const {
  return cols;
}

// get/set element at row, col
double & Matrix::at(uint row, uint col) {
  return arr[row][col];
}

// get element at row, col
const double & Matrix::at (uint row, uint col) const {
  return arr[row][col];
}

// overloaded function call operator
double & Matrix::operator()(uint row, uint col) {
  return arr[row][col];
}

// overloaded copy assignment operator
Matrix Matrix::operator=(const Matrix & m) {
  for(uint i = 0; i < m.rows; i++) {
    for(uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j];
    }
  }
  return m;
}

// overloaded operator for scalar addition
Matrix Matrix::operator+(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] + s;
    }
  }
  return m;
}
Matrix Matrix::operator+(const Matrix & m) const {  
  Matrix mm(rows, cols);
  for(uint i = 0; i < m.rows; i++) {
    for(uint j = 0; j < m.cols; j++) {
      mm.arr[i][j] = m.arr[i][j] + arr[i][j];
    }
  }
  return mm;
}

// overloaded operator for scalar subtraction
Matrix Matrix::operator-(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] - s;
    }
  }
  return m;
}
Matrix Matrix::operator-(const Matrix & m) const {
  Matrix mm(rows, cols);
  for(uint i = 0; i < m.rows; i++) {
    for(uint j = 0; j < m.cols; j++) {
      mm.arr[i][j] = arr[i][j] - m.arr[i][j];
    }
  }
  return mm;
}

// overloaded operator for scalar multiplication
Matrix Matrix::operator*(double s) const {
  Matrix m(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] * s;
    }
  }
  return m;
}
Matrix Matrix::operator*(const Matrix & m) const {
  Matrix mm(rows, cols);
  for (uint i = 0; i < m.rows; i++) {
    for (uint j = 0; j < mm.cols; j++) {
      for (uint k = 0; k < mm.cols; k++) {
        mm.arr[i][j] += arr[i][k] * m.arr[k][j];
      }
    }
  }
  return mm;
}

// overloaded operator for scalar division
Matrix Matrix::operator/(double s) const {
  Matrix m(rows, cols);
  for(uint i = 0; i < m.rows; i++) {
    for(uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = arr[i][j] / s;
    }
  }
  return m;
}

// overloaded unary minus operator
Matrix Matrix::operator-() {
  Matrix m(rows, cols);
  for(uint i = 0; i < m.rows; i++) {
    for(uint j = 0; j < m.cols; j++) {
      m.arr[i][j] = - arr[i][j];
    }
  }
  return m;
}

// operator <<
ostream & operator<<(ostream & os, const Matrix & m) {
  for (uint i = 0; i < m.numRows(); i++) {
    os << "[ ";
    for (uint j = 0; j < m.numCols(); j++) {
      os << m.at(i, j) << " ";
    }
    os << "]" << endl;
  }
  return os;
}

// operator >>
istream & operator>>(istream & in, const Matrix & m) {
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      if (!(in >> m.arr[i][j])) { 
	return in;
      }
    }
  }
  return in;
}
