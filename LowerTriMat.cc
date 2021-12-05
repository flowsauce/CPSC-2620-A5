//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#include <iostream>
#include <vector>
#include "LowerTriMat.h"

Lower_Triangular_Matrix::Lower_Triangular_Matrix(int n, double value): Triangular_Matrix(n, value)
{
   //Empty as we are inheriting from the triangular matrix class
}

//this indexing operator will return the values of the matrix that will copy the one half of the matrix. Otherwise it returns the 0 as the values for the upper  part of the matrix
const double& Lower_Triangular_Matrix::operator()(int i, int j) const
{
   static double v;
   if (j<=i)
   {
      int pos = total(i-1)+j-1;
      return mat[pos];
   }
   else
   {
      v = 0;
      return v;
   }
}

//this indexing operator will return the values of the matrix that will copy the one half of the matrix. Otherwise it returns the 0 as the values for the upper  part of the matrix
double& Lower_Triangular_Matrix::operator()(int i, int j)
{
   static double v;
   if (j<=i)
   {
      int pos = total(i-1)+j-1;
      return mat[pos];
   }
   else
   {
      v = 0;
      return v;
   }
}

//this function will loop through our matrix and output each value in its corresponding (i,j) position.
void Lower_Triangular_Matrix::print()
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
double Lower_Triangular_Matrix::sum()
{
   double sum = 0;
   int matrix = dim*dim;
   for (int i = 0; i < matrix; i++)
      sum = sum + (*this)(int(i/dim)+1, i%dim+1);
   return sum;
}
