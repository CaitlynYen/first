#include<iostream>
#include<cstring>
#include<string>
#include<fstream> 
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
	int row;
	int column;
	vector<int>r;
	vector<int>c;
	ifstream filein;
	ofstream fileout;
	string name = "./";
	string id = argv[1];
	string matrix = "/matrix.data";
	string fin = "/final.peak";
	string in = name + id + matrix;
	string out = name + id + fin;
	filein.open(in.c_str());
	if (filein)
	{
		filein >> row >> column;
		int mat[row][column];
		while (!filein.eof())
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					filein >> mat[i][j];
				}
			}
		}
		filein.close();

		fileout.open(out.c_str());
		int count = 0;
		for (int i = 1; i < row - 1; i++)
			for (int j = 1; j< column - 1; j++)
				if (mat[i][j] >= mat[i - 1][j])
					if (mat[i][j] >= mat[i + 1][j])
						if (mat[i][j] >= mat[i][j - 1])
							if (mat[i][j] >= mat[i][j + 1])
							{
								count++;
								r.push_back(i + 1);
								c.push_back(j + 1);
							}
		fileout << count << endl;
		for (int i = 0; i < r.size(); i++) 
		{
				fileout << r[i] << " ";
				cout << r[i] << " ";
				fileout << c[i] << " ";
				cout << c[i] << " ";
				fileout << endl;
				cout << endl;
		}
		fileout.close();
	}
	return 0;
}
