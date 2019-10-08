// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author: Biruk Kassahun Worku
// version: 2/06/2018

#include "pch.h"
#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main()
{
	
	// declaring integers for number of rows, number of coloumn, commonvalue, number of non sparsevalue and for the value the user inputs
	int n, m, cv, noNSV, val;
	
	// temporary SparseMatrix
	SparseMatrix* temp;
	
	// storing in the dimensions of the first matrix from the user
	cin >> n >> m >> cv >> noNSV;
	

	SparseMatrix* firstOne = new SparseMatrix(n, m, cv, noNSV);
	SparseRow* myMatrixArray1 = (*firstOne).getMyMatrix();
	int currentSize = (*firstOne).getCount();
	

	// loop through the number of rows and number of columns and put value in accordance from the user
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> val;
			
			// checking if the value is not a common value
			if (val != cv) {
				SparseRow* row = new SparseRow(i, j, val);
				myMatrixArray1[currentSize] = *row;
				++currentSize;
			}
		}
		
		    cout << endl;
	}

	// storing in the dimensions of the second matrix from the user
	cin >> n >> m >> cv >> noNSV;
	
	SparseMatrix* secondOne = new SparseMatrix(n, m, cv, noNSV);
	SparseRow* myMatrixArray2 = (*secondOne).getMyMatrix();
	int currentSize2 = (*secondOne).getCount();

	// going through the number of rows and number of column
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> val;

			//checking if the value is not a common value
			if (val != cv) {
				SparseRow* r = new SparseRow(i, j, val);
				myMatrixArray2[currentSize2] = *r;
				++currentSize2;
			}
		}
		cout << endl;
	}


	cout << "First one in sparse matrix format" << endl;
	(*firstOne).display();
	
	cout << "First one in normal matrix format" << endl;
	(*firstOne).displayMatrix();
	cout << "First one in transpose" << endl;
	// catching the first transposed matrix into temp
	temp = (*firstOne).Transpose(); 
	(*temp).displayMatrix();

	cout << "Second one in sparse matrix format" << endl;
	(*secondOne).display();

	cout << "Second one in normal matrix format" << endl;
	(*secondOne).displayMatrix();

	cout << "Second one in transpose" << endl;
	// catching the second transposed matrix into temp
	temp = (*secondOne).Transpose();
	(*temp).displayMatrix();

	cout << "Multiplication of matrices in sparse matrix form: " << endl;
	// catching the resultant product matrix of the first and second matrix
	temp = (*firstOne).Multiply(*secondOne);
	(*temp).display();

	cout << "Addition of matrices in sparse matrix form: " << endl;
	// catching the resultant sum matrix of the first and second matrix
	temp = (*firstOne).Add(*secondOne);
	(*temp).display();

	// deleting the object firstOne
	delete firstOne;

	//deleting the object secondOne
	delete secondOne;

	return 0;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
