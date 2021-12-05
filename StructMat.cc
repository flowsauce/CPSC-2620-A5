//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#include <iostream>
#include <vector>
#include <cmath>
#include "StructMat.h"

//default constructor that will initialize the matrix to size 0
Structured_Matrix::Structured_Matrix()
{
   dim = 0;
   mat.resize(0);
}

//overloaded constructor that will create with the dimension n, resize the matrix to be nxn and then loop through to assign a value to each position
Structured_Matrix::Structured_Matrix(int n, double value)
{
   dim = n;
   int matrix = dim*dim;
   mat.resize(matrix);
   
   for(int i = 0; i < matrix; i++)
      mat[i] = value;
}

//this indexing operator returns the (i,j) position of the a matrix of type const
const double& Structured_Matrix::operator()(int i, int j) const
{
   int pos = ((i-1)*dim)+(j-1);
   return mat[pos];
}

//this indexing operator returns the (i,j) position of the a matrix
double& Structured_Matrix::operator()(int i, int j)
{
   int pos = ((i-1)*dim)+(j-1);
   return mat[pos];
}

//this function will loop through our matrix and output each value in its corresponding (i,j) position.
void Structured_Matrix::print()
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
double Structured_Matrix::sum()
{
   double sum = 0;
   int matrix = dim*dim;
   for (int i = 0; i < matrix; i++)
      sum = sum + (*this)(int(i/dim)+1, i%dim+1);
   return abs(sum);
}

//helper function to be used in the function that will return a value n if it is equal to 0, otherwise it returns n and adds it again to the total until we get down to n = 0
int Structured_Matrix::total(int n)
{
   if(n == 0)
      return n;
   else
      return n + total(n-1);
}
