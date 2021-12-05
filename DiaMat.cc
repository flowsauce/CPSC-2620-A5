//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#include <iostream>
#include <vector>
#include "DiaMat.h"

Diagonal_Matrix::Diagonal_Matrix(int n, double value): Symmetric_Matrix(n, value)
{
   //Empty as we are inheriting from Symmetric Matrix class
}

//we initialize a static variable, then the position is at (i,j) where i = j, we return this value, otherwise the value is returned as 0
const double& Diagonal_Matrix::operator()(int i, int j) const
{
   static double v;
   if(j == i)
   {
      int pos = (i-1)*dim - total(i-1)+(j-1);
      return mat[pos];
   }
   else
   {
      v = 0;
      return v;
   }
}

//we initialize a static variable, then the position is at (i,j) where i = j, we return this value, otherwise the value is returned as 0
double& Diagonal_Matrix::operator()(int i, int j)
{
   static double v;
   if(j == i)
   {
      int pos = (i-1)*dim - total(i-1)+j-1;
      return mat[pos];
   }
   else
   {
      v = 0;
      return v;
   }
}   

//this function will loop through our matrix and output each value in its corresponding (i,j) position.
void Diagonal_Matrix::print()
{
   int matrix = dim*dim;
   for(int i = 0; i < (matrix); i++)
   {
      if (i%dim == 0)
      {
	 cout << endl << " ";
      }
      cout << (*this)(int(i/dim)+1, i%dim+1) << " ";
   }
}

//this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values.
double Diagonal_Matrix::sum()
{
   double sum = 0;
   int matrix = dim*dim;
   for (int i = 0; i < matrix; i++)
      sum = sum + (*this)(int(i/dim)+1, i%dim+1);
   return sum;
}
