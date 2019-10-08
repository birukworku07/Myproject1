#include "pch.h"
#include "SparseRow.h"
#include <iostream>
using namespace std;

// default constructor
SparseRow::SparseRow()
{
	row = -1;
	col = -1;
	value = 0;
}

// parametrized constructor
SparseRow::SparseRow(int a, int b, int c) {
	row = a;
	col = b;
	value = c;
}
// method that displays a single row in the sparse matrix representation
void SparseRow::display() {
	cout << row << ", " << col << ", " << value << endl;
}
 // returns the row
int SparseRow::getRow() {
	return row;
}
//returns the column 
int SparseRow::getCol() {
	return col;
}
// returns the value
int SparseRow::getValue() {
	return value;
}

SparseRow::~SparseRow()
{
}
