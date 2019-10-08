#pragma once
#include "SparseRow.h"

class SparseMatrix
{
	// protected fields of sparseMatrix
protected:
	int noRows;
	int noCols;
	int commonValue;
	int noNonSparseValues;
	SparseRow* myMatrix;
	int count;
	
	// public function prototypes of SparseMatrix class
public:
	SparseMatrix();
	SparseMatrix(int n, int m, int cv, int noNSV); 
	SparseMatrix* Transpose();
	SparseMatrix* Multiply(SparseMatrix& M);
	SparseMatrix* Add(SparseMatrix& M);
	void display();
	void displayMatrix(); 
	int getNoRows();
	int getNoCols();
	int getCommonValue();
	int getNoNonSparseValues();
	SparseRow* getMyMatrix();
	int getCount();
	void setnoNonSparseValues(int count);
	int getMyValue(int r, int c);
	~SparseMatrix();
};

