//CPSC 2620 ASSIGNMENT 5
//MADE BY: ANDREW PRIMEAU
//
//PROFESSOR: SHAHADAT HOSSAIN

#include <iostream>
#include <vector>
#include <string>
#include "SymTriDiaMat.h"
#include "DiaMat.h"
#include "LowerTriMat.h"
#include "UpperTriMat.h"
#include <bits/stdc++.h>

using namespace std;

string reverse_string(string s, int l);
int seq_search(int a[], int key, int l);
int dt_rt(int n);
void process_str_matrix(Structured_Matrix *mtxPtr[]);

int main()
{
   Structured_Matrix m1(4,0);

   cout << "A Structured Matrix constructed with intial values of zero for every entry:" << endl;
   m1.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m1.sum() << endl;
   cout << endl;

   Structured_Matrix m7(4,0);
   m7(1,1) = 1;
   m7(1,2) = 2;
   m7(1,3) = 3;
   m7(1,4) = 4;
   m7(2,1) = 5;
   m7(2,2) = 6;
   m7(2,3) = 7;
   m7(2,4) = 8;
   m7(3,1) = 9;
   m7(3,2) = 8;
   m7(3,3) = 7;
   m7(3,4) = 6;
   m7(4,1) = 5;
   m7(4,2) = 4;
   m7(4,3) = 3;
   m7(4,4) = 2;
   
   cout << "A structured Matrix:" << endl;
   m7.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m7.sum() << endl;
   cout << endl;
   
   Symmetric_Matrix m2(4,1);
   m2(1,1) = 1;
   m2(1,2) = 2;
   m2(1,3) = 3;
   m2(1,4) = 4;
   m2(2,1) = 2;
   m2(2,2) = 5;
   m2(2,3) = 6;
   m2(2,4) = 7;
   m2(3,3) = 8 ;
   m2(3,4) = 9;
   m2(4,4) = 10;
   
   cout << "A symmetric Matrix:" << endl;
   m2.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m2.sum() << endl;
   cout << endl;

   Diagonal_Matrix m3(4,0);
   m3(1,1) = 1;
   m3(2,2) = 2;
   m3(3,3) = 3;
   m3(4,4) = 4;

   cout << "A diagonal matrix:" << endl;
   m3.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m3.sum() << endl;
   cout << endl;

   Symmetric_Tridiagonal_Matrix m4(4,0);
   m4(1,1) = 1;
   m4(1,2) = 2;
   m4(2,1) = 2;
   m4(2,2) = 3;
   m4(2,3) = 4;
   m4(3,2) = 4;
   m4(3,3) = 5;
   m4(3,4) = 6;
   m4(4,3) = 6;
   m4(4,4) = 7;

   cout << "A Symmetric Tridiagonal Matrix:" << endl;
   m4.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m4.sum() << endl;
   cout << endl;

   Upper_Triangular_Matrix m5(4,0);
   m5(1,1) = 1;
   m5(1,2) = 2;
   m5(1,3) = 3;
   m5(1,4) = 4;
   m5(2,2) = 5;
   m5(2,3) = 6;
   m5(2,4) = 7;
   m5(3,3) = 8;
   m5(3,4) = 9;
   m5(4,4) = 10;

   cout << "An Upper Triangular Matrix:" << endl;
   m5.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m5.sum() << endl;
   cout << endl;

   Lower_Triangular_Matrix m6(4,0);
   m6(1,1) = 1;
   m6(2,1) = 2;
   m6(2,2) = 3;
   m6(3,1) = 4;
   m6(3,2) = 5;
   m6(3,3) = 6;
   m6(4,1) = 7;
   m6(4,2) = 8;
   m6(4,3) = 9;
   m6(4,4) = 10;

   cout << "A Lower Triangular Matrix:" << endl;
   m6.print();

   cout << endl;
   cout << endl << "The sum of the values of the matrix is: " << m6.sum() << endl;
   cout << endl;

   cout << "The string we are going to reverse is: Ambidextrous" << endl;
   string str = "Ambidextrous";
   cout << "The reverse of this is: " << reverse_string(str, 12) << endl;
   cout << endl;

   int array[10] = {1,2,3,4,5,6,7,8,9,10};
   cout << "We have an array of numbers: ";
   for(int i = 0; i < 10; i++)
      cout << array[i] << " ";
   
   cout << endl;
   cout << "We are now going to perform a sequence search to find 6 in the array of numbers is at index: " << seq_search(array, 6, 10) << " in the array!" << endl;
   cout << endl;



   int dig = 9832763;
   cout << "Now, we will use our last function to repeatedly sum the digits: " << dig << " to get a single digit number: " << dt_rt(dig) << endl;
   cout << endl;

   cout << "Finally, looking at the sums of the first 4 of our matrices, we have values of: " << m1.sum() << " " << m2.sum() << " " << m3.sum() << " " << m4.sum() << endl;
   cout << "The largest sum of all of these matrices is: ";
   Structured_Matrix* A[5];
   A[0] = &m1;
   A[1] = &m2;
   A[2] = &m3;
   A[3] = &m4;
   A[4] = nullptr;
   process_str_matrix(A);
   cout << endl;
}

//This function takes in a string of characters and reverse the string
string reverse_string(string s, int l)
{
   string str = "";
   //if the length is less than 1, we will simply return the string
   if (l < 1)
      return s;
   //if the length is less than 2, we will return the string at its place in an array, which will be at the length - 1
   if (l < 2)
   {
      str = s[l-1];
      return str;
   }
   //otherwise, we will go through and replace every value of the string until we reach the end, then retrun this reversed string
   else
   {
      str = s[l-1] + reverse_string(s, l-1);
      return str;
   }
}

int seq_search(int a[], int key, int l)
{
   //if the length isn't within our bounds and doesn't exist, such that the array is less than size 0 it returns an error
   if(l < 0)
      return -1;
   //if the position in the array is equal to our
   if(a[l-1] == key)
      return l-1;
   else
      return seq_search(a, key, l-1);
}

int dt_rt(int n)
{
   //we check if the value is less then 10, then we can simply return the single digit value.
   if(n < 10)
      return n;
   else
   {
      //We initialize a number to be our number mod 10 to shrink the digit size
      int num = n%10;
      //we then divide the number by ten
      n = n/10;
      //we finally return the function with our newly modded number, add them and pass it through until it is a single digit number
      return dt_rt(num + dt_rt(n));
   }
}

void process_str_matrix(Structured_Matrix *mtxPtr[])
{
   //we are passing a pointer to an array and derefencing it to receive a value
   double l = (*(mtxPtr[0])).sum(), v = 0;
   //we then loop through all of these values to determine the largest sum to then check these values and output them
   for(int i = 1; mtxPtr[i]; i++)
   {
      v = (*(mtxPtr[i])).sum();
      if(v > l)
      {
	 l = v;
      }
   }
   cout << l;
}
