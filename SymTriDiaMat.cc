//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#include <iostream>
#include <vector>
#include "SymTriDiaMat.h"

Symmetric_Tridiagonal_Matrix::Symmetric_Tridiagonal_Matrix(int n, double value): Symmetric_Matrix(n, value)
{
   //Empty as we are inheriting it from the symmetric matrix class
}

//since we want the positions on the three middle diagonal values, we look at when for (i,j) i = j, or i = j+1, or i = j-1 and then return the value for this position in the matrix. Otherwise the return the value as zero
const double& Symmetric_Tridiagonal_Matrix:: operator()(int i, int j) const
{
   //initializing a static variable as we don't want it to be modified
   static double v;
   int pos = (i-1)*dim - total(i-1)+j-1;
   if (j == i || j+1 == i || j-1 == i)
   {
      return mat[pos];
   }
   else
   {
      v = 0;
      return v;
   }
}

//since we want the positions on the three middle diagonal values, we look at when for (i,j) i = j, or i = j+1, or i = j-1 and then return the value for this position in the matrix. Otherwise the return the value as zero
double& Symmetric_Tridiagonal_Matrix::operator()(int i, int j)
{
   //initializing a static variable as we don't want it to be modified
   static double v;
   int pos = (i-1)*dim - total(i-1)+j-1;
   if (j == i || j+1 == i || j-1 == i)
   {
      if (j >= i)
	 return mat[pos];
      else
	 return (*this)(j, i);
   }
   else
   {
      v = 0;
      return v;
   }
}

//this function will loop through our matrix and output each value in its corresponding (i,j) position.
void Symmetric_Tridiagonal_Matrix::print()
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
double Symmetric_Tridiagonal_Matrix::sum()
{
   double sum = 0;
   int matrix = dim*dim;
   for (int i = 0; i < matrix; i++)
      sum += (*this)(int(i/dim)+1, i%dim+1);
   return sum;
}
