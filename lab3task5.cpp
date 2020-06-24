#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{

	ifstream fin;
	fin.open("Lab.txt");
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		vector<double> myVector;
		while (!fin.eof()) {
			double v;
			fin>> v;
			if (floor(v) != v)
				myVector.push_back(v);
		}
		ofstream fout;
		fout.open("newLab.txt");
		for (int i = 0; i < myVector.size(); i++) {
			fout << myVector[i] << " ";
		}
		fout.close();
	}
	fin.close();
	return 0;

}
