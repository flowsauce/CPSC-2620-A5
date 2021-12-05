//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#ifndef UPPERTRIMAT_H
#define UPPERTRIMAT_H
#include "TriMat.h"
#include <iostream>

using namespace std;

class Upper_Triangular_Matrix : public Triangular_Matrix
{
  public:
   //Overloadec constructor. Empty as we are inheriting it from the triangular matrix class
   Upper_Triangular_Matrix(int n, double value);
   //this indexing operator will return the values of the matrix that will copy the one half of the matrix. Otherwise it returns the 0 as the values for the lower part of the matrix
   const double& operator()(int i, int j) const;
   //this indexing operator will return the values of the matrix that will copy the one half of the matrix. Otherwise it returns the 0 as the values for the lower part of the matrix
   double& operator()(int i, int j);
   //this function will loop through our matrix and output each value in its corresponding (i,j) position.
   void print();
   //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values.
   double sum();
};

#endif
