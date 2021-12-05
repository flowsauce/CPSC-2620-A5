//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#ifndef DIAMAT_H
#define DIAMAT_H
#include "SymMat.h"
#include <iostream>

using namespace std;

class Diagonal_Matrix : public Symmetric_Matrix
{
  public:
   //overloaded constructor. We least this implementation empty as we are inheriting it from the symmetric matrix class
   Diagonal_Matrix(int n, double value);
   //we initialize a static variable, then the position is at (i,j) where i = j, we return this value, otherwise the value is returned as 0
   const double& operator()(int i, int j) const;
   //we initialize a static variable, then the position is at (i,j) where i = j, we return this value, otherwise the value is returned as 0
   double& operator()(int i, int j);

   //this function will loop through our matrix and output each value in its corresponding (i,j) position.
   void print();
   //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values.
   double sum();
};

#endif
