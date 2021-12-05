//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#include <iostream>
#include <vector>
#include "TriMat.h"

//overloaded constructor that will resize the matrix to the integer value of the nxn dimension divided by two added with the integer value of the dimension divided by two if the nxn dimension mod 2 is 0.
//Otherwise, it does the same thing as stated above and adds one to the size. It will then loop through and assign the value to each position in the matrix
Triangular_Matrix::Triangular_Matrix(int n, double value)
{
   dim = n;
   int matrix = dim*dim;
   if (((matrix) % 2) == 0)
      mat.resize(int(((matrix)/2)) + int((dim/2)));
   else
      mat.resize(int(((matrix)/2)) + int((dim/2)+1));

   for (unsigned int i = 0; i < mat.size(); i++)
      mat[i] = value;
}

//this function will loop through our matrix and output each value in its corresponding (i,j) position. We implement it even though we don't use this matrix form
void Triangular_Matrix::print()
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

 //this function will loop through and add to the previous value each reference point in the matrix, then returning the absolute value of the sum of these values. We implement it even though we don't use this matrix form
double Triangular_Matrix::sum()
{
   double sum = 0;
   int matrix = dim*dim;
   for (int i = 0; i < matrix; i++)
      sum = sum + (*this)(int(i/dim)+1, i%dim+1);
   return sum;
}
