//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#ifndef SYMMAT_H
#define SYMMAT_H
#include <iostream>
#include "StructMat.h"

using namespace std;
//inheriting elements of the structured matrix class
class Symmetric_Matrix : public Structured_Matrix
{
  public:
   //overloaded constructor that will resize the matrix to the integer value of the nxn dimension divided by two added with the integer value of the dimension divided by two if the nxn dimension mod 2 is 0.
//Otherwise, it does the same thing as stated above and adds one to the size. It will then loop through and assign the value to each position in the matrix
   Symmetric_Matrix(int n, double value);

   //this indexing operator will return the values of the matrix that will copy the one half of the matrix. Otherwise it returns the (i,j) positions value.
   virtual const double& operator()(int i, int j) const;
   //this indexing operator will return the values of the matrix that will copy the one half of the matrix. Otherwise it returns the (i,j) positions value.
   virtual double& operator()(int i, int j);
   //this function will loop through our matrix and output each value in its corresponding (i,j) position.
   virtual void print();
   //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values.
   double sum();
};

#endif
