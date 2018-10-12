#include<iostream>
#include<cstring>
#include<string>
#include<fstream> 
using namespace std;
int main(int argc, char *argv[]) 
{
	int row; 
	int column;
	int a[10000] = { 0 };
	int result = 0;
	ifstream filein;
	ofstream fileout;
	string name = "./";
	string id = argv[1];
	string matrix = "/matrix.data";
	string fin = "/final.peak";
	string in = name + id + matrix;
	string out = name + id + fin;
	filein.open(in.c_str);
	if (filein)
	{
		filein >> row >> column;
		int array[row][column];
		while (!filein.eof())
		{
			for (int i = 1; i < row - 1; i++)
			{
				for (int j = 1; j < column - 1; j++)
				{
					int put;
					filein >> put;
					array[i][j] = put;
				}
			}
		}
		filein.close();

		fileout.open(out.c_str());
		int count = 0;
		for (int i = 1; i < row - 1; i++)
		{
			for (int j = 1; j < column - 1; j++)
			{
				if (array[i][j] >= array[i - 1][j])
					if (array[i][j] >= array[i + 1][j])
						if (array[i][j] >= array[i][j - 1])
							if (array[i][j] >= array[i][j + 1])
							{
								count++;
								a[result++] = i + 1;
								a[result++] = j + 1;
							}
			}
			if (count)
			{
				fileout << count << endl;
			}
			else fileout << 0 << endl;
			for (int i = 1; i < result - 1; i++)
			{
				fileout << a[i] << " ";
				cout << a[i] << " ";
				if (i % 2 == 1)
				{
					fileout << endl;
					cout << endl;
				}
			}
			fileout.close();
		}
		return 0;
	}
