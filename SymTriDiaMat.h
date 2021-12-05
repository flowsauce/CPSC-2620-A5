//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#ifndef SYMTRIDIAMAT_H
#define SYMTRIDIAMAT_H
#include "SymMat.h"
#include <iostream>

using namespace std;

class Symmetric_Tridiagonal_Matrix : public Symmetric_Matrix
{
  public:
   //overloaded constructor. We least this implementation empty as we are inheriting it from the symmetric matrix class
   Symmetric_Tridiagonal_Matrix(int n, double value);
   //since we want the positions on the three middle diagonal values, we look at when for (i,j) i = j, or i = j+1, or i = j-1 and then return the value for this position in the matrix. Otherwise the return the value as zero
   const double& operator()(int i, int j) const;
   //since we want the positions on the three middle diagonal values, we look at when for (i,j) i = j, or i = j+1, or i = j-1 and then return the value for this position in the matrix. Otherwise the return the value as zero
   double& operator()(int i, int j);
   //this function will loop through our matrix and output each value in its corresponding (i,j) position.
   void print();
   //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values.
   double sum();
};

#endif
