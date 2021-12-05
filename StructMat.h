//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#ifndef STRUCTMAT_H
#define STRUCTMAT_H
#include <iostream>

using namespace std;

class Structured_Matrix
{
  public:
   //default constructor that will initialize the matrix to size 0
   Structured_Matrix();
   //overloaded constructor that will create with the dimension n, resize the matrix to be nxn and then loop through to assign a value to each position
   Structured_Matrix(int n, double value);

   //this indexing operator returns the (i,j) position of the a matrix of type const
   virtual const double& operator()(int i, int j) const;
   //this indexing operator returns the (i,j) position of the a matrix
   virtual double& operator()(int i, int j);
   //this function will loop through our matrix and output each value in its corresponding (i,j) position.
   virtual void print();
   //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values.
   double sum();
   //helper function to be used in the function that will return a value n if it is equal to 0, otherwise it returns n and adds it again to the total until we get down to n = 0
   static int total(int n);
   
  protected:
   int dim;
   vector<double> mat;
};

#endif
