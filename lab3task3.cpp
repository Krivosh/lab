#include <iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{  
	string ram = "vlados.txt";
	ofstream vlados1;
	vlados1.open(ram, ofstream::app);
	if(!vlados1.is_open())
	{
		cout << "error";
	}
	
	string S = "string1";//после первого запуска чтобы проверить программу необходимо изменить значение S
	ifstream fil;
	fil.open("vlados.txt");
	if (!fil.is_open())
	{
		cout << "error";
	
	}
	else
	{
		string str;
		vector<string>v;
		while(!fil.eof())
		{
			str = "";
			getline(fil, str);
			cout << str << endl;
			v.push_back(str);
			
		}
		ofstream file;
		file.open("vlados.txt");
		if(!file.is_open())
		{
			cout << "error";
		}
		else
		{
			file << S << endl;
		}
		for (int i = 0; i < v.size(); i++) 
		{
			file << v[i] << endl;
		}
		file.close();
	}
	fil.close();
   vlados1.close();


	return 0;
}
