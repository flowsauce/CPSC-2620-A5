//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#ifndef TRIMAT_H
#define TRIMAT_H
#include <iostream>
#include "StructMat.h"

using namespace std;
class Triangular_Matrix : public Structured_Matrix
{
  public:
   //overloaded constructor that will resize the matrix to the integer value of the nxn dimension divided by two added with the integer value of the dimension divided by two if the nxn dimension mod 2 is 0.
//Otherwise, it does the same thing as stated above and adds one to the size. It will then loop through and assign the value to each position in the matrix
   Triangular_Matrix(int n, double value);

   //we initialize this to 0 as we never know what we are actually going to be indexing so we can't call it
   virtual const double& operator()(int i, int j) const = 0;
    //we initialize this to 0 as we never know what we are actually going to be indexing so we can't call it
   virtual double& operator()(int i, int j) = 0;
   //we initialize this to zero, as there is nothing to print
   virtual void print() = 0;
   //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values. We implement it even though we don't use this matrix form
   double sum();
};

#endif
