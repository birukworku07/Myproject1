#include "pch.h"
#include "SparseMatrix.h"
using namespace std;
#include <iostream>

SparseMatrix::SparseMatrix()
{
}
// paramterized constructor
SparseMatrix::SparseMatrix (int n, int m, int cv, int noNSV) {
	noRows = n;
	noCols = m;
	commonValue = cv;
	noNonSparseValues = noNSV;
	myMatrix = new SparseRow[noNSV];
	count = 0;	
}
// method that transposes a matrix
SparseMatrix* SparseMatrix::Transpose() {
	SparseMatrix* temp = new SparseMatrix(noRows, noCols, commonValue, noNonSparseValues);  // creating a temp sparseMatrix that holds the transposed matrix
	SparseRow* transposeArray = (*temp).getMyMatrix();
	for (int i = 0; i < noNonSparseValues; ++i) { // loop that goes through the rows of the sparseMatrix
		SparseRow* tempRow = new SparseRow((*this).myMatrix[i].getCol(),(*this).myMatrix[i].getRow(),(*this).myMatrix[i].getValue()); // swaping the rows and column values
		transposeArray[i] = *tempRow;
		}

	
	return temp;
}

// add method for SparseMatrix
SparseMatrix* SparseMatrix:: Add(SparseMatrix& M) {

	// resultant sparseMatrix that holds the sum matrix of the two matrices
	SparseMatrix* temp = new SparseMatrix(noRows, noCols, commonValue, noNonSparseValues + M.noNonSparseValues);  
	int valueToAdd = commonValue; 
	// creating a resultantArray of sparseRow to store the array of rows
	SparseRow* resultantArray = (*temp).myMatrix;  
	int counter = (*temp).count;
	bool found;
	// A boolean array that checks if the row number and column numbers are present in both matrices
	bool* checkArray = new bool[M.noNonSparseValues]; 

	// initializing all checkArray to false
	for (int k = 0; k < M.noNonSparseValues; ++k) { 
		checkArray[k] = false;
	}
	
	// going through the rows of the first sparseMatrix
	for (int i = 0; i < noNonSparseValues; ++i) { 
		found = false;
		valueToAdd = commonValue; // initially assigning valueToAdd to common value
		for (int j = 0; ((j < M.noNonSparseValues) && (!found)); ++j) { 
			
			if (((*this).myMatrix[i].getRow() == M.myMatrix[j].getRow()) && ((*this).myMatrix[i].getCol() == M.myMatrix[j].getCol())) {
				found = true;
				valueToAdd = M.myMatrix[j].getValue(); // setting value to be added to the value of the second matrix at this particular position
				checkArray[j] = true;	
				
				
			} 
			
			
		}
		SparseRow* resultantRow = new SparseRow((*this).myMatrix[counter].getRow(), (*this).myMatrix[counter].getCol(), (*this).myMatrix[counter].getValue() + valueToAdd);
		resultantArray[counter] = *resultantRow;
		++counter;
		
	}
	
	// for loop that goes through the rows of the second sparse matrix
	for (int h = 0; h < M.noNonSparseValues; ++h) {
		// going through the checkArray
		if (!checkArray[h]) { 
			SparseRow* resultantRow2 = new SparseRow(M.myMatrix[h].getRow(), M.myMatrix[h].getCol(), M.myMatrix[h].getValue() + commonValue);
			resultantArray[counter] = *resultantRow2;
			++counter;
		}

	}
	(*temp).setnoNonSparseValues(counter);

	// deleting the dynamically created checkArray
	delete[] checkArray;
	return temp;

}

SparseMatrix* SparseMatrix::Multiply(SparseMatrix& M) {
	
	
	SparseMatrix* temp = new SparseMatrix(noRows, noCols, commonValue, noNonSparseValues^2); // resultant sparseMatrix that holds the product matrix of the two matrix
	
	// getting an array to store the resultant rows
	SparseRow* productArray = (*temp).getMyMatrix(); 
	// getting count and storing it in a counter
	int counter = (*temp).count; 
	// declaring an integer to store the product of the two matrices
	int productVal; 

	// looping through the number of rows
	for (int i = 0; i < noRows; ++i) { 
		for (int j = 0; j < noCols; ++j) {
			productVal = 0;
			for (int k = 0; k < noRows; ++k) {
				productVal += (*this).getMyValue(i, k) * M.getMyValue(k, j);
				
			}

			// checking if the product is not a common vlaue
			if (productVal != commonValue) { 

				// storing the value in a resultant row
				SparseRow* resR = new SparseRow(i, j, productVal); 

				// storing the resultant row in the resaltant Array (product Array)
				productArray[counter] = *resR; 
				++counter; 
			}

		}
	}
	// setter for the resultant noNonsparseValues in order to set it to counter
	(*temp).setnoNonSparseValues(counter); 
	
	return temp;
}

// returns myMatrix
SparseRow*  SparseMatrix::getMyMatrix() {
	return myMatrix;
}

// display the sparse matrix
void SparseMatrix::display() { 
	
	for (int i = 0; i < noNonSparseValues; ++i) {  
			(*this).myMatrix[i].display();
	}
}
// method to display the matrix in its normal format

void SparseMatrix::displayMatrix() {
	//nested for loops that go through the number of rows and number of coloumns 
	for (int i = 0; i < noRows; ++i) { 
		for (int j = 0; j < noCols; ++j) {
			cout << (*this).getMyValue(i, j) << '\t';
			
		}
		cout << endl;

	}
			
	
 }
// returns the noRows
int SparseMatrix::getNoRows() {
	return noRows;

}
// return the noCols
int SparseMatrix::getNoCols() {
	return noCols;

}
//return the commonValue
int SparseMatrix::getCommonValue() {
	return commonValue;

}
// returns the number of non sparse values
int SparseMatrix::getNoNonSparseValues() {
	return noNonSparseValues;

}
// returns the count
int SparseMatrix::getCount() {
	return count;
}

// sets the noNonSparseValues
void SparseMatrix::setnoNonSparseValues(int count) {
	 noNonSparseValues = count;
}

// method that takes in rows and column and return the corresponding value
int SparseMatrix::getMyValue(int r, int c) {
	int result = commonValue;
	// loop that goes through the rows of the sparseMatrix
	for (int i = 0; i < noNonSparseValues; ++i) {
		if ((myMatrix[i].getRow() == r && myMatrix[i].getCol() == c)) {
			result = myMatrix[i].getValue();
		}
		
	}

	return result;
}

SparseMatrix::~SparseMatrix() {

}


