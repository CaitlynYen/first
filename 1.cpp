#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include<stdio.h>
using namespace std;
int main() {
	int count = 0;
	string STRING;
	vector<int>r;
	vector<int>c;
	fstream fio;
	ifstream inFile;
	fio.open("final.peak", ios::trunc || ios::out || ios::in);
	inFile.open("matrix.data");
	int row; 
	int col;
	inFile >> row >> col;
	int mat[row][col];
	for (int i = 0; i<row; i++)
		for (int j = 0; j<col; j++)
		{
			inFile >> mat[i][j];
		}
	inFile.close();
	for (int i = 1; i<row - 1; i++)
		for (int j = 1; j<col - 1; j++)
			if (mat[i][j] >= mat[i - 1][j])
				if (mat[i][j] >= mat[i + 1][j])
					if (mat[i][j] >= mat[i][j - 1])
						if (mat[i][j] >= mat[i][j + 1])
						{
							count++;
							r.push_back(i + 1);
							c.push_back(j + 1);
						}
	fio << count << endl;
	int size = r.size();
	for (int i = 0; i<size; i++)
		fio << r[i] << " ";
	fio << endl;
	for (int i = 0; i<size; i++)
		fio << c[i] << " ";
	getch();
	return 0;

}
