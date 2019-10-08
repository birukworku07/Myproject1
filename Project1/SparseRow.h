#pragma once
class SparseRow
{
	// protected fields of SparseRow fields
protected:
	int row;
	int col;
	int value;

	// public fuction prototypes
public:
	SparseRow();
	// paramtarized constructor prototype
	SparseRow(int i, int j, int val);
	int getRow();
	int getCol();
	int getValue();
	void display();
	~SparseRow();
	
};

